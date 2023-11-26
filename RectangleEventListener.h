//
// Created by kayman on 06.11.23.
//

/**
 * @file RectangleEventListener.h
 * @brief Plik naglowkowy zawierajacy definicje klasy RectangleEventListener
 */
#include "Rectangle.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef INC_2D_ENGINE_RECTANGLEEVENTLISTENER_H
#define INC_2D_ENGINE_RECTANGLEEVENTLISTENER_H

/**
 * @class RectangleEventListener
 * @brief Klasa, ktora nasluchuje zdarzen dla klasy Rectangle
 */
class RectangleEventListener {
private:
    Rectangle *rectangle;
    sf::RenderWindow *window;
    std::vector<Rectangle> *rectangles;
    bool drawing;

public:
    /**
* @brief Konstruktor RectangleEventListener
* @param *rectangle Aktualnie rysowany prostokat
* @param *window Okno w ktorym rysujemy
* @param *rectangles Wektor do ktorego zapisujemy prostokaty
*/
    RectangleEventListener(Rectangle *rectangle, sf::RenderWindow *window,  std::vector<Rectangle> *rectangles);
    /**
* @brief Funkcja eventHandler
 * Funkcja czekajaca na zdarzenie zwiazene z rysowaniem prostokata
* @param event Zdarzenie ktore mialo miejsce w glownym oknie gry
 * @return Funkcja nic nie zwraca
*/
    void eventHandler(sf::Event event);
};


#endif //INC_2D_ENGINE_RECTANGLEEVENTLISTENER_H
