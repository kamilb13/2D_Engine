#include "Player.h"

Player::Player(float width, float height, int pos_x, int pos_y, float speed){
    this->width = width;
    this->height = height;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->speed = speed;

    this->rect = new sf::RectangleShape();

    this->rect->setPosition(pos_x, pos_y);
    this->rect->setSize(sf::Vector2(width, height));
    this->rect->setFillColor(sf::Color::Blue);

}

void Player::moveUp(float offset){
    this->rect->move(0, -offset);
    this->pos_y -= offset;
}

void Player::moveDown(float offset){
    this->rect->move(0, offset);
}

void Player::moveLeft(float offset){
    this->rect->move(-offset, 0);
}

void Player::moveRight(float offset){
    this->rect->move(offset, 0);
}

void Player::drawPlayer(sf::RenderWindow* window){
    sf::RectangleShape rect;

    rect.setFillColor(sf::Color::Red);
    rect.setPosition(pos_x, pos_y);
    rect.setSize(sf::Vector2(200.0f, 200.0f));

    window->draw(*(this->rect));
}


float Player::getSpeed(){
    return this->speed;
}