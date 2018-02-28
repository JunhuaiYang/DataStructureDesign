#ifndef WEIBO_H_INCLUDED
#define WEIBO_H_INCLUDED

#include"AVL.h"

extern int g_count;
extern AVLtree gp_all_name;

AVLtree NameInit(AVLtree head, char nickname[20]);

void WriteOneName();
void LoadName();
void TraverseAllName();
void PrintIDName(Info data);


#endif // WEIBO_H_INCLUDED
