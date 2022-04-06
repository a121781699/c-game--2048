#include "grid.h"

Grid::Grid(const char* pixPath)
{
	loadimage(&grid, pixPath);
	number = 0;
}
