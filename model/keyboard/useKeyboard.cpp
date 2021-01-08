#include "useKeyboard.hpp"

extern string activeTextS;
extern string wrireTextS;
extern sf::Text activeText;
extern sf::Text wrireText;
extern sf::Font font;
extern sf::Event event;
extern string command;
extern string countingEnter;
extern sf::RenderWindow window;


map<short, char> letterMap = { pair<short, char>(32, ' '),pair<short, char>(33, '!'),pair<short, char>(34, '"'),pair<short, char>(35, '#'),pair<short, char>(36, '$'),pair<short, char>(37, '%'),pair<short, char>(38, '&'),pair<short, char>(39, '\''),pair<short, char>(40, '('),pair<short, char>(41, ')'),pair<short, char>(42, '*'),pair<short, char>(43, '+'),pair<short, char>(44, ','),pair<short, char>(45, '-'),pair<short, char>(46, '.'),pair<short, char>(47, '/'),pair<short, char>(48, '0'),pair<short, char>(49, '1'),pair<short, char>(50, '2'),pair<short, char>(51, '3'),pair<short, char>(52, '4'),pair<short, char>(53, '5'),pair<short, char>(54, '6'),pair<short, char>(55, '7'),pair<short, char>(56, '8'),pair<short, char>(57, '9'),pair<short, char>(58, ':'),pair<short, char>(59, ';'),pair<short, char>(60, '<'),pair<short, char>(61, '='),pair<short, char>(62, '>'),pair<short, char>(63, '?'),pair<short, char>(64, '@')
,pair<short, char>(65, 'A'), pair<short, char>(66, 'B'), pair<short, char>(67, 'C'), pair<short, char>(68, 'D'), pair<short, char>(69, 'E'), pair<short, char>(70, 'F'), pair<short, char>(71, 'G'), pair<short, char>(72, 'H'), pair<short, char>(73, 'I'), pair<short, char>(74, 'J'), pair<short, char>(75, 'K'), pair<short, char>(76, 'L'), pair<short, char>(77, 'M'), pair<short, char>(78, 'N'), pair<short, char>(79, 'O'), pair<short, char>(80, 'P'), pair<short, char>(81, 'Q'), pair<short, char>(82, 'R'), pair<short, char>(83, 'S'), pair<short, char>(84, 'T'), pair<short, char>(85, 'U'), pair<short, char>(86, 'V'), pair<short, char>(87, 'W'), pair<short, char>(88, 'X'), pair<short, char>(89, 'Y'), pair<short, char>(90, 'Z')
,pair<short, char>(91, '['),pair<short, char>(92, '\\'),pair<short, char>(93, ']'),pair<short, char>(94, '^'),pair<short, char>(95, '_'),pair<short, char>(96, '`')
,pair<short, char>(97, 'a'), pair<short, char>(98, 'b'), pair<short, char>(99, 'c'), pair<short, char>(100, 'd'), pair<short, char>(101, 'e'), pair<short, char>(102, 'f'), pair<short, char>(103, 'g'), pair<short, char>(104, 'h'), pair<short, char>(105, 'i'), pair<short, char>(106, 'j'), pair<short, char>(107, 'k'), pair<short, char>(108, 'l'), pair<short, char>(109, 'm'), pair<short, char>(110, 'n'), pair<short, char>(111, 'o'), pair<short, char>(112, 'p'), pair<short, char>(113, 'q'), pair<short, char>(114, 'r'), pair<short, char>(115, 's'), pair<short, char>(116, 't'), pair<short, char>(117, 'u'), pair<short, char>(118, 'v'), pair<short, char>(119, 'w'), pair<short, char>(120, 'x'), pair<short, char>(121, 'y'), pair<short, char>(122, 'z'), pair<short, char>(123, '{'), pair<short, char>(124, '|'), pair<short, char>(125, '}'), pair<short, char>(126, '~')
};

void KeybordFunc::keyboard() {
    if (event.type == sf::Event::TextEntered) {
        if(event.text.unicode == 8){
            activeTextS.erase(activeTextS.length()-1, 1);
            activeText.setString(countingEnter+activeTextS);
        } else if(event.text.unicode == 13){
            wrireTextS += activeTextS;
            wrireTextS += '\n';
            countingEnter += '\n';
            activeTextS="";
            wrireText.setString(wrireTextS);
            //Wysłanie komendy
            command = "";
            activeText.setString(countingEnter+activeTextS);
        } else {
            activeTextS += letterMap[event.text.unicode];
            command += letterMap[event.text.unicode];
            activeText.setString(countingEnter+activeTextS);
        }
    }
}

void KeybordFunc::checkEdge(){
    if (activeText.getLocalBounds().width >= window.getSize().x-10 ) { 
        wrireTextS += activeTextS+'\n';
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = "";
        activeText.setString(countingEnter+activeTextS);
    }
}