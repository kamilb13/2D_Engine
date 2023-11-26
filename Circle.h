//
// Created by kayman on 21.11.23.
//
/**
 * @file Circle.h
 * @brief Plik naglowkowy zawierajacy definicje klasy Circle
 */

#ifndef INC_2D_ENGINE_CIRCLE_H
#define INC_2D_ENGINE_CIRCLE_H

#include <SFML/Graphics.hpp>


/**
 * @class Circle
 * @brief Klasa opisujaca kolo
 */

class Circle {
private:
    sf::CircleShape circleShape;
    bool drawing;

public:
    /**
* @brief Konstruktor Circle
*/

    Circle();

    /**
* @brief Funkcja startDrawing
 * Funkcja definiujaca poczatkowy punkt z ktorego rysowane jest kolo
* @param x wspolrzedna X na ukladzie
* @param y wspolrzedna Y na ukladzie
 * @return Funkcja nic nie zwraca
*/
    void startDrawing(float x, float y);

    /**
* @brief Funkcja updateCircle
 * Funkcja definiujaca wymiary kola
* @param r Promien kola
* @param window Okno w ktorym rysujemy kolo
 * @return Funkcja nic nie zwraca
*/
    void updateCircle(float r, sf::RenderWindow& window);

    /**
* @brief Funkcja endDrawing
* Funkcja konczaca edycje kola
* @return Funkcja nic nie zwraca
*/
    void endDrawing();

    /**
* @brief Funkcja draw
* Funkcja rysujaca kolo
* @param window Okno w ktorym ma byc narysowane kolo
* @return Funkcja nic nie zwraca
*/
    void draw(sf::RenderWindow& window);

    /**
* @brief Funkcja getCircleShape
* Funkcja zwraca obiekt reprezentujacy ksztalt kola
* @return Funkcja zwraca obiekt klasy sf::CircleShape
*/
    sf::CircleShape getCircleShape();
};


#endif //INC_2D_ENGINE_CIRCLE_H
