#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "BitmapRectangle.h"

class Collision {
public:
    Collision(std::vector<BitmapRectangle>* bitmapRectangles, float bulletSpeed);

    void checkBulletCollisions(std::vector<sf::RectangleShape>& bullets);

private:
    float bulletSpeed;
    std::vector<BitmapRectangle>* bitmapRectangles;

};

#endif // COLLISION_MANAGER_H
