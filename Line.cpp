#include "Line.h"

Line::Line() {
    drawing = false;
    shape = sf::VertexArray(sf::Lines, 2);
    shape[0].color = sf::Color::Red;
    shape[1].color = sf::Color::Red;
}

void Line::rozpocznijRysowanie(sf::Vector2f pozycja) {
    drawing = true;
    shape[0].position = pozycja;
    shape[1].position = pozycja;
}

void Line::aktualizujLinie(sf::Vector2f pozycja) {
    if (drawing) {
        shape[1].position = pozycja;
    }
}

void Line::zakonczRysowanie() {
    drawing = false;
}

void Line::rysuj(sf::RenderWindow& window) const {
    window.draw(shape);
}
