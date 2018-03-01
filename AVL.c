#include"AVL.h"

int count;  //全局变量count
AVLLink *gp_tree_head;    //全局头结点

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
    if(Tnode == NULL)
        return true;
    p = Tnode->lchild;
    q = Tnode->rchild;
    if (p == NULL || q == NULL)  //只有根节点
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
        printf("\n节点相同，添加失败！ \n");
    //更新节点高度信息
    newtree->height = MAX(Height(newtree->lchild), Height(newtree->rchild)) + 1;

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
        // 删除节点后，若AVL树失去平衡，则进行相应的调节。
        if(GetBlanceFactor(tree) == -2)
        {
            AVLNode *right = tree->rchild;
            if(GetBlanceFactor(right) < 0 )   //右高
                tree = Right_Right_Rotate(tree);        //相当于插入时的RR情况
            else
                tree = Right_Left_Rotate(tree);     //相当于插入时的RL情况
        }
    }
    else if(z->data.id > tree->data.id)     //待删除的在右子树
    {
        tree->rchild = DeleteAVL(tree->rchild, z); //递归去找删除节点
        //平衡处理，右子树失去平衡，应该处理左子树
        // 删除节点后，若AVL树失去平衡，则进行相应的调节。
        if(GetBlanceFactor(tree)  == 2)
        {
            AVLNode *left = tree->lchild;
            if(GetBlanceFactor(left) > 0)   // 左高
                tree = Left_Left_Rotate(tree);     //相当于插入时的LL情况
            else
                tree = Left_Right_Rotate(tree);   //相当于插入时的LR情况
        }
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
            AVLNode *temp =tree;   //保存之前的根节点指向
            tree = tree->lchild ? tree->lchild :tree->rchild;
            free(temp);     //释放
        }
    }

    return tree; //返回根
}

