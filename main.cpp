#include "main.hpp"

//Zintegorwać basic func
//błąd usuwania komędy poza linijką

string version = "0.0.2";
string path = "";

int main() {  
    setlocale( LC_ALL, "pl_PL" );

    #ifdef WIN32
        system(("title ATFAA Terminal " + version).c_str());
        string drive, home;
        drive = getenv("systemdrive");
        home = getenv("homepath");
        path = drive+home;
    #else
        char esc_start[] = { 0x1b, ']', '0', ';', 0 };
        char esc_end[] = { 0x07, 0 };
        cout << esc_start << "ATFAA Terminal" << version << esc_end;
        path = getenv("HOME");
    #endif

    cout << "ATFAA Terminal " << version <<  '\n';
    cout << "Copyright (c) ATFAA Corporation. All rights reserved"<<  '\n';
    cout << "Type 'help' to get help." <<  '\n';

    MainWindow window;
    window.mainWindow();

    return 0;   
 }