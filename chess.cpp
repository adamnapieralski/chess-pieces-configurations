/*
 * Name: chess.cpp
 * Purpose: Custom library .cpp file for chess pieces and board classes
 * @author Adam Napieralski
 * @version 0.1 29/03/2019
 */

#include "chess.h"

namespace chess{
    Position::Position() {
        this->x = 0;
        this->y = 0;
    }
    Position::Position(int x1, int y1) {
        this->x = x1;
        this->y = y1;
    }
    bool operator==(Position p1, Position p2){
        if(p1.x == p2.x && p1.y == p2.y)
            return true;
        else
            return false;
    }

    Piece::Piece() {
        this->position.x = 0;
        this->position.y = 0;
    }

    Piece::Piece(Position posit): position(posit)   {}

    Piece::Piece(Piece &piece): position(piece.position)  {}

    Piece* newPiece(int pieceSym){
        switch(pieceSym){
            case 0:
                return new Pawn();
            case 1:
                return new Rook();
            case 2:
                return new Bishop();
            case 3:
                return new Knight();
            case 4:
                return new Queen();
            case 5:
                return new King();
        }
    }

    Pawn::Pawn() {
        this->position.x = 0;
        this->position.y = 0;
    }

    bool Pawn::isCaptured(Position square) {
        //delta between figure and square in both axes
        int deltaCol = square.x - this->position.x;
        int deltaRow = square.y - this->position.y;
        //capture only on vertex neighbours
        if(abs(deltaCol) == abs(deltaRow) && abs(deltaCol) == 1)
            return true;
        else
            return false;
    }

    char Pawn::getSymbol() const {
        return 'P';
    }

    bool Rook::isCaptured(Position square) {
        //if row or column are the same
        if(square.x == this->position.x || square.y == this->position.y)
            return true;
        else
            return false;
    }

    char Rook::getSymbol() const {
        return 'R';
    }

    bool Bishop::isCaptured(Position square) {
        int deltaCol = square.x - this->position.x;
        int deltaRow = square.y - this->position.y;
        //if square is on diagonal from bishop
        if(abs(deltaCol) == abs(deltaRow))
            return true;
        else
            return false;
    }

    char Bishop::getSymbol() const {
        return 'B';
    }

    bool Knight::isCaptured(Position square) {
        int deltaCol = square.x - this->position.x;
        int deltaRow = square.y - this->position.y;

        if((abs(deltaCol) == 1 && abs(deltaRow) == 2) || (abs(deltaCol) == 2 && abs(deltaRow) == 1))
            return true;
        else
            return false;
    }

    char Knight::getSymbol() const {
        return 'N';
    }

    bool Queen::isCaptured(Position square) {
        int deltaCol = square.x - this->position.x;
        int deltaRow = square.y - this->position.y;

        if(abs(deltaCol) == abs(deltaRow) || square.x == this->position.x || square.y == this->position.y)
            return true;
        else
            return false;
    }

    char Queen::getSymbol() const {
        return 'Q';
    }
    bool King::isCaptured(Position square) {
        int deltaCol = square.x - this->position.x;
        int deltaRow = square.y - this->position.y;

        if((abs(deltaCol) == 1 || abs(deltaRow) == 1) && (abs(deltaCol) == abs(deltaRow) || square.x == this->position.x || square.y == this->position.y))
            return true;
        else
            return false;
    }

    char King::getSymbol() const {
        return 'K';
    }

    Board::Board() {
        this->dimX = 0;
        this->dimY = 0;
        this->positions.clear();
    }

    Board::~Board() {
        this->pieces.clear();
        this->positions.clear();
    }

    Board::Board(int dimX, int dimY) {
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

    Board::Board(Board &board) {
        this->dimX = board.dimX;
        this->dimY = board.dimY;
        this->positions = board.positions;
        this->pieces = board.pieces;
    }

    bool Board::setNewPiece(Piece *piece) {
        //iterate through all chessboard square positions
        for(auto positIt = this->positions.begin(); positIt != this->positions.end(); positIt++){
            //try setting piece in square
            piece->position = *positIt;
            //iterate through already set pieces on chessboard and count with how many of them piece doesn't capture each other
            int temp = 0;
            for(auto pieceIt = this->pieces.begin(); pieceIt != this->pieces.end(); pieceIt++){
                //if they capture each other or are on the same squares
                if(piece->isCaptured((*pieceIt)->position) || (*pieceIt)->isCaptured(piece->position) || (*pieceIt)->position == piece->position){
                    break;
                }
                temp++;
            }
            //if piece doesn't capture each other with any of already set pieces
            if(temp == this->pieces.size()){
                this->pieces.push_back(piece);
                return true;
            }
        }
        //no place to put new piece
        return false;
    }

    std::ostream& operator<<(std::ostream& os, const chess::Board& board) {
        for(int i = 0; i < board.dimY; i++){
            for(int j = 0; j < board.dimX; j++){
                Position *pTemp = new Position(j, i);
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

    Board& Board::operator=(const Board& newBoard){
      if(this != &newBoard){
          this->pieces = newBoard.pieces;
          this->dimX = newBoard.dimX;
          this->dimY = newBoard.dimY;
          this->positions = newBoard.positions;
      }
        return *this;
    }

    Node::Node(chess::Piece *pieceN, chess::Board *boardN, std::array<int, PIECES_TYPES> piecesConfigN)
    {
        auto nodeBoard = new Board(*boardN);
        this->board = nodeBoard;
        this->piece = pieceN;
        this->piecesConfig = piecesConfigN;
        std::fill(this->piecesNodes.begin(), this->piecesNodes.end(), nullptr);
    }

    Node::~Node(){
        delete this->piece;
        delete this->board;
    }

    void noCaptureTraverse(Node* node, bool &foundConfig, bool printAll){
        //create array zero config values to compare
        std::array<int, 6> zeroConfig = {0, };
        //if all pieces were already placed
        if(node->piecesConfig == zeroConfig){
            //if program should find and print only one configuration
            if(!printAll){
                std::cout << "Przykladowa konfiguracja ustawien figur:\n";
            }
            std::cout << *node->board << std::endl;
            foundConfig = true;
            delete node;
            return;
        }
        std::array<int, PIECES_TYPES> newPiecesConfig = {0, };
        //for every piece type
        for(int i = 0; i < PIECES_TYPES; ++i){
            //check if it should be placed
            if(node->piecesConfig[i] > 0){
                newPiecesConfig = node->piecesConfig;
                --newPiecesConfig[i];
                //create new objects for child node
                auto nPiece = newPiece(i);
                auto newBoard = *node->board;
                //try and if it's not possible to place a new piece on board
                if(!newBoard.setNewPiece(nPiece)){
                    delete nPiece;
                    delete node;
                    return;
                }
                //create new node
                auto newNode = new Node(nPiece, &newBoard, newPiecesConfig);
                //make it child of current node
                node->piecesNodes[i] = newNode;
                //execute the same algorithm for child node
                noCaptureTraverse(node->piecesNodes[i], foundConfig, printAll);
                //if for children nodes solution wasnt found and we dont want to check any more
                if(!printAll && foundConfig){
                    delete node;
                    return;
                }
            }
        }
        //if we wanted to print all after checking all children nodes
        if(printAll){
            delete node;
        }
    }
}

