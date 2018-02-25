#ifndef WEIBO_H_INCLUDED
#define WEIBO_H_INCLUDED

#include"AVL.h"

typedef struct Info
{
    int id;           //������ͨ���Ի��������û�ID���
    char nickname[20];
    struct AVLNode *friends;
    struct AVLNode *fans;
    struct AVLNode *attentions;
    struct AVLNode *hobby;
} Info;

#endif // WEIBO_H_INCLUDED
