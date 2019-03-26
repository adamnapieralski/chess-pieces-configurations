/*
 * Name: chess.cpp
 * Purpose: Custom library .cpp file for chess pieces and board classes
 * @author Adam Napieralski
 * @version 0.1 25/03/2019
 */

#include "chess.h"

Chess::Position::Position() {
    this->x = 0;
    this->y = 0;
}
Chess::Position::Position(int x1, int y1) {
    this->x = x1;
    this->y = y1;
}

Chess::Position::Position(Chess::Position &posit) {
    this->x = posit.x;
    this->y = posit.y;
}

Chess::Piece::Piece() {
    this->position.x = 0;
    this->position.y = 0;
}
Chess::Piece::Piece(Position posit): position(posit)   {}
Chess::Piece::Piece(Chess::Piece &piece): position(piece.position)  {}

//void Chess::Pawn::setCaptureSquares() {
//    //if there is row above
//    if(this->position.y < this->board.dimY){
//        //if there is column to the left
//        if(this->position.x > this->board.dimX){
//            Position pCapt(this->position.x - 1, this->position.y + 1);
//            this->captureSquares.push_back(pCapt);
//        }
//        //if there is column to the right
//        if(this->position.x < this->board.dimX){
//            Position pCapt(this->position.x + 1, this->position.y + 1);
//            this->captureSquares.push_back(pCapt);
//        }
//    }
//    if(this->position.)
//}

Chess::Pawn::Pawn() {
    this->position.x = 0;
    this->position.y = 0;
}
bool Chess::Pawn::isCaptured(Chess::Position square) {
    //delta between figure and square in both axes
    int deltaCol = square.x - this->position.x;
    int deltaRow = square.y - this->position.y;
    //capture only on vertex neighbours
    if(abs(deltaCol) == abs(deltaRow) && abs(deltaCol) == 1)
        return true;
    else
        return false;
}

bool Chess::Rook::isCaptured(Chess::Position square) {
    //if row or column are the same
    if(square.x == this->position.x || square.y == this->position.y)
        return true;
    else
        return false;
}

bool Chess::Bishop::isCaptured(Chess::Position square) {
    int deltaCol = square.x - this->position.x;
    int deltaRow = square.y - this->position.y;
    //if square is on diagonal from bishop
    if(abs(deltaCol) == abs(deltaRow))
        return true;
    else
        return false;
}

bool Chess::Knight::isCaptured(Chess::Position square) {
    int deltaCol = square.x - this->position.x;
    int deltaRow = square.y - this->position.y;

    if((abs(deltaCol) == 1 && abs(deltaRow) == 2) || (abs(deltaCol) == 2 && abs(deltaRow) == 1))
        return true;
    else
        return false;
}

bool Chess::Queen::isCaptured(Chess::Position square) {
    int deltaCol = square.x - this->position.x;
    int deltaRow = square.y - this->position.y;

    if(abs(deltaCol) == abs(deltaRow) || square.x == this->position.x || square.y == this->position.y)
        return true;
    else
        return false;
}

bool Chess::King::isCaptured(Chess::Position square) {
    int deltaCol = square.x - this->position.x;
    int deltaRow = square.y - this->position.y;

    if((abs(deltaCol) == 1 || abs(deltaRow) == 1) && (abs(deltaCol) == abs(deltaRow) || square.x == this->position.x || square.y == this->position.y))
        return true;
    else
        return false;
}

Chess::Board::Board() {
    this->dimX = 0;
    this->dimY = 0;
    this->positions.clear();
}

Chess::Board::Board(int dimX, int dimY) {
    this->dimX = dimX;
    this->dimY = dimY;
    for(int i = 0; i < dimX; i++){
        for(int j = 0; j < dimY; j++){
            Position positAppend(i, j);
            this->positions.push_back(positAppend);
        }
    }
}

Chess::Board::Board(Chess::Board &board) {
    this->dimX = board.dimX;
    this->dimY = board.dimY;
    this->positions = board.positions;
}

bool Chess::Board::setNewPiece(Piece &piece) {
    //iterate through all chessboard square positions
    for(auto positIt = this->positions.begin(); positIt != this->positions.end(); positIt++){
        //try setting piece in square
        piece.position = *positIt;
        //iterate through already set pieces on chessboard and count with how many of them piece doesn't capture each other
        int temp = 0;
        for(auto pieceIt = this->pieces.begin(); pieceIt != this->pieces.end(); pieceIt){
            //if they do not capture each other increment temp
            if(!piece.isCaptured(pieceIt->position) && !(pieceIt->isCaptured(piece.position))){
                temp++;
            }
        }
        //if piece doesn't capture each other with any of already set pieces
        if(temp == this->pieces.size()){
            return true;
        }
    }
    //no place to put new piece
    return false;
}

Chess::Node::Node(Chess::Piece *pieceN, Chess::Board boardN, std::array<int, PIECES_TYPES> piecesConfigN):
piece(*pieceN), board(boardN)
{
    this->piecesConfig = piecesConfigN;
}
void Chess::noCaptureTraverse(Node* node){

    if(node->piecesConfig[0] > 0){
        std::array<int, PIECES_TYPES> tempPiecesConfig = node->piecesConfig;
        tempPiecesConfig[0]--;
        Pawn *newPawn = new Chess::Pawn();

        noCaptureTraverse(node->P);
    }
}
