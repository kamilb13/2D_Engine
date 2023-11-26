//
// Created by kayman on 21.11.23.
//

#include "Circle.h"

Circle::Circle(){
    drawing = false;
    circleShape.setFillColor(sf::Color::White);
}

void Circle::startDrawing(float x, float y) {
    drawing = true;
    circleShape.setPosition(x, y);
}

void Circle::updateCircle(float r, sf::RenderWindow& window) {
    if (drawing) {
        circleShape.setRadius(r);
        window.draw(circleShape);
    }
}

void Circle::endDrawing() {
    drawing = false;
}

void Circle::draw(sf::RenderWindow& window){
    window.draw(circleShape);
}

sf::CircleShape Circle::getCircleShape() {
    return this->circleShape;
}
