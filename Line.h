#ifndef LINE_H
#define LINE_H

#include <SFML/Graphics.hpp>

class Line {
private:
    sf::VertexArray shape;
    bool drawing;
public:
    Line();
    void startDrawing(sf::Vector2f position);
    void updateLine(sf::Vector2f position);
    void endDrawing();
    void draw(sf::RenderWindow& window) const;

};

#endif //LINE_H
