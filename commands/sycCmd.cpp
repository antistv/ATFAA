#include "commands-Set.hpp"

extern string path;
extern sf::Text activeText;
extern sf::Text wrireText;
extern string countingEnter;
extern sf::String activeTextS;
extern sf::String wrireTextS;

bool SysCommands::checkAndExecuteCmd(string cmd){
    system((cmd +  " > commands/system-proc.txt").c_str());

	ifstream ifFile;
	ifFile.open ("commands/system-proc.txt" );

    if(isEmpty(ifFile)){
        return false;
    }

    string line;
	fstream infile;

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

    return true;
}

bool SysCommands::isEmpty(std::ifstream& pFile) {
    return pFile.peek() == std::ifstream::traits_type::eof();
}