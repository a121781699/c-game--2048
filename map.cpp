#include "map.h"

Map::Map()
{
	for (int i = 0; i < HEIGHT*WIDTH; ++i)
	{
		maxGrid[i] = new Grid;
		element[i] = NULL;
	}
}
void Map::show()
{
	for (int i = 0; i < HEIGHT*WIDTH; ++i)
		putimage((i % 4) * 130, (i / 4) * 130, &maxGrid[i]->grid);
}
void Map::operator=(const Map &map)
{
	for (int i = 0; i < HEIGHT*WIDTH; ++i)
		this->maxGrid[i]->number = map.maxGrid[i]->number;
}
Map::~Map()
{
	for (int i = 0; i < HEIGHT*WIDTH; ++i)
		delete maxGrid[i];
	for (int i = 0; i < HEIGHT*WIDTH; ++i)
		if (element[i])
			delete element[i];
}