#ifndef INC_2D_ENGINE_BULLET_H
#define INC_2D_ENGINE_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
private:
    sf::RectangleShape bullet;
    sf::Color color;
    float x;
    float y;
    int width;
    int height;
    float speed;
public:
    Bullet(sf::RectangleShape bullet, sf::Color color, float x, float y, int width, int height, float speed);
    void init();
    void updateBullet();

};


#endif //INC_2D_ENGINE_BULLET_H
