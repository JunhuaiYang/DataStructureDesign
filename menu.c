/** \brief 该文件用于保存菜单相关函数
 *
 *
 */
#include"menu.h"

//主菜单显示函数
void menu(void)
{
    SMALL_RECT Rec = {2, 1, 90, 15};


    SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);   //蓝色前景
    printf("\t\t\t基于AVL树表示的集合ADT实现与应用 演示系统");
    SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);   //黄色前景和灰色背景
    printf("\n\n\n\n\t\t1. 进入基于AVL表示及调用其6种基本运算实现集合ADT的基本运算");
    printf("\n\n\t\t2. 进入基于集合ADT实现应用层功能");
    printf("\n\n\t\t0. 退出");
    DrawBox(&Rec);
    GotoXY(2,16);
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);   //恢复
    printf("请输入要进行的操作：");
}

//ADT菜单显示函数
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
    SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);   //蓝色前景
    printf("\t\t基于AVL表示及调用其6种基本运算实现集合ADT的基本运算");
    SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);   //黄色前景和灰色背景
    printf("\n\n\t当前存在%d棵AVL树：", n);
    printf("\n                     1. set_init                   2. set_destroy");
    printf("\n                     3. set_AVL                    4. set_insert");
    printf("\n                     5. set_remove                 6. set_intersection");
    printf("\n                     7. set_union                  8. set_diffrence");
    printf("\n                     9. set_size                   10. set_member");
    printf("\n                     11. set_subset                12. set_equal");
    printf("\n\n                     13. PreOrderTraverse          14. InOrderTraverse");
    printf("\n                     15. PostOrderTraverse         16. PostOrderTraverse");
    printf("\n\n                     17. SaveADTData               18. LoadADTData");
    printf("\n\n                     0.  Back                ");

    DrawBox(&Rec);
    GotoXY(2,21);
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);   //恢复
    printf("请输入要进行的操作：");
}

//微博功能应用菜单显示函数
void weibo_Menu(void)
{
    SMALL_RECT Rec = {2, 1, 90, 20};

    SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);   //蓝色前景
    printf("\t\t\t基于集合ADT实现应用层功能");

    SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);   //黄色前景和灰色背景
    printf("\n\n                1. 手动添加用户名                    2. 删除用户集合中的某个用户");
    printf("\n                3. 添加某一用户的好友                4. 添加某一用户的粉丝");
    printf("\n                5. 添加某一用户的关注                6. 添加某一用户的个人喜好");
    printf("\n                7. 删除某一用户的好友                8. 删除某一用户的粉丝");
    printf("\n                9. 删除某一用户的关注                10. 删除某一用户的个人喜好");
    printf("\n                11. 查找某一用户                     12. 输出某一用户的所有信息");

    printf("\n\n                13. 共同关注                          14. 共同喜好");
    printf("\n                15. 二度好友           ");

    printf("\n\n                16. 随机生成用户名                   17. 随机生成其余所有数据");
    printf("\n                18. 输出当前所用用户名              ");

    printf("\n \n                 19. 保存数据                             20. 加载数据");
    printf("\n\n                 0.  Back                ");

    DrawBox(&Rec);
    GotoXY(2,21);
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);   //恢复
    printf("请输入要进行的操作：");
}

