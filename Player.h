#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>

class Player {
private:

    float speed;
    float width, height;
    int pos_x, pos_y;

public:

    sf::RectangleShape* rect;

    Player(float width, float height, int pos_x, int pox_y, float speed);

    void moveUp(float offset);
    void moveDown(float offset);
    void moveLeft(float offset);
    void moveRight(float offset);

    void drawPlayer(sf::RenderWindow* window);

    float getSpeed();




};