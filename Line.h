/**
 * @file Line.h
 * @brief Plik naglowkowy zawierajacy definicje klasy Line
 */

#ifndef LINE_H
#define LINE_H

#include <SFML/Graphics.hpp>
/**
 * @class Line
 * @brief Klasa opisujaca linie
 */
class Line {
private:
    sf::VertexArray shape;
    bool drawing;
public:
    /**
* @brief Konstruktor Line
*/
    Line();

    /**
* @brief Funkcja startDrawing
 * Funkcja definiujaca poczatkowy punkt z ktorego rysowany jest linia
* @param position Punkt poczatkowy
 * @return Funkcja nic nie zwraca
*/
    void startDrawing(sf::Vector2f position);

    /**
* @brief Funkcja updateLine
 * Funkcja definiujaca koncowy punkt lini oraz jego
* @param position Punkt koncowy
 * @return Funkcja nic nie zwraca
*/
    void updateLine(sf::Vector2f position);

    /**
* @brief Funkcja endDrawing
* Funkcja konczaca edycje lini
* @return Funkcja nic nie zwraca
*/
    void endDrawing();

    /**
* @brief Funkcja draw
* Funkcja rysujaca linie
* @param window Okno w ktorym ma byc narysowana linia
* @return Funkcja nic nie zwraca
*/
    void draw(sf::RenderWindow& window) const;

};

#endif //LINE_H
