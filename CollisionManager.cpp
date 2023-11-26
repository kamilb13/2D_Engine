//
// Created by kamil on 26.11.2023.
//

#include <iostream>
#include "CollisionManager.h"
#include "SFML/Graphics/RenderWindow.hpp"

CollisionManager::CollisionManager(sf::RenderWindow& window) : window(window) {}

bool CollisionManager::checkBulletPlayerCollision(const sf::RectangleShape& bullet, const sf::RectangleShape& player) {
    return bullet.getGlobalBounds().intersects(player.getGlobalBounds());
}

void CollisionManager::handleBulletPlayerCollision() {
    // Obsługa kolizji, np. zakończenie gry
    std::cout << "Collision with player! Game Over!" << std::endl;

    // Dodaj odpowiednie działania, takie jak zakończenie gry, restart poziomu itp.
    // Na tym etapie możesz umieścić kod zakończenia gry lub odpowiednie procedury
    // np. restart gry, zresetowanie poziomu itp.
    // ...
}