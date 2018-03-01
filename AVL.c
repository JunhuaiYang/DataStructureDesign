#include"AVL.h"

int count;  //ȫ�ֱ���count
AVLLink *gp_tree_head;    //ȫ��ͷ���

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
    if(Tnode == NULL)
        return true;
    p = Tnode->lchild;
    q = Tnode->rchild;
    if (p == NULL || q == NULL)  //ֻ�и��ڵ�
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
        printf("\n�ڵ���ͬ�����ʧ�ܣ� \n");
    //���½ڵ�߶���Ϣ
    newtree->height = MAX(Height(newtree->lchild), Height(newtree->rchild)) + 1;

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
        // ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
        if(GetBlanceFactor(tree) == -2)
        {
            AVLNode *right = tree->rchild;
            if(GetBlanceFactor(right) < 0 )   //�Ҹ�
                tree = Right_Right_Rotate(tree);        //�൱�ڲ���ʱ��RR���
            else
                tree = Right_Left_Rotate(tree);     //�൱�ڲ���ʱ��RL���
        }
    }
    else if(z->data.id > tree->data.id)     //��ɾ������������
    {
        tree->rchild = DeleteAVL(tree->rchild, z); //�ݹ�ȥ��ɾ���ڵ�
        //ƽ�⴦��������ʧȥƽ�⣬Ӧ�ô���������
        // ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
        if(GetBlanceFactor(tree)  == 2)
        {
            AVLNode *left = tree->lchild;
            if(GetBlanceFactor(left) > 0)   // ���
                tree = Left_Left_Rotate(tree);     //�൱�ڲ���ʱ��LL���
            else
                tree = Left_Right_Rotate(tree);   //�൱�ڲ���ʱ��LR���
        }
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
            AVLNode *temp =tree;   //����֮ǰ�ĸ��ڵ�ָ��
            tree = tree->lchild ? tree->lchild :tree->rchild;
            free(temp);     //�ͷ�
        }
    }

    return tree; //���ظ�
}

