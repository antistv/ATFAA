#include "../main.hpp"

extern string path;

void proc() {
    #ifdef WIN32
        system("proc");
    #else
        system("ps -U root -u root -N");
    #endif
}

void help() {
    ifstream f("help.txt");
    if (f.is_open())
        cout << f.rdbuf();
    f.close();
    cout << '\n';
}

void lsAndDir() {
    #ifdef WIN32
        system(("dir " + path).c_str());
    #else
        system(("ls " + path).c_str());
    #endif
}

void clear() {
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void treeWin() {
    #ifdef WIN32
        system(("tree " + path).c_str());
    #else
        cout<<"feature not available on linux"<<'\n';
    #endif
}

void terminal() {
    #ifdef WIN32
        system(".\\ATFAA");
    #else
        system("./ATFAA";
    #endif
}