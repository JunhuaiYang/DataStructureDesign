#include"AVL.h"

int count;  //全局变量count

//6种基本运算
bool InitAVL(AVLtree *T)
{
    *T = (AVLNode*) malloc(sizeof(AVLNode));

    (*T)->height = 0;  //表示空树
    //将左右子树置空
    (*T)->lchild = NULL;
    (*T) ->rchild = NULL;
    return true;
}

bool DestroyAVL(AVLtree *T)
{
    AVLNode *stack[100], *p, *q, *Tnode;  //stack为新建栈
    int top = -1;

    Tnode = *T;
    p = Tnode->lchild;
    q = Tnode->rchild;
    if (p == NULL && q == NULL)  //只有根节点
    {
        free(Tnode);
        return true;
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

    *T = NULL; //将其置空

    return true ;
}

AVLtree SearchAVL(AVLtree head, int key)
{
    if(head != NULL)
    {
        if(key == head->data.id) return head;     //找到返回
        else if(key < head->data.id) return SearchAVL(head->lchild, key);    //左小
        else return SearchAVL(head->rchild, key);            //右大
    }
    return NULL;
}

AVLtree InsertAVL(AVLtree newtree,Info key)
{
    if(newtree == NULL)
    {
        InitAVL(&newtree);      //若为空，则创建一个节点
        newtree->data = key; //赋值进入新节点
    }
    else if(key.id < newtree->data.id)  //插到左子树
    {
        newtree->lchild = InsertAVL(newtree->lchild, key);  //相当于递归，在空的地方插入
        //失去平衡处理
        if (Height(newtree->lchild) - Height(newtree->rchild) == 2) //左
        {
            if (key.id < newtree->lchild->data.id)     //LL  右旋
                newtree = Left_Left_Rotate(newtree);
            else                          //LR   先左旋后右旋
                newtree = Left_Right_Rotate(newtree);
        }
    }
    else if(key.id > newtree->data.id)
    {
        newtree->rchild = InsertAVL(newtree->rchild, key);   //递归
        if (Height(newtree->rchild) - Height(newtree->lchild) == 2) //右
        {
            if (key.id > newtree->rchild->data.id)     //RR  左旋
                newtree = Right_Right_Rotate(newtree);
            else                          //RL  先左旋再右旋
                newtree = Right_Left_Rotate(newtree);
        }
    }
    else  //key->id == newtree->data->id
        printf("节点相同，添加失败！\n");
    //更新节点高度信息
    newtree->height = MAX(Height(newtree->lchild), Height(newtree->rchild)) + 1;
    //更新节点平衡因子信息
    newtree->bf = GetBlanceFactor(newtree);

    return newtree;
}

AVLtree DeleteAVL(AVLtree tree, AVLNode *z)
{
    // 根为空 或者 没有要删除的节点，直接返回NULL。
    if (tree==NULL || z==NULL)
        return NULL;

    if(z->data.id < tree->data.id)  //待删除的在左子树
    {
        tree->lchild = DeleteAVL(tree->lchild, z); //递归去找删除节点
        //平衡处理，左子树失去平衡，应该处理右子树
        AVLNode *right = tree->rchild;
        if(GetBlanceFactor(right) == -2)
            tree = Right_Right_Rotate(tree);        //相当于插入时的RR情况
        else
            tree = Right_Left_Rotate(tree);     //相当于插入时的RL情况
    }
    else if(z->data.id > tree->data.id)     //待删除的在右子树
    {
        tree->rchild = DeleteAVL(tree->rchild, z); //递归去找删除节点
        //平衡处理，右子树失去平衡，应该处理左子树
        AVLNode *left = tree->lchild;
        if(GetBlanceFactor(left) == 2)
            tree = Left_Left_Rotate(tree);     //相当于插入时的LL情况
        else
            tree = Left_Right_Rotate(tree);   //相当于插入时的LR情况
    }
    else   //tree 就是要删的
    {
        //tree的左右子树非空
        if(tree->lchild && tree->rchild)
        {
            if(GetBlanceFactor(tree)>0)  //左子树比右子树高的话
            {
                //找到tree左子树的最大节点，把最大节点赋值给tree
                //再删除最大节点
                AVLNode *max = FindMaxNode(tree->lchild);
                tree->data = max->data;
                tree->lchild = DeleteAVL(tree->lchild, max);
            }
            else //右子树高的话
            {
                //找右子树的最小节点，把最小节点赋值给tree
                //再删除最小节点
                AVLNode *min = FindMinNode(tree->rchild);
                tree->data = min->data;
                tree->rchild = DeleteAVL(tree->rchild, min);
            }
        }
        else  //tree的左子树或者右子树为空时，直接移动到根部
        {
            AVLNode *temp =tree;
            tree = temp->lchild ? temp->lchild :temp->rchild;
            free(temp);
        }
    }

    return tree; //返回根
}

void TraverseAVL(AVLtree p, void (*visit)(Info data))
{
    if(p == NULL) return;

    Info re;
    TraverseAVL(p->lchild,visit);  //中序遍历
    visit(p->data);
    TraverseAVL(p->rchild,visit);

    return ;
}

int GetBlanceFactor(AVLtree tree)
{
    return Height(tree->lchild) - Height(tree->rchild);  //获得平衡因子
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

int MAX(int a, int b)
{
    return (a>b) ? a : b;
}

int Height(AVLtree tree)
{
    if (tree == NULL)
        return 0;
    else return tree->height;
}

AVLtree FindMaxNode(AVLtree tree)
{
    if(tree->rchild == NULL)
        return tree;
    else
        return FindMaxNode(tree->rchild);
}

AVLtree FindMinNode(AVLtree tree)
{
    if(tree->lchild == NULL)
        return tree;
    else
        return FindMinNode(tree->lchild);
}

Info JustPrintfId(Info data)
{
    printf("%d  ",data.id); //中序遍历输出
    return 0;     //返回0匹配接口
}

Info GetTraverseInfo(Info data)
{
    return data;          //直接返回Info
}

//ADT基本运算
void set_init(AVLtree *T)
{
    //如果当前存在AVL树
    if(*T != NULL)
    {
        printf("当前已存在AVL树，请销毁后再创建\n");
        return;
    }
    InitAVL(T);    //调用InitAVL
    return;
}

void set_destory(AVLtree *T)
{
    if(*T == NULL)
    {
        printf("当前不存在AVL树，请创建！\n");
        return;
    }

    DestroyAVL(T);
    return;
}


bool set_insert(AVLtree *T,Info e)
{
    if(*T == NULL)
    {
        printf("当前没有树，请初始化一棵树。");
        return false;
    }
    else
    {
        *T = InsertAVL(*T, e);
        return true;
    }
}

bool set_remove(AVLtree *T,int key)
{
    AVLNode* tnode; //查找要删除的节点

    if(*T == NULL)
    {
        printf("当前没有树，请初始化一棵树。");
        return false;
    }
    else
    {
        tnode = SearchAVL(*T, key);
        if(tnode != NULL)
        {
            *T = DeleteAVL(*T, tnode);  //调用删除, 并将根返回
            return true;
        }
        else
            return false;   //删除失败
    }
}

void set_intersection(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    //如果NEWTREE存在的话，将其销毁
    if(*NEWTREE)
    {
        DestroyAVL(NEWTREE);
    }

    Intersection(T, T1, NEWTREE);   //递归实现

    return;
}

void Intersection(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    if(T == NULL) return;  //遍历T

    Intersection(T->lchild, T1, NEWTREE);
    if(SearchAVL(T1, T->data->id))               //找T1中是否存在该节点
        *NEWTREE = InsertAVL(*NEWTREE, T->data);  //若存在则放NEWTREE
    Intersection(T->rchild, T1, NEWTREE);

    return;
}

void set_union(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    //如果NEWTREE存在的话，将其销毁
    if(*NEWTREE)
    {
        DestroyAVL(NEWTREE);
    }
    if(T)  //现将T放入新树
        Union(T, NEWTREE);
    if(T1)  //再将T1放入新树
        Union(T1, NEWTREE;)

    return;

}

void Union(AVLtree T, AVLtree *newtree)
{
    if(T == NULL) return;

    Union(T->lchild, newtree);     //中序遍历
    *newtree = InsertAVL(*newtree, T->data);   //每次遍历创建节点
    Union(T->rchild, newtree);

    return;
}


void set_difference(AVLtree *T,AVLtree T1, AVLtree *NEWTREE)
{
    //如果NEWTREE存在的话，将其销毁
    if(*NEWTREE)
    {
        DestroyAVL(NEWTREE);
    }

}

void Difference(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    if(T == NULL) return;  //遍历T

    Intersection(T->lchild, T1, NEWTREE);
    if(!SearchAVL(T1, T->data->id))               //找T1中是否存在该节点
        *NEWTREE = InsertAVL(*NEWTREE, T->data);   //若不存在则放NEWTREE
    Intersection(T->rchild, T1, NEWTREE);

    return;
}

int set_size(AVLtree T)
{
    count = 0;     //将count置零
    TraverseAVL(T, Count);   //调用遍历函数实现

    return count;
}

void Count(Info data)
{
    count++;
}

bool set_member(AVLtree T,int key)
{
    if(SearchAVL(T, key))  //直接调用
        return true;
    else return false;
}

bool set_subset(AVLtree TS,AVLtree T1)
{
    return Subset(TS, T1);
}

bool Subset(AVLtree TS, AVLtree T1) //TS 是否为T1子集
{
    if(TS == NULL)
        return true;

    bool boo1, boo2, boo3;         //用来标记是否找到
    boo1 = Subset(TS->lchild, T1);
    if(set_member(T1, TS->data.id))   //找到
        boo2 = true;
    else
        boo2 = false;
    boo3 = Subset(TS->rchild, T1);

    if(boo1 && boo2 && boo3)  //如果3个都为真，才是子集
        return true;
    else
        return false;
}

bool set_equal(AVLtree T,AVLtree T1)
{
    //判断相等即判断其是否互为子集
    if(set_subset(T,T1) && set_subset(T1, T))
        return true;
    else
        return false;
}






