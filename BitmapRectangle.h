//
// Created by kamil on 24.11.2023.
//
/**
 * @file BitmapRectangle.h
 * @brief Plik naglowkowy zawierajacy definicje klasy BitmapRectangle
 */

#ifndef INC_2D_ENGINE_BITMAPRECTANGLE_H
#define INC_2D_ENGINE_BITMAPRECTANGLE_H


#include <SFML/Graphics.hpp>
#include <iostream>
/**
 * @class BitmapRectangle
 * @brief Klasa opisujaca BitmapRectangle
 */
class BitmapRectangle {
public:
    /**
* @brief Konstruktor BitmapRectangle
*/
    BitmapRectangle(); //std::string pathOfEnemy

    /**
* @brief Funkcja startDrawing
* Funkcja definiujaca polozenie BitmapRectangle
* @param position Polozenie bitmapy
* @return Funkcja nic nie zwraca
*/
    void startDrawing(sf::Vector2f position);
    /**
* @brief Funkcja updateRectangle
* Funkcja aktualizujaca polozenie BitmapRectangle
* @param position Nowa pozycja
* @return Funkcja nic nie zwraca
*/
    void updateRectangle(sf::Vector2f position);

    /**
* @brief Funkcja endDrawing
* Funkcja konczaca rysowanie bitmapy
* @return Funkcja nic nie zwraca
*/
    void endDrawing();

    /**
* @brief Funkcja draw
* Funkcja rysujaca BitmapRectangle
     * @param window Okno w ktorym chcemy rysowac
* @return Funkcja nic nie zwraca
*/
    void draw(sf::RenderWindow& window) const;
    /**
* @brief Funkcja getGlobalBounds
* Funkcja zwracajaca granice wroga
* @return Funkcja zwraca obiekt typu sf::FloatRect
*/
    sf::FloatRect getGlobalBounds() const;
    sf::Clock shootClock;
    float shootCooldown = 2.0f;
    /**
* @brief Funkcja shoot
* Funkcja odpowiadajaca za wystrzelenie pocisku
* @return Funkcja nic nie zwraca
*/
    void shoot();
    /**
* @brief Funkcja updateBullets
* Funkcja odpowiadajaca za ruch pocisku i wykrywanie kolizji
* @param window Okno w ktorym ma byc narysowany pocisk
* @param playerBounds Obiekt przedstawiajacy granice gracza
* @return Funkcja nic nie zwraca
*/
    void updateBullets(sf::RenderWindow &window, sf::RectangleShape playerBounds );
    float bulletSpeed = 3.0f;

    // Dodaj funkcję do ładowania bitmapy
    /**
* @brief Funkcja loadBitmap
* Funkcja ladujaca bitmape z dysku
* @param imagePath Sciezka do bitmapy
* @return Funkcja nic nie zwraca
*/
    void loadBitmap(const std::string& imagePath);

private:
    bool drawing;
    sf::VertexArray shape;
    sf::Sprite sprite;  // Dodaj sprite dla bitmapy

    sf::RectangleShape bitmapNew;
    sf::Texture texture;
    std::vector<sf::RectangleShape> bullets;


};

#endif //INC_2D_ENGINE_BITMAPRECTANGLE_H