#include"menu.h"

void menu(void)
{
    SMALL_RECT Rec = {2, 2, 90, 15};

    printf("\t\t基于AVL树表示的集合ADT实现与应用 演示系统");
    printf("\n\n\n\n\t\t1. 进入基于AVL表示及调用其6种基本运算实现集合ADT的基本运算");
    printf("\n\n\t\t2. 进入基于集合ADT实现应用层功能");
    printf("\n\n\t\t3. 数据的储存与读取");
    printf("\n\n\t\t0. 退出");
    DrawBox(&Rec);
    GotoXY(2,16);
    printf("请输入要进行的操作：");
}


void ADT_menu()
{
    SMALL_RECT Rec = {2, 1, 90, 20};
    AVLLink *p = gp_tree_head;
    int n=0;

    while(p)   //几棵树计数
    {
        n++;
        p = p->next;
    }
    printf("\t\t基于AVL表示及调用其6种基本运算实现集合ADT的基本运算");
    printf("\n\n\t当前存在%d棵AVL树：", n);
    printf("\n                     1. set_init                   2. set_destroy");
    printf("\n                     3. set_AVL                    4. set_insert");
    printf("\n                     5. set_remove                 6. set_intersection");
    printf("\n                     7. set_union                  8. set_diffrence");
    printf("\n                     9. set_size                   10. set_member");
    printf("\n                     11. set_subset                12. set_equal");
    printf("\n\n                     13. PreOrderTraverse          14. InOrderTraverse");
    printf("\n                     15. PostOrderTraverse         16. PostOrderTraverse");
    printf("\n\n                     17. SaveADTData                  18. LoadADTData");
    printf("\n\n                     19. PaintTree                    0.  Back                ");

    DrawBox(&Rec);
    GotoXY(2,21);
    printf("请输入要进行的操作：");
}

