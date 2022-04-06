#include<graphics.h>
#include<conio.h>
#include"map.h"
#include"element.h"
#include"littleGame.h"

void func(const Map &map) { Map map1 = map; }

int main(int argc, char *argv[])
{
	initgraph(520, 520);
	setfillcolor(RGB(255, 255, 255));
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	Map map;
	map.show();
	initGame(map);

	char ch;
	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a')
				move_left(map);
			else if (ch == 'd')
				move_right(map);
			else if (ch == 'w')
				move_up(map);
			else if (ch == 's')
				move_down(map);
			else if (ch == 'e')
				break;
		}
	}
	//_getch();
	closegraph();
	return 0;
}