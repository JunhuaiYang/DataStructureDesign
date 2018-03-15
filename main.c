/** \brief 该文件用于保存主函数
 *
 *
 */
#include"AVL.h"
#include"menu.h"

int main()
{
    gh_std_out = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出设备句柄*/
    int op=1;
    srand(time(NULL));//设置随机数种子。

    while(op)
    {
        system("cls");
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:   //ADT_menu
            ADT_main();
            break;

        case 2:
            weibo_main();
            break;


        default:
            Exit();
            break;
        }

    }
    printf("欢迎下次再使用本系统！\n");

    return 0;
}

void Exit(void)  //退出时清空所有树
{
    DestroyAVL(&gp_all_name);   //清空第一层

    AVLLink *p;

    while(gp_tree_head)   //清空第二层
    {
        p = gp_tree_head;
        gp_tree_head = gp_tree_head->next;
        DestroyAVL(&p->tree);
        free(p);
    }
}
