#include "main.hpp"

string version = "0.0.2";
string path = "";
string cmd = "";

void command() {
    string arg;
    
    cout << path << "> ";
    getline(cin, cmd);

    if(cmd.size() > 0){
        cmd = clearTabsAndSpaces(cmd);
        arg = getStringCommand(cmd);
        cmd.erase(0, arg.length()+1);

        if(arg == "exit" || arg == "close") {
            exit(0);
        } else if(arg == "color"){
            cmd = clearTabsAndSpaces(cmd);
            arg = getStringCommand(cmd);
            cmd.erase(0, arg.length()+1);   

            color(arg);
        } else if(arg == "clear" || arg == "cls") {  
            clear();
        } else if(arg == "cd") {
            CDCommand(cmd);
        } else if(arg == "help"){
            help();
        } else if(arg == "dir" || arg == "ls" || arg == "list") {
            lsAndDir();
        } else if(arg == "tree") {
            treeWin();
        } else if(arg == "version" || arg == "v"){
            cout << "Version --> "<< version << '\n';
        } else if(arg == "proc") {
            proc();
        } else if(arg == "mkdir"){
            cmd = clearTabsAndSpaces(cmd);
            arg = getStringCommand(cmd);
            cmd.erase(0, arg.length()+1); 
    
            createFolder(arg);
        } else if(arg == "deldir"){
            cmd = clearTabsAndSpaces(cmd);
            arg = getStringCommand(cmd);
            cmd.erase(0, arg.length()+1); 
    
            deleteFolder(arg);
        } else {
            cout<<"Command not found"<<'\n';
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

    cout << "ATFAA Terminal " << version <<  '\n';
    cout << "Copyright (c) ATFAA Corporation. All rights reserved"<<  '\n';
    cout << "Type 'help' to get help." <<  '\n';

    command(); 
    return 0;   
 }