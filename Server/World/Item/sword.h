#ifndef SWORD_H
#define SWORD_H

#include "item.h"


class Sword : public Item
{
public:
    Sword(b2World &PhysicsWorld, b2Vec2 Position);
};

#endif // SWORD_H
