#include"menu.h"

void menu(void)
{
    SMALL_RECT Rec = {2, 2, 118, 29};

    printf("\t\t基于AVL树表示的集合ADT实现与应用 演示系统");
    DrawBox(&Rec);

    printf("\t\t1. 进入基于AVL表示及调用其6种基本运算实现集合ADT的基本运算\n");
    printf("\n\t\t2. 进入基于集合ADT实现应用层功能");
    printf("\n\t\t3. 数据的储存与读取");

}
