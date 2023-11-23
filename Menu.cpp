//
// Created by kayman on 21.11.23.
//

#include "Menu.h"

Menu::Menu(){
    this->choice = 1;
}

void Menu::menuHandler(sf::Event event) {
    if (event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Num0){
            this->choice = 0;
        }else if(event.key.code == sf::Keyboard::Num1){
            this->choice = 1;
        } else if (event.key.code == sf::Keyboard::Num2){
            this->choice = 2;
        }
    }
}

int Menu::getChoice(){
    return this->choice;
}

