#include"AVL.h"
#include"menu.h"

int main()
{
    gh_std_out = GetStdHandle(STD_OUTPUT_HANDLE); /* ��ȡ��׼����豸���*/
    int op=1;

    while(op)
    {
        system("cls");
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:   //ADT_menu

            break;

        case 2:
            ADT_main();
            break;

        case 3:
            weibo_main();
            break;

        default:
            break;
        }

    }
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");

    return 0;
}

