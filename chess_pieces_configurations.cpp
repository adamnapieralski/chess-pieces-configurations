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

int main(int argc, char *argv[]) {
	
	//number of input arguments needed to run the algorithm
    const int argN = 8;
    std::array<int, argN> inputData = {0, };
    int i = 0;
	//if amount of args is as it should be
    if(argc == argN + 1){
        for(i = 0; i < argN; i++){
            try {
				//try to convert to int
                inputData[i] = std::stoi(argv[i+1]);
				//for board dimensions
                if((i == 0 || i == 1) && inputData[i] < 1){
                    throw std::invalid_argument("Out of range");
                }
            }
            catch(std::invalid_argument){
                std::cout << "Niepoprawne dane wejsciowe\n\n";
                break;
            }

        }
    }
	//if any arguments were put but not the required amount
    else if(argc > 1){
        std::cout << "Niepoprawne dane wejsciowe\n\n";
    }
	//if all were correctly converted to int
    if(i == argN){
        shell::Shell shell(inputData);
        shell.chessConfigSearch();
    }

    //create shell object to handle user commands
    shell:: Shell shell;
    shell.displayWelcomeScreen();
    //constant looped work until decided to exit
    while(shell.exeMenu()){ }

    return 0;
}