#include "human.h"

Human::Human(b2World &PhysicsWorld, b2Vec2 Position, unsigned int ID)
{
    this->ID = ID;

    b2BodyDef BodyDef;
    BodyDef.type = b2_dynamicBody;
    BodyDef.position = Position;

    Body = PhysicsWorld.CreateBody(&BodyDef);


    b2PolygonShape Shape;
    Shape.SetAsBox(0.5f, 0.5f);

    b2FixtureDef FixtureDef;
    FixtureDef.shape = &Shape;
    FixtureDef.density = 5250.0f;

    Body->CreateFixture(&FixtureDef);
}


void Human::Move(b2Vec2 Vector)
{
    Body->ApplyForceToCenter(Vector, true);
}


b2Vec2 Human::GetPosition()
{
    return Body->GetPosition();
}
