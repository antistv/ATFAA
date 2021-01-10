#include "commands-Set.hpp"
#include <SFML/Graphics.hpp>
#include "../model/main-win.hpp"

extern string path;
extern sf::Text activeText;
extern sf::Text wrireText;
extern string countingEnter;
extern string activeTextS;
extern string wrireTextS;

extern string path;

void BasicFunc :: proc() {
    #ifdef WIN32
        string str;
        str = system("proc");

        int countingEnterinFile=0;
        for(int i=0; i<str.length(); ++i) {
            if(str[i] == '\n') ++countingEnterinFile;
        }

        wrireTextS += str + '\n';
        wrireText.setString(wrireTextS);
        for(int i=0; i<=countingEnterinFile; ++i) countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    #else
        string str;
        str = system("ps -U root -u root -N");

        int countingEnterinFile=0;
        for(int i=0; i<str.length(); ++i) {
            if(str[i] == '\n') ++countingEnterinFile;
        }
    
        wrireTextS += str + '\n';
        wrireText.setString(wrireTextS);
        for(int i=0; i<=countingEnterinFile; ++i) countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    #endif
}

void BasicFunc :: help() {
    ifstream f("help.txt");
    if (f.is_open()){
        string str;

        f.seekg(0, ios::end);   
        str.reserve(f.tellg());
        f.seekg(0, std::ios::beg);

        str.assign((istreambuf_iterator<char>(f)),
                    istreambuf_iterator<char>());

        int countingEnterinFile=0;
        for(int i=0; i<str.length(); ++i) {
            if(str[i] == '\n') ++countingEnterinFile;
        }

        wrireTextS += str + '\n';
        wrireText.setString(wrireTextS);
        for(int i=0; i<=countingEnterinFile; ++i) countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    }
    f.close();
}

void BasicFunc :: lsAndDir() {
    #ifdef WIN32
        wrireTextS += system(("dir " + path).c_str()) + '\n';
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    #else
        wrireTextS += system(("ls " + path).c_str()) + '\n';
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    #endif
}

void BasicFunc :: clear() {
    wrireTextS = "";
    countingEnter="";
    wrireText.setString(wrireTextS);
    activeTextS = path+">";
    activeText.setString(countingEnter+activeTextS);
}

void BasicFunc :: treeWin() {
    #ifdef WIN32
        system(("tree " + path).c_str());
    #else
        cout<<"feature not available on linux"<<'\n';
    #endif
}

void BasicFunc :: terminal() {
    #ifdef WIN32
        MainWindow window;
        window.mainWindow();
    #else
        MainWindow window;
        window.mainWindow();
    #endif
}