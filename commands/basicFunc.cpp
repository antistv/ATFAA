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

        short howManyEnter=0;
        string line;
	    fstream infile;
	    infile.open ("commands/system-proc.txt" );
        while(!infile.eof()) { // To get you all the lines.
	        infile >> line; // Saves the line in STRING.
            ++howManyEnter;
            
            if(howManyEnter == 6){
                wrireTextS += line + '\n';
                wrireText.setString(wrireTextS);
                countingEnter += '\n';
                activeTextS = path+">";
                activeText.setString(countingEnter+activeTextS);
                howManyEnter = 0;
            } else {
                wrireTextS += line + " ";
            }
        }
	    infile.close();

        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
    #else
        system("ps -U root -u root -N > commands/system-proc.txt");

        short howManyEnter=0;
        string line;
	    fstream infile;
	    infile.open ("commands/system-proc.txt" );
        while(!infile.eof()) { // To get you all the lines.
	        infile >> line; // Saves the line in STRING.
            ++howManyEnter;
            
            if(howManyEnter == 4){
                wrireTextS += line + '\n';
                wrireText.setString(wrireTextS);
                countingEnter += '\n';
                activeTextS = path+">";
                activeText.setString(countingEnter+activeTextS);
                howManyEnter = 0;
            } else {
                wrireTextS += line + " ";
            }
        }
	    infile.close();

        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
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
        system(("dir " + path + " > commands/system-proc.txt").c_str());

        string line;
	    fstream infile;
	    infile.open ("commands/system-proc.txt" );
        while(!infile.eof()) { // To get you all the lines.
	        infile >> line; // Saves the line in STRING.
            cout << line << '\n';

            wrireTextS += line + '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
	    infile.close();

        infile.open ("commands/system-proc.txt", std::ifstream::out | std::ifstream::trunc );
        infile.close();
    #else
        system(("ls " + path + " > commands/system-proc.txt").c_str());

        string line;
	    fstream infile;
	    infile.open ("commands/system-proc.txt" );
        while(!infile.eof()) { // To get you all the lines.
	        infile >> line; // Saves the line in STRING.
            cout << line << '\n';

            wrireTextS += line + '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
	    infile.close();

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
        system(("tree " + path).c_str());
    #else
        cout<<"feature not available on linux"<<'\n';
    #endif
}

void BasicFunc :: terminal() {
    #ifdef WIN32

    #else
        system("./sfml-app");
    #endif
}