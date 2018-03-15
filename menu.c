/** \brief ���ļ����ڱ���˵���غ���
 *
 *
 */
#include"menu.h"

//���˵���ʾ����
void menu(void)
{
    SMALL_RECT Rec = {2, 1, 90, 15};


    SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);   //��ɫǰ��
    printf("\t\t\t����AVL����ʾ�ļ���ADTʵ����Ӧ�� ��ʾϵͳ");
    SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);   //��ɫǰ���ͻ�ɫ����
    printf("\n\n\n\n\t\t1. �������AVL��ʾ��������6�ֻ�������ʵ�ּ���ADT�Ļ�������");
    printf("\n\n\t\t2. ������ڼ���ADTʵ��Ӧ�ò㹦��");
    printf("\n\n\t\t0. �˳�");
    DrawBox(&Rec);
    GotoXY(2,16);
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);   //�ָ�
    printf("������Ҫ���еĲ�����");
}

//ADT�˵���ʾ����
void ADT_menu()
{
    SMALL_RECT Rec = {2, 1, 90, 20};
    AVLLink *p = gp_tree_head;
    int n=0;

    while(p)   //����������
    {
        n++;
        p = p->next;
    }
    SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);   //��ɫǰ��
    printf("\t\t����AVL��ʾ��������6�ֻ�������ʵ�ּ���ADT�Ļ�������");
    SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);   //��ɫǰ���ͻ�ɫ����
    printf("\n\n\t��ǰ����%d��AVL����", n);
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
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);   //�ָ�
    printf("������Ҫ���еĲ�����");
}

//΢������Ӧ�ò˵���ʾ����
void weibo_Menu(void)
{
    SMALL_RECT Rec = {2, 1, 90, 20};

    SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);   //��ɫǰ��
    printf("\t\t\t���ڼ���ADTʵ��Ӧ�ò㹦��");

    SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);   //��ɫǰ���ͻ�ɫ����
    printf("\n\n                1. �ֶ�����û���                    2. ɾ���û������е�ĳ���û�");
    printf("\n                3. ���ĳһ�û��ĺ���                4. ���ĳһ�û��ķ�˿");
    printf("\n                5. ���ĳһ�û��Ĺ�ע                6. ���ĳһ�û��ĸ���ϲ��");
    printf("\n                7. ɾ��ĳһ�û��ĺ���                8. ɾ��ĳһ�û��ķ�˿");
    printf("\n                9. ɾ��ĳһ�û��Ĺ�ע                10. ɾ��ĳһ�û��ĸ���ϲ��");
    printf("\n                11. ����ĳһ�û�                     12. ���ĳһ�û���������Ϣ");

    printf("\n\n                13. ��ͬ��ע                          14. ��ͬϲ��");
    printf("\n                15. ���Ⱥ���           ");

    printf("\n\n                16. ��������û���                   17. �������������������");
    printf("\n                18. �����ǰ�����û���              ");

    printf("\n \n                 19. ��������                             20. ��������");
    printf("\n\n                 0.  Back                ");

    DrawBox(&Rec);
    GotoXY(2,21);
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);   //�ָ�
    printf("������Ҫ���еĲ�����");
}

