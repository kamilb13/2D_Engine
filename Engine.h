#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <chrono>
#include <iomanip>

class Engine {
private:
    sf::RenderWindow window;

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
    void game() {
        auto start_time = std::chrono::high_resolution_clock::now();

        sf::RectangleShape rectangle(sf::Vector2f(100, 100));
        rectangle.setFillColor(sf::Color::Green);
        rectangle.setPosition(150, 150);

        float speed = 10.f;

        sf::Clock framerate_clock;

        while(window.isOpen()) {
            sf::Event event;

            //licznik fps
            sf::Font framerate_font;
            framerate_font.loadFromFile("../resources/fonts/arial.ttf");
            int fps = (int (1.f / framerate_clock.getElapsedTime().asSeconds()));
            sf::Text framerate(std::to_string(fps), framerate_font, 20);
            framerate.setFillColor(sf::Color::White);
            framerate_clock.restart();

            while(window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        if (event.key.code == sf::Keyboard::Escape) {
                            exit();
                            std::cout << timer(start_time) + "exit" << std::endl;
                        } else if (event.key.code == sf::Keyboard::Left) {
                            rectangle.move(-speed, 0.f);
                            std::cout << timer(start_time) + "left arrow" << std::endl;
                        } else if (event.key.code == sf::Keyboard::Right) {
                            rectangle.move(speed, 0);
                            std::cout << timer(start_time) + "right arrow" << std::endl;
                        } else if (event.key.code == sf::Keyboard::Up) {
                            rectangle.move(0, -speed);
                            std::cout << timer(start_time) + "up arrow" << std::endl;
                        } else if (event.key.code == sf::Keyboard::Down) {
                            rectangle.move(0, speed);
                            std::cout << timer(start_time) + "down arrow" << std::endl;
                        }
                        break;
                    case sf::Event::MouseButtonPressed:
                        if (event.mouseButton.button == sf::Mouse::Left) {
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
            window.draw(rectangle);
            window.draw(framerate);
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

