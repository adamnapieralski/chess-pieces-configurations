/*
 * Name: chess.h
 * Purpose: Custom library .h file for chess pieces and board classes
 * @author Adam Napieralski
 * @version 0.1 25/03/2019
 */

#ifndef CHESS_H
#define CHESS_H

#include <vector>

namespace Chess{

    class Board{
    public:
        int dimX;
        int dimY;

        Board(int dimX, int dimY);
        Board(Board &board);
    };

    class Position{
    public:
        int x;
        int y;

        Position(int x1, int y1);
        Position(Position &posit);
    };

    class Piece{
    public:
        Board board;
        Position position;
        std::vector<Position> captureSquares;

        Piece(Position posit, Board board1);
        virtual void setCaptureSquares() = 0;
        bool isCaptured(Position square);
    };

    class Pawn: public Piece{
    public:
        void setCaptureSquares() override;
    };

    class Rook: public Piece{

    };

    class Bishop: public Piece{

    };

    class Knight: public Piece{

    };

    class Queen: public Piece{

    };

    class King: public Piece{

    };
}

#endif //CHESS_H
