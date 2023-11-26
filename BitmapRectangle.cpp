#include <iostream>
#include "BitmapRectangle.h"
#include "Player.h"

//TODO DLACZEGO NIE MOGE Z PARAMETRU?? WYWALA BLAD ZE BRAK KONSTRUKTORA ENGINE?!?!
BitmapRectangle::BitmapRectangle() : drawing(false) { //std::string pathOfEnemy
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

void BitmapRectangle::shoot() {
    if (shootClock.getElapsedTime().asSeconds() > shootCooldown) {
        sf::RectangleShape bullet(sf::Vector2f(5.0f, 5.0f));
        bullet.setFillColor(sf::Color::Red);
        bullet.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y + sprite.getGlobalBounds().height);
        bullets.push_back(bullet);

        shootClock.restart();
    }
}

void BitmapRectangle::updateBullets(sf::RenderWindow &window, sf::RectangleShape playerBounds ) {
    //collisionManager.checkBulletCollisions(bullets);

    auto bulletIt = bullets.begin();
    while (bulletIt != bullets.end()) {
        bulletIt->move(0.0f, bulletSpeed);
        if(bulletIt->getGlobalBounds().intersects(playerBounds.getGlobalBounds())){
            exit(0);
        }
        // Usunięcie pocisku, jeśli przekroczył dolną granicę ekranu
        if (bulletIt->getPosition().y > window.getSize().y) {
            bulletIt = bullets.erase(bulletIt);
        } else {
            ++bulletIt;
        }
    }
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

    for (const auto& bullet : bullets) {
        window.draw(bullet);
    }
}

sf::FloatRect BitmapRectangle::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

