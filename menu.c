#include"menu.h"

void menu(void)
{
    SMALL_RECT Rec = {2, 2, 118, 29};

    printf("\t\t����AVL����ʾ�ļ���ADTʵ����Ӧ�� ��ʾϵͳ");
    DrawBox(&Rec);

    printf("\t\t1. �������AVL��ʾ��������6�ֻ�������ʵ�ּ���ADT�Ļ�������\n");
    printf("\n\t\t2. ������ڼ���ADTʵ��Ӧ�ò㹦��");
    printf("\n\t\t3. ���ݵĴ������ȡ");

}
