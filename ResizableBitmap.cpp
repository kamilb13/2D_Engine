#include <iostream>
#include "ResizableBitmap.h"

//TODO BEZUZYTECZNA KLASA
ResizableBitmap::ResizableBitmap(const std::string& texturePath) : isResizing(false) {
    // Wczytaj teksturę z pliku PNG
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Failed to load texture from file: " << texturePath << std::endl;
    }
    // Ustaw teksturę dla naszej bitmapy
    bitmap.setTexture(&texture);
    // Ustaw początkową wielkość i pozycję bitmapy
    bitmap.setSize(sf::Vector2f(50.f, 50.f));
    bitmap.setPosition(400.f, 100.f);
}

void ResizableBitmap::update() {
    // Tutaj można umieścić kod aktualizujący logikę (jeśli potrzebny)
}

void ResizableBitmap::draw(sf::RenderWindow& window) {
    window.draw(bitmap);
}
