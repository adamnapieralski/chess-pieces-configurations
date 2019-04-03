/*
 * Name: chess_pieces_configurations.cpp
 * Purpose: PROI 2. project
 * @author Adam Napieralski
 * @version 0.3 2/04/2019
 */

#include <iostream>
#include <array>
#include "chess.h"
#include "shell.h"

int main() {
    //create shell object to handle user commands
    shell:: Shell shell;
    shell.displayWelcomeScreen();
    //constant looped work until decided to exit
    while(shell.exeMenu()){ }

    return 0;
}