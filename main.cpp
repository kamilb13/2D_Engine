#include "Engine.h"

int main() {
    Engine engine;
    engine.sfml_init(false, 1024, 768);
    engine.drawRectangle(sf::Color::Green, 100, 100, 100, 100);
    engine.set_fps(165);
    engine.game();
    return 0;
}