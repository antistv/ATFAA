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

void renameDir(string nameFolderToRename, string newNameFolder){
    #ifdef WIN32
        system(("rename " + path + "\\" + nameFolderToRename + " " + newNameFolder).c_str());
    #else
        int status;
        status = system(("mv " + path + '/' + nameFolderToRename + " " + path + '/' + newNameFolder).c_str());
        if (status == -1)
            cerr << "Error : " << strerror(errno) << '\n';
        else
            cout << "Directories are renamed" << '\n';
    #endif
}

//FILE

void createFile(string nameFile) {
    #ifdef WIN32
        system(("mkdir " + path + "\\" + nameFile).c_str());
    #else
        int status;
        status = system(("mkdir -p " + path + '/' + nameFile).c_str());
        if (status == -1)
            cerr << "Error : " << strerror(errno) << '\n';
        else
            cout << "File are created" << '\n';
    #endif
}

void deleteFile(string nameFileS) {
    #ifdef WIN32
        system(("rmdir /s /q " + path + "\\" + nameFileS).c_str());
    #else
        int status;
        status = system(("rm -r /" + path + '/' + nameFileS).c_str());
        if (status == -1)
            cerr << "Error : " << strerror(errno) << '\n';
        else
            cout << "File are removed" << '\n';
    #endif
}

void renameFile(string fileToRename, string newNameOfFile){
    #ifdef WIN32
        system(("rename " + path + "\\" + fileToRename + " " + newNameOfFile).c_str());
    #else
        int status;
        status = system(("mv " + path + '/' + fileToRename + " " + path + '/' + newNameOfFile).c_str());
        if (status == -1)
            cerr << "Error : " << strerror(errno) << '\n';
        else
            cout << "File are renamed" << '\n';
    #endif
}