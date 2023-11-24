
//
// Created by kayman on 21.11.23.
//

#ifndef MENU_H
#define MENU_H


#include <SFML/Graphics.hpp>

class Menu {
private:
    int choice;


public:
    Menu();
    void menuHandler(sf::Event event);
    int getChoice();
};

#endif MENU_H

