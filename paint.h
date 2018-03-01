#ifndef PAINT_H_INCLUDED
#define PAINT_H_INCLUDED

#include"AVL.h"

#include<windows.h>
#include<wincon.h>
#include<conio.h>  //控制台函数用的头文件
#include<io.h>    //IO
#include<math.h>

HANDLE gh_std_out;
DWORD ul;

void GotoXY(int x, int y);
void Show_Cursor(BOOL boo);
void DrawBox(SMALL_RECT *pRc);
bool SetConsoleColor(WORD wAttributes);

#endif // PAINT_H_INCLUDED
