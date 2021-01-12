#include "commands-Set.hpp"
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
        system("tasklist > commands/system-proc.txt");

        string line;
	    fstream infile;
	    infile.open ("commands/system-proc.txt" );

        while(getline(infile, line)) {
            wrireTextS += line + " " + '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }

        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
    #else
        system("ps -U root -u root -N > commands/system-proc.txt");

        string line;
	    fstream infile;
	    infile.open ("commands/system-proc.txt" );

        while(getline(infile, line)) {
            wrireTextS += line + " " + '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }

        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
    #endif
}

void BasicFunc :: help() {
    string line;
    fstream infile;
    infile.open ("help.txt" );

    while(getline(infile, line)) {
        wrireTextS += line + " " + '\n';
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    }
    infile.close();
}

void BasicFunc :: lsAndDir() {
    #ifdef WIN32
        system(("dir " + path + " > commands/system-proc.txt").c_str());

        string line;
	    fstream infile;
	    infile.open ("commands/system-proc.txt" );

        while(getline(infile, line)) {
            cout<<line<<endl;
            wrireTextS += line + " " + '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }

        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
    #else
        system(("ls " + path + " > commands/system-proc.txt").c_str());

        string line;
	    fstream infile;
	    infile.open ("commands/system-proc.txt" );

        while(getline(infile, line)) {
            cout<<line<<endl;
            wrireTextS += line + " " + '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }

        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
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
        system(("tree " + path + " > commands/system-proc.txt").c_str());

        string line;
	    fstream infile;
	    infile.open ("commands/system-proc.txt" );
/*
            wrireText.setString(L"aąeęiouót|\n");
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
*/
        while(getline(infile, line)) {
            cout<<line<<endl;
            wrireTextS +=  line + " " + '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }

        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
    #else
        wrireTextS += "Feature not available on linux"+ '\n';
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    #endif
}

void BasicFunc :: terminal() {
    #ifdef WIN32

    #else
        system("./sfml-app");
    #endif
}