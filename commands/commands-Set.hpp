#pragma once
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
        void proc(string &path, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS);
        void help(string &path, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS);
        void lsAndDir(string &path, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS);
        void clear(string &path, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS);
        void treeWin(string &path, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS);
        void terminal();
    private:
        string line;
        fstream infile;
};

class CDcom {
    public:
        void CDCommand(string container, string &path, sf::Text &activeText, sf::Text &wrireText, string &countingEnter,sf::String &activeTextS, sf::String &wrireTextS);
    private:    
        string popath {""};
};

class Colors {
    public:
        void Fcolor(string clr, string clr2, string clr3, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS, sf::RectangleShape &rect, string &path);
        void Bcolor(string clr, string clr2, string clr3, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS, string &path, sf::Color &background_color);
        bool is_number(const std::string &s);
};

class FilesOperation{
    public:
        void createFolder(string nameFolder, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS, string &path);
        void deleteFolder(string nameFolderS, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS, string &path);
        void renameDir(string nameFolderToRename, string newNameFolder, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS, string &path);
        void createFile(string nameFile, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS, string &path);
        void deleteFile(string nameFileS, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS, string &path);
        void renameFile(string fileToRename, string newNameOfFile, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS, string &path);
};

class OperateCmd {
    public:
        bool runCommand(string cmd, sf::Text &activeText,sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS, sf::RectangleShape &rect, string &version, string &path, sf::Color &background_color);
};

class SysCommands {
    public:
        bool checkAndExecuteCmd(string cmd, string &path, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS);
        bool isEmpty(std::ifstream &pFile);
};
