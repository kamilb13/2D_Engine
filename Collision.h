#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "BitmapRectangle.h"

class Collision {
public:
    Collision(std::vector<BitmapRectangle>* bitmapRectangles, float bulletSpeed);
    Collision(std::vector<sf::RectangleShape>* rectangleShape, float bulletSpeed);
    void checkBulletCollisions(std::vector<sf::RectangleShape>& bullets);

private:
    float bulletSpeed;
    std::vector<BitmapRectangle>* bitmapRectangles;
    std::vector<BitmapRectangle>* rectangleShape;

};

#endif // COLLISION_MANAGER_H
