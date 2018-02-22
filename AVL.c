#include"AVL.h"

void set_init(AVLtree *T)
{
    //�����ǰ����AVL��
    if(*T != NULL)
    {
        printf("��ǰ�Ѵ���AVL���������ٺ��ٴ���\n")��
        return;
    }

    *T = (AVLNode*) malloc(sizeof(AVLNode));

    (*T)->height = 0;  //��ʾ����
    //�����������ÿ�
    (*T)->lchild = NULL;
    (*T) ->rchild = NULL;
    return;
}

void set_destory(AVLtree *T)
{
    AVLNode *stack[100], *p, *q, *Tnode;
    int top = -1;

    p = Tnode->lchild;
    q = Tnode->rchild;
    if (p == NULL && q == NULL)  //ֻ�и��ڵ�
    {
        free(Tnode);
        return;
    }
    if (p->lchild) stack[++top] = p->lchild;   //�������ʾջ
    else if (p->rchild) stack[++top] = p->rchild;

    while (top>-1)       //topΪջ��
    {
        p = stack[top--];   //��ջ
        q = p;
        if (p->rchild) stack[++top] = p->rchild; //��������ջ
        if (p->lchild) stack[++top] = p->lchild; //��������ջ
        free(q);
    }

    return;
}

AVLtree Left_Left_Rotate(AVLtree p)  //LL���������
{
    AVLtree lc;

    lc = p->lchild;           //���������ڵ�
    p->lchild = lc->rchild;
    lc->rchild = p;

    p->height = MAX(Height(p->lchild), Height(p->rchild)) + 1;       //���¸߶�
    lc->height = MAX(Height(lc->lchild), Height(lc->rchild)) + 1;

    return lc; //���ظ��ڵ�
}

AVLtree Right_Right_Rotate(AVLtree p)
{
    AVLtree rc;

    rc = p ->rchild;         //���������ڵ�
    p->rchild = rc->lchild;
    rc->lchild = p;

    p->height = MAX(Height(p->lchild), Height(p->rchild)) + 1;     //���¸߶�
    rc->height = MAX(Height(rc->lchild), Height(rc->rchild)) + 1;

    return rc;
}

AVLtree Left_Right_Rotate(AVLtree p)
{
    p->lchild = Right_Right_Rotate(p->lchild);  //�ȶ�p�����������
    return Left_Left_Rotate(p);   //�ٽ���������ֱ�ӷ���
}

AVLtree Right_Left_Rotate(AVLtree p)
{
    p->rchild = Left_Left_Rotate(p->rchild);  //�ȶ�p���Ҷ�������
    return Right_Right_Rotate(p);  //������
}

bool set_insert(AVLtree *T,Info e,bool *taller)
{

}


int MAX(int a, int b)
    return (a>b) ? a : b;

int Height(AVLtree tree)
{
    if tree == NULL
        return 0;
    else return tree->height;
}
