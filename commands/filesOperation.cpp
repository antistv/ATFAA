#include "commands-Set.hpp"

extern sf::Text activeText;
extern sf::Text wrireText;
extern string countingEnter;
extern string activeTextS;
extern string wrireTextS;
extern string path;

void FilesOperation :: createFolder(string nameFolder) {
    #ifdef WIN32
        system(("mkdir " + path + "\\" + nameFolder).c_str());
        wrireTextS += "Directories are created\n";
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    #else
        int status;
        status = system(("mkdir -p " + path + '/' + nameFolder).c_str());
        if (status == -1){
            wrireTextS += "Error : " + string(strerror(errno)) +  '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        } else{
            wrireTextS += "Directories are created\n";
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
    #endif
}

void FilesOperation :: deleteFolder(string nameFolderS) {
    #ifdef WIN32
        system(("rmdir /s /q " + path + "\\" + nameFolderS).c_str());
        wrireTextS += "Directories are removed\n";
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    #else
        int status;
        status = system(("rm -r /" + path + '/' + nameFolderS).c_str());
        if (status == -1){
            wrireTextS += "Error : " + string(strerror(errno)) +  '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        } else {
            wrireTextS += "Directories are removed\n";
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
    #endif
}

void FilesOperation :: renameDir(string nameFolderToRename, string newNameFolder){
    #ifdef WIN32
        system(("rename " + path + "\\" + nameFolderToRename + " " + newNameFolder).c_str());
        wrireTextS += "Directories are renamed\n";
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    #else
        int status;
        status = system(("mv " + path + '/' + nameFolderToRename + " " + path + '/' + newNameFolder).c_str());
        if (status == -1){
            wrireTextS += "Error : " + string(strerror(errno)) +  '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        } else {
            wrireTextS += "Directories are renamed\n";
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
    #endif
}

//FILE

void FilesOperation :: createFile(string nameFile) {
    #ifdef WIN32
        //system(("mkdir " + path + "\\" + nameFile).c_str());
        ofstream outfile (path+"\\"+nameFile);
        outfile.close();
        wrireTextS += "File are created\n";
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    #else
        int status;
        status = system(("mkdir -p " + path + '/' + nameFile).c_str());
        if (status == -1) {
            wrireTextS += "Error : " + string(strerror(errno)) +  '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        } else {
            wrireTextS += "File are created\n";
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
    #endif
}

void FilesOperation :: deleteFile(string nameFileS) {
    #ifdef WIN32
        system(("del /f " + path + "\\" + nameFileS).c_str());
        wrireTextS += "File are removed\n";
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    #else
        int status;
        status = system(("rm -r /" + path + '/' + nameFileS).c_str());
        if (status == -1) {
            wrireTextS += "Error : " + string(strerror(errno)) +  '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        } else {
            wrireTextS += "File are removed\n";
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
    #endif
}

void FilesOperation :: renameFile(string fileToRename, string newNameOfFile){
    #ifdef WIN32
        system(("rename " + path + "\\" + fileToRename + " " + newNameOfFile).c_str());
        wrireTextS += "File are renamed\n";
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = path+">";
        activeText.setString(countingEnter+activeTextS);
    #else
        int status;
        status = system(("mv " + path + '/' + fileToRename + " " + path + '/' + newNameOfFile).c_str());
        if (status == -1) {
            wrireTextS += "Error : " + string(strerror(errno)) +  '\n';
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        } else {
            wrireTextS += "File are renamed\n";
            wrireText.setString(wrireTextS);
            countingEnter += '\n';
            activeTextS = path+">";
            activeText.setString(countingEnter+activeTextS);
        }
    #endif
}