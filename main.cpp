#include "main.hpp"

string version = "0.0.2";
string path = "";
string cmd = "";

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

    MainFunc mainFunc;
    BasicFunc basicFunc;
    CDcom cd;
    FilesOperation filesOperationFunc;
    Colors colorFunc;

    string arg, arg2;

    while (true) {
        cout << path << "> ";
        getline(cin, cmd);
        if(cmd.size() > 0){

            cmd = mainFunc.clearTabsAndSpaces(cmd);
            arg = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg.length()+1);

            if(arg == "exit" || arg == "close") {
                exit(0);
            } else if(arg == "color"){
                cmd = mainFunc.clearTabsAndSpaces(cmd);
                arg = mainFunc.getStringCommand(cmd);
                cmd.erase(0, arg.length()+1);   

                colorFunc.color(arg);
            } else if(arg == "clear" || arg == "cls") {  
                basicFunc.clear();
            } else if(arg == "cd") {
                cd.CDCommand(cmd);
            } else if(arg == "help"){
                basicFunc.help();
            } else if(arg == "dir" || arg == "ls" || arg == "list") {
                basicFunc.lsAndDir();
            } else if(arg == "tree") {
                basicFunc.treeWin();
            } else if(arg == "version" || arg == "v"){
                cout << "Version --> "<< version << '\n';
            } else if(arg == "proc") {
                basicFunc.proc();
            } else if(arg == "mkdir"){
                cmd = mainFunc.clearTabsAndSpaces(cmd);
                arg = mainFunc.getStringCommand(cmd);
                cmd.erase(0, arg.length()+1); 
            
                filesOperationFunc.createFolder(arg);
            } else if(arg == "deldir"){
                cmd = mainFunc.clearTabsAndSpaces(cmd);
                arg = mainFunc.getStringCommand(cmd);
                cmd.erase(0, arg.length()+1); 
            
                filesOperationFunc.deleteFolder(arg);
            } else if(arg == "rndir"){
                cmd = mainFunc.clearTabsAndSpaces(cmd);
                arg = mainFunc.getStringCommand(cmd);
                cmd.erase(0, arg.length()+1); 
                arg2 = mainFunc.getStringCommand(cmd);
                cmd.erase(0, arg2.length()+1); 

                filesOperationFunc.renameDir(arg, arg2);
            } else if(arg == "mkfile"){
                cmd = mainFunc.clearTabsAndSpaces(cmd);
                arg = mainFunc.getStringCommand(cmd);
                cmd.erase(0, arg.length()+1); 
            
                filesOperationFunc.createFile(arg);
            } else if(arg == "delfile"){
                cmd = mainFunc.clearTabsAndSpaces(cmd);
                arg = mainFunc.getStringCommand(cmd);
                cmd.erase(0, arg.length()+1); 
            
                filesOperationFunc.deleteFile(arg);
            } else if(arg == "rnfile"){
                cmd = mainFunc.clearTabsAndSpaces(cmd);
                arg = mainFunc.getStringCommand(cmd);
                cmd.erase(0, arg.length()+1); 
                arg2 = mainFunc.getStringCommand(cmd);
                cmd.erase(0, arg2.length()+1); 

                filesOperationFunc.renameFile(arg, arg2);
            } else if(arg == "cmd" || arg == "terminal" || arg == "console") {
                basicFunc.terminal();
            } else {
                cout<<"Command not found"<<'\n';
            }
        }
    }

    return 0;   
 }