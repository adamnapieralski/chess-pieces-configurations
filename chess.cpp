/*
 * Name: chess.cpp
 * Purpose: Custom library .cpp file for chess pieces and board classes
 * @author Adam Napieralski
 * @version 0.1 29/03/2019
 */

#include "chess.h"

chess::Position::Position() {
    this->x = 0;
    this->y = 0;
}
chess::Position::Position(int x1, int y1) {
    this->x = x1;
    this->y = y1;
}

bool chess::operator==(Position p1, Position p2){
    if(p1.x == p2.x && p1.y == p2.y)
        return true;
    else
        return false;
}

//chess::Position::Position(chess::Position &posit) {
//    this->x = posit.x;
//    this->y = posit.y;
//}

chess::Piece::Piece() {
    this->position.x = 0;
    this->position.y = 0;
}

chess::Piece::Piece(Position posit): position(posit)   {}

chess::Piece::Piece(chess::Piece &piece): position(piece.position)  {}

chess::Piece* chess::newPiece(int pieceSym){
    switch(pieceSym){
        case 0:
            return new chess::Pawn();
        case 1:
            return new chess::Rook();
        case 2:
            return new chess::Bishop();
        case 3:
            return new chess::Knight();
        case 4:
            return new chess::Queen();
        case 5:
            return new chess::King();
    }
}

chess::Pawn::Pawn() {
    this->position.x = 0;
    this->position.y = 0;
}

bool chess::Pawn::isCaptured(chess::Position square) {
    //delta between figure and square in both axes
    int deltaCol = square.x - this->position.x;
    int deltaRow = square.y - this->position.y;
    //capture only on vertex neighbours
    if(abs(deltaCol) == abs(deltaRow) && abs(deltaCol) == 1)
        return true;
    else
        return false;
}

char chess::Pawn::getSymbol() const {
    return 'P';
}

bool chess::Rook::isCaptured(chess::Position square) {
    //if row or column are the same
    if(square.x == this->position.x || square.y == this->position.y)
        return true;
    else
        return false;
}

char chess::Rook::getSymbol() const {
    return 'R';
}

bool chess::Bishop::isCaptured(chess::Position square) {
    int deltaCol = square.x - this->position.x;
    int deltaRow = square.y - this->position.y;
    //if square is on diagonal from bishop
    if(abs(deltaCol) == abs(deltaRow))
        return true;
    else
        return false;
}

char chess::Bishop::getSymbol() const {
    return 'B';
}

bool chess::Knight::isCaptured(chess::Position square) {
    int deltaCol = square.x - this->position.x;
    int deltaRow = square.y - this->position.y;

    if((abs(deltaCol) == 1 && abs(deltaRow) == 2) || (abs(deltaCol) == 2 && abs(deltaRow) == 1))
        return true;
    else
        return false;
}

char chess::Knight::getSymbol() const {
    return 'N';
}

bool chess::Queen::isCaptured(chess::Position square) {
    int deltaCol = square.x - this->position.x;
    int deltaRow = square.y - this->position.y;

    if(abs(deltaCol) == abs(deltaRow) || square.x == this->position.x || square.y == this->position.y)
        return true;
    else
        return false;
}

char chess::Queen::getSymbol() const {
    return 'Q';
}
bool chess::King::isCaptured(chess::Position square) {
    int deltaCol = square.x - this->position.x;
    int deltaRow = square.y - this->position.y;

    if((abs(deltaCol) == 1 || abs(deltaRow) == 1) && (abs(deltaCol) == abs(deltaRow) || square.x == this->position.x || square.y == this->position.y))
        return true;
    else
        return false;
}

char chess::King::getSymbol() const {
    return 'K';
}

chess::Board::Board() {
    this->dimX = 0;
    this->dimY = 0;
    this->positions.clear();
}

chess::Board::Board(int dimX, int dimY) {
    this->dimX = dimX;
    this->dimY = dimY;
    //initialize vector of square positions on board
    for(int i = 0; i < dimY; i++){
        for(int j = 0; j < dimX; j++){
            Position positAppend(j, i);
            this->positions.push_back(positAppend);
        }
    }
}

chess::Board::Board(chess::Board &board) {
    this->dimX = board.dimX;
    this->dimY = board.dimY;
    this->positions = board.positions;
    this->pieces = board.pieces;
}

bool chess::Board::setNewPiece(chess::Piece &piece) {
    //iterate through all chessboard square positions
    for(auto positIt = this->positions.begin(); positIt != this->positions.end(); positIt++){
        //try setting piece in square
        piece.position = *positIt;
        //iterate through already set pieces on chessboard and count with how many of them piece doesn't capture each other
        int temp = 0;
        for(auto pieceIt = this->pieces.begin(); pieceIt != this->pieces.end(); pieceIt++){
            //if they capture each other or are on the same squares
            if(piece.isCaptured((*pieceIt)->position) || (*pieceIt)->isCaptured(piece.position) || (*pieceIt)->position == piece.position){
                break;
            }
            temp++;
        }
        //if piece doesn't capture each other with any of already set pieces
        if(temp == this->pieces.size()){
            this->pieces.push_back(&piece);
            return true;
        }
    }
    //no place to put new piece
    return false;
}

std::ostream& chess::operator<<(std::ostream& os, const chess::Board& board) {
    for(int i = 0; i < board.dimY; i++){
        for(int j = 0; j < board.dimX; j++){
            chess::Position *pTemp = new chess::Position(j, i);
            bool isPiece = false;
            for(auto pieceIt = board.pieces.begin(); pieceIt != board.pieces.end(); pieceIt++){
                if(*pTemp == (*pieceIt)->position){
                    os << (*pieceIt)->getSymbol() << " ";
                    isPiece = true;
                    break;
                }
            }
            if(!isPiece){
                os << "_ ";
            }
            delete pTemp;
        }
        os << std::endl;
    }
    return os;
}

chess::Node::Node(chess::Piece *pieceN, chess::Board boardN, std::array<int, PIECES_TYPES> piecesConfigN):
board(boardN)
{
    this->piece = pieceN;
    this->piecesConfig = piecesConfigN;
}

chess::Board* chess::noCaptureTraverse(Node* node, bool printAll){
    std::array<int, 6> zeroConfig = {0, };
    if(node->piecesConfig == zeroConfig){
        std::cout << node->board << std::endl;
        delete node->piece;
        delete node;
        return &node->board;
    }
    chess::Board* resultBoard;
    std::array<int, PIECES_TYPES> newPiecesConfig;
    for(int i = 0; i < PIECES_TYPES; ++i){
        if(node->piecesConfig[i] > 0){
            newPiecesConfig = node->piecesConfig;
            --newPiecesConfig[i];
            auto newPiece = chess::newPiece(i);
            auto newBoard = node->board;
            if(!newBoard.setNewPiece(*newPiece)){
                delete newPiece;
                delete node->piece;
                delete node;
                return nullptr;
            }
            auto newNode = new Node(newPiece, newBoard, newPiecesConfig);
            node->piecesNodes[i] = newNode;
            resultBoard = noCaptureTraverse(node->piecesNodes[i], printAll);
            if(resultBoard){
                if(!printAll){
                    delete newPiece;
                    delete node->piece;
                    delete node;
                    return resultBoard;
                }
            }
        }
    }
    delete node->piece;
    delete node;
}