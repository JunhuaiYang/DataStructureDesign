#include"AVL.h"

int count;  //ȫ�ֱ���count

//6�ֻ�������
bool InitAVL(AVLtree *T)
{
    *T = (AVLNode*) malloc(sizeof(AVLNode));

    (*T)->height = 0;  //��ʾ����
    //�����������ÿ�
    (*T)->lchild = NULL;
    (*T) ->rchild = NULL;
    return true;
}

bool DestroyAVL(AVLtree *T)
{
    AVLNode *stack[100], *p, *q, *Tnode;  //stackΪ�½�ջ
    int top = -1;

    Tnode = *T;
    p = Tnode->lchild;
    q = Tnode->rchild;
    if (p == NULL && q == NULL)  //ֻ�и��ڵ�
    {
        free(Tnode);
        return true;
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

    *T = NULL; //�����ÿ�

    return true ;
}

AVLtree SearchAVL(AVLtree head, int key)
{
    if(head != NULL)
    {
        if(key == head->data.id) return head;     //�ҵ�����
        else if(key < head->data.id) return SearchAVL(head->lchild, key);    //��С
        else return SearchAVL(head->rchild, key);            //�Ҵ�
    }
    return NULL;
}

AVLtree InsertAVL(AVLtree newtree,Info key)
{
    if(newtree == NULL)
    {
        InitAVL(&newtree);      //��Ϊ�գ��򴴽�һ���ڵ�
        newtree->data = key; //��ֵ�����½ڵ�
    }
    else if(key.id < newtree->data.id)  //�嵽������
    {
        newtree->lchild = InsertAVL(newtree->lchild, key);  //�൱�ڵݹ飬�ڿյĵط�����
        //ʧȥƽ�⴦��
        if (Height(newtree->lchild) - Height(newtree->rchild) == 2) //��
        {
            if (key.id < newtree->lchild->data.id)     //LL  ����
                newtree = Left_Left_Rotate(newtree);
            else                          //LR   ������������
                newtree = Left_Right_Rotate(newtree);
        }
    }
    else if(key.id > newtree->data.id)
    {
        newtree->rchild = InsertAVL(newtree->rchild, key);   //�ݹ�
        if (Height(newtree->rchild) - Height(newtree->lchild) == 2) //��
        {
            if (key.id > newtree->rchild->data.id)     //RR  ����
                newtree = Right_Right_Rotate(newtree);
            else                          //RL  ������������
                newtree = Right_Left_Rotate(newtree);
        }
    }
    else  //key->id == newtree->data->id
        printf("�ڵ���ͬ�����ʧ�ܣ�\n");
    //���½ڵ�߶���Ϣ
    newtree->height = MAX(Height(newtree->lchild), Height(newtree->rchild)) + 1;
    //���½ڵ�ƽ��������Ϣ
    newtree->bf = GetBlanceFactor(newtree);

    return newtree;
}

AVLtree DeleteAVL(AVLtree tree, AVLNode *z)
{
    // ��Ϊ�� ���� û��Ҫɾ���Ľڵ㣬ֱ�ӷ���NULL��
    if (tree==NULL || z==NULL)
        return NULL;

    if(z->data.id < tree->data.id)  //��ɾ������������
    {
        tree->lchild = DeleteAVL(tree->lchild, z); //�ݹ�ȥ��ɾ���ڵ�
        //ƽ�⴦��������ʧȥƽ�⣬Ӧ�ô���������
        AVLNode *right = tree->rchild;
        if(GetBlanceFactor(right) == -2)
            tree = Right_Right_Rotate(tree);        //�൱�ڲ���ʱ��RR���
        else
            tree = Right_Left_Rotate(tree);     //�൱�ڲ���ʱ��RL���
    }
    else if(z->data.id > tree->data.id)     //��ɾ������������
    {
        tree->rchild = DeleteAVL(tree->rchild, z); //�ݹ�ȥ��ɾ���ڵ�
        //ƽ�⴦��������ʧȥƽ�⣬Ӧ�ô���������
        AVLNode *left = tree->lchild;
        if(GetBlanceFactor(left) == 2)
            tree = Left_Left_Rotate(tree);     //�൱�ڲ���ʱ��LL���
        else
            tree = Left_Right_Rotate(tree);   //�൱�ڲ���ʱ��LR���
    }
    else   //tree ����Ҫɾ��
    {
        //tree�����������ǿ�
        if(tree->lchild && tree->rchild)
        {
            if(GetBlanceFactor(tree)>0)  //���������������ߵĻ�
            {
                //�ҵ�tree�����������ڵ㣬�����ڵ㸳ֵ��tree
                //��ɾ�����ڵ�
                AVLNode *max = FindMaxNode(tree->lchild);
                tree->data = max->data;
                tree->lchild = DeleteAVL(tree->lchild, max);
            }
            else //�������ߵĻ�
            {
                //������������С�ڵ㣬����С�ڵ㸳ֵ��tree
                //��ɾ����С�ڵ�
                AVLNode *min = FindMinNode(tree->rchild);
                tree->data = min->data;
                tree->rchild = DeleteAVL(tree->rchild, min);
            }
        }
        else  //tree������������������Ϊ��ʱ��ֱ���ƶ�������
        {
            AVLNode *temp =tree;
            tree = temp->lchild ? temp->lchild :temp->rchild;
            free(temp);
        }
    }

    return tree; //���ظ�
}

void TraverseAVL(AVLtree p, void (*visit)(Info data))
{
    if(p == NULL) return;

    Info re;
    TraverseAVL(p->lchild,visit);  //�������
    visit(p->data);
    TraverseAVL(p->rchild,visit);

    return ;
}

int GetBlanceFactor(AVLtree tree)
{
    return Height(tree->lchild) - Height(tree->rchild);  //���ƽ������
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
    printf("%d  ",data.id); //����������
    return 0;     //����0ƥ��ӿ�
}

Info GetTraverseInfo(Info data)
{
    return data;          //ֱ�ӷ���Info
}

//ADT��������
void set_init(AVLtree *T)
{
    //�����ǰ����AVL��
    if(*T != NULL)
    {
        printf("��ǰ�Ѵ���AVL���������ٺ��ٴ���\n");
        return;
    }
    InitAVL(T);    //����InitAVL
    return;
}

void set_destory(AVLtree *T)
{
    if(*T == NULL)
    {
        printf("��ǰ������AVL�����봴����\n");
        return;
    }

    DestroyAVL(T);
    return;
}


bool set_insert(AVLtree *T,Info e)
{
    if(*T == NULL)
    {
        printf("��ǰû���������ʼ��һ������");
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
    AVLNode* tnode; //����Ҫɾ���Ľڵ�

    if(*T == NULL)
    {
        printf("��ǰû���������ʼ��һ������");
        return false;
    }
    else
    {
        tnode = SearchAVL(*T, key);
        if(tnode != NULL)
        {
            *T = DeleteAVL(*T, tnode);  //����ɾ��, ����������
            return true;
        }
        else
            return false;   //ɾ��ʧ��
    }
}

void set_intersection(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    //���NEWTREE���ڵĻ�����������
    if(*NEWTREE)
    {
        DestroyAVL(NEWTREE);
    }

    Intersection(T, T1, NEWTREE);   //�ݹ�ʵ��

    return;
}

void Intersection(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    if(T == NULL) return;  //����T

    Intersection(T->lchild, T1, NEWTREE);
    if(SearchAVL(T1, T->data->id))               //��T1���Ƿ���ڸýڵ�
        *NEWTREE = InsertAVL(*NEWTREE, T->data);  //���������NEWTREE
    Intersection(T->rchild, T1, NEWTREE);

    return;
}

void set_union(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    //���NEWTREE���ڵĻ�����������
    if(*NEWTREE)
    {
        DestroyAVL(NEWTREE);
    }
    if(T)  //�ֽ�T��������
        Union(T, NEWTREE);
    if(T1)  //�ٽ�T1��������
        Union(T1, NEWTREE;)

    return;

}

void Union(AVLtree T, AVLtree *newtree)
{
    if(T == NULL) return;

    Union(T->lchild, newtree);     //�������
    *newtree = InsertAVL(*newtree, T->data);   //ÿ�α��������ڵ�
    Union(T->rchild, newtree);

    return;
}


void set_difference(AVLtree *T,AVLtree T1, AVLtree *NEWTREE)
{
    //���NEWTREE���ڵĻ�����������
    if(*NEWTREE)
    {
        DestroyAVL(NEWTREE);
    }

}

void Difference(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    if(T == NULL) return;  //����T

    Intersection(T->lchild, T1, NEWTREE);
    if(!SearchAVL(T1, T->data->id))               //��T1���Ƿ���ڸýڵ�
        *NEWTREE = InsertAVL(*NEWTREE, T->data);   //�����������NEWTREE
    Intersection(T->rchild, T1, NEWTREE);

    return;
}

int set_size(AVLtree T)
{
    count = 0;     //��count����
    TraverseAVL(T, Count);   //���ñ�������ʵ��

    return count;
}

void Count(Info data)
{
    count++;
}

bool set_member(AVLtree T,int key)
{
    if(SearchAVL(T, key))  //ֱ�ӵ���
        return true;
    else return false;
}

bool set_subset(AVLtree TS,AVLtree T1)
{
    return Subset(TS, T1);
}

bool Subset(AVLtree TS, AVLtree T1) //TS �Ƿ�ΪT1�Ӽ�
{
    if(TS == NULL)
        return true;

    bool boo1, boo2, boo3;         //��������Ƿ��ҵ�
    boo1 = Subset(TS->lchild, T1);
    if(set_member(T1, TS->data.id))   //�ҵ�
        boo2 = true;
    else
        boo2 = false;
    boo3 = Subset(TS->rchild, T1);

    if(boo1 && boo2 && boo3)  //���3����Ϊ�棬�����Ӽ�
        return true;
    else
        return false;
}

bool set_equal(AVLtree T,AVLtree T1)
{
    //�ж���ȼ��ж����Ƿ�Ϊ�Ӽ�
    if(set_subset(T,T1) && set_subset(T1, T))
        return true;
    else
        return false;
}






