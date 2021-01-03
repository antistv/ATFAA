#include "../main.hpp"

extern string path;

void proc() {
    #ifdef WIN32
        system("proc > system-proc.txt");
    #else
        system("ps -U root -u root -N > system-proc.txt");
    #endif

    string line;
    fstream plik;
    plik.open("system-proc.txt", ios::in);
    if(plik.good() == true){
        while(!plik.eof()) {
            getline(plik, line);
            printw("%s\n", line.c_str());
        }
    }
    plik.close();
}

void lsAndDir() {
    #ifdef WIN32
        system(("dir " + path + "> system-proc.txt").c_str());
    #else
        system(("ls " + path + "> system-proc.txt").c_str());
    #endif

    string line;
    fstream plik;
    plik.open("system-proc.txt", ios::in);
    if(plik.good() == true){
        while(!plik.eof()) {
            getline(plik, line);
            printw("%s ", line.c_str());
        }
    }
    plik.close();
}


void clearTerminal(){
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void treeWin(){
    #ifdef WIN32
        system(("tree " + path + "> system-proc.txt").c_str());
    #else
        printw("feature not available on linux\n");
    #endif
}

void help(){
    string line;
    fstream plik;

    plik.open("help.txt", ios::in);
    if(plik.good() == true){
        while(!plik.eof()) {
            getline(plik, line);
            printw("%s\n", line.c_str());
        }
        plik.close();
    }
}