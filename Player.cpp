//
// Created by kamil on 23.11.2023.
//

#include "Player.h"

// Player.cpp
#include "Player.h"

Player::Player(std::vector<Rectangle> *vectorRectangle, sf::RenderWindow &window) : window(window) {
    playerShape.setSize(sf::Vector2f(50.0f, 50.0f));
    playerShape.setFillColor(sf::Color::Green);
    playerShape.setPosition(200, 200);
    this->vectorRectangles = vectorRectangle;
}

Player::Player(std::vector<BitmapRectangle> *bitmapRectangle, sf::RenderWindow &window) : window(window) {
    playerShape.setSize(sf::Vector2f(50.0f, 50.0f));
    playerShape.setFillColor(sf::Color::Green);
    playerShape.setPosition(200, 200);
    this->bitmapRectangles = bitmapRectangle;
}

void Player::handleInput() {
    // Ruch w górę
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && playerShape.getPosition().y > 0) {
        playerShape.move(0, -movementSpeed);
    }
    // Ruch w dół
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        playerShape.move(0, movementSpeed);
    }
    // Ruch w lewo
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && playerShape.getPosition().x > 0) {
        playerShape.move(-movementSpeed, 0);
    }
    // Ruch w prawo
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
        playerShape.move(movementSpeed, 0);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && shootClock.getElapsedTime().asSeconds() > shootCooldown) {
        sf::RectangleShape bullet(sf::Vector2f(5.0f, 5.0f));
        bullet.setFillColor(sf::Color::Red);
        bullet.setPosition(playerShape.getPosition().x + playerShape.getSize().x / 2, playerShape.getPosition().y);
        bullets.push_back(bullet);

        shootClock.restart();
    }
}

/*
void Player::update() {
    // Aktualizacja pozycji pocisków
    auto bulletIt = bullets.begin();
    while (bulletIt != bullets.end()) {
        bulletIt->move(0.0f, -bulletSpeed);

        // Sprawdzenie kolizji z prostokątami
        bool removeBullet = false;
        for (auto rectIt = vectorRectangles->begin(); rectIt != vectorRectangles->end(); ++rectIt) {
            if (bulletIt->getGlobalBounds().intersects(rectIt->getGlobalBounds())) {
                // Kolizja! Usuń prostokąt i pocisk
                rectIt = vectorRectangles->erase(rectIt);
                removeBullet = true;
                break; // Wyjście z pętli wewnętrznej po wykryciu kolizji
            }
        }

        // Usunięcie pocisku, jeśli przekroczył górną granicę ekranu lub kolizja
        if (bulletIt->getPosition().y < 0 || removeBullet) {
            bulletIt = bullets.erase(bulletIt);
        } else {
            ++bulletIt;
        }
    }
}
 */
void Player::update() {
    // Aktualizacja pozycji pocisków
    auto bulletIt = bullets.begin();
    while (bulletIt != bullets.end()) {
        bulletIt->move(0.0f, -bulletSpeed);

        // Sprawdzenie kolizji z prostokątami
        bool removeBullet = false;
        for (auto rectIt = bitmapRectangles->begin(); rectIt != bitmapRectangles->end(); ++rectIt) {
            if (bulletIt->getGlobalBounds().intersects(rectIt->getGlobalBounds())) {
                // Kolizja! Usuń prostokąt i pocisk
                rectIt = bitmapRectangles->erase(rectIt);
                removeBullet = true;
                break; // Wyjście z pętli wewnętrznej po wykryciu kolizji
            }
        }

        // Usunięcie pocisku, jeśli przekroczył górną granicę ekranu lub kolizja
        if (bulletIt->getPosition().y < 0 || removeBullet) {
            bulletIt = bullets.erase(bulletIt);
        } else {
            ++bulletIt;
        }
    }
}




void Player::draw() {
    window.draw(playerShape);

    for (const auto& bullet : bullets) {
        window.draw(bullet);
    }
}
