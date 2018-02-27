#include"paint.h"

HANDLE gh_std_out;          /*标准输出设备句柄*/
DWORD ul; //着色长度
int Lv;

/**
 * 函数名称: GotoXY
 * 函数功能: 把光标移到屏幕上的XY处.
 * 输入参数: 无
 * 输出参数: 无
 * 返 回 值: 无
 *
 * 调用说明:
 */
void GotoXY(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(gh_std_out, pos);
}

/**
 * 函数名称:Show_Cursor
 * 函数功能: 显示或隐藏控制台光标.
 * 输入参数: 无
 * 输出参数: 无
 * 返 回 值: 无
 *
 * 调用说明:
 */

void Show_Cursor(BOOL boo)
{
    CONSOLE_CURSOR_INFO lpCur; //控制台光标信息

    GetConsoleCursorInfo(gh_std_out, &lpCur); //检索有关指定的控制台屏幕缓冲区的光标的可见性和大小信息。
    lpCur.bVisible = boo;
    SetConsoleCursorInfo(gh_std_out, &lpCur);
}


/**
 * 函数名称: DrawBox
 * 函数功能: 在指定区域画边框.
 * 输入参数: pRc 存放区域位置信息的地址
 * 输出参数: 无
 * 返 回 值: 无
 *
 * 调用说明:
 */
void DrawBox(SMALL_RECT *pRc)
{
    char chBox[] = {'+','-','|'};  /*画框用的字符*/
    COORD pos = {pRc->Left, pRc->Top};  /*定位在区域的左上角*/

    WriteConsoleOutputCharacter(gh_std_out, &chBox[0], 1, pos, &ul);/*画边框左上角*/
    for (pos.X = pRc->Left + 1; pos.X < pRc->Right; pos.X++)
    {   /*此循环画上边框横线*/
        WriteConsoleOutputCharacter(gh_std_out, &chBox[1], 1, pos, &ul);
    }
    pos.X = pRc->Right;
    WriteConsoleOutputCharacter(gh_std_out, &chBox[0], 1, pos, &ul);/*画边框右上角*/
    for (pos.Y = pRc->Top+1; pos.Y < pRc->Bottom; pos.Y++)
    {   /*此循环画边框左边线和右边线*/
        pos.X = pRc->Left;
        WriteConsoleOutputCharacter(gh_std_out, &chBox[2], 1, pos, &ul);
        pos.X = pRc->Right;
        WriteConsoleOutputCharacter(gh_std_out, &chBox[2], 1, pos, &ul);
    }
    pos.X = pRc->Left;
    pos.Y = pRc->Bottom;
    WriteConsoleOutputCharacter(gh_std_out, &chBox[0], 1, pos, &ul);/*画边框左下角*/
    for (pos.X = pRc->Left + 1; pos.X < pRc->Right; pos.X++)
    {   /*画下边框横线*/
        WriteConsoleOutputCharacter(gh_std_out, &chBox[1], 1, pos, &ul);
    }
    pos.X = pRc->Right;
    WriteConsoleOutputCharacter(gh_std_out, &chBox[0], 1, pos, &ul);/*画边框右下角*/
    return;
}

void PaintTree(AVLtree T)
{
    count = 0, Lv = 0;
    AVLtree queue[100];
    paint_LevelOrderTraverse(T, queue, queue);
    getch();
}

void paint_LevelOrderTraverse(AVLtree T, AVLtree *F,AVLtree *H )
{
    if(T == NULL)
    {
        tree_print(-1024);
        return;
    }
    *F=T;            //将当前节点放入队列首指针所指位置
    tree_print((*F)->data.id);

    //if((*F)->lchild != NULL)
    //{
        H=H+1;             //头指针后移
        *H=(*F)->lchild;    //节点的左儿子放入队头
    //}


    //if((*F)->rchild != NULL)
    //{
        H=H+1;                //头针向后移动一格
        *H=(*F)->rchild;    //节点的右儿子放入队头
   // }

    F=F+1;    //尾指针后移一位
    //if(F != H || (*F)->lchild != NULL || (*F)->rchild != NULL)   //当队头不等于队尾时递归， 此时要注意队尾也有可能有左子树右子树没有进队列
        paint_LevelOrderTraverse(*F ,F ,H);//递归
    //else
        tree_print((*F)->data.id);    //输出尾指针
    return;
}

void tree_print(int i)
{
    if(i == -1024)
        printf(" 000 ");
    else
        printf("%d   ", i);
    if(count == (int)pow(2,Lv)-1)
    {
        Lv++ , count = 0;
        printf("\n");
    }
    else
        count++;

}
