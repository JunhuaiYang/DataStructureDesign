#include"menu.h"

void menu(void)
{
    SMALL_RECT Rec = {2, 2, 90, 15};

    printf("\t\t����AVL����ʾ�ļ���ADTʵ����Ӧ�� ��ʾϵͳ");
    printf("\n\n\n\n\t\t1. �������AVL��ʾ��������6�ֻ�������ʵ�ּ���ADT�Ļ�������");
    printf("\n\n\t\t2. ������ڼ���ADTʵ��Ӧ�ò㹦��");
    printf("\n\n\t\t3. ���ݵĴ������ȡ");
    printf("\n\n\t\t0. �˳�");
    DrawBox(&Rec);
    GotoXY(2,16);
    printf("������Ҫ���еĲ�����");
}


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
    printf("\t\t����AVL��ʾ��������6�ֻ�������ʵ�ּ���ADT�Ļ�������");
    printf("\n\n\t��ǰ����%d��AVL����", n);
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
    printf("������Ҫ���еĲ�����");
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
            printf("�ڵ㴴���ɹ���\n");
            getch();
            break;

        case 2:  //set_destroy
            if(set_destory(&gp_tree_head))
                printf("ɾ���ɹ���\n");
            else
                printf("ɾ��ʧ�ܣ�");
            getch();
            break;

        case 3:  //set_AVL
            {
            if(gp_tree_head == NULL)   //û�г�ʼ��ͷ���
            {
                printf("��ǰû�г�ʼ���ڵ㣬���ʼ����");
                getch();
                break;
            }
            printf("������Ҫ��������ݵĸ�����");
            scanf("%d", &sn);
            int array[100];
            printf("\n������Ҫ�����Ԫ�أ�\n");
            for(i=0; i<sn; i++)
            {
                scanf("%d", &array[i]);
                printf("    ");
            }
            set_AVL(gp_tree_head, array, sn);
            printf("\n�½��ɹ���");
            getch();
            break;
            }

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
                if(newlink)
                {
                    printf("\n�����Ľ���Ϊ��");
                    InOrderTraverse(newlink->tree, JustPrintfId);   //��������������
                }
                else
                    printf("\n�����Ľ���Ϊ�ռ���");
            }
            else  //�Ҳ���
            {
                printf("����ʧ�ܣ������Ҳ����ö�������");
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
                if(newlink)
                {
                    printf("\n�����Ĳ���Ϊ��");
                    InOrderTraverse(newlink->tree, JustPrintfId);   //��������������
                }
                else
                    printf("\n�����Ĳ���Ϊ�ռ���");
            }
            else  //�Ҳ���
            {
                printf("����ʧ�ܣ������Ҳ����ö�������");
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

            printf("\n��������Ҫȡ��ĵ�һ�����ϣ�");   //�ҵ�һ��
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            printf("\n��������Ҫȡ��ĵڶ������ϣ�");  //�ҵڶ���
            scanf("%s",name);
            temp2 = NULL;
            temp2 = FindAVLLink(gp_tree_head, name);

            if(temp2 && temp)    //�ҵ��Ļ�
            {
                printf("\n�³�ʼ��һ�������ڱ��棡");
                AVLLink *newlink = set_init(&gp_tree_head);  //�³�ʼ��һ�������ڱ��棡
                set_difference(temp->tree, temp2->tree, &newlink->tree);
                if(newlink)
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
            }
            else  //�Ҳ���
            {
                printf("\n�Ҳ����ü��ϣ�");
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
            }
            else  //�Ҳ���
            {
                printf("\n�Ҳ����ü��ϣ�");
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
            }
            else  //�Ҳ���
            {
                printf("����ʧ�ܣ������Ҳ����ö�������");
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
            }
            else  //�Ҳ���
            {
                printf("����ʧ�ܣ������Ҳ����ö�������");
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
                PreOrderTraverse(temp->tree, JustPrintfId);
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
            break;

        case 18:  //LoadADTData
            break;

        case 19:  //PaintTree
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

            printf("\n��������Ҫ��ӡ�Ķ�������");
            scanf("%s",name);
            temp = NULL;
            temp = FindAVLLink(gp_tree_head, name);

            if(temp)   //�ҵ�
            {
                PaintTree(temp->tree);
            }
            else  //�Ҳ���
            {
                printf("\n�Ҳ����ü��ϣ�");
            }
            break;
            break;

        default:
            break;
        }
    }
}





