#include"menu.h"

void menu(void)
{
    SMALL_RECT Rec = {2, 2, 90, 15};

    printf("\t\t����AVL����ʾ�ļ���ADTʵ����Ӧ�� ��ʾϵͳ");
    printf("\n\n\n\n\t\t1. �������AVL��ʾ��������6�ֻ�������ʵ�ּ���ADT�Ļ�������");
    printf("\n\n\t\t2. ������ڼ���ADTʵ��Ӧ�ò㹦��");
    printf("\n\n\t\t3. ���ݵĴ������ȡ");
    DrawBox(&Rec);
    GotoXY(2,16);
    printf("������Ҫ���еĲ�����");
}


void ADT_menu()
{
    SMALL_RECT Rec = {2, 2, 90, 20};
    printf("\t\t����AVL��ʾ��������6�ֻ�������ʵ�ּ���ADT�Ļ�������");
    printf("\n\n\n                     1. set_init                   2. set_destroy");
    printf("\n\n                     3. new_AVL                    4. set_insert");
    printf("\n\n                     5. set_remove                 6. set_intersection");
    printf("\n\n                     7. set_union                  8. set_diffrence");
    printf("\n\n                     9. set_size                   10. set_member");
    printf("\n\n                     11. set_subset                12. set_equal");

    DrawBox(&Rec);
}
