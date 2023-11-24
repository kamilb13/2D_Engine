
#include "Rectangle.h"

Rectangle::Rectangle(){
    drawing = false;
    shape = sf::VertexArray(sf::Quads, 4);
    shape[0].color = sf::Color::Yellow;
    shape[1].color = sf::Color::Yellow;
    shape[2].color = sf::Color::Yellow;
    shape[3].color = sf::Color::Yellow;
}

void Rectangle::startDrawing(sf::Vector2f position) {
    drawing = true;
    shape[0].position = position;
    shape[1].position = position;
    shape[2].position = position;
    shape[3].position = position;
}

void Rectangle::updateRectangle(sf::Vector2f position) {
    if (drawing) {
        shape[1].position = sf::Vector2f(shape[0].position.x, position.y);
        shape[2].position = position;
        shape[3].position = sf::Vector2f(position.x, shape[0].position.y);
    }
}

void Rectangle::endDrawing() {
    drawing = false;
}

void Rectangle::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::VertexArray Rectangle::getShape() {
    return this->shape;
}
