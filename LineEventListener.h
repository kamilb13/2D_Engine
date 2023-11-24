<<<<<<< HEAD
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
    std::vector<Line> *lines;
    bool drawing;

public:
    LineEventListener(Line *line, sf::RenderWindow *window, std::vector<Line> *lines);
    void eventHandler(sf::Event event);
    Line getLine();

};


#endif //INC_2D_ENGINE_LINEEVENTLISTENER_H
=======
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
    std::vector<Line> *lines;
    bool drawing;

public:
    LineEventListener(Line *line, sf::RenderWindow *window, std::vector<Line> *lines);
    void eventHandler(sf::Event event);
    Line getLine();

};


#endif //INC_2D_ENGINE_LINEEVENTLISTENER_H
>>>>>>> d7ebeb8896b7f9c2027c8f51b06c18e162652817
