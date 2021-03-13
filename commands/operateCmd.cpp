#include "../main.hpp"

bool OperateCmd::runCommand(string cmd, sf::Text &activeText,sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS, sf::RectangleShape &rect, string &version, string &path, sf::Color &background_color){
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

            colorFunc.Fcolor(arg, arg2, arg3, activeText, wrireText, countingEnter, activeTextS, wrireTextS, rect, path);
        } else if(arg == "bcolor"){
            cmd = mainFunc.clearTabsAndSpaces(cmd);
            arg = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg.length()+1); 
            arg2 = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg2.length()+1); 
            arg3 = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg2.length()+1);   

            colorFunc.Bcolor(arg, arg2, arg3, activeText, wrireText, countingEnter, activeTextS, wrireTextS, path, background_color);
        } else if(arg == "clear" || arg == "cls") {  
            basicFunc.clear(path, activeText, wrireText, countingEnter, activeTextS, wrireTextS);
        } else if(arg == "cd") {
            cd.CDCommand(cmd, path, activeText, wrireText, countingEnter, activeTextS, wrireTextS);
        } else if(arg == "help"){
            basicFunc.help(path, activeText, wrireText, countingEnter, activeTextS, wrireTextS);
        } else if(arg == "dir" || arg == "ls" || arg == "list") {
            basicFunc.lsAndDir(path, activeText, wrireText, countingEnter, activeTextS, wrireTextS);
        } else if(arg == "tree") {
            basicFunc.treeWin(path, activeText, wrireText, countingEnter, activeTextS, wrireTextS);
        } else if(arg == "version" || arg == "v"){
            cout << "Version --> "<< version << '\n';
        } else if(arg == "proc") {
            basicFunc.proc(path, activeText, wrireText, countingEnter, activeTextS, wrireTextS);
        } else if(arg == "mkdir"){
            cmd = mainFunc.clearTabsAndSpaces(cmd);
            arg = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg.length()+1); 
        
            filesOperationFunc.createFolder(arg, activeText, wrireText, countingEnter, activeTextS, wrireTextS, path);
        } else if(arg == "deldir"){
            cmd = mainFunc.clearTabsAndSpaces(cmd);
            arg = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg.length()+1); 
        
            filesOperationFunc.deleteFolder(arg, activeText, wrireText, countingEnter, activeTextS, wrireTextS, path);
        } else if(arg == "rndir"){
            cmd = mainFunc.clearTabsAndSpaces(cmd);
            arg = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg.length()+1); 
            arg2 = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg2.length()+1); 

            filesOperationFunc.renameDir(arg, arg2, activeText, wrireText, countingEnter, activeTextS, wrireTextS, path);
        } else if(arg == "mkfile"){
            cmd = mainFunc.clearTabsAndSpaces(cmd);
            arg = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg.length()+1); 
        
            filesOperationFunc.createFile(arg, activeText, wrireText, countingEnter, activeTextS, wrireTextS, path);
        } else if(arg == "delfile"){
            cmd = mainFunc.clearTabsAndSpaces(cmd);
            arg = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg.length()+1); 
        
            filesOperationFunc.deleteFile(arg, activeText, wrireText, countingEnter, activeTextS, wrireTextS, path);
        } else if(arg == "rnfile"){
            cmd = mainFunc.clearTabsAndSpaces(cmd);
            arg = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg.length()+1); 
            arg2 = mainFunc.getStringCommand(cmd);
            cmd.erase(0, arg2.length()+1); 

            filesOperationFunc.renameFile(arg, arg2, activeText, wrireText, countingEnter, activeTextS, wrireTextS, path);
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
