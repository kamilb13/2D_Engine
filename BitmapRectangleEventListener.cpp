//
// Created by kamil on 24.11.2023.
//

#include "BitmapRectangleEventListener.h"

BitmapRectangleEventListener::BitmapRectangleEventListener(BitmapRectangle* bitmapRectangle, sf::RenderWindow* window, std::vector<BitmapRectangle>* bitmapRectangles) {
    this->bitmapRectangle = bitmapRectangle;
    this->window = window;
    this->bitmapRectangles = bitmapRectangles;
}

void BitmapRectangleEventListener::eventHandler() { //event
    //if (event.type == sf::Event::MouseButtonPressed) {d
        //if (event.mouseButton.button == sf::Mouse::Right) {
            //sf::Vector2f mousePosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    bitmapRectangle->startDrawing(sf::Vector2f(500, 100));
    bitmapRectangles->push_back(*bitmapRectangle);
    bitmapRectangle->startDrawing(sf::Vector2f(400, 150));
    bitmapRectangles->push_back(*bitmapRectangle);
    bitmapRectangle->startDrawing(sf::Vector2f(300, 100));
    bitmapRectangles->push_back(*bitmapRectangle);
    bitmapRectangle->startDrawing(sf::Vector2f(200, 100));
    bitmapRectangles->push_back(*bitmapRectangle);
        //}
    //} else if (event.type == sf::Event::MouseMoved) {
        //sf::Vector2f mousePosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
        //bitmapRectangle->updateRectangle(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
   // } else if (event.type == sf::Event::MouseButtonReleased) {
        //if (event.mouseButton.button == sf::Mouse::Right) {
           //bitmapRectangle->endDrawing();

        //}
    //}
}
