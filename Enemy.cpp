#include "Enemy.h"

Enemy::Enemy(sf::Color color, int width, int height, bool enabled) {
    this->color = color;
    this->width = width;
    this->height = height;
    this->enabled = enabled;
};

void Enemy::init(int x, int y) {
    if (enabled) {
        enemy.setFillColor(color);
        enemy.setSize(sf::Vector2f(width, height));
        enemy.setPosition(x, y);
        enemies.push_back(enemy);
    }
}

void Enemy::shoot() {
    if (enabled && shootClock.getElapsedTime().asSeconds() > shootCooldown) {
        sf::RectangleShape bullet(sf::Vector2f(5.0f, 5.0f));
        bullet.setFillColor(sf::Color::Red);
        bullet.setPosition(enemy.getPosition().x + enemy.getSize().x / 2, enemy.getPosition().y);
        bullets.push_back(bullet);

        shootClock.restart();
    }
}

void Enemy::draw(sf::RenderWindow &window) {
    if (enabled) {
        window.draw(enemy);
    }

    for (const auto& bullet : bullets) {
        window.draw(bullet);
    }
}

void Enemy::updateBullets(sf::RenderWindow &window, Player player) {
    auto bulletIt = bullets.begin();
    while (bulletIt != bullets.end()) {
        bulletIt->move(0.0f, bulletSpeed);

        // Sprawdzenie kolizji z prostokątami
        bool removeBullet = false;
//        if (bulletIt->getGlobalBounds().intersects(player.getGlobalBounds())) {
//            // Kolizja! Usuń prostokąt i pocisk
//            removeBullet = true;
//            break; // Wyjście z pętli wewnętrznej po wykryciu kolizji
//        }

        // Usunięcie pocisku, jeśli przekroczył górną granicę ekranu lub kolizja
        if (bulletIt->getPosition().y > window.getSize().y || removeBullet) {
            bulletIt = bullets.erase(bulletIt);
        } else {
            ++bulletIt;
        }
    }
}