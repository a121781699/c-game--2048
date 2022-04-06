#ifndef MAP_H
#define MAP_H

#define WIDTH 4
#define HEIGHT 4
#include "grid.h"
#include "element.h"
class Map
{
public:
	Map();
	void show();
	Grid* getGid(int i) { return maxGrid[i]; }
	~Map();
	Grid *maxGrid[WIDTH*HEIGHT];
	Element *element[WIDTH*HEIGHT];

	void operator=(const Map& map);
};
#endif // !MAP_H


