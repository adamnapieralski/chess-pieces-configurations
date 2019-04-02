/*
 * Name: chess_pieces_configurations.cpp
 * Purpose: PROI 2. project
 * @author Adam Napieralski
 * @version 0.1 25/03/2019
 */

#include <iostream>
#include <array>
#include "chess.h"
#include "shell.h"

int main() {
    shell:: Shell shell;
    shell.displayWelcomeScreen();
    while(shell.exeMenu()){ }

    return 0;
}