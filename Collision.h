/**
 * @file Collision.h
 * @brief Plik naglowkowy zawierajacy definicje klasy Collision
 */

#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "BitmapRectangle.h"
/**
 * @class Collision
 * @brief Klasa wykrywajaca kolizje
 */
class Collision {
public:
    /**
* @brief Konstruktor Collision
     * @param bitmapRectangles Wektor z obiektami dla ktorych chcemy wykryc kolizje
     * @param bulletSpeed Predkosc pocisku
*/
    Collision(std::vector<BitmapRectangle>* bitmapRectangles, float bulletSpeed);

    /**
* @brief Konstruktor Collision
 * @param bitmapRectangles Wektor z obiektami dla ktorych chcemy wykryc kolizje
 * @param bulletSpeed Predkosc pocisku
*/
    Collision(std::vector<sf::RectangleShape>* rectangleShape, float bulletSpeed);

    /**
* @brief Funkcja checkBulletCollisions
 * @param bullets Pociski dla ktorych chcemy wykryc kolizje
*/
    void checkBulletCollisions(std::vector<sf::RectangleShape>& bullets);

private:
    float bulletSpeed;
    std::vector<BitmapRectangle>* bitmapRectangles;
    std::vector<BitmapRectangle>* rectangleShape;

};

#endif // COLLISION_MANAGER_H
