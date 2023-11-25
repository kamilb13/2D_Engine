#include <iostream>
#include "BitmapRectangle.h"

BitmapRectangle::BitmapRectangle() : drawing(false) {
    // Ustawienie koloru prostokąta na przezroczysty
    shape = sf::VertexArray(sf::Quads, 4);
    shape[0].color = sf::Color::Transparent;
    shape[1].color = sf::Color::Transparent;
    shape[2].color = sf::Color::Transparent;
    shape[3].color = sf::Color::Transparent;

    // Wczytanie tekstury z pliku PNG
    if (!texture.loadFromFile(R"(C:\Users\kamil\Desktop\Space-Invaders\graphics\my_ufo.png)")) {
        std::cerr << "Nie udało się wczytać pliku tekstury." << std::endl;
    }

    // Utworzenie sprite'a i ustawienie tekstury
    sprite.setTexture(texture);
}

void BitmapRectangle::startDrawing(sf::Vector2f position) {
    drawing = true;
    shape[0].position = position;
    shape[1].position = position;
    shape[2].position = position;
    shape[3].position = position;

    // Ustawienie pozycji sprite'a
    sprite.setPosition(position);
}

void BitmapRectangle::updateRectangle(sf::Vector2f position) {
    if (drawing) {
        shape[1].position = sf::Vector2f(shape[0].position.x, position.y);
        shape[2].position = position;
        shape[3].position = sf::Vector2f(position.x, shape[0].position.y);

        // Aktualizacja pozycji sprite'a
        sprite.setPosition(shape[0].position);
    }
}

void BitmapRectangle::endDrawing() {
    drawing = false;
}

void BitmapRectangle::draw(sf::RenderWindow& window) const {
    window.draw(shape);
    window.draw(sprite);  // Rysuj sprite'a z teksturą
}

sf::FloatRect BitmapRectangle::getGlobalBounds() const {
    // Zwróć globalne ograniczenia sprite'a
    return sprite.getGlobalBounds();
}
