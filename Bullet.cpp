#include "Bullet.h"

Bullet::Bullet(sf::RectangleShape bullet, sf::Color color, float x, float y, int width, int height, float speed) {
    this->bullet = bullet;
    this->color = color;
    this->width = width;
    this->height = height;
    this->speed = speed;
    this->x = x;
    this->y = y;
}

void Bullet::init() {
    bullet.setFillColor(color);
    bullet.setSize(sf::Vector2f(width, height));
    bullet.setPosition(x, y);
}

void Bullet::updateBullet() {
    bullet.move(sf::Vector2f(0, speed));
}