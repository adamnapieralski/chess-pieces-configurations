/*
 * Name: chess.h
 * Purpose: Custom library .h file for chess pieces and board classes
 * @author Adam Napieralski
 * @version 0.1 25/03/2019
 */

#ifndef CHESS_H
#define CHESS_H

#include <vector>


class Position{
public:
    int x;
    int y;
};

class ChessPiece{
public:
    Position position;
    std::vector<Position> captureSquares;

    virtual void capture() = 0;
};

#endif //CHESS_H
