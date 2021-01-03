#include "../main.hpp"

extern string path;

void CDCommand(string container) {
    
    container = clearTabsAndSpaces(container);
    string popath="";
    popath=path;

    if(container == "..") {
        bool spr = false;
        int i=0;
        for(i=popath.length()-1; i>=0; --i){
            if(popath[i] == '/' || popath[i] == '\\'){
                spr = true;
                break;
            }
        }
        if(spr == true){
            path.erase(i, path.length()-i);
        } else {
            printw("Can't be undone\n");
        }
    } else if(container == "/" || container == "\\") {
        #ifdef WIN32
            path = "C:";
        #else
            path = getenv("HOME");
        #endif
    } else if(container.length()>0) {
        #ifdef WIN32
            popath = popath+'\\'+container;
            if(access( popath.c_str(), F_OK ) == -1) {
                printw("This path is not exist\n");
            } else {
                path = popath;
            }
        #else
            popath = popath+"/"+container;
            if(access( popath.c_str(), F_OK ) == -1){
                printw("This path is not exist\n");
            } else {
                path = popath;
            }
        #endif
    } else {
        //wypisz path
        printw("%s\n", path.c_str());
    }

    command();
}