#include "../main.hpp"

void color(string clr) {
    if(clr == "red") {
        cout << "\x1B[31m\031\t\t" << '\n';
        command();
    } else if(clr == "green") {
        cout << "\x1B[32m\032\t\t" << '\n';
        command();
    } else if(clr == "yellow") {
        cout << "\x1B[33m\033\t\t" << '\n';
        command();
    } else if(clr == "blue") {
        cout << "\x1B[34m\034\t\t" << '\n';
        command();
    } else if(clr == "magenta") {
        cout << "\x1B[35m\035\t\t" << '\n';
        command();
    } else if(clr == "cyan") {
        cout << "\x1B[36m\036\t\t" << '\n';
        command();
    } else if(clr == "white" || clr == "default" || clr == "standard") {
        cout << "\x1B[37m\037\t\t" << '\n';
        command();
    } else {
        cout << "'" << clr << "': Color not found." << '\n';
        command();
    }
}