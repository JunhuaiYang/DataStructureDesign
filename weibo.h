#ifndef WEIBO_H_INCLUDED
#define WEIBO_H_INCLUDED

#define MAX_RAND 30   //每个节点最多随机生成的信息

#include"AVL.h"
#include<time.h>

extern int g_count;
extern int g_i;
extern AVLtree gp_all_name;

int GetRand(int n); //生成n以内的伪随机数
AVLtree NameInit(AVLtree head, char nickname[20]);
void WriteOneName();
void TraverseAllName();
void PrintIDName(Info data);
void PutOneInfo(void);
void PrintName(Info data);

void DeleteUser(void);

void AddOnesFriend(void);
void AddOnesFans(void);
void AddOnesAtt(void);
void AddOnesHobby(void);
void DeleteOneFriend(void);
void DeleteOneFans(void);
void DeleteOneAtt(void);
void DeleteOneHobby(void);

void RandName(void);
void RandOneInfo(Info *data);
void RandAllInfo(AVLtree tree);

void SameAtt(void);
void SameHobby(void);
void TwoFriend(void);

void FindHobby(AVLtree T1, AVLtree T2);
bool FindName(AVLtree tree, char *name);

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
