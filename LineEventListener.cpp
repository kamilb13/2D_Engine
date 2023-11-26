//
// Created by Komputer on 22.11.2023.
//

#include "LineEventListener.h"

LineEventListener::LineEventListener(Line *line, sf::RenderWindow *window, std::vector<Line> *lines) {
    this->line = line;
    this->window = window;
    this->lines = lines;
}

void LineEventListener::eventHandler(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed){
        if (event.mouseButton.button == sf::Mouse::Left) {
            line->startDrawing(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
        }
    } else if(event.type == sf::Event::MouseMoved){
        line->updateLine(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
    } else if (event.type == sf::Event::MouseButtonReleased){
        if (event.mouseButton.button == sf::Mouse::Left) {
            line->endDrawing();
            lines->push_back(*line);
        }
    }
}

