/** \brief 该文件用于保存第三层二叉树应用的相关函数申明
 *
 *
 */
#ifndef WEIBO_H_INCLUDED
#define WEIBO_H_INCLUDED

#define MAX_RAND 30   //每个节点最多随机生成的信息

#include"AVL.h"
#include<time.h>

//定义全局变量
extern int g_count;   //计数多少信息
extern int g_i;    //输出信息相关的全局变量
extern AVLtree gp_all_name;   //所有树的头结点


int GetRand(int n); //生成n以内的伪随机数
AVLtree NameInit(AVLtree head, char nickname[20]);
//交互相关函数
void WriteOneName();
//打印相关函数
void TraverseAllName();
void PrintIDName(Info data);
void PutOneInfo(void);
void PrintName(Info data);
//删除用户
void DeleteUser(void);
//添加各种信息
void AddOnesFriend(void);
void AddOnesFans(void);
void AddOnesAtt(void);
void AddOnesHobby(void);
//删除各种信息
void DeleteOneFriend(void);
void DeleteOneFans(void);
void DeleteOneAtt(void);
void DeleteOneHobby(void);
//随机生成各种信息
void RandName(void);
void RandOneInfo(AVLtree tree);
void RandAllInfo(AVLtree tree);
//相同关注
void SameAtt(void);
//相同喜好
void SameHobby(void);
//二度好友
void TwoFriend(void);
//查找相关函数
void FindHobby(AVLtree T1, AVLtree T2);
bool FindName(AVLtree tree, char *name);

//保存相关函数
void SaveName(void);
void SaveInfo(void);
void LoadName(void);
void LoadInfo(void);

void SaveTraverseName(AVLtree T, FILE *fp);
void SaveTraverseInfo(AVLtree T, FILE *fp);
void SaveTraverseHobby(AVLtree T, FILE *fp);

void LoadEachInfo(AVLtree *T, FILE *fp);
void LoadEachHobby(AVLtree *T, FILE *fp);

#endif // WEIBO_H_INCLUDED
