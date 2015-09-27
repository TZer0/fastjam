#include "gridobject.h"

GridObject::GridObject(intvec pos) : mPos(pos)
{
}

GridObject::GridObject(intvec pos, intvec size) : mPos(pos)
{
	mColliders.push_back(intrec(intvec(), size));
}
