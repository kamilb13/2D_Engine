#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>

class Rectangle {
private:
    sf::VertexArray shape;
    bool drawing;
public:
    Rectangle();
    void startDrawing(sf::Vector2f position);
    void updateRectangle(sf::Vector2f position);
    void endDrawing();
    void draw(sf::RenderWindow& window) const;

    sf::VertexArray getShape();

    sf::FloatRect getGlobalBounds() const;
};


#endif //RECTANGLE_H
