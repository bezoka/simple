#ifndef GAME_H
#define GAME_H

#include <thread>

#include "World/world.h"
#include "window.h"


class Game
{
public:
    Game();

    void KeyboardHandling();
    void WindowHandling();
    void WorldHandling();

//private:
    Window ToadWindow;
    World ToadWorld;

    std::thread KeyboardHandlingThread;
    std::thread WindowHandlingThread;
    std::thread WorldHandlingThread;

    bool IsRunning;
};

#endif // GAME_H
