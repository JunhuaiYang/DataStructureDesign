#include"AVL.h"
#include"weibo.h"

int g_count;
AVLtree gp_all_name;

AVLtree NameInit(AVLtree head, char nickname[20])
{
    Info data;
    strcpy(data.nickname, nickname);
    data.id = ++g_count;       //��ȫ�ֱ������
    data.attentions = NULL;   //����ȫ����ʼ��Ϊ��
    data.fans = NULL;
    data.friends = NULL;
    data.hobby = NULL;

    return InsertAVL(head, data);
}


void WriteOneName()
{
    AVLtree temp = NULL;
    char name[20];
    printf("��ǰ����һ�����֣�");
    scanf("%s",name);
    temp = NameInit(gp_all_name, name);   //����NameInit���������������ֵļ���
    if(temp)
        printf("\n�û����뼯�ϳɹ���\n��ǰ�û���ţ�%d",temp->data.id);
    else
        printf("\n�û�����ʧ�ܣ�");
}

void LoadName()
{
    FILE *fp;
    fp = fopen("nickname.dat","r");  //ֻ����ʽ���ļ�
    char name[20];

    if(fp)   //�ļ��򿪳ɹ�
    {
        while(fscanf(fp,"%s",name) != EOF)
            NameInit(gp_all_name, name);      //��������
        printf("�ļ���ȡ�ɹ���\n");
        printf("��ǰ�����û���%d����", g_count);
    }
    else   //�ļ���ʧ��
    {
        printf("�ļ���ʧ��!");
    }
}

void TraverseAllName()
{
    printf("��ǰ¼��������û���Ϊ��");
    TraverseAVL(gp_all_name, PrintIDName);
}

void PrintIDName(Info data)
{
    printf("%d\t%s\t",data.id,data.nickname);
}
