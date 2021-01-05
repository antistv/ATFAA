#include "../main.hpp"

extern string path;

void FilesOperation :: createFolder(string nameFolder) {
    #ifdef WIN32
        system(("mkdir " + path + "\\" + nameFolder).c_str());
        cout << "Folder are created" << '\n';
    #else
        int status;
        status = system(("mkdir -p " + path + '/' + nameFolder).c_str());
        if (status == -1)
            cerr << "Error : " << strerror(errno) << '\n';
        else
            cout << "Directories are created" << '\n';
    #endif
}

void FilesOperation :: deleteFolder(string nameFolderS) {
    #ifdef WIN32
        system(("rmdir /s /q " + path + "\\" + nameFolderS).c_str());
        cout << "File are deleted" << '\n';
    #else
        int status;
        status = system(("rm -r /" + path + '/' + nameFolderS).c_str());
        if (status == -1)
            cerr << "Error : " << strerror(errno) << '\n';
        else
            cout << "Directories are removed" << '\n';
    #endif
}

void FilesOperation :: renameDir(string nameFolderToRename, string newNameFolder){
    #ifdef WIN32
        system(("rename " + path + "\\" + nameFolderToRename + " " + newNameFolder).c_str());
        cout << "Folder are renamed" << '\n';
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

void FilesOperation :: createFile(string nameFile) {
    #ifdef WIN32
        //system(("mkdir " + path + "\\" + nameFile).c_str());
        ofstream outfile (path+"\\"+nameFile);
        outfile.close();
        cout << "File are created" << '\n';
    #else
        int status;
        status = system(("mkdir -p " + path + '/' + nameFile).c_str());
        if (status == -1)
            cerr << "Error : " << strerror(errno) << '\n';
        else
            cout << "File are created" << '\n';
    #endif
}

void FilesOperation :: deleteFile(string nameFileS) {
    #ifdef WIN32
        system(("del /f " + path + "\\" + nameFileS).c_str());
        cout << "File are deleted" << '\n';
    #else
        int status;
        status = system(("rm -r /" + path + '/' + nameFileS).c_str());
        if (status == -1)
            cerr << "Error : " << strerror(errno) << '\n';
        else
            cout << "File are removed" << '\n';
    #endif
}

void FilesOperation :: renameFile(string fileToRename, string newNameOfFile){
    #ifdef WIN32
        system(("rename " + path + "\\" + fileToRename + " " + newNameOfFile).c_str());
        cout << "File are renamed" << '\n';
    #else
        int status;
        status = system(("mv " + path + '/' + fileToRename + " " + path + '/' + newNameOfFile).c_str());
        if (status == -1)
            cerr << "Error : " << strerror(errno) << '\n';
        else
            cout << "File are renamed" << '\n';
    #endif
}