#include "commands-Set.hpp"
#include "../adminFunc/adminDef.hpp"

extern string path;
extern sf::Text activeText;
extern sf::Text wrireText;
extern string countingEnter;
extern string activeTextS;
extern string wrireTextS;

void CDcom :: CDCommand(string container) {
    popath = path;
    MainFunc obj;
    container = obj.clearTabsAndSpaces(container);

    if(container[0] == '.' && container[1] == '.') {
        int howManyTimesBack=0;
        for(int i=0; i<container.length(); ++i){
            if(container[i] == '/' || (string(container[i], container[i+1]) == "\\") ){
                ++howManyTimesBack;
                i+=2;
            }
        }
        ++howManyTimesBack;

        bool spr = false;
        int i=0;
        for(i=popath.length()-1; i>=0; --i){
            if(popath[i] == '/' || popath[i] == '\\'){
                --howManyTimesBack;
            }
            if(howManyTimesBack == 0){
                spr = true;
                break;
            }
        }
        if(spr == true){
            path.erase(i, path.length()-i);
        } else {
            wrireTextS += "Can't be undone\n";
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
    } else if(container == "/" || container == "\\") {
        #ifdef WIN32
            path = "C:";
        #else
            path = getenv("HOME");
        #endif
    } else if(container.length()>0) {
        #ifdef WIN32
            for(int i=0; i<container.length(); ++i) {
                if(container[i] == '/') container[i] = '\\';
            }
            popath = popath+'\\'+container;

            if(access( popath.c_str(), F_OK ) == -1) {
                wrireTextS += "This path is not exist\n";
                wrireText.setString(wrireTextS);
                countingEnter += '\n';
                activeTextS = path+">";
                activeText.setString(countingEnter+activeTextS);
            } else {
                path = popath;
            }
        #else
            popath = popath+"/"+container;
            if(access( popath.c_str(), F_OK ) == -1){
                wrireTextS += "This path is not exist\n";
                wrireText.setString(wrireTextS);
                countingEnter += '\n';
                activeTextS = path+">";
                activeText.setString(countingEnter+activeTextS);
            } else {
                path = popath;
            }
        #endif
    }
}