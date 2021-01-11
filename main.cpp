#include "main.hpp"

//błąd usuwania komendy poza linijką

string version = "0.0.2";
string path = "";

int main() {  
    setlocale( LC_ALL, "pl_PL" );

    #ifdef WIN32
        path = getenv("systemdrive") + getenv("homepath");
        HWND hWnd = GetConsoleWindow();
        ShowWindow( hWnd, SW_HIDE );
    #else
        path = getenv("HOME");
    #endif

    MainWindow window;
    window.mainWindow();

    return 0;   
 }