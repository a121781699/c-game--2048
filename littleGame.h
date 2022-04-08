#ifndef LITTLEGAME_H
#define LITTLEGAME_H
#include"map.h"
#include"element.h"
#include<time.h>
#include<stdio.h>
int random()
{
	srand((unsigned)time(NULL));
	return rand() % 4;
}
void initGame(Map &map)
{
	int i = random();
	int j = random();
	Element *e1 = new Element("img/pix2.png"); 
	map.element[j * 4 + i] = e1;
	putimage(i * 133, j * 133, &e1->elem);
	map.maxGrid[j * 4 + i]->number = 2;
}
bool equalMaps(const Map &map1, const Map &map2)
{
	for (int i = 0; i < HEIGHT*WIDTH; ++i)
	{
		if (map1.maxGrid[i]->number != map2.maxGrid[i]->number)
			return false;
	}
	return true;
}
void move_left(Map &map)
{
	Map map_copy;
	map_copy = map;
	//combine one number with the same number of its left neighboor
	for (int j = 0; j < HEIGHT; ++j)
	{
		for (int i = j * HEIGHT; i < j*HEIGHT + WIDTH - 1; ++i)
		{
			int k = i + 1;
			if (map.maxGrid[i]->number)
			{
				while (k < j*HEIGHT + WIDTH - 1 && !map.maxGrid[k]->number)
					++k;
				if (map.maxGrid[i]->number == map.maxGrid[k]->number)
				{
					map.maxGrid[i]->number *= 2;
					map.maxGrid[k]->number = 0;
				}
			}
		}
	}

	//move all the grid to left on full steps
	for (int cir = 0; cir < WIDTH; ++cir)
	{
		//move all the grid to left on one step
		for (int j = 0; j < HEIGHT; ++j)
		{
			for (int i = j * HEIGHT; i <= j * HEIGHT + WIDTH - 1; ++i)
			{
				bool flag = false;
				if (i == j * HEIGHT && map.maxGrid[i]->number) flag = true;
				if (!flag)
				{
					if (i == j * HEIGHT) continue;
					if (map.maxGrid[i]->number && !map.maxGrid[i - 1]->number)
					{
						map.maxGrid[i - 1]->number = map.maxGrid[i]->number;
						map.maxGrid[i]->number = 0;
					}
				}
			}
		}
	}

	//create number on random place
	bool cflag = equalMaps(map_copy, map);
	int i = random();
	int j = random();
	int num = j * 4 + i;
	while (!cflag)
	{
		if (!map.maxGrid[num]->number)
		{
			map.maxGrid[num]->number = 2;
			cflag = true;
		}
		++num;
		num = num % 16;
	}

	//paint all elements of map
	cleardevice();
	map.show();
	for (int i = 0; i < HEIGHT*WIDTH; ++i)
	{
		if (map.maxGrid[i]->number)
		{
			char filename[256];
			sprintf(filename, "img/pix%d.png", map.maxGrid[i]->number);
			Element *e1 = new Element(filename);
			if (map.element[i])
			{
				delete map.element[i];
				map.element[i] = NULL;
			}
			map.element[i] = e1;
			putimage((i % 4) * 133, (i / 4) * 133, &e1->elem);
		}
	}
}

void move_right(Map &map)
{
	Map map_copy;
	map_copy = map;
	//combine one number with the same number of its right neighboor
	for (int j = 0; j < HEIGHT; ++j)
	{
		for (int i = j * HEIGHT + WIDTH - 1; i > j * HEIGHT; --i)
		{
			int k = i - 1;
			if (map.maxGrid[i]->number)
			{
				while (k > j * HEIGHT && !map.maxGrid[k]->number)
					--k;
				if (map.maxGrid[i]->number == map.maxGrid[k]->number)
				{
					map.maxGrid[i]->number = 0;
					map.maxGrid[k]->number *= 2;
					i = k;
				}
			}
		}
	}

	//move all the grid to right on full steps 
	for (int cir = 0; cir < WIDTH; ++cir)
	{
		//move all the grid to right on one step 
		for (int j = 0; j < HEIGHT; ++j)
		{
			for (int i = j * HEIGHT + WIDTH - 1; i >= j * HEIGHT; --i)
			{
				bool flag = false;
				if (i == j * HEIGHT + WIDTH - 1 && map.maxGrid[i]->number) flag = true;
				if (!flag)
				{
					if (i == j * HEIGHT + WIDTH - 1) continue;
					if (map.maxGrid[i]->number && !map.maxGrid[i + 1]->number)
					{
						map.maxGrid[i + 1]->number = map.maxGrid[i]->number;
						map.maxGrid[i]->number = 0;
					}
				}
			}
		}
	}

	//create number on random place
	bool cflag = equalMaps(map_copy, map);
	int i = random();
	int j = random();
	int num = j * 4 + i;
	while (!cflag)
	{
		if (!map.maxGrid[num]->number)
		{
			map.maxGrid[num]->number = 2;
			cflag = true;
		}
		++num;
		num = num % 16;
	}

	//paint all elements of map
	cleardevice();
	map.show();
	for (int i = 0; i < HEIGHT*WIDTH; ++i)
	{
		if (map.maxGrid[i]->number)
		{
			char filename[256];
			sprintf(filename, "img/pix%d.png", map.maxGrid[i]->number);
			Element *e1 = new Element(filename);
			if (map.element[i])
			{
				delete map.element[i];
				map.element[i] = NULL;
			}
			map.element[i] = e1;
			putimage((i % 4) * 133, (i / 4) * 133, &e1->elem);
		}
	}
}

