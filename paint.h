/** \brief ���ļ����ڱ��潻��������غ�������
 *
 */
#ifndef PAINT_H_INCLUDED
#define PAINT_H_INCLUDED

#include"AVL.h"

#include<windows.h>
#include<wincon.h>
#include<conio.h>  //����̨�����õ�ͷ�ļ�
#include<io.h>    //IO
#include<math.h>

//ȫ�ֱ���
HANDLE gh_std_out;  //��׼������
DWORD ul;      //���ڱ����DWORD����

//����Ļ���в�����һЩ����
void GotoXY(int x, int y);
void Show_Cursor(BOOL boo);
void DrawBox(SMALL_RECT *pRc);
bool SetConsoleColor(WORD wAttributes);

#endif // PAINT_H_INCLUDED
