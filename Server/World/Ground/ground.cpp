#include "ground.h"

Ground::Ground(b2World &PhysicsWorld, b2Vec2 Position)
{
    b2BodyDef BodyDef;
//    BodyDef.type = b2_staticBody;
    BodyDef.position = Position;

    Body = PhysicsWorld.CreateBody(&BodyDef);


    b2PolygonShape Shape;
    Shape.SetAsBox(100.0f, 0.5f);

    b2FixtureDef FixtureDef;
    FixtureDef.shape = &Shape;
    //FixtureDef.density = 5250.0f;

    Body->CreateFixture(&FixtureDef);
}
