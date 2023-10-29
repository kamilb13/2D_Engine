#include "Engine.h"

int main() {
    Engine engine;
    engine.sfml_init(false, 1024, 768);
    engine.set_fps(60);                                         // 0 - no limit
    engine.game();
    return 0;
}