void TraverseAVL(AVLtree p, void (*visit)(Info data))
{
    if(p == NULL) return;

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

void JustPrintfId(Info data)
{
    printf("%d  ",data.id); //����������
    return;     //����0ƥ��ӿ�
}

Info GetTraverseInfo(Info data)
{
    return data;          //ֱ�ӷ���Info
}


//ADT��������
AVLLink* set_init(AVLLink **head)
{
    AVLLink *p;
    //�����ǰ������AVL��

    if(*head == NULL)
    {
        *head = (AVLLink*)malloc(sizeof(AVLLink));    //������
        (*head)->next = NULL;
        p = *head;
    }
    else
    {
        p = *head;
        while(p->next)   //����
            p = p->next;
        p->next = (AVLLink*)malloc(sizeof(AVLLink));    //�½��ڵ�
        p = p ->next;
        p->next = NULL;
    }

    printf("������ö����������֣�\n");
    scanf("%s",p->name);
    p->tree = NULL;

    return p;
}

bool set_destory(AVLLink **head)
{
    AVLLink *p = *head, *temp = NULL;
    char sname[10];
    if((*head) == NULL)         //�����ڵĻ��������ɹ�
    {
        printf("��ǰ�������������ʼ��������");
        return false;
    }
    printf("��ǰ���ڵ�����\n");
    while(p)         //���������ǰ���ڵ���
    {
        printf("%s    ",p->name);
        p = p->next;
    }
    printf("\n������Ҫ���ٵ��������֣�");
    scanf("%s",sname);
    p = *head;
    if(!strcmp(sname,p->name))   //����һ�����ǵĻ�
    {
        *head = p->next;  //Ҫ����ͷ���ָ��
        DestroyAVL(&p->tree);
        free(p);
    }
    else
    {
        temp = p;
        p = p->next;
        while(p)
        {
            if(!strcmp(sname,p->name))    //�ҵ�p��temp��p�ĸ��ڵ�
            {
                break;
            }
            p = p->next;
            temp = temp->next;
        }
        if(p)   //����ҵ�
        {
            temp->next = p->next;   //��p�Ƴ�����
            DestroyAVL(&p->tree);   //����AVL���ٺ���
            free(p);            //��p��������free
            return true;
        }
        else   //���û���ҵ�
            return false;
    }
    return true;

}

bool set_AVL(AVLLink *p, int *array, int count)
{
    Info temp;
    int i;
    for(i=0; i<count; i++)    //ѭ����������뵽����
    {
        temp.id = array[i];
        p->tree = InsertAVL(p->tree, temp);
    }
    return true;
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
    *NEWTREE = NULL;

    Intersection(T, T1, NEWTREE);   //�ݹ�ʵ��

    return;
}

void Intersection(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    if(T == NULL) return;  //����T

    Intersection(T->lchild, T1, NEWTREE);
    if(SearchAVL(T1, T->data.id))               //��T1���Ƿ���ڸýڵ�
        *NEWTREE = InsertAVL(*NEWTREE, T->data);  //���������NEWTREE
    Intersection(T->rchild, T1, NEWTREE);

    return;
}

void set_union(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    //���NEWTREE���ڵĻ�����������
    *NEWTREE = NULL;

    if(T)  //�ֽ�T��������
        Union(T, NEWTREE);
    if(T1)  //�ٽ�T1��������
        Union(T1, NEWTREE);

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


void set_difference(AVLtree T,AVLtree T1, AVLtree *NEWTREE)
{
    //���NEWTREE���ڵĻ�����������
    *NEWTREE = NULL;

    Difference(T, T1, NEWTREE);
}

void Difference(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    if(T == NULL) return;  //����T

    Difference(T->lchild, T1, NEWTREE);
    if(!SearchAVL(T1, T->data.id))               //��T1���Ƿ���ڸýڵ�
        *NEWTREE = InsertAVL(*NEWTREE, T->data);   //�����������NEWTREE
    Difference(T->rchild, T1, NEWTREE);

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
    else
        return false;
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


AVLLink* FindAVLLink(AVLLink *head, char* name)
{
    AVLLink *p = head;
    while(p)
    {
        if(!strcmp(p->name, name))  //�ҵ�
            return p;
        p = p->next;
    }
    return NULL;    //�Ҳ���
}

/** \brief ǰ�����������������PreOrderTraverse(T,Visit())��
*        ��ʼ�����Ƕ�����T���ڣ�Visit�ǶԽ�������Ӧ�ú���������������������t��
*          ��ÿ�������ú���Visitһ����һ�Σ�һ������ʧ�ܣ������ʧ�ܡ�
*/
bool PreOrderTraverse(AVLtree T,void (*visit)(Info c) )
{
    if(T == NULL) return false;

    visit(T->data);                //�ȷ��ʸ��ڵ�
    PreOrderTraverse(T->lchild, visit);   //����������
    PreOrderTraverse(T->rchild, visit);   //����������

    return true;
}

/** \brief �������������������InOrderTraverse(T,Visit))��(T)
*        ��ʼ�����Ƕ�����T���ڣ�Visit�ǶԽ�������Ӧ�ú���������������������t��
*          ��ÿ�������ú���Visitһ����һ�Σ�һ������ʧ�ܣ������ʧ�ܡ�
*/
bool InOrderTraverse(AVLtree T,void (*visit)(Info c) )
{
    if(T == NULL) return false;

    InOrderTraverse(T->lchild, visit);   //����������
    visit(T->data);                //���ʸ��ڵ�
    InOrderTraverse(T->rchild, visit);   //����������

    return true;
}

/** \brief �������������������PostOrderTraverse(T,Visit))��(T)
*        ��ʼ�����Ƕ�����T���ڣ�Visit�ǶԽ�������Ӧ�ú�������������Ǻ������t��
*          ��ÿ�������ú���Visitһ����һ�Σ�һ������ʧ�ܣ������ʧ��
*/
bool PostOrderTraverse(AVLtree T,void (*visit)(Info c) )
{
    if(T == NULL) return false;

    PostOrderTraverse(T->lchild, visit);   //����������
    PostOrderTraverse(T->rchild, visit);   //����������
    visit(T->data);                //�����ʸ��ڵ�

    return true;
}

/** \brief �������������������LevelOrderTraverse(T,Visit))��
*        ��ʼ�����Ƕ�����T���ڣ�Visit�ǶԽ�������Ӧ�ú�������������ǲ������t��
*          ��ÿ�������ú���Visitһ����һ�Σ�һ������ʧ�ܣ������ʧ��
*          ͨ��������ʵ��
*          F�Ƕ��е�βָ�룬H�Ƕ��е�ͷָ�룬��������������
*/
bool LevelOrderTraverse(AVLtree T,void (*visit)(Info c), AVLtree *F,AVLtree *H )
{
    if(T == NULL)
        return false;
    *F=T;            //����ǰ�ڵ���������ָ����ָλ��
    visit((*F)->data);   //���βָ��

    if((*F)->lchild != NULL)
    {
        H=H+1;             //ͷָ�����
        *H=(*F)->lchild;    //�ڵ������ӷ����ͷ
    }
    if((*F)->rchild != NULL)
    {
        H=H+1;                //ͷ������ƶ�һ��
        *H=(*F)->rchild;    //�ڵ���Ҷ��ӷ����ͷ
    }

    F=F+1;    //βָ�����һλ
    if(F != H || (*F)->lchild != NULL || (*F)->rchild != NULL)   //����ͷ�����ڶ�βʱ�ݹ飬 ��ʱҪע���βҲ�п�����������������û�н�����
        LevelOrderTraverse(*F ,visit ,F ,H);//�ݹ�
    else
        visit((*F)->data);    //���βָ��
    return true;
}

bool SaveADTData(AVLLink *head)
{
    if(head == NULL)   //���ж�
    {
        printf("��ǰ�����ڱ����������Ա����ʼ���ٱ��棡");
        getch();
        return false;
    }
    FILE *fp = fopen("AVLtree.dat","w");   //ֻд�ķ�ʽ���ļ�
    int length = 0;
    AVLLink *p = head;
    while(p)       //ͳ��������Ϣ
    {
        length++;
        p = p->next;
    }

    if(fp != NULL)
    {
        fprintf(fp, "%d\n", length);   //��һ�б����������
        for(p = head; p; p = p->next)
        {
            fprintf(fp,"%s  %d  ",p->name, set_size(p->tree));   //��ͷ�������������   ����
            SaveInOrderTraverse(p->tree, fp);
            fprintf(fp,"\n");
        }
        fclose(fp);   //�ر��ļ�
        printf("\n�ļ�����ɹ���");
        getch();
        return true;
    }
    else
    {
        printf("�ļ���ʧ�ܣ�");
        return false;
    }
}

bool SaveInOrderTraverse(AVLtree T,FILE *fp)
{
    if(T == NULL) return false;

    SaveInOrderTraverse(T->lchild, fp);   //����������
    fprintf(fp,"%d  ", T->data.id);               //���ʸ��ڵ�
    SaveInOrderTraverse(T->rchild, fp);   //����������

    return true;
}

bool LoadADTData(AVLLink **head)
{
    FILE *fp = fopen("AVLtree.dat","r");   //ֻ���ķ�ʽ���ļ�
    AVLLink *p = *head;
    int length, i, c, j, array[100];

    if(fp)
    {
        if(p != NULL)  //��ǰ����Ϊ�յĻ�
        {
            while(p->next)   //����
                p = (p)->next;
            p->next = (AVLLink*)malloc(sizeof(AVLLink));
            p = p->next;
            (p)->next = NULL;
            (p)->tree = NULL;
        }
        else
        {
            *head = (AVLLink*)malloc(sizeof(AVLLink));
            p = *head;
            (p)->next = NULL;
            (p)->tree = NULL;
        }

        fscanf(fp, "%d", &length);  //��ȡ����

        for(i=0; i<length; i++)  //��ȡÿһ����Ϣ
        {
            fscanf(fp,"%s %d", (p)->name, &c);
            for(j=0; j<c; j++)
            {
                fscanf(fp, "%d", &array[j]);
            }
            set_AVL((p), array, c);

            if(i == length-1)
            {
                (p)->next = NULL;
            }
            else
            {
                p->next = (AVLLink*)malloc(sizeof(AVLLink));
                (p) = (p)->next;
                (p)->tree = NULL;
            }
        }
        fclose(fp); //�ر��ļ�
        printf("�ļ���ȡ�ɹ���");
        getch();
        return true;
    }
    else
    {
        printf("�ļ���ʧ�ܣ�");
        getch();
        return false;
    }
}
