#include "Engine.h"
#include "Player.h"
#include "BitmapRectangle.h"
#include "BitmapRectangleEventListener.h"
#include "ResizableBitmap.h"

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
    //tablica z czym chce kolizje
    Collision collisionManager(&bitmapRectangles, 5.0f);

    Player *player = new Player(5.0f,  collisionManager, window);


    BitmapRectangle bitmapRect(); //

    // Ścieżka do pliku z bitmapą
    //std::string imagePath = "C:\\Users\\kamil\\Desktop\\Space-Invaders\\graphics\\my_ufo.png"; //C:\Users\kamil\Desktop\Space-Invaders\graphic\smy_ufo.png

    //ResizableBitmap resizableBitmap("C:\\Users\\kamil\\Desktop\\Space-Invaders\\graphics\\my_ufo.png");

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

            // Obsługa zdarzeń dla BitmapRectangle
            bitmapRectangleEventListener->eventHandler(event);
            if (menu->getChoice() == 1){
                circleEventListener->eventHandler(event);
                //rectangleEventListener->eventHandler(event);  // TODO 1. POPRAWIĆ TO RYSOWANIE
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
        //bitmapRect.draw(window);
        for (const auto& l : lines) {
            l.draw(window);
        }
        line.draw(window);
        /*
        for (const auto& r : rectangles) {
            r.draw(window);
        }
         */

        for (Circle circ : circles) {
            circ.draw(window);
        }
        //TODO NAPRAWIC BY TE BITMAPY SIE WYSWIETLALY i DODAC OSOBNA KOLIZJE

        for (const auto& br : bitmapRectangles) {
            br.draw(window);
        }



        //window.clear(sf::Color::White); // Dodaj to przed rysowaniem
        //resizableBitmap.update();
        //resizableBitmap.draw(window);
        //window.display();

        player->handleInput();
        player->update();
        player->draw();
        //bitmapRectangle.draw(window);
        line.draw(window);
        //rectangle.draw(window);
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
