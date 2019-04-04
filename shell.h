/*
 * Name: shell.h
 * Purpose: Custom library header file with class for chess pieces and board classes
 * @author Adam Napieralski
 * @version 0.3 2/04/2019
 */
#ifndef SHELL_H
#define SHELL_H

#define ARG_NUM 8
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
        Shell(std::array<int, ARG_NUM> inputData);
        ~Shell();

        void setInputBoard();
        void setPiecesConfig();
        void setPrintAll();
        void displayWelcomeScreen();
        void displayMainMenu();
        void displaySettings();
        void displayDescription();
        void chessConfigSearch();
        bool exeMenu();
        int getChoice();
    };
}

#endif //SHELL_H
