#include "../main.hpp"

extern string path;

void createFolder(string nameFolder) {
    #ifdef WIN32
        system(("mkdir " + path + "\\" + nameFolder).c_str());
    #else
        int status;
        status = system(("mkdir -p " + path + '/' + nameFolder).c_str());
        if (status == -1)
            cerr << "Error : " << strerror(errno) << '\n';
        else
            cout << "Directories are created" << '\n';
    #endif
}

void deleteFolder(string nameFolderS) {
    #ifdef WIN32
        system(("rmdir /s /q " + path + "\\" + nameFolderS).c_str());
    #else
        int status;
        status = system(("rm -r /" + path + '/' + nameFolderS).c_str());
        if (status == -1)
            cerr << "Error : " << strerror(errno) << '\n';
        else
            cout << "Directories are removed" << '\n';
    #endif
}