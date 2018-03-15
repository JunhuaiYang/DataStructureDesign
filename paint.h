/** \brief 该文件用于保存交互界面相关函数申明
 *
 */
#ifndef PAINT_H_INCLUDED
#define PAINT_H_INCLUDED

#include"AVL.h"

#include<windows.h>
#include<wincon.h>
#include<conio.h>  //控制台函数用的头文件
#include<io.h>    //IO
#include<math.h>

//全局变量
HANDLE gh_std_out;  //标准输出句柄
DWORD ul;      //用于保存的DWORD变量

//对屏幕进行操作的一些函数
void GotoXY(int x, int y);
void Show_Cursor(BOOL boo);
void DrawBox(SMALL_RECT *pRc);
bool SetConsoleColor(WORD wAttributes);

#endif // PAINT_H_INCLUDED
