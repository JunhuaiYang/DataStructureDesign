/** \brief 该文件用于保存二叉树的基本运算函数申明及基本数据结构定义
 *
 *
 */

#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>

//#include"weibo.h"

//基本数据结构变量的定义于申明
typedef struct Info
{
    int id;           //用于普通测试或者用于用户ID编号
    char nickname[20];
    struct AVLNode *friends;  //朋友
    struct AVLNode *fans;    //粉丝
    struct AVLNode *attentions;  //关注
    struct AVLNode *hobby;   //喜好
}Info;   //基本信息节点

typedef struct AVLNode
{
    Info data;    //保存信息
    int height;   //高度
    struct AVLNode *lchild,*rchild;    //左右子树
} AVLNode, *AVLtree;  //基本树节点

//多树管理结构
typedef struct AVLLink
{
    AVLtree tree;  //多树管理
    char name[10];
    struct AVLLink *next;  //链表指针
}AVLLink;

//全局变量
extern AVLLink *gp_tree_head;    //全局头结点
extern int count;  //全局变量count

//6种基本运算
bool InitAVL(AVLtree *T);
bool DestroyAVL(AVLtree *T);
AVLtree SearchAVL(AVLtree head, int key);
AVLtree InsertAVL(AVLtree newtree,Info key);
AVLtree DeleteAVL(AVLtree tree, AVLNode *z);
void TraverseAVL(AVLtree p, void (*visit)(Info data));
int GetBlanceFactor(AVLtree tree);


//ADT集合应用函数
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

//一些辅助函数
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

//遍历函数
bool PreOrderTraverse(AVLtree T,void (*visit)(Info c) );
bool InOrderTraverse(AVLtree T,void (*visit)(Info c) );
bool PostOrderTraverse(AVLtree T,void (*visit)(Info c) );
bool LevelOrderTraverse(AVLtree T,void (*visit)(Info c), AVLtree *F,AVLtree *H );

//数据保存相关
bool SaveADTData(AVLLink *head);
bool SaveInOrderTraverse(AVLtree T,FILE *fp);
bool LoadADTData(AVLLink **head);

void Exit(void);  //退出时清空所有树

#endif // AVL_H_INCLUDED
