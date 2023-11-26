//
// Created by kamil on 26.11.2023.
//
/**
 * @file Enemy.h
 * @brief Plik naglowkowy zawierajacy definicje klasy Rectangle
 */

#ifndef INC_2D_ENGINE_ENEMY_H
#define INC_2D_ENGINE_ENEMY_H


#include <SFML/Graphics.hpp>
#include "Player.h"

/**
 * @class Enemy
 * @brief Klasa opisujaca wroga
 */


class Enemy {
private:
    sf::RectangleShape enemy;
    sf::Color color;
    int width;
    int height;
    bool enabled;
    sf::Clock shootClock;
    float shootCooldown = 1.0f;
    float bulletSpeed = 3.0f;
    sf::Texture enemyTexture;

    std::vector<sf::RectangleShape> bullets;
    std::vector<sf::RectangleShape> enemies;

public:
/**
* @brief Konstruktor Rectangle
 * @param color Kolor wroga
 * @param width Szerokosc w pixelach
 * @param height Wysokosc w pixelach'
 * @param enabled Parametr decydujacy o widocznosci wroga
*/
    Enemy(sf::Color color, int width, int height, bool enabled);

    /**
* @brief Funkcja init
     * Funkcja inicjujaca pola wroga
 * @param x Polozenie na osi X
 * @param y Polozenie na osi Y
 * @return Funkcja nic nie zwraca
*/
    void init(int x, int y);

    /**
* @brief Funkcja shoot
* Funkcja odpowiadajaca za wystrzelenie pocisku
* @return Funkcja nic nie zwraca
*/
    void shoot();

    /**
* @brief Funkcja draw
* Funkcja odpowiadajaca za rysowanie wroga
     * @param window Okno w ktorym ma byc narysowany wrog
* @return Funkcja nic nie zwraca
*/
    void draw(sf::RenderWindow &window);

    /**
* @brief Funkcja updateBullets
* Funkcja odpowiadajaca za ruch pocisku i wykrywanie kolizji
 * @param window Okno w ktorym ma byc narysowany pocisk
 * @param player Obiekt klasy Player z ktorym badana jest kolizja
* @return Funkcja nic nie zwraca
*/
    void updateBullets(sf::RenderWindow &window, Player player);

    /**
* @brief Funkcja getEnemies
* Funkcja zwracajaca wektor wrogow=
* @return Funkcja zwraca std::vector<sf::RectangleShape>
*/
    std::vector<sf::RectangleShape> getEnemies();
    sf::Sprite sprite;
    /**
* @brief Funkcja getGlobalBounds
* Funkcja zwracajaca granice wroga
* @return Funkcja zwraca obiekt typu sf::FloatRect
*/
    sf::FloatRect getGlobalBounds() const;

    /**
* @brief Funkcja getGlobalBounds
* Funkcja zwracajaca granice wroga
* @return Funkcja zwraca obiekt typu sf::RectangleShape
*/
    sf::RectangleShape getGlobalBounds();
};

#endif //INC_2D_ENGINE_ENEMY_H
