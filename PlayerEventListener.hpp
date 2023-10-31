#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
class PlayerEventListener {
    private:
        Player* player;

    public:
        PlayerEventListener(Player* player);
        ~PlayerEventListener();

        void eventHandler(sf::Event);
};