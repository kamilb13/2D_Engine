//
// Created by kamil on 23.11.2023.
//

#ifndef INC_2D_ENGINE_PLAYER_H
#define INC_2D_ENGINE_PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Rectangle.h"
#include "BitmapRectangle.h"
#include "Collision.h"

class Player {
public:
    //Player(std::vector<Rectangle> *vectorRectangle, sf::RenderWindow &window);
    //Player(std::vector<BitmapRectangle> *bitmapRectangle, sf::RenderWindow &window);
    Player(float bulletSpeed, Collision &collisionManager, sf::RenderWindow &window);

    void handleInput();
    void update();
    void draw();

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

};

#endif //INC_2D_ENGINE_PLAYER_H
