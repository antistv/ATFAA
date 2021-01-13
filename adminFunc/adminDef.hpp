#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <SFML/System/String.hpp>
#include <SFML/System/Utf.hpp>

using namespace std;

class MainFunc {
  public:
    string clearTabsAndSpaces(string line);
    string getStringCommand(string line);
    sf::String fromUtf8(const string &in);
};