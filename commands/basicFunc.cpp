#include "commands-Set.hpp"

extern string path;

void BasicFunc :: proc() {
    #ifdef WIN32
        system("proc");
    #else
        system("ps -U root -u root -N");
    #endif
}

void BasicFunc :: help() {
    ifstream f("help.txt");
    if (f.is_open())
        cout << f.rdbuf();
    f.close();
    cout << '\n';
}

void BasicFunc :: lsAndDir() {
    #ifdef WIN32
        system(("dir " + path).c_str());
    #else
        system(("ls " + path).c_str());
    #endif
}

void BasicFunc :: clear() {
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void BasicFunc :: treeWin() {
    #ifdef WIN32
        system(("tree " + path).c_str());
    #else
        cout<<"feature not available on linux"<<'\n';
    #endif
}

void BasicFunc :: terminal() {
    #ifdef WIN32
        system(".\\ATFAA");
    #else
        system("./ATFAA");
    #endif
}