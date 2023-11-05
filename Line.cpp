#include "Line.h"

Line::Line() {
    drawing = false;
    shape = sf::VertexArray(sf::Lines, 2);
    shape[0].color = sf::Color::Red;
    shape[1].color = sf::Color::Red;
}

void Line::startDrawing(sf::Vector2f position) {
    drawing = true;
    shape[0].position = position;
    shape[1].position = position;
}

void Line::updateLine(sf::Vector2f position) {
    if (drawing) {
        shape[1].position = position;
    }
}

void Line::endDrawing() {
    drawing = false;
}

void Line::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}
