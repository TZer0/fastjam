#ifndef GRIDSCENE_H
#define GRIDSCENE_H

#include<vector>
#include<memory>

#include "scene.h"
#include "util.h"
#include "gridobject.h"

class GridScene : public Scene
{
public:
	std::vector<std::shared_ptr<GridObject> > mObjects;
	std::shared_ptr<GridObject> getObjectInPoint(GridObject::intvec pos);
};

#endif // GRIDSCENE_H

