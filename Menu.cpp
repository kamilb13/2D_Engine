//
// Created by kayman on 21.11.23.
//

#include "Menu.h"

Menu::Menu(){
    this->choice = 1;
}

void Menu::menuHandler(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        switch(event.key.code){
            case sf::Keyboard::Num1:
                this->choice = 1;
                break;
            case sf::Keyboard::Num2:
                this->choice = 2;
                break;
            case sf::Keyboard::Num3:
                this->choice = 3;
                break;
            case sf::Keyboard::Enter:
                this->choice = 4;
                break;
        }
    }
}

int Menu::getChoice(){
    return this->choice;
}

