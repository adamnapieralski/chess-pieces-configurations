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

class Node{
public:
    Node* parent;
    Node* A;
    Node* B;
    Node* C;
    char symbol;
    array<int, 3> board;
    array<int, 3> set;
};

void preorder(Node* node){

    if(node->symbol == 'A'){
        node->board[0]++;
    }
    if(node->symbol == 'B'){
        node->board[1]++;
    }
    if(node->symbol == 'C'){
        node->board[2]++;
    }
    if(node->set[0] > 0){
        array<int, 3> setTemp = node->set;
        setTemp[0]--;
        Node* newNode = new Node;
        newNode->parent = node;
        newNode->symbol = 'A';
        cout << 'A' << "\t" << node->board[0] << node->board[1] << node->board[2] << endl;
        newNode->set = setTemp;
        newNode->board = node->board;
        node->A = newNode;
        preorder(node->A);
    }
    if(node->set[1] > 0){
        array<int, 3> setTemp = node->set;
        setTemp[1]--;
        Node* newNode = new Node;
        newNode->parent = node;
        newNode->symbol = 'B';
        cout << 'B' << "\t" << node->board[0] << node->board[1] << node->board[2] << endl;
        newNode->set = setTemp;
        newNode->board = node->board;
        node->B = newNode;
        preorder(node->B);
    }
    if(node->set[2] > 0){
        array<int, 3> setTemp = node->set;
        setTemp[2]--;
        Node* newNode = new Node;
        newNode->parent = node;
        newNode->symbol = 'C';
        cout << 'C' << "\t" << node->board[0] << node->board[1] << node->board[2] << endl;
        newNode->set = setTemp;
        newNode->board = node->board;
        node->C = newNode;
        preorder(node->C);
    }
    cout << "Delete" << endl;
    delete node;
}

bool f(Chess::Piece *P){
    cout << P->position.x << endl;
}

int main() {
    //Board board(8, 8);

    char figures[] = {'P', 'P', 'R'};

    Node* root = new Node;
    root->set = {2, 1, 1};
    root->board = {0,};
    preorder(root);

    Chess::Piece *p = new Chess::Pawn();
    f(p);
//    cout << piece->position.x << endl;

    return 0;
}