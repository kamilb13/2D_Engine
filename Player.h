//
// Created by kamil on 23.11.2023.
//
/**
 * @file Player.h
 * @brief Plik naglowkowy zawierajacy definicje klasy Player
 */
#ifndef INC_2D_ENGINE_PLAYER_H
#define INC_2D_ENGINE_PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Rectangle.h"
#include "BitmapRectangle.h"
#include "Collision.h"
/**
 * @class Player
 * @brief Klasa opisujaca obiekt gracza
 */
class Player {
public:
    //Player(std::vector<Rectangle> *vectorRectangle, sf::RenderWindow &window);
    //Player(std::vector<BitmapRectangle> *bitmapRectangle, sf::RenderWindow &window);

    /**
* @brief Konstruktor Player
* @param bulletSpeed Wartosc opisujaca szybkosc pocisku
* @param collisionManager Parametr typu Collision wykrywajacy kolizje
* @param window okno w ktorym rysowany jest Player
*/
    Player(float bulletSpeed, Collision &collisionManager, sf::RenderWindow &window);

    /**
* @brief Funkcja handleInput
* Funkcja odpowiedzialna za ruchy
* @return Funkcja nic nie zwraca
*/
    void handleInput();

    /**
* @brief Funkcja update
* Funkcja odpowiedzialna za poruszanie sie pocisku i sprawdzanie kolizji
* @return Funkcja nic nie zwraca
*/
    void update();

    /**
* @brief Funkcja draw
* Funkcja rysujaca gracza
* @return Funkcja nic nie zwraca
*/
    void draw();

    /**
* @brief Funkcja getGlobalBounds
* Funkcja zwracajaca granice gracza
* @return Funkcja zwraca obiekt typu sf::RectangleShape
*/
    sf::RectangleShape getGlobalBounds();
private:
    sf::RenderWindow& window;
    sf::RectangleShape playerShape;
    float movementSpeed = 5.0f;

    sf::Clock shootClock;
    float shootCooldown = 0.5f;
    float bulletSpeed = 10.0f;

    std::vector<sf::RectangleShape> bullets;
    std::vector<Rectangle>* vectorRectangles;
    std::vector<BitmapRectangle>* bitmapRectangles;

    Collision& collisionManager;

    sf::Texture playerTexture;


};

#endif //INC_2D_ENGINE_PLAYER_H
