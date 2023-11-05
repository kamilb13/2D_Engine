#include "Engine.h"

void Engine::exit() {
    window.close();
}

void Engine::game() {
    sf::Clock framerate_clock;
    float speed = 10.f;

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
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "left click" << std::endl;
                    } else if (event.mouseButton.button == sf::Mouse::Right) {
                        std::cout << "right click" << std::endl;
                    } else if (event.mouseButton.button == sf::Mouse::Middle) {
                        std::cout << "middle click" << std::endl;
                    }
                    break;
            }

            //FIXME EVENT_LISTENER

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    line.startDrawing(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                }
            }
            if (event.type == sf::Event::MouseMoved) {
                line.updateLine(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    line.endDrawing();
                    lines.push_back(line);
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    rectangle_c.startDrawing(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                }
            }
            if (event.type == sf::Event::MouseMoved) {
                rectangle_c.updateRectangle(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    rectangle_c.endDrawing();
                    rectangles.push_back(rectangle_c);
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
        rectangle_c.draw(window);

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

sf::RectangleShape Engine::rectangle(sf::Color color, int width, int height, int x, int y) {
    rect.setFillColor(color);
    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(width, height));

    return rect;
}
