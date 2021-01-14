#include "useKeyboard.hpp"
#include"../../commands/commands-Set.hpp"
#include "../../adminFunc/adminDef.hpp"
#include "../object/object-set.hpp"

extern sf::String activeTextS;
extern sf::String wrireTextS;
extern sf::Text activeText;
extern sf::Text wrireText;
extern sf::Event event;
extern string command;
extern string countingEnter;
extern sf::RenderWindow window;
extern int textSize;
extern sf::Font font;
extern bool scrollOrNo;
extern sf::View camera;
extern string path;
extern int counter;
extern sf::RectangleShape rect;

int scrollEnter = 0;
vector<string> cmdSaver;
int cmdPointer=-1;
string saveBackCommand;

MainFunc FunctionUtf;
SysCommands systemCommands;
OperateCmd operation;
Cursor cursor;

map<short, string> letterMap = { pair<short, string>(32, " "),pair<short, string>(33, "!"),pair<short, string>(34, "%"),pair<short, string>(35, "#"),pair<short, string>(36, "$"),pair<short, string>(37, "%"),pair<short, string>(38, "&"),pair<short, string>(39, "\""),pair<short, string>(40, "("),pair<short, string>(41, ")"),pair<short, string>(42, "*"),pair<short, string>(43, "+"),pair<short, string>(44, ","),pair<short, string>(45, "-"),pair<short, string>(46, "."),pair<short, string>(47, "/"),pair<short, string>(48, "0"),pair<short, string>(49, "1"),pair<short, string>(50, "2"),pair<short, string>(51, "3"),pair<short, string>(52, "4"),pair<short, string>(53, "5"),pair<short, string>(54, "6"),pair<short, string>(55, "7"),pair<short, string>(56, "8"),pair<short, string>(57, "9"),pair<short, string>(58, ":"),pair<short, string>(59, ";"),pair<short, string>(60, "<"),pair<short, string>(61, "="),pair<short, string>(62, ">"),pair<short, string>(63, "?"),pair<short, string>(64, "@")
,pair<short, string>(65, "A"), pair<short, string>(66, "B"), pair<short, string>(67, "C"), pair<short, string>(68, "D"), pair<short, string>(69, "E"), pair<short, string>(70, "F"), pair<short, string>(71, "G"), pair<short, string>(72, "H"), pair<short, string>(73, "I"), pair<short, string>(74, "J"), pair<short, string>(75, "K"), pair<short, string>(76, "L"), pair<short, string>(77, "M"), pair<short, string>(78, "N"), pair<short, string>(79, "O"), pair<short, string>(80, "P"), pair<short, string>(81, "Q"), pair<short, string>(82, "R"), pair<short, string>(83, "S"), pair<short, string>(84, "T"), pair<short, string>(85, "U"), pair<short, string>(86, "V"), pair<short, string>(87, "W"), pair<short, string>(88, "X"), pair<short, string>(89, "Y"), pair<short, string>(90, "Z")
,pair<short, string>(91, "["),pair<short, string>(92, "\\"),pair<short, string>(93, "]"),pair<short, string>(94, "^"),pair<short, string>(95, "_"),pair<short, string>(96, "`")
,pair<short, string>(97, "a"), pair<short, string>(98, "b"), pair<short, string>(99, "c"), pair<short, string>(100, "d"), pair<short, string>(101, "e"), pair<short, string>(102, "f"), pair<short, string>(103, "g"), pair<short, string>(104, "h"), pair<short, string>(105, "i"), pair<short, string>(106, "j"), pair<short, string>(107, "k"), pair<short, string>(108, "l"), pair<short, string>(109, "m"), pair<short, string>(110, "n"), pair<short, string>(111, "o"), pair<short, string>(112, "p"), pair<short, string>(113, "q"), pair<short, string>(114, "r"), pair<short, string>(115, "s"), pair<short, string>(116, "t"), pair<short, string>(117, "u"), pair<short, string>(118, "v"), pair<short, string>(119, "w"), pair<short, string>(120, "x"), pair<short, string>(121, "y"), pair<short, string>(122, "z"), pair<short, string>(123, "{"), pair<short, string>(124, "|"), pair<short, string>(125, "}"), pair<short, string>(126, "~"),
pair<short, string>(261, "ą"),pair<short, string>(260, "Ą"),pair<short, string>(263, "ć"),pair<short, string>(262, "Ć"),pair<short, string>(281, "ę"), pair<short, string>(280, "Ę"),pair<short, string>(322, "ł"),pair<short, string>(321, "Ł"),pair<short, string>(324, "ń"),pair<short, string>(323, "Ń"),pair<short, string>(243, "ó"),pair<short, string>(211, "Ó"),pair<short, string>(347, "ś"),pair<short, string>(346, "Ś"),pair<short, string>(378, "ź"),pair<short, string>(377, "Ź"),pair<short, string>(380, "ż"),pair<short, string>(379, "Ż")
};

