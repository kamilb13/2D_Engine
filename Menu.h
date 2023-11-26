//
// Created by kayman on 21.11.23.
//
/**
 * @file Menu.h
 * @brief Plik naglowkowy zawierajacy definicje klasy Menu
 */

#ifndef INC_2D_ENGINE_MENU_H
#define INC_2D_ENGINE_MENU_H


#include <SFML/Graphics.hpp>

/**
 * @class Menu
 * @brief Klasa odpowiedzialna za obsluge menu w silniku
 */

class Menu {
private:
    int choice;


public:
    /**
* @brief Konstruktor Menu
*/
    Menu();

    /**
* @brief Funkcja menuHandler
* Funkcja nasluchujaca zdarzenia
* @param event Zdarzenie
* @return Funkcja nic nie zwraca
*/
    void menuHandler(sf::Event event);

    /**
* @brief Funkcja getChoice
* Funkcja zwracajaca wybor opcji
* @return Funkcja zwraca wartosc typu int
*/
    int getChoice();
};


#endif //INC_2D_ENGINE_MENU_H
