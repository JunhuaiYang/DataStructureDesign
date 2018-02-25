#include"AVL.h"
#include"menu.h"

int main()
{
    gh_std_out = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出设备句柄*/
    ADT_menu();
    getch();
    return 0;
}
