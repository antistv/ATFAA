#include "main.hpp"

string version = "0.0.3";
string path = "";

int main() {  
    setlocale( LC_ALL, "pl_PL" );

    #ifdef WIN32
        string drive = getenv("systemdrive");
        string home = getenv("homepath");
        path = drive+home;
        HWND hWnd = GetConsoleWindow();
        ShowWindow( hWnd, SW_HIDE );
    #else
        path = getenv("HOME");
    #endif

    MainWindow window;
    window.mainWindow(path, version);

    return 0;   
 }