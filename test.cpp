#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

int main()
{
    // Inicjalizacja okna
    sf::RenderWindow window(sf::VideoMode(800, 600), "Prosty Silnik 2D");

    // Tworzenie prostokąta
    sf::RectangleShape rectangle(sf::Vector2f(100, 100));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(350, 250);

    // Utwórz zegar do mierzenia czasu
    sf::Clock clock;

    // Ustal szybkość ruchu
    float speed = 100.0; // Możesz dostosować tę wartość

    bool isDragging = false;
    sf::Vector2f offset; // Przechowuje przesunięcie myszy względem prostokąta

    std::vector<sf::RectangleShape> blackSquares; // Lista czarnych kwadratów

    sf::Texture texture;
    texture.create(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Obsługa zdarzeń myszy
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Sprawdź, czy kliknięto w kwadrat
                    if (rectangle.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        isDragging = true;
                        offset = rectangle.getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    }
                    else
                    {
                        // Pobierz kolor piksela pod myszą
                        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                        sf::Color pixelColor = texture.copyToImage().getPixel(pixelPos.x, pixelPos.y);

                        // Jeśli kliknięto na czarnym polu, stwórz nowy kwadrat
                        if (pixelColor == sf::Color::Black)
                        {
                            sf::RectangleShape blackSquare(sf::Vector2f(100, 100));
                            blackSquare.setFillColor(sf::Color::Green); // Ustaw kolor na zielony
                            blackSquare.setPosition(pixelPos.x, pixelPos.y);
                            blackSquares.push_back(blackSquare);
                        }
                    }
                }
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    isDragging = false;
                }
            }
        }

        // Przesuwanie kwadratu, jeśli mysz jest przeciągana
        if (isDragging)
        {
            sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
            rectangle.setPosition(mousePosition + offset);
        }

        // Pobierz czas od ostatniej klatki
            float deltaTime = clock.restart().asSeconds();

        // Obsługa klawiszy strzałek
        if (!isDragging)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                rectangle.move(-speed * deltaTime, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                rectangle.move(speed * deltaTime, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                rectangle.move(0, -speed * deltaTime);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                rectangle.move(0, speed * deltaTime);
            }
        }

        // Aktualizacja tekstury
        window.clear();
        window.draw(rectangle);
        for (const sf::RectangleShape& blackSquare : blackSquares)
        {
            window.draw(blackSquare);
        }
        texture.update(window);
        window.display();
    }

    return 0;
}