//
// Created by kamil on 25.11.2023.
//

#ifndef INC_2D_ENGINE_RESIZABLEBITMAP_H
#define INC_2D_ENGINE_RESIZABLEBITMAP_H

#include <SFML/Graphics.hpp>

class ResizableBitmap {
public:
    ResizableBitmap(const std::string& texturePath);

    void update();
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape bitmap;
    sf::Texture texture; // Dodane pole do przechowywania tekstury

    bool isResizing;
};


#endif //INC_2D_ENGINE_RESIZABLEBITMAP_H
