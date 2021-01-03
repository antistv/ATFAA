#include "main.hpp"


string path = "";
string version = "0.0.2";
string cmd = "";

void command() {
    string arg;
    
    printw("%s> ", path.c_str());

//Wczytywanie cmd
    nocbreak();
    echo();
    int ch = getch();
    while ( ch != '\n' ) {
        cmd.push_back( ch );
        ch = getch();
    }

//Wyszukiwanie komend
    if(cmd.size() > 0){
        cmd = clearTabsAndSpaces(cmd);
        arg = getStringCommand(cmd);
        cmd.erase(0, arg.length()+1);

        if(arg == "exit" || arg == "close") {
            endwin();
            exit(0);
        } else if(arg == "color"){
            cmd = clearTabsAndSpaces(cmd);
            arg = getStringCommand(cmd);
            cmd.erase(0, arg.length()+1);   

            color(arg);
        } else if(arg == "clear" || arg == "cls") {  
            clearTerminal();
        } else if(arg == "cd") {
            CDCommand(cmd);
        } else if(arg == "help"){
            help();
        } else if(arg == "dir" || arg == "ls" || arg == "list") {
            lsAndDir();
        } else if(arg == "tree") {
            treeWin();
        } else if(arg == "version" || arg == "v"){
            printw("Version --> %s \n", version.c_str());
        } else if(arg == "proc") {
            proc();
        } else {
            printw("Command not found\n");
        }

    }
    
    command();
}

////////////////////////////////////////////////////////////////////////////////////////////////
//WYWOŁANIE/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

int main() { 

    setlocale( LC_ALL, "pl_PL" );

    #ifdef WIN32
        system(("title ATFAA Terminal " + version).c_str());
        string drive, home;
        drive = getenv("systemdrive");
        home = getenv("homepath");
        path = drive+home;
    #else
        char esc_start[] = { 0x1b, ']', '0', ';', 0 };
        char esc_end[] = { 0x07, 0 };
        cout << esc_start << "ATFAA Terminal" << version << esc_end;
        path = getenv("HOME");
    #endif

    initscr();

    use_default_colors();
    start_color(); 

    printw("ATFAA Terminal %s \n", version.c_str());
    printw("Copyright (c) ATFAA Corporation. All rights reserved\n");
    printw("Type 'help' to get help.\n");
    refresh();
    beep();

    command();
    endwin();
    return 0;   
 }
