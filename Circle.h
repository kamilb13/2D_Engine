//
// Created by kayman on 21.11.23.
//

#ifndef INC_2D_ENGINE_CIRCLE_H
#define INC_2D_ENGINE_CIRCLE_H

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


#endif //INC_2D_ENGINE_CIRCLE_H