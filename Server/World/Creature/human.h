#ifndef HUMAN_H
#define HUMAN_H

#include <Box2D/Box2D.h>


class Human
{
public:
    Human(b2World &PhysicsWorld, b2Vec2 Position, unsigned int ID);

    void Move(b2Vec2 Vector);

    b2Vec2 GetPosition();

//private:
    b2Body *Body;

    unsigned int ID;
};

#endif // HUMAN_H
