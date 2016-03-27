#ifndef GROUND_H
#define GROUND_H

#include <Box2D/Box2D.h>


class Ground
{
public:
    Ground(b2World &PhysicsWorld, b2Vec2 Position);

//protected:
    b2Body *Body;
};

#endif // GROUND_H
