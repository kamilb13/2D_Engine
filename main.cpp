<<<<<<< HEAD
#include "Engine.h"

int main() {
    Engine engine;
    engine.sfml_init(false, 1024, 768);
    engine.drawRectangle(sf::Color::Green, 100, 100, 100, 100);
    engine.set_fps(165);
    engine.game();
    return 0;
=======
#include "Engine.h"

int main() {
    Engine engine;
    engine.sfml_init(false, 1024, 768);
    engine.drawRectangle(sf::Color::Green, 100, 100, 100, 100);
    engine.set_fps(165);
    engine.game();
    return 0;
>>>>>>> d7ebeb8896b7f9c2027c8f51b06c18e162652817
}