#include "Engine.h"

int main() {
    Engine engine;
    engine.sfml_init(true, 1024, 768);
    engine.rectangle(sf::Color::Blue, 100, 100, 100, 100);
    engine.set_fps(10);                                         // 0 - no limit
    engine.game();
    return 0;
}