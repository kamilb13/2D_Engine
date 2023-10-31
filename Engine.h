#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>
#include "Player.h"
#include "PlayerEventListener.hpp"

class Engine {
private:
    sf::RenderWindow window;
    sf::RectangleShape rect;
    std::vector<sf::RectangleShape> redRectangles; 

    void exit() {
        window.close();
    }

    std::string timer(std::chrono::high_resolution_clock::time_point start_time) {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

        int hours = duration.count() / 3600;
        int minutes = (duration.count() % 3600) / 60;
        int seconds = duration.count() % 60;

        std::ostringstream final_time;

        final_time << "[" << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds << "] ";

        return final_time.str();
    }



public:

    Player* player;
    PlayerEventListener* playerEventListener;

    void game() {
        auto start_time = std::chrono::high_resolution_clock::now();

        float speed = 10.f;
        player = new Player(100.0f, 100.0f, 100, 100, speed);
        playerEventListener = new PlayerEventListener(player);

        sf::Clock framerate_clock;

        while(window.isOpen()) {
            sf::Event event;

            //licznik fps


            float rotation = 0;

            

            while(window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;  
                    case sf::Event::KeyPressed:
                        playerEventListener->eventHandler(event);
                        break;
                    case sf::Event::MouseButtonPressed:
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            redRectangles.push_back(sf::RectangleShape());
                            redRectangles.back().setPosition(event.mouseButton.x, event.mouseButton.y);
                            redRectangles.back().setSize(sf::Vector2(200.0f, 200.0f));
                            redRectangles.back().setFillColor(sf::Color::Red);
                            std::cout << timer(start_time) + "left click" << std::endl;
                        } else if (event.mouseButton.button == sf::Mouse::Right) {
                            std::cout << timer(start_time) + "right click" << std::endl;
                        } else if (event.mouseButton.button == sf::Mouse::Middle) {
                            std::cout << timer(start_time) + "middle click" << std::endl;
                        }
                        break;
                }
            }
            window.clear(sf::Color::Black);
            player->drawPlayer(&window);

            for(int i = 0; i < redRectangles.size(); i++){
                window.draw(redRectangles.at(i));
            }
            window.display();
        }
    }

    void set_fps(int fps) {
        window.setFramerateLimit(fps);
    }

    void sfml_init(bool fullscreen, int width, int height) {
        if (fullscreen) {
            window.create(sf::VideoMode::getDesktopMode(), "Engine 2D", sf::Style::Fullscreen);
        } else {
            window.create(sf::VideoMode(width, height), "Engine 2D", sf::Style::Default);
        }
    }

};