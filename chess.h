/*
 * Name: chess.h
 * Purpose: Custom library .h file for chess pieces and board classes
 * @author Adam Napieralski
 * @version 0.2 29/03/2019
 */

#ifndef CHESS_H
#define CHESS_H

#include <iostream>
#include <vector>
#include <array>
#include <math.h>

#define PIECES_TYPES 6

namespace chess{

    class Position{
    public:
        int x;
        int y;

        Position();
        Position(int x1, int y1);

        friend bool operator==(Position p1, Position p2);
        // Position(Position &posit);
    };

    class Piece{
    public:
        Position position;

        Piece();
        Piece(Position posit);
        Piece(Piece &piece);
        // virtual void setCaptureSquares() = 0;
        virtual bool isCaptured(Position square) = 0;
        virtual char getSymbol() const = 0;

        friend Piece* newPiece(int pieceSym);
    };

    class Pawn: public Piece{
    public:
        Pawn();
        // Pawn(Position positP);
        bool isCaptured(Position square) override;
        char getSymbol() const override;
        // void setCaptureSquares() override;
    };

    class Rook: public Piece{
    public:
        bool isCaptured(Position square) override;
        char getSymbol() const override;
    };

    class Bishop: public Piece{
    public:
        bool isCaptured(Position square) override;
        char getSymbol() const override;
    };

    class Knight: public Piece{
    public:
        bool isCaptured(Position square) override;
        char getSymbol() const override;
    };

    class Queen: public Piece{
    public:
        bool isCaptured(Position square) override;
        char getSymbol() const override;
    };

    class King: public Piece{
    public:
        bool isCaptured(Position square) override;
        char getSymbol() const override;
    };

    class Board{
    public:
        int dimX;
        int dimY;
        std::vector<chess::Position> positions;
        std::vector<chess::Piece*> pieces;
        Board();
        ~Board();
        Board(int dimX, int dimY);
        Board(Board &board);

        bool setNewPiece(Piece *piece);
        friend std::ostream& operator<<(std::ostream& os, const chess::Board& board);
        Board& operator=(const Board& newBoard);
    };

    class Node{
    public:
        Piece *piece;
        Board *board;
        //array with remaining number of occurences for each piece
        std::array<int, PIECES_TYPES> piecesConfig;

        //array of pointers to children nodes
        std::array<chess::Node*, PIECES_TYPES> piecesNodes;

        Node(Piece *pieceN, Board *boardN, std::array<int, PIECES_TYPES> piecesConfigN);
        ~Node();
        friend void noCaptureTraverse(Node* node, bool &foundConfig, bool printAll);
    };
}

#endif //CHESS_H
