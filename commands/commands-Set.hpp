#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <cstdio> 
#include <SFML/Graphics.hpp>

using namespace std;

class BasicFunc{
    public:
        void proc();
        void help();
        void lsAndDir();
        void clear();
        void treeWin();
        void terminal();
    private:
        string line;
        fstream infile;
};

class CDcom {
    public:
        void CDCommand(string container);
    private:    
        string popath="";
};

class Colors {
    public:
        void Fcolor(string clr, string clr2, string clr3);
        void Bcolor(string clr, string clr2, string clr3);
        bool is_number(const std::string &s);
};

class FilesOperation{
    public:
        void createFolder(string nameFolder);
        void deleteFolder(string nameFolderS);
        void renameDir(string nameFolderToRename, string newNameFolder);
        void createFile(string nameFile);
        void deleteFile(string nameFileS);
        void renameFile(string fileToRename, string newNameOfFile);
};

class OperateCmd {
    public:
        bool runCommand(string cmd);
};

class SysCommands {
    public:
        bool checkAndExecuteCmd(string cmd);
        bool isEmpty(std::ifstream& pFile);
};
