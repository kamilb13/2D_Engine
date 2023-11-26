/**
 * @file Engine.h
 * @brief Plik naglowkowy zawierajacy definicje klasy Engine
 */

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
#include "Player.h"
#include "BitmapRectangle.h"
#include "Enemy.h"

/**
 * @class Engine
 * @brief Klasa glowna
 */
class Engine {
private:
    sf::RenderWindow window;
    sf::RectangleShape rect;

    sf::Texture texture;
    sf::Sprite background;

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

    /**
    * @brief Funkcja exit
     * Funkcja konczaca wykonywanie sie programu
     * @return Funkcja nic nie zwraca
    */
    void exit();

public:
    /**
* @brief Funkcja game
* Funkcja zawierajaca glowna petle gry
* @return Funkcja nic nie zwraca
*/
    void game();

    /**
* @brief Funkcja set_fps
* Funkcja ustawiajaca ilosc FPS
     * @param fps Ilosc klatek
* @return Funkcja nic nie zwraca
*/
    void set_fps(int fps);

    /**
* @brief Funkcja sfml_init
* Funkcja inicjujaca okno
* @param fullscreen Parametr true/false decydujacy o pelnoekranowosci
     * @param width Szerokosc okna w pixelach
     * @param height Wysokosc okna w pixelach
* @return Funkcja nic nie zwraca
*/
    void sfml_init(bool fullscreen, int width, int height);

};

#endif //ENGINE_H