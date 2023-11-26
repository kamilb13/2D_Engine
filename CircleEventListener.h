//
// Created by kayman on 21.11.23.
//
/**
 * @file CircleEventListener.h
 * @brief Plik naglowkowy zawierajacy definicje klasy CircleEventListener
 */
#ifndef INC_2D_ENGINE_CIRCLEEVENTLISTENER_H
#define INC_2D_ENGINE_CIRCLEEVENTLISTENER_H
#include <SFML/Graphics.hpp>
#include "Circle.h"
#include <cmath>
#include "iostream"

/**
 * @class CircleEventListener
 * @brief Klasa, ktora nasluchuje zdarzen dla klasy Circle
 */
class CircleEventListener {
private:
    Circle *circle;
    sf::RenderWindow *window;
    std::vector<Circle> *circles;
    bool drawing;

public:

    /**
* @brief Konstruktor CircleEventListener
* @param circle Aktualnie rysowane kolo
* @param window Okno w ktorym rysujemy
* @param rectangles Wektor do ktorego zapisujemy kola
*/
    CircleEventListener(Circle *circle, sf::RenderWindow *window, std::vector<Circle> *circles);

    /**
* @brief Funkcja eventHandler
 * Funkcja czekajaca na zdarzenie zwiazene z rysowaniem kol
* @param event Zdarzenie ktore mialo miejsce w glownym oknie gry
 * @return Funkcja nic nie zwraca
*/
    void eventHandler(sf::Event event);
};


#endif //INC_2D_ENGINE_CIRCLEEVENTLISTENER_H
