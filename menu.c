#include"menu.h"

void menu(void)
{
    SMALL_RECT Rec = {2, 2, 90, 15};

    printf("\t\t基于AVL树表示的集合ADT实现与应用 演示系统");
    printf("\n\n\n\n\t\t1. 进入基于AVL表示及调用其6种基本运算实现集合ADT的基本运算");
    printf("\n\n\t\t2. 进入基于集合ADT实现应用层功能");
    printf("\n\n\t\t3. 数据的储存与读取");
    DrawBox(&Rec);
    GotoXY(2,16);
    printf("请输入要进行的操作：");
}


void ADT_menu()
{
    SMALL_RECT Rec = {2, 2, 90, 20};
    printf("\t\t基于AVL表示及调用其6种基本运算实现集合ADT的基本运算");
    printf("\n\n\n                     1. set_init                   2. set_destroy");
    printf("\n\n                     3. new_AVL                    4. set_insert");
    printf("\n\n                     5. set_remove                 6. set_intersection");
    printf("\n\n                     7. set_union                  8. set_diffrence");
    printf("\n\n                     9. set_size                   10. set_member");
    printf("\n\n                     11. set_subset                12. set_equal");

    DrawBox(&Rec);
}
