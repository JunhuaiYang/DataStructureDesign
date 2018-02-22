#ifndef WEIBO_H_INCLUDED
#define WEIBO_H_INCLUDED

#include"AVL.h"

typedef struct Info
{
    int id;           //用于普通测试或者用于用户ID编号
    char lastname[3];
    char givenname[5];
    struct AVLNode *friends;
    struct AVLNode *fans;
    struct AVLNode *attention;
    struct AVLNode *hobby;
} Info;

#endif // WEIBO_H_INCLUDED
