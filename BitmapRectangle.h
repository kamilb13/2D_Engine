//
// Created by kamil on 24.11.2023.
//

#ifndef INC_2D_ENGINE_BITMAPRECTANGLE_H
#define INC_2D_ENGINE_BITMAPRECTANGLE_H


#include <SFML/Graphics.hpp>

class BitmapRectangle {
public:
    BitmapRectangle();
    void startDrawing(sf::Vector2f position);
    void updateRectangle(sf::Vector2f position);
    void endDrawing();
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getGlobalBounds() const;

    // Dodaj funkcję do ładowania bitmapy
    void loadBitmap(const std::string& imagePath);

private:
    bool drawing;
    sf::VertexArray shape;
    sf::Sprite sprite;  // Dodaj sprite dla bitmapy

    sf::RectangleShape bitmapNew;
    sf::Texture texture;
};

#endif //INC_2D_ENGINE_BITMAPRECTANGLE_H