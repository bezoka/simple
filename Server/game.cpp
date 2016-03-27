#include "game.h"

Game::Game()
    : ToadWindow(ToadWorld),
      KeyboardHandlingThread(&Game::KeyboardHandling, this),
      WindowHandlingThread(&Game::WindowHandling, this),
      WorldHandlingThread(&Game::WorldHandling, this)
{
    IsRunning = true;

    WorldHandlingThread.join();
}


void Game::KeyboardHandling()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        IsRunning = false;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        ToadWorld.Humans[0]->Move(b2Vec2(0.0f, 10.0f));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        ToadWorld.Humans[0]->Move(b2Vec2(10.0f, 0.0f));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        ToadWorld.Humans[0]->Move(b2Vec2(-10.0f, 0.0f));
    }
}


void Game::WindowHandling()
{
    while(IsRunning)
    {
        //std::this_thread::sleep_for(std::chrono::milliseconds(16));

        ToadWindow.Display();
    }
}


void Game::WorldHandling()
{
    while(IsRunning)
    {
        ToadWorld.Loop();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}
