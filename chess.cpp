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

void Chess::Pawn::setCaptureSquares() {
    //if there is row above
    if(this->position.y < this->board.dimY){
        //if there is column to the left
        if(this->position.x > this->board.dimX){
            Position pCapt(this->position.x - 1, this->position.y + 1);
            this->captureSquares.push_back(pCapt);
        }
        //if there is column to the right
        if(this->position.x < this->board.dimX){
            Position pCapt(this->position.x + 1, this->position.y + 1);
            this->captureSquares.push_back(pCapt);
        }
    }
}
