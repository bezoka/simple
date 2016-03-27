#include "world.h"

World::World()
    : PhysicsWorld(b2Vec2(0.0f, -9.8f))
{
    CreateWorld();
}


void World::CreateWorld()
{
    CreateFixedGround();
    CreateHuman(b2Vec2(0.0f, 10.0f));
}


void World::Loop()
{
    PhysicsWorld.Step(1.0f/60.0f, 8, 3);
}


void World::CreateHuman(b2Vec2 Position)
{
    Humans.resize(Humans.size()+1);
    ID++;
    Humans[Humans.size()-1] = new Human(PhysicsWorld, Position, ID);
}



void World::CreateGround(b2Vec2 Position)
{
    Grounds.resize(Grounds.size()+1);
    Grounds[Grounds.size()-1] = new Ground(PhysicsWorld, Position);
}


//test
void World::CreateFixedGround()
{
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(0.0f, 0.0f);

    b2Body * Body = PhysicsWorld.CreateBody(&BodyDef);


    b2PolygonShape Shape;
    Shape.SetAsBox(2000.0f, 1.0f);

    b2FixtureDef FixtureDef;
    FixtureDef.shape = &Shape;

    Body->CreateFixture(&FixtureDef);

    Shape.SetAsBox(1.0f, 100.0f, b2Vec2(4000.0f, 0.0f), 0);
    Body->CreateFixture(&FixtureDef);

    Shape.SetAsBox(1.0f, 100.0f, b2Vec2(-4000.0f, 0.0f), 0);
    Body->CreateFixture(&FixtureDef);
}
