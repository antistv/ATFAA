#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <filesystem>
#include <sys/stat.h>
#include <stdlib.h> 
#include <cstdlib>
#include <cstdio> 
#include <streambuf>

using namespace std;

class BasicFunc{
    public:
        void proc();
        void help();
        void lsAndDir();
        void clear();
        void treeWin();
        void terminal();
};

class CDcom {
    public:
        void CDCommand(string container);
        string popath="";
};

class Colors {
    public:
        void color(string clr);
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

class MainFunc {
  public:
    string clearTabsAndSpaces(string line);
    string getStringCommand(string line);
};

class OperateCmd {
    public:
        void runCommand(string cmd);
};