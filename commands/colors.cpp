#include "../main.hpp"

void color(string clr) {
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_YELLOW, -1);
    init_pair(4, COLOR_BLUE, -1);
    init_pair(5, COLOR_MAGENTA, -1);
    init_pair(6, COLOR_CYAN, -1);
    init_pair(7, COLOR_WHITE, -1);

    if(clr == "red") {
        attron(COLOR_PAIR(1));
    } else if(clr == "green") {
        attron(COLOR_PAIR(2));
    } else if(clr == "yellow") {
        attron(COLOR_PAIR(3));
    } else if(clr == "blue") {
        attron(COLOR_PAIR(4));
    } else if(clr == "magenta" || clr == "purple" || clr == "violet") {
        attron(COLOR_PAIR(5));
    } else if(clr == "cyan") {
        attron(COLOR_PAIR(6));
    } else if(clr == "white" || clr == "default" || clr == "standard") {
        attron(COLOR_PAIR(7));
    } else {
        printw("%s: Color not found.\n", clr.c_str());
    }
}