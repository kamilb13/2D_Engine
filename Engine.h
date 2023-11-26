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
#include "RectangleEventListener.h"
#include "Circle.h"
#include "CircleEventListener.h"
#include "Menu.h"
#include "LineEventListener.h"
#include "BitmapRectangleEventListener.h"

class Engine {
private:
    sf::RenderWindow window;
    sf::RectangleShape rect;

    Line line;
    std::vector<Line> lines;
    LineEventListener *lineEventListener;

    Rectangle rectangle;
    std::vector<Rectangle> rectangles;
    RectangleEventListener *rectangleEventListener;

    Circle circle;
    std::vector<Circle> circles;
    CircleEventListener *circleEventListener;

    BitmapRectangle bitmapRectangle;
    std::vector<BitmapRectangle> bitmapRectangles;
    BitmapRectangleEventListener *bitmapRectangleEventListener;

    Menu *menu;


    void exit();

public:
    sf::RectangleShape drawRectangle(sf::Color color, int width, int height, int x, int y);
    void game();
    void set_fps(int fps);
    void sfml_init(bool fullscreen, int width, int height);

};

#endif //ENGINE_H