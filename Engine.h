#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include "Line.h"
#include "Rectangle.h"

class Engine {
private:
    sf::RenderWindow window;
    sf::RectangleShape rect;

    Line line;
    std::vector<Line> lines;

    Rectangle rectangle_c;
    std::vector<Rectangle> rectangles;

    void exit();

public:
    sf::RectangleShape rectangle(sf::Color color, int width, int height, int x, int y);
    void game();
    void set_fps(int fps);
    void sfml_init(bool fullscreen, int width, int height);

};

#endif //ENGINE_H