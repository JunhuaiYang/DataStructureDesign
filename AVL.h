#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>

#include"weibo.h"

#define LH 1   //左高
#define EH 0   //平衡
#define RH -1  //右高


typedef struct AVLNode
{
    Info data;    //保存信息
    int bf;       //平衡因子
    int height;   //高度
    struct AVLNode *lchild,*rchild;    //左右子树
} AVLNode,*AVLtree;

extern int set_size(AVLtree T);

//6种基本运算
bool InitAVL(AVLtree *T);
bool DestroyAVL(AVLtree *T);
AVLtree SearchAVL(AVLtree head, int key);
AVLtree InsertAVL(AVLtree newtree,Info key);
AVLtree DeleteAVL(AVLtree tree, AVLNode *z);
void TraverseAVL(AVLtree p, void (*visit)(Info data));
int GetBlanceFactor(AVLtree tree);



void set_init(AVLtree *T);
void set_destory(AVLtree *T);
bool set_insert(AVLtree *T,Info e);
bool set_remove(AVLtree *T,int key);
void set_intersection(AVLtree T,AVLtree T1,AVLtree *NEWTREE);
void Intersection(AVLtree T,AVLtree T1,AVLtree *NEWTREE);
void set_union(AVLtree T,AVLtree T1, AVLtree *NEWTREE);
void Union(AVLtree T, AVLtree *newtree);
void set_difference(AVLtree *T,AVLtree T1, AVLtree *NEWTREE);
void Difference(AVLtree T,AVLtree T1,AVLtree *NEWTREE);
int set_size(AVLtree T);
void Count(Info data);
bool set_member(AVLtree T,int key);
bool set_subset(AVLtree TS,AVLtree T1);
bool Subset(AVLtree TS, AVLtree T1);
bool set_equal(AVLtree T,AVLtree T1);

//void LeftBalance(AVLtree *T);
//void RightBalance(AVLtree *T);
//void L_Rotate(AVLtree *p);
//void R_Rotate(AVLtree *p);
//bool load_data(AVLtree *T,char *filename);
//bool save_data(AVLtree T,FILE *fp);
//void input_data(Info *data);
//void create(AVLtree *T);
//void height(AVLtree T,int i);
//void graph(AVLtree T,int x,int y,visit fp);
//void operate_id(AVLtree T);
//void operate_relation(AVLtree T1,AVLtree T);
//void operate_hobby(AVLtree T1,AVLtree H);
//void gotoxy(int x,int y);
//void menu();
//bool person_input(AVLtree *T,int p_gross);
//bool hobby_set_input(AVLtree *H,int *h_gross);
//void relation_input(AVLtree *T,int p_gross,int h_gross);
//void id_input(AVLtree *T,int gross,int max,int min);

void PreOrderTraverse(AVLtree T);
void indirect_friends_traverse(AVLtree T,AVLtree Tf,AVLtree *T0);
void indirect_friends_insert(AVLtree T,AVLtree *T0);
void adjust_traverse(AVLtree T);
void complete_traverse(AVLtree T,AVLtree T0);
void complete_friends(AVLtree T,AVLtree T1,AVLtree Tf);
void complete_fans(AVLtree T,AVLtree T1,AVLtree Tf);
void complete_sttention(AVLtree T,AVLtree T1,AVLtree Tf);

AVLtree Left_Left_Rotate(AVLtree p);
AVLtree Right_Right_Rotate(AVLtree p);
AVLtree Left_Right_Rotate(AVLtree p);
AVLtree Right_Left_Rotate(AVLtree p);

AVLtree FindMaxNode(AVLtree tree);
AVLtree FindMinNode(AVLtree tree);

int MAX(int a, int b);
int Height(AVLtree tree);
void JustPrintfId(Info data);

#endif // AVL_H_INCLUDED
