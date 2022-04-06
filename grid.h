#ifndef GRID_H
#define GRID_H
#include<easyx.h>

class Grid
{
	friend class Map;
public:
	Grid(const char* pixPath = "img/pix.png");
	int number;
	~Grid() { }
private:
	IMAGE grid;
};
#endif // !MAP_H

