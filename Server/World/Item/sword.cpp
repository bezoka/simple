#include "sword.h"

Sword::Sword(b2World &PhysicsWorld, b2Vec2 Position)
{
    b2BodyDef BodyDef;
    BodyDef.type = b2_dynamicBody;
    BodyDef.position = Position;

    Body = PhysicsWorld.CreateBody(&BodyDef);


    b2PolygonShape Shape;
    Shape.SetAsBox(0.02f, 0.5f);

    b2FixtureDef FixtureDef;
    FixtureDef.shape = &Shape;
    FixtureDef.density = 62.88f;

    Body->CreateFixture(&FixtureDef);
}
