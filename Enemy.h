#ifndef INC_2D_ENGINE_ENEMY_H
#define INC_2D_ENGINE_ENEMY_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Enemy {
private:
    sf::RectangleShape enemy;
    sf::Color color;
    int width;
    int height;
    bool enabled;
public:
    Enemy(sf::RectangleShape enemy, sf::Color color, int width, int height, bool enabled);
    void init(int x, int y);
    void shoot();
};

#endif //INC_2D_ENGINE_ENEMY_H
