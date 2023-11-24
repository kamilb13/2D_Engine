#include "Enemy.h"

Enemy::Enemy(sf::RectangleShape enemy, sf::Color color, int width, int height, bool enabled) {
    this->enemy = enemy;
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
    }
}

void Enemy::shoot() {
    if (enabled) {
        sf::RectangleShape bul;
        Bullet *bullet = new Bullet(bul, sf::Color::Red,  this->enemy.getPosition().x +  width / 2, this->enemy.getPosition().y + height, 2, 4, 3);
        bullet->init();
    }
}