void KeybordFunc::keyboard() { 
    if(event.text.unicode == 8){
        if(command.length() > 0){
            if(counter > 0){
                activeTextS.erase(counter+path.length(), 1);
                command.erase(counter-1, 1);
                --counter;
                rect.move(-font.getLineSpacing(textSize)/2 , 0);
                activeText.setString(countingEnter+activeTextS);
                scrollEnter = countingEnter.length();
            }
        }
    } else if(event.text.unicode == 13){
        counter = 0;
        wrireTextS += activeTextS;
        wrireText.setString(wrireTextS);
        wrireTextS += "\n";
        countingEnter += "\n";
        //Wysłanie komendy
            if(!operation.runCommand(command)){
                if(!systemCommands.checkAndExecuteCmd(command)){
                    wrireTextS += FunctionUtf.fromUtf8("Command not found\n");
                    wrireText.setString(wrireTextS);
                    countingEnter += "\n";
                    activeTextS= FunctionUtf.fromUtf8(path+">");
                    activeText.setString(countingEnter+activeTextS);
                }
            }
        //
        if(command != "") cmdSaver.push_back(command);
        cmdPointer = cmdSaver.size();
        activeTextS= FunctionUtf.fromUtf8(path+">");
        command = "";
        activeText.setString(countingEnter+activeTextS);
        scrollEnter = countingEnter.length();
        cursor.rectMove();
    } else {
        activeTextS.insert(counter+path.length()+1, FunctionUtf.fromUtf8(letterMap[event.text.unicode]));
        command.insert(counter, FunctionUtf.fromUtf8(letterMap[event.text.unicode]));
        saveBackCommand = command;
        ++counter;
        activeText.setString(countingEnter+activeTextS);
        scrollEnter = countingEnter.length();
        rect.move(+font.getLineSpacing(textSize)/2 , 0);
    }
    
    scrollOrNo = true;
    if(activeText.getLocalBounds().height < camera.getCenter().y-window.getSize().y/2 || activeText.getLocalBounds().height > camera.getCenter().y+window.getSize().y/2) {
        camera.setCenter(window.getSize().x/2 , countingEnter.length()*font.getLineSpacing(textSize)-window.getSize().y / 2);
    }
}

void KeybordFunc::checkEdge(){
    if (activeText.getLocalBounds().width >= window.getSize().x-20 ) { 
        wrireTextS += FunctionUtf.fromUtf8(activeTextS+'\n');
        wrireText.setString(wrireTextS);
        countingEnter += '\n';
        activeTextS = "";
        activeText.setString(countingEnter+activeTextS);
    }
}

void KeybordFunc::rememberCmd(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(cmdPointer > 0 && cmdSaver.size()>0){
            --cmdPointer;
            activeTextS =  FunctionUtf.fromUtf8(path+">"+cmdSaver[cmdPointer]);
            activeText.setString(countingEnter+activeTextS);
            command = cmdSaver[cmdPointer];
            cursor.rectMove();
        } else {
            cmdPointer = cmdSaver.size();
            activeTextS =  FunctionUtf.fromUtf8(path+">"+saveBackCommand);
            activeText.setString(countingEnter+activeTextS);
            command = saveBackCommand;
            cursor.rectMove();    
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if(cmdPointer < cmdSaver.size()-1 && cmdSaver.size()>0) {
            ++cmdPointer;
            activeTextS =  FunctionUtf.fromUtf8(path+">"+cmdSaver[cmdPointer]);
            activeText.setString(countingEnter+activeTextS);
            command = cmdSaver[cmdPointer];
            cursor.rectMove();
        } else {
            cmdPointer = cmdSaver.size();
            activeTextS =  FunctionUtf.fromUtf8(path+">"+saveBackCommand);
            activeText.setString(countingEnter+activeTextS);
            command = saveBackCommand;
            cursor.rectMove();    
        }
    }
}