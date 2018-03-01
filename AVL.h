#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>

//#include"weibo.h"

typedef struct Info
{
    int id;           //������ͨ���Ի��������û�ID���
    char nickname[20];
    struct AVLNode *friends;
    struct AVLNode *fans;
    struct AVLNode *attentions;
    struct AVLNode *hobby;
}Info;

typedef struct AVLNode
{
    Info data;    //������Ϣ
    int height;   //�߶�
    struct AVLNode *lchild,*rchild;    //��������
} AVLNode, *AVLtree;

typedef struct AVLLink
{
    AVLtree tree;  //��������
    char name[10];
    struct AVLLink *next;
}AVLLink;


extern AVLLink *gp_tree_head;    //ȫ��ͷ���
extern int count;  //ȫ�ֱ���count

//6�ֻ�������
bool InitAVL(AVLtree *T);
bool DestroyAVL(AVLtree *T);
AVLtree SearchAVL(AVLtree head, int key);
AVLtree InsertAVL(AVLtree newtree,Info key);
AVLtree DeleteAVL(AVLtree tree, AVLNode *z);
void TraverseAVL(AVLtree p, void (*visit)(Info data));
int GetBlanceFactor(AVLtree tree);



AVLLink* set_init(AVLLink **head);
bool set_destory(AVLLink **head);
bool set_insert(AVLtree *T,Info e);
bool set_remove(AVLtree *T,int key);
void set_intersection(AVLtree T,AVLtree T1,AVLtree *NEWTREE);
void Intersection(AVLtree T,AVLtree T1,AVLtree *NEWTREE);
void set_union(AVLtree T,AVLtree T1, AVLtree *NEWTREE);
void Union(AVLtree T, AVLtree *newtree);
void set_difference(AVLtree T,AVLtree T1, AVLtree *NEWTREE);
void Difference(AVLtree T,AVLtree T1,AVLtree *NEWTREE);
int set_size(AVLtree T);
void Count(Info data);
bool set_member(AVLtree T,int key);
bool set_subset(AVLtree TS,AVLtree T1);
bool Subset(AVLtree TS, AVLtree T1);
bool set_equal(AVLtree T,AVLtree T1);
bool set_AVL(AVLLink *p, int *array, int count);

AVLtree Left_Left_Rotate(AVLtree p);
AVLtree Right_Right_Rotate(AVLtree p);
AVLtree Left_Right_Rotate(AVLtree p);
AVLtree Right_Left_Rotate(AVLtree p);

AVLtree FindMaxNode(AVLtree tree);
AVLtree FindMinNode(AVLtree tree);

AVLLink* FindAVLLink(AVLLink *head, char* name);

int MAX(int a, int b);
int Height(AVLtree tree);
void JustPrintfId(Info data);

bool PreOrderTraverse(AVLtree T,void (*visit)(Info c) );
bool InOrderTraverse(AVLtree T,void (*visit)(Info c) );
bool PostOrderTraverse(AVLtree T,void (*visit)(Info c) );
bool LevelOrderTraverse(AVLtree T,void (*visit)(Info c), AVLtree *F,AVLtree *H );

bool SaveADTData(AVLLink *head);
bool SaveInOrderTraverse(AVLtree T,FILE *fp);
bool LoadADTData(AVLLink **head);

void Exit(void);  //�˳�ʱ���������

#endif // AVL_H_INCLUDED
