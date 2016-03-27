#ifndef ITEM_H
#define ITEM_H

#include <Box2D/Box2D.h>


class Item
{
public:
    Item();

    b2Vec2 GetPosition();

//protected:
    b2Body *Body;

};

#endif // ITEM_H
