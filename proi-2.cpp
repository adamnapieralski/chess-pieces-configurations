/*
 * Name: proi_2.cpp
 * Purpose: PROI 2. project
 * @author Adam Napieralski
 * @version 0.1 25/03/2019
 */

#include <iostream>
#include <array>
#include "chess.h"
#include "shell.h"
using namespace std;
//using namespace chess;

int main() {
    chess::Board board(1, 1);
    chess::Position p1(2, 2);
    chess::Position p2(3, 3);
    if(p1 == p2)
        cout << "cos";
    array<int, PIECES_TYPES> pConfig = {1, 0, 0,};
    chess::Node* root = new chess::Node(nullptr, board, pConfig);
    auto resultBoard = noCaptureTraverse(root, true);
    if(resultBoard){
        cout << "Przykladowa szachownica o podanej konfiguracji figur:" << endl << endl;
        //cout << *resultBoard << endl;
    }
    else{
        cout << "Brak mozliwosci ustawienia podanej konfiguracji figur na danej szachownicy." << endl;
    }

    shell:: Shell shell;
    while(shell.exeMenu()){ }

    return 0;
}