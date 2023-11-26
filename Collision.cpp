#include <iostream>
#include "Collision.h"

Collision::Collision(std::vector<BitmapRectangle>* bitmapRectangles, float bulletSpeed)
        : bitmapRectangles(bitmapRectangles), bulletSpeed(bulletSpeed) {
    // Konstruktor klasy CollisionManager
}

Collision::Collision(std::vector<sf::RectangleShape>* rectangleShape, float bulletSpeed)
        : bitmapRectangles(bitmapRectangles), bulletSpeed(bulletSpeed) {
    // Konstruktor klasy CollisionManager
}

void Collision::checkBulletCollisions(std::vector<sf::RectangleShape>& bullets) {
    auto bulletIt = bullets.begin();
    while (bulletIt != bullets.end()) {
        bulletIt->move(0.0f, -bulletSpeed);

        // Sprawdzenie kolizji z prostokątami
        bool removeBullet = false;
        for (auto rectIt = bitmapRectangles->begin(); rectIt != bitmapRectangles->end(); ++rectIt) {
            if (bulletIt->getGlobalBounds().intersects(rectIt->getGlobalBounds())) {
                // Kolizja! Usuń prostokąt i pocisk
                std::cout << "Wykryta kolizja" << std::endl;
                bitmapRectangles->erase(rectIt);
                removeBullet = true;
                break; // Wyjście z pętli wewnętrznej po wykryciu kolizji
            }
        }

        // Usunięcie pocisku, jeśli przekroczył górną granicę ekranu lub kolizja
        if (bulletIt->getPosition().y < 0 || removeBullet) {
            std::cout << "Pocisk usuniety" << std::endl;
            bulletIt = bullets.erase(bulletIt);
        } else {
            ++bulletIt;
        }
    }
}

