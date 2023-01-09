#include "Textbox.h"
Textbox::Textbox()=default;
Textbox::Textbox(int size,sf::Color color, bool sel,sf::Font &fonts){
    setCharacterSize(size);
    setColor(color);
    isSelected=sel;
    textbox.setCharacterSize(size);
    textbox.setFillColor(color);
    textbox.setFont(fonts);
    if(sel){
        textbox.setString("_");
    }
    else
        textbox.setString("");
}

void Textbox::setPosition(sf::Vector2f pos){
    textbox.setPosition(pos);
}
void Textbox::setLimit(bool ToF){
    hasLimit=ToF;
}
void Textbox::setLimit(bool ToF, int lim){
    hasLimit = ToF;
    limit =lim;
}
//void Textbox::setSelected(bool sel){
//    isSelected=sel;
//    if(!sel) {
//        std::string t=text.str();
//        std::string newT="";
//        for(unsigned long i = 0;i<t.length()-1;i++){
//            newT+=t[i];
//        }
//        textbox.setString(newT);
//    }
//}
std::string Textbox::getText(){
    return text.str();
}
void Textbox::drawTo(sf::RenderWindow &window){
    window.draw(textbox);
}
void Textbox::setCharacterSize(int size){
    textbox.setCharacterSize(size);
}
void Textbox::setColor(sf::Color color){
    textbox.setFillColor(color);
}
void Textbox::typedOn(sf::Event input){
    if(isSelected){
        int charTyped=input.text.unicode;
        if(charTyped<128){
            if(hasLimit){
                if(text.str().length()<=limit){
                    inputLogic(charTyped);
                }
                else if(charTyped==DELETE_KEY)
                    deleteLastChar();
            }
            else
                inputLogic(charTyped);
        }
    }
}
void Textbox::inputLogic(int charTyped){
    if(charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY){
        text<<static_cast<char>(charTyped);
    }
    else if(charTyped == DELETE_KEY){
        if(text.str().length() > 0){
            deleteLastChar();
        }
    }
    textbox.setString(text.str()+"_");
}
void Textbox::deleteLastChar(){
    std::string t=text.str();
    std::string newT="";
    for(unsigned long i = 0;i<t.length()-1;i++){
        newT+=t[i];
    }
    text.str("");
    text<<newT;
    textbox.setString(text.str());
}