//ADT�˵�ִ�к���
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
            printf("�ڵ㴴���ɹ���\n");

            printf("������Ҫ��������ݵĸ�����");
            scanf("%d", &sn);
            printf("\n������Ҫ�����Ԫ�أ�\n");
            for(i=0; i<sn; i++)
            {
                scanf("%d", &array[i]);
                printf("    ");
            }
            set_AVL(temp, array, sn);
            printf("\n�½��ɹ���");
            getch();
            break;

        case 2:  //set_destroy
            if(set_destory(&gp_tree_head))
                printf("ɾ���ɹ���\n");
            else
                printf("ɾ��ʧ�ܣ�");
            getch();
            break;

        case 3:  //set_AVL      ͬset_init
            temp = set_init(&gp_tree_head);
            printf("�ڵ㴴���ɹ���\n");

            printf("������Ҫ��������ݵĸ�����");
            scanf("%d", &sn);
            printf("\n������Ҫ�����Ԫ�أ�\n");
            for(i=0; i<sn; i++)
            {
                scanf("%d", &array[i]);
                printf("    ");
            }
            set_AVL(temp, array, sn);
            printf("\n�½��ɹ���");
            getch();

            break;

        case 4:  //set_insert
            if(gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���ڵ�����\n");
            temp = gp_tree_head;
            while(temp)         //���������ǰ���ڵ���
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }
            printf("\n������Ҫ�����Ķ���������: ");
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);
            if(temp)   //�ҵ�
            {
                printf("������Ҫ��������ݣ�");
                scanf("%d",&tinfo.id);
                set_insert(&temp->tree, tinfo);
                printf("\n����ɹ���\n");
            }
            else
            {
                printf("����ʧ�ܣ������Ҳ����ö�������");
            }
            getch();
            break;

        case 5:  //set_remove
            if(gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���ڵ�����\n");
            temp = gp_tree_head;
            while(temp)         //���������ǰ���ڵ���
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }
            printf("\n������Ҫ�����Ķ���������: ");
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);
            if(temp)   //�ҵ�
            {
                printf("\n��ǰ���Ľڵ�Ϊ��");
                InOrderTraverse(temp->tree, JustPrintfId);
                printf("\n������Ҫɾ����Ԫ�أ�");
                scanf("%d", &t);
                if(set_remove(&temp->tree, t))
                    printf("\nɾ���ɹ���");
                else
                    printf("\nɾ��ʧ��");

            }
            else
            {
                printf("����ʧ�ܣ������Ҳ����ö�������");
            }
            getch();
            break;

        case 6:  //set_intersection
            if(gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���ڵ�����\n");
            temp = gp_tree_head;
            while(temp)         //���������ǰ���ڵ���
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n��������Ҫȡ�����ĵ�һ�����ϣ�");   //�ҵ�һ��
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            printf("\n��������Ҫȡ�����ĵڶ������ϣ�");  //�ҵڶ���
            scanf("%s",name);
            temp2 = NULL;
            temp2 = FindAVLLink(gp_tree_head, name);

            if(temp2 && temp)    //�ҵ��Ļ�
            {
                printf("\n�³�ʼ��һ�������ڱ��棡");
                AVLLink *newlink = set_init(&gp_tree_head);  //�³�ʼ��һ�������ڱ��棡
                set_intersection(temp->tree, temp2->tree, &newlink->tree);
                if(newlink->tree)
                {
                    printf("\n�����Ľ���Ϊ��");
                    InOrderTraverse(newlink->tree, JustPrintfId);   //��������������
                }
                else
                    printf("\n�����Ľ���Ϊ�ռ���");
                getch();
            }
            else  //�Ҳ���
            {
                printf("����ʧ�ܣ������Ҳ����ö�������");
                getch();
            }

            break;

        case 7:  //set_union
            if(gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���ڵ�����\n");
            temp = gp_tree_head;
            while(temp)         //���������ǰ���ڵ���
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n��������Ҫȡ�����ĵ�һ�����ϣ�");   //�ҵ�һ��
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            printf("\n��������Ҫȡ�����ĵڶ������ϣ�");  //�ҵڶ���
            scanf("%s",name);
            temp2 = NULL;
            temp2 = FindAVLLink(gp_tree_head, name);

            if(temp2 && temp)    //�ҵ��Ļ�
            {
                printf("\n�³�ʼ��һ�������ڱ��棡");
                AVLLink *newlink = set_init(&gp_tree_head);  //�³�ʼ��һ�������ڱ��棡
                set_union(temp->tree, temp2->tree, &newlink->tree);
                if(newlink->tree)
                {
                    printf("\n�����Ĳ���Ϊ��");
                    InOrderTraverse(newlink->tree, JustPrintfId);   //��������������
                }
                else
                    printf("\n�����Ĳ���Ϊ�ռ���");
                getch();
            }
            else  //�Ҳ���
            {
                printf("����ʧ�ܣ������Ҳ����ö�������");
                getch();
            }

            break;

        case 8:  //set_diffrence
            if(gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���ڵ�����\n");
            temp = gp_tree_head;
            while(temp)         //���������ǰ���ڵ���
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n�ò���ȡA-B�Ĳ");
            printf("\n��������Ҫȡ��ĵ�һ������A��");   //�ҵ�һ��
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            printf("\n��������Ҫȡ��ĵڶ�������B��");  //�ҵڶ���
            scanf("%s",name);
            temp2 = NULL;
            temp2 = FindAVLLink(gp_tree_head, name);

            if(temp2 && temp)    //�ҵ��Ļ�
            {
                printf("\n�³�ʼ��һ�������ڱ��棡");
                AVLLink *newlink = set_init(&gp_tree_head);  //�³�ʼ��һ�������ڱ��棡
                set_difference(temp->tree, temp2->tree, &newlink->tree);
                if(newlink->tree)
                {
                    printf("\n�����ĲΪ��");
                    InOrderTraverse(newlink->tree, JustPrintfId);   //��������������
                }
                else
                    printf("\n�����ĲΪ�ռ���");
            }
            else  //�Ҳ���
            {
                printf("����ʧ�ܣ������Ҳ����ö�������");
            }
            getch();
            break;

        case 9:  //set_size
            if(gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���ڵ�����\n");
            temp = gp_tree_head;
            while(temp)         //���������ǰ���ڵ���
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n��������Ҫȡ��Ա�����ļ��ϣ�");
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            if(temp)   //�ҵ�
            {
                printf("\n�ü��ϵĳ�Ա����Ϊ %d", set_size(temp->tree));
                getch();
            }
            else  //�Ҳ���
            {
                printf("\n�Ҳ����ü��ϣ�");
                getch();
            }
            break;

        case 10:  //set_member
            if(gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���ڵ�����\n");
            temp = gp_tree_head;
            while(temp)         //���������ǰ���ڵ���
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n��������Ҫ���ҳ�Ա�ļ��ϣ�");
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            if(temp)   //�ҵ�
            {
                printf("\n������Ҫ���ҵ�Ԫ�أ�");
                scanf("%d", &t);
                if(set_member(temp->tree, t))
                    printf("\n��Ԫ�ش��ڣ�");
                else
                    printf("\n��Ԫ�ز����ڣ�");
                getch();
            }
            else  //�Ҳ���
            {
                printf("\n�Ҳ����ü��ϣ�");
                getch();
            }
            break;

        case 11:  //set_subset
            if(gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���ڵ�����\n");
            temp = gp_tree_head;
            while(temp)         //���������ǰ���ڵ���
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n�ж� T �Ƿ�Ϊ P ���Ӽ���");
            printf("\n�������һ������T��");   //�ҵ�һ��
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            printf("\n������ڶ�������P��");  //�ҵڶ���
            scanf("%s",name);
            temp2 = NULL;
            temp2 = FindAVLLink(gp_tree_head, name);

            if(temp2 && temp)    //�ҵ��Ļ�
            {
                if(set_subset(temp->tree, temp2->tree))
                {
                    printf("\nT Ϊ P ���Ӽ���");
                }
                else
                    printf("\nT ��Ϊ P ���Ӽ���");
                getch();
            }
            else  //�Ҳ���
            {
                printf("����ʧ�ܣ������Ҳ����ö�������");
                getch();
            }
            break;

        case 12:  //set_equal
            if(gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���ڵ�����\n");
            temp = gp_tree_head;
            while(temp)         //���������ǰ���ڵ���
            {
                printf("%s    ",temp->name);
                temp = temp->next;
            }

            printf("\n��������Ҫ�ж���ȵĵ�һ�����ϣ�");   //�ҵ�һ��
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            printf("\n��������Ҫ�ж���ȵĵڶ������ϣ�");  //�ҵڶ���
            scanf("%s",name);
            temp2 = NULL;
            temp2 = FindAVLLink(gp_tree_head, name);

            if(temp2 && temp)    //�ҵ��Ļ�
            {

                if(set_equal(temp->tree, temp2->tree))
                {
                    printf("\n������ȣ�");
                }
                else
                    printf("\n��������ȣ���");
                getch();
            }
            else  //�Ҳ���
            {
                printf("����ʧ�ܣ������Ҳ����ö�������");
                getch();
            }
            break;

        case 13:  //PreOrderTraverse
            if(gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���еĶ�����ǰ�������\n");
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
            if(gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���еĶ��������������\n");
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
            if (gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���еĶ��������������\n");
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
            if(gp_tree_head == NULL)  //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("��ǰ���еĶ��������������\n");
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


//΢�����ܲ˵�ִ�к���
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
        case 1:  //�ֶ�����û���
            WriteOneName();
            getch();
            break;

        case 2:  //ɾ���û������е�ĳ���û�
            DeleteUser();
            getch();
            break;

        case 3://���ĳһ�û��ĺ���
            AddOnesFriend();
            getch();
            break;

        case 4://���ĳһ�û��ķ�˿
            AddOnesFans();
            getch();
            break;

        case 5://���ĳһ�û��Ĺ�ע
            AddOnesAtt();
            getch();
            break;

        case 6://���ĳһ�û��ĸ���ϲ��
            AddOnesHobby();
            getch();
            break;

        case 7://ɾ��ĳһ�û��ĺ���
            DeleteOneFriend();
            getch();
            break;

        case 8://ɾ��ĳһ�û��ķ�˿
            DeleteOneFans();
            getch();
            break;

        case 9://ɾ��ĳһ�û��Ĺ�ע
            DeleteOneAtt();
            getch();
            break;

        case 10://ɾ��ĳһ�û��ĸ���ϲ��
            DeleteOneHobby();
            getch();
            break;

        case 11://����ĳһ�û�
            PutOneInfo();
            getch();
            break;

        case 12://���ĳһ�û���������Ϣ
            PutOneInfo();
            getch();
            break;

        case 13://��ͬ��ע
            SameAtt();
            getch();
            break;

        case 14://��ͬϲ��
            SameHobby();
            getch();
            break;

        case 15://���Ⱥ���
            TwoFriend();
            getch();
            break;

        case 16://��������û���
            RandName();
            getch();
            break;

        case 17://�������������Ϣ
            RandAllInfo(gp_all_name);
            getch();
            break;

        case 18://�����ǰ�����û���
            TraverseAllName();
            getch();
            break;

        case 19://��������
            SaveName();
            SaveInfo();
            getch();
            break;

        case 20://��������
            LoadName();
            LoadInfo();
            getch();
            break;


        default://Back
            break;
        }

    }
}