void move_up(Map &map)
{
	Map map_copy;
	map_copy = map;
	//combine one number with the same number of its above neighboor
	for (int j = 0; j < HEIGHT; ++j)
	{
		for (int i = j; i < (WIDTH - 1)*HEIGHT + j; i += WIDTH)
		{
			int k = i + WIDTH;
			if (map.maxGrid[i]->number)
			{
				while (k < (WIDTH - 1)*HEIGHT + j && !map.maxGrid[k]->number)
					k += WIDTH;
				if (map.maxGrid[i]->number == map.maxGrid[k]->number)
				{
					map.maxGrid[i]->number *= 2;
					map.maxGrid[k]->number = 0;
				}
			}
		}
	}

	//move all the grid to up on full steps 
	for (int cir = 0; cir < WIDTH; ++cir)
	{
		//move all the grid to up on one step 
		for (int j = 0; j < HEIGHT; ++j)
		{
			for (int i = j; i <= (WIDTH - 1)*HEIGHT + j; i += WIDTH)
			{
				bool flag = false;
				if (i == j && map.maxGrid[i]->number) flag = true;
				if (!flag)
				{
					if (i == j) continue;
					if (map.maxGrid[i]->number && !map.maxGrid[i - WIDTH]->number)
					{
						map.maxGrid[i - WIDTH]->number = map.maxGrid[i]->number;
						map.maxGrid[i]->number = 0;
					}
				}
			}
		}
	}

	//create number on random place
	bool cflag = equalMaps(map_copy, map);
	int i = random();
	int j = random();
	int num = j * 4 + i;
	while (!cflag)
	{
		if (!map.maxGrid[num]->number)
		{
			map.maxGrid[num]->number = 2;
			cflag = true;
		}
		++num;
		num = num % 16;
	}

	//paint all elements of map
	cleardevice();
	map.show();
	for (int i = 0; i < HEIGHT*WIDTH; ++i)
	{
		if (map.maxGrid[i]->number)
		{
			char filename[256];
			sprintf(filename, "img/pix%d.png", map.maxGrid[i]->number);
			Element *e1 = new Element(filename);
			if (map.element[i])
			{
				delete map.element[i];
				map.element[i] = NULL;
			}
			map.element[i] = e1;
			putimage((i % 4) * 133, (i / 4) * 133, &e1->elem);
		}
	}
}

void move_down(Map &map)
{
	Map map_copy;
	map_copy = map;
	//combine one number with the same number of its down neighboor
	for (int j = 0; j < HEIGHT; ++j)
	{
		for (int i = (WIDTH - 1)*HEIGHT + j; i > j; i -= WIDTH)
		{
			int k = i - WIDTH;
			if (map.maxGrid[i]->number)
			{
				while (k > j && !map.maxGrid[k]->number)
					k -= WIDTH;
				if (map.maxGrid[i]->number == map.maxGrid[k]->number)
				{
					map.maxGrid[i]->number = 0;
					map.maxGrid[k]->number *= 2;
					i = k;
				}
			}
		}
	}

	//move all the grid to down on full steps 
	for (int cir = 0; cir < WIDTH; ++cir)
	{
		//move all the grid to down on one step 
		for (int j = 0; j < HEIGHT; ++j)
		{
			for (int i = (WIDTH - 1)*HEIGHT + j; i >= j; i -= WIDTH)
			{
				bool flag = false;
				if (i == (WIDTH - 1)*HEIGHT + j && map.maxGrid[i]->number) flag = true;
				if (!flag)
				{
					if (i == (WIDTH - 1)*HEIGHT + j) continue;
					if (map.maxGrid[i]->number && !map.maxGrid[i + WIDTH]->number)
					{
						map.maxGrid[i + WIDTH]->number = map.maxGrid[i]->number;
						map.maxGrid[i]->number = 0;
					}
				}
			}
		}
	}

	//create number on random place
	bool cflag = equalMaps(map_copy, map);
	int i = random();
	int j = random();
	int num = j * 4 + i;
	while (!cflag)
	{
		if (!map.maxGrid[num]->number)
		{
			map.maxGrid[num]->number = 2;
			cflag = true;
		}
		++num;
		num = num % 16;
	}

	//paint all elements of map
	cleardevice();
	map.show();
	for (int i = 0; i < HEIGHT*WIDTH; ++i)
	{
		if (map.maxGrid[i]->number)
		{
			char filename[256];
			sprintf(filename, "img/pix%d.png", map.maxGrid[i]->number);
			Element *e1 = new Element(filename);
			if (map.element[i])
			{
				delete map.element[i];
				map.element[i] = NULL;
			}
			map.element[i] = e1;
			putimage((i % 4) * 133, (i / 4) * 133, &e1->elem);
		}
	}
}
#endif // !LITTLEGAME_H

