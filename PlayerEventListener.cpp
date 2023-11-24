#include "PlayerEventListener.hpp"

PlayerEventListener::PlayerEventListener(Player* player){
    this->player = player;
    
}

PlayerEventListener::~PlayerEventListener() {
    
}

void PlayerEventListener::eventHandler(sf::Event event){


    
    if(event.key.code == sf::Keyboard::Right){
        this->player->moveRight(this->player->getSpeed());
        std::cout << "go right" << std::endl;
        std::cout << this->player->rect->getPosition().x << std::endl;
    } else if(event.key.code == sf::Keyboard::Left){
        this->player->moveLeft(this->player->getSpeed());
    } else if(event.key.code == sf::Keyboard::Up){
        this->player->moveUp(this->player->getSpeed());
    } else if(event.key.code == sf::Keyboard::Down){
        this->player->moveDown(this->player->getSpeed());
    }
}