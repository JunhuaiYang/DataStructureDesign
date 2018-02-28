#include"AVL.h"
#include"weibo.h"

int g_count;
AVLtree gp_all_name;

AVLtree NameInit(AVLtree head, char nickname[20])
{
    Info data;
    strcpy(data.nickname, nickname);
    data.id = ++g_count;       //以全局变量编号
    data.attentions = NULL;   //其他全部初始化为空
    data.fans = NULL;
    data.friends = NULL;
    data.hobby = NULL;

    return InsertAVL(head, data);
}


void WriteOneName()
{
    AVLtree temp = NULL;
    char name[20];
    printf("当前输入一个名字：");
    scanf("%s",name);
    temp = NameInit(gp_all_name, name);   //调用NameInit函数加入所有名字的集合
    if(temp)
        printf("\n用户加入集合成功！\n当前用户编号：%d",temp->data.id);
    else
        printf("\n用户加入失败！");
}

void LoadName()
{
    FILE *fp;
    fp = fopen("nickname.dat","r");  //只读方式打开文件
    char name[20];

    if(fp)   //文件打开成功
    {
        while(fscanf(fp,"%s",name) != EOF)
            NameInit(gp_all_name, name);      //持续调用
        printf("文件读取成功！\n");
        printf("当前读入用户共%d名！", g_count);
    }
    else   //文件打开失败
    {
        printf("文件打开失败!");
    }
}

void TraverseAllName()
{
    printf("当前录入的所用用户名为：");
    TraverseAVL(gp_all_name, PrintIDName);
}

void PrintIDName(Info data)
{
    printf("%d\t%s\t",data.id,data.nickname);
}
