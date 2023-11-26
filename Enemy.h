//
// Created by kamil on 26.11.2023.
//

#ifndef INC_2D_ENGINE_ENEMY_H
#define INC_2D_ENGINE_ENEMY_H


#include <SFML/Graphics.hpp>
#include "Player.h"

class Enemy {
private:
    sf::RectangleShape enemy;
    sf::Color color;
    int width;
    int height;
    bool enabled;
    sf::Clock shootClock;
    float shootCooldown = 1.0f;
    float bulletSpeed = 3.0f;
    sf::Texture enemyTexture;

    std::vector<sf::RectangleShape> bullets;
    std::vector<sf::RectangleShape> enemies;

public:
    Enemy(sf::Color color, int width, int height, bool enabled);
    void init(int x, int y);
    void shoot();
    void draw(sf::RenderWindow &window);
    void updateBullets(sf::RenderWindow &window, Player player);


    std::vector<sf::RectangleShape> getEnemies();
    sf::Sprite sprite;
    sf::FloatRect getGlobalBounds() const;

    sf::RectangleShape getGlobalBounds();
};

#endif //INC_2D_ENGINE_ENEMY_H
