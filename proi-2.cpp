/*
 * Name: proi_2.cpp
 * Purpose: PROI 2. project
 * @author Adam Napieralski
 * @version 0.1 25/03/2019
 */

#include <iostream>
#include <algorithm>
#include <array>
#include <typeinfo>
#include "chess.h"
#include "shell.h"
using namespace std;
//using namespace chess;

int main() {
    chess::Board board(1, 1);
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

    return 0;
}