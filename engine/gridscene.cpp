#include "gridscene.h"

std::shared_ptr<GridObject> GridScene::getObjectInPoint(GridObject::intvec pos) {
	for (std::shared_ptr<GridObject> &obj : mObjects) {
		if (obj->collides(pos)) {
			return obj;
		}
	}

	return nullptr;
}
