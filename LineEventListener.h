//
// Created by Komputer on 22.11.2023.
//

#ifndef INC_2D_ENGINE_LINEEVENTLISTENER_H
#define INC_2D_ENGINE_LINEEVENTLISTENER_H


#include "Line.h"

class LineEventListener {
private:
    Line *line;
    sf::RenderWindow *window;
    bool drawing;

public:
    LineEventListener(Line *line, sf::RenderWindow *window);
    void eventHandler(sf::Event event);
    Line getLine();

};


#endif //INC_2D_ENGINE_LINEEVENTLISTENER_H
