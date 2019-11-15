#include "Position.h"
#include <windows.h>
Position::Position(int x, int y)
{
	COORD CursorPosition = {x,y}; //Mengatur posisi
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CursorPosition);
}