void ADT_main(void)
{
    int op = 1;
    int sn, i, t;
    char name[10];
    AVLLink *temp, *temp2;
    AVLtree queue[100];
    Info tinfo;

    while(op)
    {
        system("cls");
        ADT_menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:   //set_init
            set_init(&gp_tree_head);
            printf("节点创建成功！\n");
            getch();
            break;

        case 2:  //set_destroy
            if(set_destory(&gp_tree_head))
                printf("删除成功！\n");
            else
                printf("删除失败！");
            getch();
            break;

        case 3:  //set_AVL
            {
            if(gp_tree_head == NULL)   //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("请输入要插入的数据的个数：");
            scanf("%d", &sn);
            int array[100];
            printf("\n请输入要插入的元素：\n");
            for(i=0; i<sn; i++)
            {
                scanf("%d", &array[i]);
                printf("    ");
            }
            set_AVL(gp_tree_head, array, sn);
            printf("\n新建成功！");
            getch();
            break;
            }

        case 4:  //set_insert
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前存在的树：\n");
            temp = gp_tree_head;
            while(temp)         //遍历输出当前存在的树
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }
            printf("\n请输入要操作的二叉树名称: ");
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);
            if(temp)   //找到
            {
                printf("请输入要插入的数据：");
                scanf("%d",&tinfo.id);
                set_insert(&temp->tree, tinfo);
                printf("\n插入成功！\n");
            }
            else
            {
                printf("查找失败！！！找不到该二叉树！");
            }
            getch();
            break;

        case 5:  //set_remove
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前存在的树：\n");
            temp = gp_tree_head;
            while(temp)         //遍历输出当前存在的树
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }
            printf("\n请输入要操作的二叉树名称: ");
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);
            if(temp)   //找到
            {
                printf("\n当前树的节点为：");
                InOrderTraverse(temp->tree, JustPrintfId);
                printf("\n请输入要删除的元素：");
                scanf("%d", &t);
                if(set_remove(&temp->tree, t))
                    printf("\n删除成功！");
                else
                    printf("\n删除失败");
            }
            else
            {
                printf("查找失败！！！找不到该二叉树！");
            }
            getch();
            break;

        case 6:  //set_intersection
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前存在的树：\n");
            temp = gp_tree_head;
            while(temp)         //遍历输出当前存在的树
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n请输输入要取交集的第一个集合：");   //找第一个
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            printf("\n请输输入要取交集的第二个集合：");  //找第二个
            scanf("%s",name);
            temp2 = NULL;
            temp2 = FindAVLLink(gp_tree_head, name);

            if(temp2 && temp)    //找到的话
            {
                printf("\n新初始化一棵树用于保存！");
                AVLLink *newlink = set_init(&gp_tree_head);  //新初始化一棵树用于保存！
                set_intersection(temp->tree, temp2->tree, &newlink->tree);
                if(newlink)
                {
                    printf("\n两树的交集为：");
                    InOrderTraverse(newlink->tree, JustPrintfId);   //中序遍历输出该树
                }
                else
                    printf("\n两树的交集为空集！");
            }
            else  //找不到
            {
                printf("查找失败！！！找不到该二叉树！");
            }

            break;

        case 7:  //set_union
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前存在的树：\n");
            temp = gp_tree_head;
            while(temp)         //遍历输出当前存在的树
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n请输输入要取并集的第一个集合：");   //找第一个
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            printf("\n请输输入要取并集的第二个集合：");  //找第二个
            scanf("%s",name);
            temp2 = NULL;
            temp2 = FindAVLLink(gp_tree_head, name);

            if(temp2 && temp)    //找到的话
            {
                printf("\n新初始化一棵树用于保存！");
                AVLLink *newlink = set_init(&gp_tree_head);  //新初始化一棵树用于保存！
                set_union(temp->tree, temp2->tree, &newlink->tree);
                if(newlink)
                {
                    printf("\n两树的并集为：");
                    InOrderTraverse(newlink->tree, JustPrintfId);   //中序遍历输出该树
                }
                else
                    printf("\n两树的并集为空集！");
            }
            else  //找不到
            {
                printf("查找失败！！！找不到该二叉树！");
            }

            break;

        case 8:  //set_diffrence
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前存在的树：\n");
            temp = gp_tree_head;
            while(temp)         //遍历输出当前存在的树
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n请输输入要取差集的第一个集合：");   //找第一个
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            printf("\n请输输入要取差集的第二个集合：");  //找第二个
            scanf("%s",name);
            temp2 = NULL;
            temp2 = FindAVLLink(gp_tree_head, name);

            if(temp2 && temp)    //找到的话
            {
                printf("\n新初始化一棵树用于保存！");
                AVLLink *newlink = set_init(&gp_tree_head);  //新初始化一棵树用于保存！
                set_difference(temp->tree, temp2->tree, &newlink->tree);
                if(newlink)
                {
                    printf("\n两树的差集为：");
                    InOrderTraverse(newlink->tree, JustPrintfId);   //中序遍历输出该树
                }
                else
                    printf("\n两树的差集为空集！");
            }
            else  //找不到
            {
                printf("查找失败！！！找不到该二叉树！");
            }
            break;

        case 9:  //set_size
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前存在的树：\n");
            temp = gp_tree_head;
            while(temp)         //遍历输出当前存在的树
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n请输输入要取成员个数的集合：");
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            if(temp)   //找到
            {
                printf("\n该集合的成员个数为 %d", set_size(temp->tree));
            }
            else  //找不到
            {
                printf("\n找不到该集合！");
            }
            break;

        case 10:  //set_member
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前存在的树：\n");
            temp = gp_tree_head;
            while(temp)         //遍历输出当前存在的树
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n请输输入要查找成员的集合：");
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            if(temp)   //找到
            {
                printf("\n请输入要查找的元素：");
                scanf("%d", &t);
                if(set_member(temp->tree, t))
                    printf("\n该元素存在！");
                else
                    printf("\n该元素不存在！");
            }
            else  //找不到
            {
                printf("\n找不到该集合！");
            }
            break;

        case 11:  //set_subset
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前存在的树：\n");
            temp = gp_tree_head;
            while(temp)         //遍历输出当前存在的树
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n判断 T 是否为 P 的子集：");
            printf("\n请输入第一个集合T：");   //找第一个
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            printf("\n请输入第二个集合P：");  //找第二个
            scanf("%s",name);
            temp2 = NULL;
            temp2 = FindAVLLink(gp_tree_head, name);

            if(temp2 && temp)    //找到的话
            {
                if(set_subset(temp->tree, temp2->tree))
                {
                    printf("\nT 为 P 的子集！");
                }
                else
                    printf("\nT 不为 P 的子集！");
            }
            else  //找不到
            {
                printf("查找失败！！！找不到该二叉树！");
            }
            break;

        case 12:  //set_equal
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前存在的树：\n");
            temp = gp_tree_head;
            while(temp)         //遍历输出当前存在的树
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n请输输入要判断相等的第一个集合：");   //找第一个
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            printf("\n请输输入要判断相等的第二个集合：");  //找第二个
            scanf("%s",name);
            temp2 = NULL;
            temp2 = FindAVLLink(gp_tree_head, name);

            if(temp2 && temp)    //找到的话
            {

                if(set_equal(temp->tree, temp2->tree))
                {
                    printf("\n两树相等！");
                }
                else
                    printf("\n两树不相等！！");
            }
            else  //找不到
            {
                printf("查找失败！！！找不到该二叉树！");
            }
            break;

        case 13:  //PreOrderTraverse
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前所有的二叉树前序遍历：\n");
            temp = gp_tree_head;
            while(temp)
            {
                printf("\n%s:  ", temp->name);
                PreOrderTraverse(temp->tree, JustPrintfId);
                temp = temp->next;
            }
            getch();
            break;

        case 14:  //InOrderTraverse
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前所有的二叉树中序遍历：\n");
            temp = gp_tree_head;
            while(temp)
            {
                printf("\n%s:  ", temp->name);
                InOrderTraverse(temp->tree, JustPrintfId);
                temp = temp->next;
            }
            getch();
            break;

        case 15:  //PostOrderTraverse
            if (gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前所有的二叉树后序遍历：\n");
            temp = gp_tree_head;
            while(temp)
            {
                printf("\n%s:  ", temp->name);
                PreOrderTraverse(temp->tree, JustPrintfId);
                temp = temp->next;
            }
            getch();
            break;

        case 16:  //LevelOrderTraverse
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前所有的二叉树按层遍历：\n");
            temp = gp_tree_head;
            while(temp)
            {
                printf("\n%s:  ", temp->name);
                LevelOrderTraverse(temp->tree, JustPrintfId,queue, queue);
                temp = temp->next;
            }
            getch();
            break;

        case 17:  //SaveADTData
            break;

        case 18:  //LoadADTData
            break;

        case 19:  //PaintTree
            if(gp_tree_head == NULL)  //没有初始化头结点
            {
                printf("当前没有初始化节点，请初始化！");
                getch();
                break;
            }
            printf("当前存在的树：\n");
            temp = gp_tree_head;
            while(temp)         //遍历输出当前存在的树
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n请输输入要打印的二叉树：");
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            if(temp)   //找到
            {
                PaintTree(temp->tree);
            }
            else  //找不到
            {
                printf("\n找不到该集合！");
            }
            break;
            break;

        default:
            break;
        }
    }
}





