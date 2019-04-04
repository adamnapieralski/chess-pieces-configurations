/*
 * Name: shell.cpp
 * Purpose: Custom library .cpp file with class for chess pieces and board classes
 * @author Adam Napieralski
 * @version 0.3 2/04/2019
 */

#include "shell.h"

using namespace chess;

namespace shell{

    Shell::Shell(){
        this->piecesConfig = {0, };
        this->printAll = false;
        this->inputBoard = new Board();
    }

    Shell::Shell(std::array<int, ARG_NUM> inputData){
        auto shellBoard = new Board(inputData[0], inputData[1]);
        this->inputBoard = shellBoard;
        this->piecesConfig = {inputData[2], inputData[3], inputData[4], inputData[5], inputData[6], inputData[7]};
        this->printAll = false;
    }

    Shell::~Shell() {
        delete this->inputBoard;
    }

    void Shell::setInputBoard() {
        std::cout << "Podaj wymiary szachownicy (w ilosci pol):" << std::endl;
        int dimX=-1, dimY=-1;
        while ((std::cout << "\tw poziomie " && !(std::cin >> dimX)) || dimX < 1 || std::cin.peek() != '\n')
        {
            std::cout << "Niepoprawne dane. Wprowadz ponownie." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT8_MAX, '\n');
        }
        while ((std::cout << "\tw pionie " && !(std::cin >> dimY)) || dimY < 1 || std::cin.peek() != '\n')
        {
            std::cout << "Niepoprawne dane. Wprowadz ponownie." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT8_MAX, '\n');
        }
        delete this->inputBoard;
        auto inBoard = new Board(dimX, dimY);
        this->inputBoard = inBoard;
        std::cout << *this->inputBoard << '\n';
    }

    void Shell::setPiecesConfig() {
        std::cout << "Podaj ilosc figur" << std::endl;
        for(int i = 0; i < PIECES_TYPES; ++i){
            while ((std::cout << "\t" << this->piecesNames[i] << " "  && !(std::cin >> this->piecesConfig[i]) && this->piecesConfig[i] < 0) || std::cin.peek() != '\n')
            {
                std::cout << "Niepoprawne dane. Wprowadz ponownie." << std::endl;
                std::cin.clear();
                std::cin.ignore(INT8_MAX, '\n');
            }
        }
    }

    void Shell::setPrintAll() {
        std::cout << "Wyswietlac wszystkie znalezione konfiguracje?" << std::endl;
        std::cout << "\t0 - Nie, wyswietl tylko jedna przykladowa\n\t1 - Tak, wyswietl wszystkie znalezione" << std::endl;
        int temp;
        while ((!(std::cin >> temp) || (temp != 0 && temp != 1)) || std::cin.peek() != '\n')
        {
            std::cout << "Niepoprawne dane. Wprowadz ponownie." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT8_MAX, '\n');
        }
        this->printAll = temp;
    }

    int Shell::getChoice(){
        int choice;
        while (!(std::cin >> choice) || std::cin.peek() != '\n')
        {
            std::cout << "Niepoprawne dane. Wprowadz ponownie." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT8_MAX, '\n');
        }
        return choice;
    }

    void Shell::displayWelcomeScreen() {
        std::cout << "Witaj!\n\n";
        std::cout << "Program pozwala zbadac mozliwosc ustawienia dowolnego zbioru figur szachowych ";
        std::cout << "na szachownicy o dowolnej wielkosci tak, aby zadna z figur nie \"bila\" innej.\n\n";
    }
    void Shell::displayMainMenu() {
        std::cout << "\nMENU\n\n";
        std::cout << "\t0 - realizuj algorytm\n";
        std::cout << "\t1 - okresl wielkosc szachownicy\n";
        std::cout << "\t2 - okresl ilosc figur\n";
        std::cout << "\t3 - okresl sposob wyswietlania\n";
        std::cout << "\t4 - wyswietl aktualne ustawienia\n";
        std::cout << "\t5 - wyswietl opisy oznaczen\n";
        std::cout << "\t6 - wyjscie\n" << std::endl;
    }

    void Shell::displaySettings() {
        std::cout << "Wielkosc szachownicy:\n";
        std::cout << "\tw poziomie:\t" << this->inputBoard->dimX << std::endl;
        std::cout << "\tw pionie:\t" << this->inputBoard->dimY << std::endl << std::endl;
        std::cout << "Figury:\n";
        for(int i = 0; i < PIECES_TYPES; ++i){
            std::cout << "\t" << this->piecesNames[i] << ":\t" << this->piecesConfig[i] << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Wyswietlanie wszystkich konfiguracji:\t" << this->printAll << std::endl;
    }

    void Shell::displayDescription() {
        std::cout << "\tP - Pawn - Pion\n";
        std::cout << "\tR - Rook - Wieza\n";
        std::cout << "\tB - Bishop - Goniec\n";
        std::cout << "\tN - Knight - Kon\n";
        std::cout << "\tQ - Queen - Hetman\n";
        std::cout << "\tK - King - Krol\n" << std::endl;
    }

    void Shell::chessConfigSearch(){
        auto rootNode = new Node(nullptr, this->inputBoard, this->piecesConfig, 0);
        bool foundConfig = false;
        noCaptureTraverse(rootNode, foundConfig, this->printAll);
        if(!foundConfig){
            std::cout << "Brak mozliwych konfiguracji\n";
        }
    }

    bool Shell::exeMenu() {
        this->displayMainMenu();
        switch(this->getChoice()){
            case 0:{
                chessConfigSearch();
                return true;
            }
            case 1:
                this->setInputBoard();
                return true;
            case 2:
                this->setPiecesConfig();
                return true;
            case 3:
                this->setPrintAll();
                return true;
            case 4:
                this->displaySettings();
                return true;
            case 5:
                this->displayDescription();
                return true;
            case 6:
                std::cout << "\nWYJSCIE\n";
                return false;
            default:
                std::cout << "Niepoprawne polecenie. Sprobuj ponownie.\n\n";
                return true;
        }
    }
}