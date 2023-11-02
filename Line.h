#pragma once
#include <SFML/Graphics.hpp>

class Line {
public:
    Line();
    void rozpocznijRysowanie(sf::Vector2f pozycja);
    void aktualizujLinie(sf::Vector2f pozycja);
    void zakonczRysowanie();
    void rysuj(sf::RenderWindow& window) const;

private:
    bool drawing;
    sf::VertexArray shape;
};
