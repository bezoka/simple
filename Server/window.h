#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

#include "World/world.h"


class Window
{
public:
    Window(World &GameWorld);

    void Display();

//private:
    World &GameWorld;

    sf::RenderWindow GameWindow;

    sf::VertexArray Quad;

    sf::View View;
};

#endif // WINDOW_H
