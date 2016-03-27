#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include <Box2D/Box2D.h>

#include "Creature/human.h"
#include "Ground/ground.h"


class World
{
public:
    World();

    void Loop();

    void CreateWorld();

    void CreateHuman(b2Vec2 Position);
    void CreateGround(b2Vec2 Position);

    //test
    void CreateFixedGround();

//private:
    b2World PhysicsWorld;

    unsigned int ID;

    std::vector<Human *> Humans;
    std::vector<Ground *> Grounds;
};

#endif // WORLD_H
