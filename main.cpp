#include "Engine.h"

#define FPS_LIMIT       60
#define FULLSCREEN      0
#define WIDTH           1024
#define HEIGHT          768


int main() {
    Engine engine;
    engine.sfml_init(FULLSCREEN, WIDTH, HEIGHT);
    //engine.drawRectangle(sf::Color::Green, 100, 100, 100, 100);
    engine.set_fps(FPS_LIMIT);
    engine.game();
    return 0;
}