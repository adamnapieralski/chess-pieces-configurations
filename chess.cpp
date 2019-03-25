/*
 * Name: chess.cpp
 * Purpose: Custom library .cpp file for chess pieces and board classes
 * @author Adam Napieralski
 * @version 0.1 25/03/2019
 */

#include "chess.h"

Chess::Board::Board(int dimX, int dimY) {
    this->dimX = dimX;
    this->dimY = dimY;
}

Chess::Board::Board(Chess::Board &board) {
    this->dimX = board.dimX;
    this->dimY = board.dimY;
}

Chess::Position::Position(int x1, int y1) {
    this->x = x1;
    this->y = y1;
}

Chess::Position::Position(Chess::Position &posit) {
    this->x = posit.x;
    this->y = posit.y;
}

Chess::Piece::Piece(Position posit, Board board1): position(posit), board(board1)   {}

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
