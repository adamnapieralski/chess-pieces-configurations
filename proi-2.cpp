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

using namespace std;
//using namespace Chess;

int main() {
    Chess::Board board(6, 6);
    array<int, PIECES_TYPES> pConfig = {3, 1, 3, 1, 1, 1};
    Chess::Node* root = new Chess::Node(nullptr, board, pConfig);
    auto resultBoard = noCaptureTraverse(root);
    if(resultBoard){
        cout << "Przykladowa szachownica o podanej konfiguracji figur:" << endl << endl;
        cout << *resultBoard << endl;
    }
    else{
        cout << "Brak mozliwosci ustawienia podanej konfiguracji figur na danej szachownicy." << endl;
    }

    return 0;
}