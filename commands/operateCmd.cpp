#include "../main.hpp"

extern sf::Text activeText;
extern sf::Text wrireText;
extern string countingEnter;
extern string activeTextS;
extern string wrireTextS;
extern sf::RectangleShape rect;
extern string version;
extern string path;

bool OperateCmd::runCommand(string cmd){
    MainFunc mainFunc;
    BasicFunc basicFunc;
    CDcom cd;
    FilesOperation filesOperationFunc;
    Colors colorFunc;
    MainWindow window;

    string arg, arg2, arg3;

    if(cmd.size() > 0){

        cmd = mainFunc.clearTabsAndSpaces(cmd);
        arg = mainFunc.getStringCommand(cmd);
        cmd.erase(0, arg.length()+1);

        if(arg == "exit" || arg == "close") {
            exit(0);
        } else if(arg == "fcolor"){
            cmd = mainFunc.clearTabsAndSpaces(cmd);
            arg = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg.length()+1);   
            arg2 = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg2.length()+1); 
            arg3 = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg2.length()+1); 

            colorFunc.Fcolor(arg, arg2, arg3);
        } else if(arg == "bcolor"){
            cmd = mainFunc.clearTabsAndSpaces(cmd);
            arg = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg.length()+1); 
            arg2 = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg2.length()+1); 
            arg3 = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg2.length()+1);   

            colorFunc.Bcolor(arg, arg2, arg3);
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
            return false;
        }
    } else {
        return false;
    }
    return true;
}
