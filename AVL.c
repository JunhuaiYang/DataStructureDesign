#include"AVL.h"

void set_init(AVLtree *T)
{
    //如果当前存在AVL树
    if(*T != NULL)
    {
        printf("当前已存在AVL树，请销毁后再创建\n")；
        return;
    }

    *T = (AVLNode*) malloc(sizeof(AVLNode));

    (*T)->height = 0;  //表示空树
    //将左右子树置空
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
    if (p == NULL && q == NULL)  //只有根节点
    {
        free(Tnode);
        return;
    }
    if (p->lchild) stack[++top] = p->lchild;   //用数组表示栈
    else if (p->rchild) stack[++top] = p->rchild;

    while (top>-1)       //top为栈顶
    {
        p = stack[top--];   //出栈
        q = p;
        if (p->rchild) stack[++top] = p->rchild; //右子树入栈
        if (p->lchild) stack[++top] = p->lchild; //左子树入栈
        free(q);
    }

    return;
}

AVLtree Left_Left_Rotate(AVLtree p)  //LL情况，右旋
{
    AVLtree lc;

    lc = p->lchild;           //右旋交换节点
    p->lchild = lc->rchild;
    lc->rchild = p;

    p->height = MAX(Height(p->lchild), Height(p->rchild)) + 1;       //更新高度
    lc->height = MAX(Height(lc->lchild), Height(lc->rchild)) + 1;

    return lc; //返回根节点
}

AVLtree Right_Right_Rotate(AVLtree p)
{
    AVLtree rc;

    rc = p ->rchild;         //左旋交换节点
    p->rchild = rc->lchild;
    rc->lchild = p;

    p->height = MAX(Height(p->lchild), Height(p->rchild)) + 1;     //更新高度
    rc->height = MAX(Height(rc->lchild), Height(rc->rchild)) + 1;

    return rc;
}

AVLtree Left_Right_Rotate(AVLtree p)
{
    p->lchild = Right_Right_Rotate(p->lchild);  //先对p的左儿子左旋
    return Left_Left_Rotate(p);   //再进行右旋，直接返回
}

AVLtree Right_Left_Rotate(AVLtree p)
{
    p->rchild = Left_Left_Rotate(p->rchild);  //先对p的右儿子右旋
    return Right_Right_Rotate(p);  //再左旋
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
