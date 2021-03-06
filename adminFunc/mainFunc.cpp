#include "adminDef.hpp"

string MainFunc::clearTabsAndSpaces(string line){
    string deleted="";
    bool make = false;
    for (int i = 0; i < line.size(); ++i) {
        if(make == false) {
            if(line[i] != ' ') {
                deleted += line[i];
                make = true;
            } 
        } else {
            deleted += line[i];
        }
    }
    return deleted;
}

string MainFunc :: getStringCommand(string line) {
    string command = "";
    for(int i=0; i<line.size(); ++i){
        if(line[i] == ' '){
            return command;
        }
        command += line[i];
    }
    return command;
}

sf::String MainFunc :: fromUtf8(const string &in) {
    basic_string<sf::Uint32> tmp;
    sf::Utf8::toUtf32(in.begin(), in.end(), back_inserter(tmp));
    return sf::String(tmp);
}