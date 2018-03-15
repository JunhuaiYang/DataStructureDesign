/** \brief ���ļ����ڱ���������
 *
 *
 */
#include"AVL.h"
#include"menu.h"

int main()
{
    gh_std_out = GetStdHandle(STD_OUTPUT_HANDLE); /* ��ȡ��׼����豸���*/
    int op=1;
    srand(time(NULL));//������������ӡ�

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
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");

    return 0;
}

void Exit(void)  //�˳�ʱ���������
{
    DestroyAVL(&gp_all_name);   //��յ�һ��

    AVLLink *p;

    while(gp_tree_head)   //��յڶ���
    {
        p = gp_tree_head;
        gp_tree_head = gp_tree_head->next;
        DestroyAVL(&p->tree);
        free(p);
    }
}
