#ifndef GRIDOBJECT_H
#define GRIDOBJECT_H

#include "gameobject.h"
#include "util.h"
#include <vector>

class GridObject : GameObject
{
public:
	typedef Vector2D<int> intvec;
	typedef Rectangle<int> intrec;
	GridObject(intvec pos);
	GridObject(intvec pos, intvec size);
	intvec mPos;
	std::vector<intrec> mColliders;

	bool collides(const intvec &pos) {
		for (const intrec &rec : mColliders) {
			if (rec.collides(pos, mPos)) {
				return true;
			}
		}
		return false;
	}
};

#endif // GRIDOBJECT_H