//ADT菜单执行函数
void ADT_main(void)
{
    int op = 1;
    int t, sn, i;
    char name[10];
    AVLLink *temp, *temp2;
    AVLtree queue[100];
    Info tinfo;
    int array[100];

    while(op)
    {
        system("cls");
        ADT_menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:   //set_init
            temp = set_init(&gp_tree_head);
            printf("节点创建成功！\n");

            printf("请输入要插入的数据的个数：");
            scanf("%d", &sn);
            printf("\n请输入要插入的元素：\n");
            for(i=0; i<sn; i++)
            {
                scanf("%d", &array[i]);
                printf("    ");
            }
            set_AVL(temp, array, sn);
            printf("\n新建成功！");
            getch();
            break;

        case 2:  //set_destroy
            if(set_destory(&gp_tree_head))
                printf("删除成功！\n");
            else
                printf("删除失败！");
            getch();
            break;

        case 3:  //set_AVL      同set_init
            temp = set_init(&gp_tree_head);
            printf("节点创建成功！\n");

            printf("请输入要插入的数据的个数：");
            scanf("%d", &sn);
            printf("\n请输入要插入的元素：\n");
            for(i=0; i<sn; i++)
            {
                scanf("%d", &array[i]);
                printf("    ");
            }
            set_AVL(temp, array, sn);
            printf("\n新建成功！");
            getch();

            break;

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
                if(newlink->tree)
                {
                    printf("\n两树的交集为：");
                    InOrderTraverse(newlink->tree, JustPrintfId);   //中序遍历输出该树
                }
                else
                    printf("\n两树的交集为空集！");
                getch();
            }
            else  //找不到
            {
                printf("查找失败！！！找不到该二叉树！");
                getch();
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
                if(newlink->tree)
                {
                    printf("\n两树的并集为：");
                    InOrderTraverse(newlink->tree, JustPrintfId);   //中序遍历输出该树
                }
                else
                    printf("\n两树的并集为空集！");
                getch();
            }
            else  //找不到
            {
                printf("查找失败！！！找不到该二叉树！");
                getch();
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

            printf("\n该操作取A-B的差集");
            printf("\n请输输入要取差集的第一个集合A：");   //找第一个
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            printf("\n请输输入要取差集的第二个集合B：");  //找第二个
            scanf("%s",name);
            temp2 = NULL;
            temp2 = FindAVLLink(gp_tree_head, name);

            if(temp2 && temp)    //找到的话
            {
                printf("\n新初始化一棵树用于保存！");
                AVLLink *newlink = set_init(&gp_tree_head);  //新初始化一棵树用于保存！
                set_difference(temp->tree, temp2->tree, &newlink->tree);
                if(newlink->tree)
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
            getch();
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
                getch();
            }
            else  //找不到
            {
                printf("\n找不到该集合！");
                getch();
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
                getch();
            }
            else  //找不到
            {
                printf("\n找不到该集合！");
                getch();
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
                getch();
            }
            else  //找不到
            {
                printf("查找失败！！！找不到该二叉树！");
                getch();
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
                getch();
            }
            else  //找不到
            {
                printf("查找失败！！！找不到该二叉树！");
                getch();
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
                PostOrderTraverse(temp->tree, JustPrintfId);
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
            SaveADTData(gp_tree_head);
            break;

        case 18:  //LoadADTData
            LoadADTData(&gp_tree_head);
            break;

        default:
            break;
        }
    }
}


//微博功能菜单执行函数
void weibo_main(void)
{
    int op = 1;

    while(op)
    {
        system("cls");
        weibo_Menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:  //手动添加用户名
            WriteOneName();
            getch();
            break;

        case 2:  //删除用户集合中的某个用户
            DeleteUser();
            getch();
            break;

        case 3://添加某一用户的好友
            AddOnesFriend();
            getch();
            break;

        case 4://添加某一用户的粉丝
            AddOnesFans();
            getch();
            break;

        case 5://添加某一用户的关注
            AddOnesAtt();
            getch();
            break;

        case 6://添加某一用户的个人喜好
            AddOnesHobby();
            getch();
            break;

        case 7://删除某一用户的好友
            DeleteOneFriend();
            getch();
            break;

        case 8://删除某一用户的粉丝
            DeleteOneFans();
            getch();
            break;

        case 9://删除某一用户的关注
            DeleteOneAtt();
            getch();
            break;

        case 10://删除某一用户的个人喜好
            DeleteOneHobby();
            getch();
            break;

        case 11://查找某一用户
            PutOneInfo();
            getch();
            break;

        case 12://输出某一用户的所有信息
            PutOneInfo();
            getch();
            break;

        case 13://共同关注
            SameAtt();
            getch();
            break;

        case 14://共同喜好
            SameHobby();
            getch();
            break;

        case 15://二度好友
            TwoFriend();
            getch();
            break;

        case 16://随机生成用户名
            RandName();
            getch();
            break;

        case 17://随机生成所有信息
            RandAllInfo(gp_all_name);
            getch();
            break;

        case 18://输出当前所用用户名
            TraverseAllName();
            getch();
            break;

        case 19://保存数据
            SaveName();
            SaveInfo();
            getch();
            break;

        case 20://加载数据
            LoadName();
            LoadInfo();
            getch();
            break;


        default://Back
            break;
        }

    }
}
