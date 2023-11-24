<<<<<<< HEAD
#include "Engine.h"
#include <SFML/Audio.hpp>


void Engine::exit() {
    window.close();
}

void Engine::game() {
    std::cout << "Brak pliku" << std::endl;
    sf::Clock framerate_clock;
    float speed = 10.f;

    rectangleEventListener = new RectangleEventListener(&(this->rectangle), &(this->window), &(this->rectangles));
    circleEventListener = new CircleEventListener(&(this->circle), &(this->window), &(this->circles));
    lineEventListener = new LineEventListener(&(this->line), &(this->window), &(this->lines));

    menu = new Menu();

    while(window.isOpen()) {
        //licznik fps
        sf::Font framerate_font;
        framerate_font.loadFromFile("../resources/fonts/arial.ttf");
        int fps = (int (1.f / framerate_clock.getElapsedTime().asSeconds()));
        sf::Text framerate(std::to_string(fps), framerate_font, 20);
        framerate.setFillColor(sf::Color::White);
        framerate_clock.restart();

        sf::Event event;

        while(window.pollEvent(event)) {
            menu->menuHandler(event);


            if (menu->getChoice() == 1){
                circleEventListener->eventHandler(event);
                rectangleEventListener->eventHandler(event);
            } else if (menu->getChoice() == 2){
                lineEventListener->eventHandler(event);
                std::cout << menu->getChoice() << std::endl;
            }
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    exit();
                    std::cout << "exit" << std::endl;
                } else if (event.key.code == sf::Keyboard::Left) {
                    rect.move(-speed, 0.f);
                    std::cout << "left arrow" << std::endl;
                } else if (event.key.code == sf::Keyboard::Right) {
                    rect.move(speed, 0);
                    std::cout << "right arrow" << std::endl;
                } else if (event.key.code == sf::Keyboard::Up) {
                    rect.move(0, -speed);
                    std::cout << "up arrow" << std::endl;
                } else if (event.key.code == sf::Keyboard::Down) {
                    rect.move(0, speed);
                    std::cout << "down arrow" << std::endl;
                }
                // TODO Przerobic ruch kwadratu na taki jak to, zeby mogl sie ruszac po skosie:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                    rect.move(speed, speed);
                }

            }
        }   // koniec petli

        window.clear(sf::Color::Black);

        for (const auto& l : lines) {
            l.draw(window);
        }
        line.draw(window);

        for (const auto& r : rectangles) {
            r.draw(window);
        }

        for (Circle circ : circles) {
            circ.draw(window);
        }

        line.draw(window);
        rectangle.draw(window);
        circle.draw(window);
        window.draw(rect);
        window.draw(framerate);
        window.display();
    }
}

void Engine::set_fps(int fps) {
    window.setFramerateLimit(fps);
}

void Engine::sfml_init(bool fullscreen, int width, int height) {
    if (fullscreen) {
        window.create(sf::VideoMode::getDesktopMode(), "Engine 2D", sf::Style::Fullscreen);
    } else {
        window.create(sf::VideoMode(width, height), "Engine 2D", sf::Style::Default);
    }
}

sf::RectangleShape Engine::drawRectangle(sf::Color color, int width, int height, int x, int y) {
    rect.setFillColor(color);
    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(width, height));

    return rect;
}
=======
#include "Engine.h"
#include <SFML/Audio.hpp>


void Engine::exit() {
    window.close();
}

void Engine::game() {
    std::cout << "Brak pliku" << std::endl;
    sf::Clock framerate_clock;
    float speed = 10.f;

    rectangleEventListener = new RectangleEventListener(&(this->rectangle), &(this->window), &(this->rectangles));
    circleEventListener = new CircleEventListener(&(this->circle), &(this->window), &(this->circles));
    lineEventListener = new LineEventListener(&(this->line), &(this->window), &(this->lines));

    this->buffer = new sf::SoundBuffer();
    this->sound = new sf::Sound();

    menu = new Menu();

    while(window.isOpen()) {
        //licznik fps
        sf::Font framerate_font;
        framerate_font.loadFromFile("../resources/fonts/arial.ttf");
        int fps = (int (1.f / framerate_clock.getElapsedTime().asSeconds()));
        sf::Text framerate(std::to_string(fps), framerate_font, 20);
        framerate.setFillColor(sf::Color::White);
        framerate_clock.restart();

        sf::Event event;

        while(window.pollEvent(event)) {
            menu->menuHandler(event);


            if (menu->getChoice() == 1){
                circleEventListener->eventHandler(event);
                rectangleEventListener->eventHandler(event);
            } else if (menu->getChoice() == 2){
                lineEventListener->eventHandler(event);
                std::cout << menu->getChoice() << std::endl;
            }
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    exit();
                    std::cout << "exit" << std::endl;
                } else if (event.key.code == sf::Keyboard::Left) {
                    rect.move(-speed, 0.f);
                    std::cout << "left arrow" << std::endl;
                } else if (event.key.code == sf::Keyboard::Right) {
                    rect.move(speed, 0);
                    std::cout << "right arrow" << std::endl;
                } else if (event.key.code == sf::Keyboard::Up) {
                    rect.move(0, -speed);
                    std::cout << "up arrow" << std::endl;
                } else if (event.key.code == sf::Keyboard::Down) {
                    rect.move(0, speed);
                    std::cout << "down arrow" << std::endl;
                }else if (event.key.code == sf::Keyboard::Space) {
                    std::cout << "SPACJA" << std::endl;

                    if (!buffer->loadFromFile("sound.wav")) return;
                    sound->setBuffer(*buffer);
                    sound->play();
                }
                // TODO Przerobic ruch kwadratu na taki jak to, zeby mogl sie ruszac po skosie:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                    rect.move(speed, speed);
                }

            }
        }   // koniec petli

        window.clear(sf::Color::Black);

        for (const auto& l : lines) {
            l.draw(window);
        }
        line.draw(window);

        for (const auto& r : rectangles) {
            r.draw(window);
        }

        for (Circle circ : circles) {
            circ.draw(window);
        }

        line.draw(window);
        rectangle.draw(window);
        circle.draw(window);
        window.draw(rect);
        window.draw(framerate);
        window.display();
    }
}

void Engine::set_fps(int fps) {
    window.setFramerateLimit(fps);
}

void Engine::sfml_init(bool fullscreen, int width, int height) {
    if (fullscreen) {
        window.create(sf::VideoMode::getDesktopMode(), "Engine 2D", sf::Style::Fullscreen);
    } else {
        window.create(sf::VideoMode(width, height), "Engine 2D", sf::Style::Default);
    }
}

sf::RectangleShape Engine::drawRectangle(sf::Color color, int width, int height, int x, int y) {
    rect.setFillColor(color);
    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(width, height));

    return rect;
}
>>>>>>> d7ebeb8896b7f9c2027c8f51b06c18e162652817
