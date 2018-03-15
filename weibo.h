/** \brief ���ļ����ڱ�������������Ӧ�õ���غ�������
 *
 *
 */
#ifndef WEIBO_H_INCLUDED
#define WEIBO_H_INCLUDED

#define MAX_RAND 30   //ÿ���ڵ����������ɵ���Ϣ

#include"AVL.h"
#include<time.h>

//����ȫ�ֱ���
extern int g_count;   //����������Ϣ
extern int g_i;    //�����Ϣ��ص�ȫ�ֱ���
extern AVLtree gp_all_name;   //��������ͷ���


int GetRand(int n); //����n���ڵ�α�����
AVLtree NameInit(AVLtree head, char nickname[20]);
//������غ���
void WriteOneName();
//��ӡ��غ���
void TraverseAllName();
void PrintIDName(Info data);
void PutOneInfo(void);
void PrintName(Info data);
//ɾ���û�
void DeleteUser(void);
//��Ӹ�����Ϣ
void AddOnesFriend(void);
void AddOnesFans(void);
void AddOnesAtt(void);
void AddOnesHobby(void);
//ɾ��������Ϣ
void DeleteOneFriend(void);
void DeleteOneFans(void);
void DeleteOneAtt(void);
void DeleteOneHobby(void);
//������ɸ�����Ϣ
void RandName(void);
void RandOneInfo(AVLtree tree);
void RandAllInfo(AVLtree tree);
//��ͬ��ע
void SameAtt(void);
//��ͬϲ��
void SameHobby(void);
//���Ⱥ���
void TwoFriend(void);
//������غ���
void FindHobby(AVLtree T1, AVLtree T2);
bool FindName(AVLtree tree, char *name);

//������غ���
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
