#include"paint.h"

HANDLE gh_std_out;          /*��׼����豸���*/
DWORD ul; //��ɫ����
int Lv;

/**
 * ��������: GotoXY
 * ��������: �ѹ���Ƶ���Ļ�ϵ�XY��.
 * �������: ��
 * �������: ��
 * �� �� ֵ: ��
 *
 * ����˵��:
 */
void GotoXY(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(gh_std_out, pos);
}

/**
 * ��������:Show_Cursor
 * ��������: ��ʾ�����ؿ���̨���.
 * �������: ��
 * �������: ��
 * �� �� ֵ: ��
 *
 * ����˵��:
 */

void Show_Cursor(BOOL boo)
{
    CONSOLE_CURSOR_INFO lpCur; //����̨�����Ϣ

    GetConsoleCursorInfo(gh_std_out, &lpCur); //�����й�ָ���Ŀ���̨��Ļ�������Ĺ��Ŀɼ��Ժʹ�С��Ϣ��
    lpCur.bVisible = boo;
    SetConsoleCursorInfo(gh_std_out, &lpCur);
}


/**
 * ��������: DrawBox
 * ��������: ��ָ�����򻭱߿�.
 * �������: pRc �������λ����Ϣ�ĵ�ַ
 * �������: ��
 * �� �� ֵ: ��
 *
 * ����˵��:
 */
void DrawBox(SMALL_RECT *pRc)
{
    char chBox[] = {'+','-','|'};  /*�����õ��ַ�*/
    COORD pos = {pRc->Left, pRc->Top};  /*��λ����������Ͻ�*/

    WriteConsoleOutputCharacter(gh_std_out, &chBox[0], 1, pos, &ul);/*���߿����Ͻ�*/
    for (pos.X = pRc->Left + 1; pos.X < pRc->Right; pos.X++)
    {   /*��ѭ�����ϱ߿����*/
        WriteConsoleOutputCharacter(gh_std_out, &chBox[1], 1, pos, &ul);
    }
    pos.X = pRc->Right;
    WriteConsoleOutputCharacter(gh_std_out, &chBox[0], 1, pos, &ul);/*���߿����Ͻ�*/
    for (pos.Y = pRc->Top+1; pos.Y < pRc->Bottom; pos.Y++)
    {   /*��ѭ�����߿�����ߺ��ұ���*/
        pos.X = pRc->Left;
        WriteConsoleOutputCharacter(gh_std_out, &chBox[2], 1, pos, &ul);
        pos.X = pRc->Right;
        WriteConsoleOutputCharacter(gh_std_out, &chBox[2], 1, pos, &ul);
    }
    pos.X = pRc->Left;
    pos.Y = pRc->Bottom;
    WriteConsoleOutputCharacter(gh_std_out, &chBox[0], 1, pos, &ul);/*���߿����½�*/
    for (pos.X = pRc->Left + 1; pos.X < pRc->Right; pos.X++)
    {   /*���±߿����*/
        WriteConsoleOutputCharacter(gh_std_out, &chBox[1], 1, pos, &ul);
    }
    pos.X = pRc->Right;
    WriteConsoleOutputCharacter(gh_std_out, &chBox[0], 1, pos, &ul);/*���߿����½�*/
    return;
}

void PaintTree(AVLtree T)
{
    count = 0, Lv = 0;
    AVLtree queue[100];
    paint_LevelOrderTraverse(T, queue, queue);
    getch();
}

void paint_LevelOrderTraverse(AVLtree T, AVLtree *F,AVLtree *H )
{
    if(T == NULL)
    {
        tree_print(-1024);
        return;
    }
    *F=T;            //����ǰ�ڵ���������ָ����ָλ��
    tree_print((*F)->data.id);

    //if((*F)->lchild != NULL)
    //{
        H=H+1;             //ͷָ�����
        *H=(*F)->lchild;    //�ڵ������ӷ����ͷ
    //}


    //if((*F)->rchild != NULL)
    //{
        H=H+1;                //ͷ������ƶ�һ��
        *H=(*F)->rchild;    //�ڵ���Ҷ��ӷ����ͷ
   // }

    F=F+1;    //βָ�����һλ
    //if(F != H || (*F)->lchild != NULL || (*F)->rchild != NULL)   //����ͷ�����ڶ�βʱ�ݹ飬 ��ʱҪע���βҲ�п�����������������û�н�����
        paint_LevelOrderTraverse(*F ,F ,H);//�ݹ�
    //else
        tree_print((*F)->data.id);    //���βָ��
    return;
}

void tree_print(int i)
{
    if(i == -1024)
        printf(" 000 ");
    else
        printf("%d   ", i);
    if(count == (int)pow(2,Lv)-1)
    {
        Lv++ , count = 0;
        printf("\n");
    }
    else
        count++;

}
