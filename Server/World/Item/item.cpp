#include "item.h"

Item::Item()
{

}


b2Vec2 Item::GetPosition()
{
    return Body->GetPosition();
}
