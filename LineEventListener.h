//
// Created by Komputer on 22.11.2023.
//
/**
 * @file LineEventListener.h
 * @brief Plik naglowkowy zawierajacy definicje klasy LineEventListener
 */

#ifndef INC_2D_ENGINE_LINEEVENTLISTENER_H
#define INC_2D_ENGINE_LINEEVENTLISTENER_H


#include "Line.h"
/**
 * @class LineEventListener
 * @brief Klasa, ktora nasluchuje zdarzen dla klasy Line
 */
class LineEventListener {
private:


    Line *line;
    sf::RenderWindow *window;
    std::vector<Line> *lines;
    bool drawing;

public:
    /**
* @brief Konstruktor LineEventListener
* @param *line Aktualnie rysowana linia
* @param *window Okno w ktorym rysujemy
* @param *lines Wektor do ktorego zapisujemy linie
*/
    LineEventListener(Line *line, sf::RenderWindow *window, std::vector<Line> *lines);

    /**
* @brief Funkcja eventHandler
* Funkcja czekajaca na zdarzenie zwiazene z rysowaniem lini
* @param event Zdarzenie ktore mialo miejsce w glownym oknie gry
* @return Funkcja nic nie zwraca
*/
    void eventHandler(sf::Event event);

    /**
* @brief Funkcja getLine
* @return Funkcja zwraca obiekt klasy Line
*/
    Line getLine();

};


#endif //INC_2D_ENGINE_LINEEVENTLISTENER_H
