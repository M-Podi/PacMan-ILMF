
#pragma once
#ifndef OOP_TEXTBOX_H
#define OOP_TEXTBOX_H
#include<iostream>
#include<SFML/Graphics.hpp>
#include<sstream>
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
public:
    Textbox(){}
    Textbox(int size,sf::Color color, bool sel){
        setCharacterSize(size);
        limit=60;
        setColor(color);
        isSelected=sel;
        textbox.setCharacterSize(size);
        textbox.setFillColor(color);
        if(sel){
            textbox.setString("_");
        }
        else
            textbox.setString("");
    }
    void setFont(sf::Font &font){
        textbox.setFont(font);
    }
    void setPosition(sf::Vector2f pos){
        textbox.setPosition(pos);
    }
    void setLimit(bool ToF){
        hasLimit=ToF;
    }
    void setLimit(bool ToF, int lim){
        hasLimit = ToF;
        limit =lim;
    }
    void setSelected(bool sel){
        isSelected=sel;
        if(!sel) {
            std::string t=text.str();
            std::string newT="";
            for(unsigned long i = 0;i<t.length()-1;i++){
                newT+=t[i];
            }
            textbox.setString(newT);
        }
    }
    std::string getText(){
        return text.str();
    }
    void drawTo(sf::RenderWindow &window){
        window.draw(textbox);
    }
    void setCharacterSize(int size){
        textbox.setCharacterSize(size);
    }
    void setColor(sf::Color color){
        textbox.setFillColor(color);
    }
    void typedOn(sf::Event input){
        if(isSelected){
            int charTyped=input.text.unicode;
            if(charTyped<128){
                if(hasLimit){
                    if(text.str().length()<=limit){
                        inputLogic(charTyped);
                    }
                    else if(text.str().length()>limit&&charTyped==DELETE_KEY)
                        deleteLastChar();
                }
                else
                    inputLogic(charTyped);
            }
        }
    }
private:
    sf::Text textbox;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    unsigned long limit;
    void inputLogic(int charTyped){
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
    void deleteLastChar(){
        std::string t=text.str();
        std::string newT="";
        for(unsigned long i = 0;i<t.length()-1;i++){
            newT+=t[i];
        }
        text.str("");
        text<<newT;
        textbox.setString(text.str());
    }
};


#endif //OOP_TEXTBOX_H