void TraverseAVL(AVLtree p, void (*visit)(Info data))
{
    if(p == NULL) return;

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

void JustPrintfId(Info data)
{
    printf("%d  ",data.id); //中序遍历输出
    return;     //返回0匹配接口
}

Info GetTraverseInfo(Info data)
{
    return data;          //直接返回Info
}


//ADT基本运算
AVLLink* set_init(AVLLink **head)
{
    AVLLink *p;
    //如果当前不存在AVL树

    if(*head == NULL)
    {
        *head = (AVLLink*)malloc(sizeof(AVLLink));    //不存在
        (*head)->next = NULL;
        p = *head;
    }
    else
    {
        p = *head;
        while(p->next)   //查找
            p = p->next;
        p->next = (AVLLink*)malloc(sizeof(AVLLink));    //新建节点
        p = p ->next;
        p->next = NULL;
    }

    printf("请输入该二叉树的名字：\n");
    scanf("%s",p->name);
    p->tree = NULL;

    return p;
}

bool set_destory(AVLLink **head)
{
    AVLLink *p = *head, *temp = NULL;
    char sname[10];
    if((*head) == NULL)         //不存在的话操作不成功
    {
        printf("当前不存在树，请初始化创建！");
        return false;
    }
    printf("当前存在的树：\n");
    while(p)         //遍历输出当前存在的树
    {
        printf("%s    ",p->name);
        p = p->next;
    }
    printf("\n请输入要销毁的树的名字：");
    scanf("%s",sname);
    p = *head;
    if(!strcmp(sname,p->name))   //当第一个就是的话
    {
        *head = p->next;  //要更改头结点指向
        DestroyAVL(&p->tree);
        free(p);
    }
    else
    {
        temp = p;
        p = p->next;
        while(p)
        {
            if(!strcmp(sname,p->name))    //找到p，temp是p的父节点
            {
                break;
            }
            p = p->next;
            temp = temp->next;
        }
        if(p)   //如果找到
        {
            temp->next = p->next;   //将p移除链表
            DestroyAVL(&p->tree);   //调用AVL销毁函数
            free(p);            //将p从链表中free
            return true;
        }
        else   //如果没有找到
            return false;
    }
    return true;

}

bool set_AVL(AVLLink *p, int *array, int count)
{
    Info temp;
    int i;
    for(i=0; i<count; i++)    //循环将数组插入到其中
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
    *NEWTREE = NULL;

    Intersection(T, T1, NEWTREE);   //递归实现

    return;
}

void Intersection(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    if(T == NULL) return;  //遍历T

    Intersection(T->lchild, T1, NEWTREE);
    if(SearchAVL(T1, T->data.id))               //找T1中是否存在该节点
        *NEWTREE = InsertAVL(*NEWTREE, T->data);  //若存在则放NEWTREE
    Intersection(T->rchild, T1, NEWTREE);

    return;
}

void set_union(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    //如果NEWTREE存在的话，将其销毁
    *NEWTREE = NULL;

    if(T)  //现将T放入新树
        Union(T, NEWTREE);
    if(T1)  //再将T1放入新树
        Union(T1, NEWTREE);

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


void set_difference(AVLtree T,AVLtree T1, AVLtree *NEWTREE)
{
    //如果NEWTREE存在的话，将其销毁
    *NEWTREE = NULL;

    Difference(T, T1, NEWTREE);
}

void Difference(AVLtree T,AVLtree T1,AVLtree *NEWTREE)
{
    if(T == NULL) return;  //遍历T

    Difference(T->lchild, T1, NEWTREE);
    if(!SearchAVL(T1, T->data.id))               //找T1中是否存在该节点
        *NEWTREE = InsertAVL(*NEWTREE, T->data);   //若不存在则放NEWTREE
    Difference(T->rchild, T1, NEWTREE);

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
    else
        return false;
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


AVLLink* FindAVLLink(AVLLink *head, char* name)
{
    AVLLink *p = head;
    while(p)
    {
        if(!strcmp(p->name, name))  //找到
            return p;
        p = p->next;
    }
    return NULL;    //找不到
}

/** \brief 前序遍历：函数名称是PreOrderTraverse(T,Visit())；
*        初始条件是二叉树T存在，Visit是对结点操作的应用函数；操作结果：先序遍历t，
*          对每个结点调用函数Visit一次且一次，一旦调用失败，则操作失败。
*/
bool PreOrderTraverse(AVLtree T,void (*visit)(Info c) )
{
    if(T == NULL) return false;

    visit(T->data);                //先访问根节点
    PreOrderTraverse(T->lchild, visit);   //访问左子树
    PreOrderTraverse(T->rchild, visit);   //访问右子树

    return true;
}

/** \brief 中序遍历：函数名称是InOrderTraverse(T,Visit))；(T)
*        初始条件是二叉树T存在，Visit是对结点操作的应用函数；操作结果是中序遍历t，
*          对每个结点调用函数Visit一次且一次，一旦调用失败，则操作失败。
*/
bool InOrderTraverse(AVLtree T,void (*visit)(Info c) )
{
    if(T == NULL) return false;

    InOrderTraverse(T->lchild, visit);   //访问左子树
    visit(T->data);                //访问根节点
    InOrderTraverse(T->rchild, visit);   //访问右子树

    return true;
}

/** \brief 后序遍历：函数名称是PostOrderTraverse(T,Visit))；(T)
*        初始条件是二叉树T存在，Visit是对结点操作的应用函数；操作结果是后序遍历t，
*          对每个结点调用函数Visit一次且一次，一旦调用失败，则操作失败
*/
bool PostOrderTraverse(AVLtree T,void (*visit)(Info c) )
{
    if(T == NULL) return false;

    PostOrderTraverse(T->lchild, visit);   //访问左子树
    PostOrderTraverse(T->rchild, visit);   //访问右子树
    visit(T->data);                //最后访问根节点

    return true;
}

/** \brief 按层遍历：函数名称是LevelOrderTraverse(T,Visit))；
*        初始条件是二叉树T存在，Visit是对结点操作的应用函数；操作结果是层序遍历t，
*          对每个结点调用函数Visit一次且一次，一旦调用失败，则操作失败
*          通过队列来实现
*          F是队列的尾指针，H是队列的头指针，定义在主函数中
*/
bool LevelOrderTraverse(AVLtree T,void (*visit)(Info c), AVLtree *F,AVLtree *H )
{
    if(T == NULL)
        return false;
    *F=T;            //将当前节点放入队列首指针所指位置
    visit((*F)->data);   //输出尾指针

    if((*F)->lchild != NULL)
    {
        H=H+1;             //头指针后移
        *H=(*F)->lchild;    //节点的左儿子放入队头
    }
    if((*F)->rchild != NULL)
    {
        H=H+1;                //头针向后移动一格
        *H=(*F)->rchild;    //节点的右儿子放入队头
    }

    F=F+1;    //尾指针后移一位
    if(F != H || (*F)->lchild != NULL || (*F)->rchild != NULL)   //当队头不等于队尾时递归， 此时要注意队尾也有可能有左子树右子树没有进队列
        LevelOrderTraverse(*F ,visit ,F ,H);//递归
    else
        visit((*F)->data);    //输出尾指针
    return true;
}

bool SaveADTData(AVLLink *head)
{
    if(head == NULL)   //先判断
    {
        printf("当前不存在保存树的线性表！请初始化再保存！");
        getch();
        return false;
    }
    FILE *fp = fopen("AVLtree.dat","w");   //只写的方式打开文件
    int length = 0;
    AVLLink *p = head;
    while(p)       //统计链表信息
    {
        length++;
        p = p->next;
    }

    if(fp != NULL)
    {
        fprintf(fp, "%d\n", length);   //第一行保存链表个数
        for(p = head; p; p = p->next)
        {
            fprintf(fp,"%s  %d  ",p->name, set_size(p->tree));   //开头保存二叉树名字   长度
            SaveInOrderTraverse(p->tree, fp);
            fprintf(fp,"\n");
        }
        fclose(fp);   //关闭文件
        printf("\n文件保存成功！");
        getch();
        return true;
    }
    else
    {
        printf("文件打开失败！");
        return false;
    }
}

bool SaveInOrderTraverse(AVLtree T,FILE *fp)
{
    if(T == NULL) return false;

    SaveInOrderTraverse(T->lchild, fp);   //访问左子树
    fprintf(fp,"%d  ", T->data.id);               //访问根节点
    SaveInOrderTraverse(T->rchild, fp);   //访问右子树

    return true;
}

bool LoadADTData(AVLLink **head)
{
    FILE *fp = fopen("AVLtree.dat","r");   //只读的方式打开文件
    AVLLink *p = *head;
    int length, i, c, j, array[100];

    if(fp)
    {
        if(p != NULL)  //当前链表不为空的话
        {
            while(p->next)   //查找
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

        fscanf(fp, "%d", &length);  //读取长度

        for(i=0; i<length; i++)  //读取每一条信息
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
        fclose(fp); //关闭文件
        printf("文件读取成功！");
        getch();
        return true;
    }
    else
    {
        printf("文件打开失败！");
        getch();
        return false;
    }
}
