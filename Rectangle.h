<<<<<<< HEAD
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
};


#endif //RECTANGLE_H
=======
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
};


#endif //RECTANGLE_H
>>>>>>> d7ebeb8896b7f9c2027c8f51b06c18e162652817
