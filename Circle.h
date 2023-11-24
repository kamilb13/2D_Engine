
//
// Created by kayman on 21.11.23.
//

#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>



class Circle {
private:
    sf::CircleShape circleShape;
    bool drawing;

public:
    Circle();

    void startDrawing(float x, float y);
    void updateCircle(float r, sf::RenderWindow& window);
    void endDrawing();
    void draw(sf::RenderWindow& window);
    sf::CircleShape getCircleShape();
};


#endif CIRCLE_H