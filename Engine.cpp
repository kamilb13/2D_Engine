#include "Engine.h"

void Engine::exit() {
    window.close();
}

void Engine::game() {
    sf::Clock framerate_clock;
    float speed = 10.f;

    rectangleEventListener = new RectangleEventListener(&(this->rectangle), &(this->window), &(this->rectangles));
    circleEventListener = new CircleEventListener(&(this->circle), &(this->window), &(this->circles));
    lineEventListener = new LineEventListener(&(this->line), &(this->window), &(this->lines));
    bitmapRectangleEventListener = new BitmapRectangleEventListener(&(this->bitmapRectangle), &(this->window), &(this->bitmapRectangles));

    menu = new Menu();


    //Enemy *enemy = new Enemy(sf::Color::Red, 60, 60, true);
    //enemy->init(100, 100);

    //tablica z czym chce kolizje
    Collision collisionManager(&(this->bitmapRectangles), 5.0f);

    Player *player = new Player(5.0f,  collisionManager, window);


    BitmapRectangle bitmapRect();

    bitmapRectangleEventListener->eventHandler(); //event
    while(window.isOpen()) {
        if(bitmapRectangles.empty()){
            std::cout << "WYGRALES" << std::endl;
            exit();
        }
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

            // Obsługa zdarzeń dla BitmapRectangle

            if (menu->getChoice() == 1){
                circleEventListener->eventHandler(event);
            } else if (menu->getChoice() == 2){
                lineEventListener->eventHandler(event);
            } else if (menu->getChoice() == 3) {
                rectangleEventListener->eventHandler(event);
            } else if (menu->getChoice() == 4) {
                circles.clear();
                lines.clear();
                rectangles.clear();
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
            }

        }   // koniec petli

        window.clear(sf::Color::Black);

        if (menu->getChoice() != 4) {
            for (const auto& l : lines) {
                l.draw(window);
            }

            for (const auto& r : rectangles) {
                r.draw(window);
            }

            for (Circle circ : circles) {
                circ.draw(window);
            }

            line.draw(window);
            rectangle.draw(window);
            circle.draw(window);

        } else {
            for (const auto& br : bitmapRectangles) {
                br.draw(window);
            }

            for (auto& br : bitmapRectangles) {
                sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
                rectangle.updateRectangle(mousePosition);
                br.shoot();
                br.updateBullets(window, player->getGlobalBounds());
            }

            player->handleInput();
            player->update();
            player->draw();

        }

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