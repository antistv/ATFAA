#include "../main.hpp"

extern string path;

void CDcom :: CDCommand(string container) {
    popath = path;
    MainFunc obj;
    container = obj.clearTabsAndSpaces(container);

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