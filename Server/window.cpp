#include "window.h"

Window::Window(World &GameWorld)
    : GameWorld(GameWorld),
      Quad(sf::Quads, 4)
{
    GameWindow.create(sf::VideoMode(1366, 768, 32), "Toad");

    View.setSize(sf::Vector2f(1366, 768));

    for(int i=0; i<4; i++)
    {
        Quad[i].color = sf::Color::Green;
    }
}


void Window::Display()
{
    GameWindow.clear();

    for(unsigned int i=0; i<GameWorld.Humans.size(); i++)
    {
        Quad[0].position = sf::Vector2f((GameWorld.Humans[i]->Body->GetPosition().x-0.5f)*0.02f, (GameWorld.Humans[i]->Body->GetPosition().y-0.5f)*0.02f);
        Quad[1].position = sf::Vector2f((GameWorld.Humans[i]->Body->GetPosition().x-0.5f)*0.02f, (GameWorld.Humans[i]->Body->GetPosition().y+0.5f)*0.02f);
        Quad[2].position = sf::Vector2f((GameWorld.Humans[i]->Body->GetPosition().x+0.5f)*0.02f, (GameWorld.Humans[i]->Body->GetPosition().y+0.5f)*0.02f);
        Quad[3].position = sf::Vector2f((GameWorld.Humans[i]->Body->GetPosition().x+0.5f)*0.02f, (GameWorld.Humans[i]->Body->GetPosition().y-0.5f)*0.02f);

        GameWindow.draw(Quad);
    }

    GameWindow.display();

    View.setCenter(sf::Vector2f(GameWorld.Humans[0]->Body->GetPosition().x*0.02f, GameWorld.Humans[0]->Body->GetPosition().y*0.02f));
}
