//
// Created by kamil on 24.11.2023.
//

#include "BitmapRectangleEventListener.h"

BitmapRectangleEventListener::BitmapRectangleEventListener(BitmapRectangle* bitmapRectangle, sf::RenderWindow* window, std::vector<BitmapRectangle>* bitmapRectangles) {
    this->bitmapRectangle = bitmapRectangle;
    this->window = window;
    this->bitmapRectangles = bitmapRectangles;
}

void BitmapRectangleEventListener::eventHandler(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Right) {
            //sf::Vector2f mousePosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
            bitmapRectangle->startDrawing(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
        }
    } else if (event.type == sf::Event::MouseMoved) {
        //sf::Vector2f mousePosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
        bitmapRectangle->updateRectangle(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
    } else if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Right) {
            bitmapRectangle->endDrawing();
            bitmapRectangles->push_back(*bitmapRectangle);
        }
    }
}
