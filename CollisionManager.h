//
// Created by kamil on 26.11.2023.
//

#ifndef INC_2D_ENGINE_COLLISIONMANAGER_H
#define INC_2D_ENGINE_COLLISIONMANAGER_H



#include <SFML/Graphics.hpp>

class CollisionManager {
public:
    CollisionManager(sf::RenderWindow& window);

    bool checkBulletPlayerCollision(const sf::RectangleShape& bullet, const sf::RectangleShape& player);
    void handleBulletPlayerCollision();

private:
    sf::RenderWindow& window;
};


#endif //INC_2D_ENGINE_COLLISIONMANAGER_H
