#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <filesystem>
#include <sys/stat.h>
#include <stdlib.h> 
#include <cstdlib>
#include <cstdio> 

#ifdef WIN32
    //
#else
    #include <sys/stat.h>
    #include <sys/types.h>
#endif

using namespace std;

void color(string clr);
void proc();
void help();
void lsAndDir();
void clear();
void treeWin();
void terminal();
string clearTabsAndSpaces(string line);
string getStringCommand(string line);
void CDCommand(string container);
void command();
int main();
void createFolder(string nameFolder);
void deleteFolder(string nameFolderS);
void renameDir(string nameFolderToRename, string newNameFolder);
void createFile(string nameFile);
void deleteFile(string nameFileS);
void renameFile(string fileToRename, string newNameOfFile);