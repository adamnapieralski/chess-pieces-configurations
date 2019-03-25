/*
 * Name: chess.h
 * Purpose: Custom library .h file for chess pieces and board classes
 * @author Adam Napieralski
 * @version 0.1 25/03/2019
 */

#ifndef CHESS_H
#define CHESS_H

#include <vector>
#include <math.h>

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
        // virtual void setCaptureSquares() = 0;
        virtual bool isCaptured(Position square);
    };

    class Pawn: public Piece{
    public:
        bool isCaptured(Position square) override;
        // void setCaptureSquares() override;
    };

    class Rook: public Piece{
    public:
        bool isCaptured(Position square) override;
    };

    class Bishop: public Piece{
    public:
        bool isCaptured(Position square) override;
    };

    class Knight: public Piece{
    public:
        bool isCaptured(Position square) override;
    };

    class Queen: public Piece{
    public:
        bool isCaptured(Position square) override;
    };

    class King: public Piece{
    public:
        bool isCaptured(Position square) override;
    };
}

#endif //CHESS_H
