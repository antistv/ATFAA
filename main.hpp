#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <filesystem>
#include <sys/stat.h>
#include <stdlib.h> 
#include <cstdlib>
#include <cstdio> 
#include <ncurses.h>

using namespace std;

//Funkcje
void color(string clr);
void proc();
void help();
void lsAndDir();
void clearTerminal();
void treeWin();
string clearTabsAndSpaces(string line);
string getStringCommand(string line);
void CDCommand(string container);
void command();
//cos nowego
