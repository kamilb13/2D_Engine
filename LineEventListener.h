
//
// Created by Komputer on 22.11.2023.
//

#ifndef LINEEVENTLISTENER_H
#define LINEEVENTLISTENER_H


#include "Line.h"

class LineEventListener {
private:


    Line *line;
    sf::RenderWindow *window;
    std::vector<Line> *lines;
    bool drawing;

public:
    LineEventListener(Line *line, sf::RenderWindow *window, std::vector<Line> *lines);
    void eventHandler(sf::Event event);
    Line getLine();

};

#endif

