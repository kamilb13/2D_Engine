/**
 * @file Rectangle.h
 * @brief Plik naglowkowy zawierajacy definicje klasy Rectangle
 */


#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
/**
 * @class Rectangle
 * @brief Klasa opisujaca prostokat
 */
class Rectangle {
private:
    sf::VertexArray shape;
    bool drawing;
public:
    /**
* @brief Konstruktor Rectangle
*/
    Rectangle();

    /**
* @brief Funkcja startDrawing
* Funkcja definiujaca poczatkowy punkt z ktorego rysowany jest prostokat
* @param position Punkt poczatkowy
* @return Funkcja nic nie zwraca
*/
    void startDrawing(sf::Vector2f position);

    /**
* @brief Funkcja updateRectangle
* Funkcja definiujaca koncowy punkt prostokata oraz jego wymiary
* @param position Punkt koncowy
* @return Funkcja nic nie zwraca
*/
    void updateRectangle(sf::Vector2f position);

    /**
* @brief Funkcja endDrawing
* Funkcja konczaca edycje prostokata
* @return Funkcja nic nie zwraca
*/
    void endDrawing();

    /**
* @brief Funkcja draw
* Funkcja rysujaca prostokat
* @param window Okno w ktorym ma byc narysowany prostokat
* @return Funkcja nic nie zwraca
*/
    void draw(sf::RenderWindow& window) const;

    /**
* @brief Funkcja getShape
* Funkcja zwracajaca granice prostokata
* @return Funkcja zwraca obiekt typu sf::FloatRect
*/
    sf::VertexArray getShape();

    /**
* @brief Funkcja getGlobalBounds
* Funkcja zwracajaca granice prostokata
* @return Funkcja zwraca obiekt typu sf::FloatRect
*/
    sf::FloatRect getGlobalBounds() const;
};


#endif //RECTANGLE_H
