#include "commands-Set.hpp"
#include "../model/main-win.hpp"
#include "../adminFunc/adminDef.hpp"

MainFunc Function; 

void BasicFunc::proc(string &path, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS) {
    #ifdef WIN32
        system("tasklist > commands/system-proc.txt");

	    infile.open ("commands/system-proc.txt" );

        while(getline(infile, line)) {
            wrireTextS += Function.fromUtf8(line + " " + '\n');
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = Function.fromUtf8(path+">");
            activeText.setString(countingEnter+activeTextS);
        }

        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
    #else
        system("ps -U root -u root -N > commands/system-proc.txt");

	    infile.open ("commands/system-proc.txt" );

        while(getline(infile, line)) {
            wrireTextS += Function.fromUtf8(line + " " + '\n');
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = Function.fromUtf8(path+">");
            activeText.setString(countingEnter+activeTextS);
        }
        infile.close();
        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
    #endif
}

void BasicFunc::help(string &path, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS) {
    infile.open ("help.txt" );

    while(getline(infile, line)) {
        wrireTextS += Function.fromUtf8(line) + Function.fromUtf8(" ") + '\n';
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = Function.fromUtf8(path+">");
        activeText.setString(countingEnter+activeTextS);
    }
    infile.close();
}

void BasicFunc::lsAndDir(string &path, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS) {
    #ifdef WIN32
        system(("dir " + path + " > commands/system-proc.txt").c_str());

	    infile.open ("commands/system-proc.txt" );

        while(getline(infile, line)) {
            wrireTextS += Function.fromUtf8(line) + Function.fromUtf8(" ") + '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = Function.fromUtf8(+">");
            activeText.setString(countingEnter+activeTextS);
        }
        infile.close();

        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
    #else
        system(("ls " + path + " > commands/system-proc.txt").c_str());

	    infile.open ("commands/system-proc.txt" );

        while(getline(infile, line)) {
            wrireTextS += Function.fromUtf8(line) + Function.fromUtf8(" ") + '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = Function.fromUtf8(+">");
            activeText.setString(countingEnter+activeTextS);
        }
        infile.close();
        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
    #endif
}

void BasicFunc::clear(string &path, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS) {
    wrireTextS = "";
    countingEnter= "";
    wrireText.setString(wrireTextS);
    activeTextS = Function.fromUtf8(path+">");
    activeText.setString(countingEnter+activeTextS);
}

void BasicFunc::treeWin(string &path, sf::Text &activeText, sf::Text &wrireText, string &countingEnter, sf::String &activeTextS, sf::String &wrireTextS) {
    #ifdef WIN32
        system(("tree " + path + " > commands/system-proc.txt").c_str());

	    infile.open ("commands/system-proc.txt" );

        while(getline(infile, line)) {
            cout<<line<<endl;
            wrireTextS +=  Function.fromUtf8(line + " " + '\n');
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = Function.fromUtf8(path+">");
            activeText.setString(countingEnter+activeTextS);
        }
        infile.close();

        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
    #else
        wrireTextS += Function.fromUtf8("Feature not available on linux")+ '\n';
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = Function.fromUtf8(path+">");
        activeText.setString(countingEnter+activeTextS);
    #endif
}

void BasicFunc::terminal() {
    #ifdef WIN32
        system(".\\sfml-app.exe");
    #else
        system("./sfml-app");
    #endif
}