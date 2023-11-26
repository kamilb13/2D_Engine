//
// Created by kayman on 21.11.23.
//

#ifndef INC_2D_ENGINE_MENU_H
#define INC_2D_ENGINE_MENU_H


#include <SFML/Graphics.hpp>

class Menu {
private:
    int choice;

public:
    Menu();
    void menuHandler(sf::Event event);
    int getChoice();
};


#endif //INC_2D_ENGINE_MENU_H
