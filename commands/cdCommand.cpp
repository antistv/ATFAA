#include "commands-Set.hpp"

extern string path;

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
            cout << "Can't be undone" << '\n';
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
                cout<<"This path is not exist"<<'\n';
            } else {
                path = popath;
            }
        #else
            popath = popath+"/"+container;
            if(access( popath.c_str(), F_OK ) == -1){
                cout<<"This path is not exist"<<'\n';
            } else {
                path = popath;
            }
        #endif
    } else {
        cout<<path<<'\n';
    }
}