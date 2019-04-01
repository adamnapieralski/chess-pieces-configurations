/*
 * Name: shell.h
 * Purpose: Custom library header file with class for chess pieces and board classes
 * @author Adam Napieralski
 * @version 0.2 29/03/2019
 */
//#ifndef SHELL_H
//#define SHELL_H

#include <iostream>
#include <array>
#include <vector>
#include "chess.h"

namespace shell{
    class Shell{
    public:
        chess::Board* inputBoard;
        std::array<int, PIECES_TYPES> piecesConfig;
        std::array<std::string, PIECES_TYPES> piecesNames = {"Pionek", "Wieza", "Goniec", "Kon", "Hetman", "Krol"};
        bool printAll;
        Shell();
        ~Shell();
        void setInputBoard();
        void setPiecesConfig();
        void setPrintAll();
        void displayWelcomeScreen();
        void displayMainMenu();
        void displaySettings();
        void displayDescription();
        void chessConfigSearch(chess::Node* rootNode);
        bool exeMenu();
        int getChoice();
    };
}

//#endif //SHELL_H
