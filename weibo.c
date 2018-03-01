#include"AVL.h"
#include"weibo.h"

int g_count;
int g_i;
AVLtree gp_all_name;

int GetRand(int n) //����n���ڵ�α�����
{
    return rand()%n+1;
}

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


void WriteOneName(void)
{
    char name[20];

    printf("��ǰ����һ�����֣�");
    scanf("%s",name);

    gp_all_name = NameInit(gp_all_name, name);   //����NameInit���������������ֵļ���
        printf("\n�û����뼯�ϳɹ���\n��ǰ�û���ţ�%d",g_count);
}


void TraverseAllName(void)
{
    printf("��ǰ¼��������û���Ϊ��");
    g_i = 0;
    TraverseAVL(gp_all_name, PrintIDName);
}

void PrintIDName(Info data)
{
    if(++g_i % 5 == 1)
        printf("\n");
    printf("%-5d%-15s",data.id,data.nickname);
}

void PrintName(Info data)
{
    if(++g_i % 7 == 1)
        printf("\n");
    printf("%-15s",data.nickname);
}

void PutOneInfo(void)
{
    int id;
    AVLtree temp;
    printf("������Ҫ�鿴���û���ţ�");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //�������û�
    if (temp)//�ҵ�
    {
        printf("\n���û���IDΪ��%-5d���û��ǳ�Ϊ��%s",temp->data.id, temp->data.nickname);
        printf("\n\n���û��ĺ����У�");
        g_i = 0;     //�ѱ�������������
        TraverseAVL(temp->data.friends, PrintName);
        printf("\n\n���û��ķ�˿�У�");
        g_i = 0;     //�ѱ�������������
        TraverseAVL(temp->data.fans, PrintName);
        printf("\n\n���û��Ĺ�ע�У�");
        g_i = 0;     //�ѱ�������������
        TraverseAVL(temp->data.attentions, PrintName);
        printf("\n\n���û��ĸ���ϲ���У�");
        g_i = 0;     //�ѱ�������������
        TraverseAVL(temp->data.hobby, PrintName);
    }
    else  //û���ҵ�
    {
        printf("\n�Ҳ������û���");
    }
}

void DeleteUser(void)
{
    int id;
    AVLtree temp;
    char key;
    printf("������Ҫɾ�����û���ţ�");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //�������û�
    if (temp)
    {
        printf("\n���û�����ϢΪ:");
        printf("\n���û���IDΪ��%-5d���û��ǳ�Ϊ��%s",temp->data.id, temp->data.nickname);
        printf("\n\n���û��ĺ����У�");
        g_i = 0;     //�ѱ�������������
        TraverseAVL(temp->data.friends, PrintName);
        printf("\n\n���û��ķ�˿�У�");
        g_i = 0;     //�ѱ�������������
        TraverseAVL(temp->data.fans, PrintName);
        printf("\n\n���û��Ĺ�ע�У�");
        g_i = 0;     //�ѱ�������������
        TraverseAVL(temp->data.attentions, PrintName);
        printf("\n\n���û��ĸ���ϲ���У�");
        g_i = 0;     //�ѱ�������������
        TraverseAVL(temp->data.hobby, PrintName);
        printf("\n\n�Ƿ�ɾ�������밴Y�����������\n");
        scanf(" %c",&key);
        if(key == 'Y' || key == 'y')
        {
            gp_all_name = DeleteAVL(gp_all_name, temp);
            printf("\nɾ���ɹ���");
        }

    }
    else
    {
        printf("\n�Ҳ������û�!");
    }
}

void AddOnesFriend(void)
{
    int id;
    AVLtree temp, p;
    printf("������Ҫ�༭���û���ţ�");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //�������û�
    if(temp)   //�ҵ�
    {
        printf("\n������Ҫ��Ӻ��ѵ��û���ţ�");
        scanf("%d",&id);
        p = SearchAVL(gp_all_name, id);  //����
        if (p)     //�ҵ�
        {
            temp->data.friends = InsertAVL(temp->data.friends, p->data);  //�൱���ڴ˴��½���
            printf("\n%s       ��ӳɹ���",p->data.nickname);
        }
        else   //û���ҵ�
        {
            printf("\n�Ҳ������û������ʧ��");
        }
    }
    else  //û���ҵ�
    {
        printf("\n�Ҳ������û������ʧ��");
    }
}

void AddOnesFans(void)
{
    int id;
    AVLtree temp, p;
    printf("������Ҫ�༭���û���ţ�");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //�������û�
    if(temp)   //�ҵ�
    {
        printf("\n������Ҫ��ӷ�˿���û���ţ�");
        scanf("%d",&id);
        p = SearchAVL(gp_all_name, id);  //����
        if (p)     //�ҵ�
        {
            temp->data.fans = InsertAVL(temp->data.fans, p->data);  //�൱���ڴ˴��½���
            printf("\n%s       ��ӳɹ���",p->data.nickname);
        }
        else   //û���ҵ�
        {
            printf("\n�Ҳ������û������ʧ��");
        }
    }
    else  //û���ҵ�
    {
        printf("\n�Ҳ������û������ʧ��");
    }
}

void AddOnesAtt(void)
{
    int id;
    AVLtree temp, p;
    printf("������Ҫ�༭���û���ţ�");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //�������û�
    if(temp)   //�ҵ�
    {
        printf("\n������Ҫ��ӹ�ע���û���ţ�");
        scanf("%d",&id);
        p = SearchAVL(gp_all_name, id);  //����
        if (p)     //�ҵ�
        {
            temp->data.attentions = InsertAVL(temp->data.attentions, p->data);  //�൱���ڴ˴��½���
            printf("\n%s       ��ӳɹ���",p->data.nickname);
        }
        else   //û���ҵ�
        {
            printf("\n�Ҳ������û������ʧ��");
        }
    }
    else  //û���ҵ�
    {
        printf("\n�Ҳ������û������ʧ��");
    }
}

void AddOnesHobby(void)
{
    int id;
    AVLtree temp;
    Info hobby;
    printf("������Ҫ�༭���û���ţ�");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //�������û�
    if(temp)   //�ҵ�
    {
        printf("\n��������û���ϲ��֮һ��");
        scanf("%s",hobby.nickname);   //��nickname����hobby
        hobby.id = GetRand(100);  //����100�ڵ�α�������֧�ֶ������Ĵ���
        temp->data.hobby = InsertAVL(temp->data.hobby, hobby);  //������Ȥ������
        printf("\n��ӳɹ���");
    }
    else  //û���ҵ�
    {
        printf("\n�Ҳ������û������ʧ��");
    }
}

void DeleteOneFriend(void)
{
    int id;
    char key;
    AVLtree temp, p;
    printf("������Ҫ�༭���û���ţ�");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //�������û�
    if(temp)   //�ҵ�
    {
        printf("\n��ǰ�û��ĺ����У�");
        g_i = 0;     //�ѱ�������������
        TraverseAVL(temp->data.friends, PrintIDName);
        printf("\n������Ҫɾ�����ѵ��û���ţ�");
        scanf("%d",&id);
        p = SearchAVL(temp->data.friends, id);  //���� �ں�����
        if (p)     //�ҵ�
        {
            printf("\n\n�Ƿ�ɾ�������밴Y�����������\n");
            scanf(" %c",&key);
            if(key == 'Y' || key == 'y')
            {
                temp->data.friends = DeleteAVL(temp->data.friends, p);
                printf("\nɾ���ɹ���");
            }
        }
        else   //û���ҵ�
        {
            printf("\n�Ҳ������û���ɾ��ʧ��");
        }
    }
    else  //û���ҵ�
    {
        printf("\n�Ҳ������û���ɾ��ʧ��");
    }
}


void DeleteOneFans(void)
{
    int id;
    char key;
    AVLtree temp, p;
    printf("������Ҫ�༭���û���ţ�");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //�������û�
    if(temp)   //�ҵ�
    {
        printf("\n��ǰ�û��ķ�˿�У�");
        g_i = 0;     //�ѱ�������������
        TraverseAVL(temp->data.fans, PrintIDName);
        printf("\n������Ҫɾ����˿���û���ţ�");
        scanf("%d",&id);
        p = SearchAVL(temp->data.fans, id);  //���� �ڷ�˿��
        if (p)     //�ҵ�
        {
            printf("\n\n�Ƿ�ɾ�������밴Y�����������\n");
            scanf(" %c",&key);
            if(key == 'Y' || key == 'y')
            {
                temp->data.fans = DeleteAVL(temp->data.fans, p);
                printf("\nɾ���ɹ���");
            }
        }
        else   //û���ҵ�
        {
            printf("\n�Ҳ������û���ɾ��ʧ��");
        }
    }
    else  //û���ҵ�
    {
        printf("\n�Ҳ������û���ɾ��ʧ��");
    }
}

void DeleteOneAtt(void)
{
    int id;
    char key;
    AVLtree temp, p;
    printf("������Ҫ�༭���û���ţ�");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //�������û�
    if(temp)   //�ҵ�
    {
        printf("\n��ǰ�û��Ĺ�ע�У�");
        g_i = 0;     //�ѱ�������������
        TraverseAVL(temp->data.attentions, PrintIDName);
        printf("\n������Ҫɾ����ע���ñ�ţ�");
        scanf("%d",&id);
        p = SearchAVL(temp->data.attentions, id);  //���� �ڹ�ע��
        if (p)     //�ҵ�
        {
            printf("\n\n�Ƿ�ɾ�������밴Y�����������\n");
            scanf(" %c",&key);
            if(key == 'Y' || key == 'y')
            {
                temp->data.attentions = DeleteAVL(temp->data.attentions, p);
                printf("\nɾ���ɹ���");
            }
        }
        else   //û���ҵ�
        {
            printf("\n�Ҳ������û���ɾ��ʧ��");
        }
    }
    else  //û���ҵ�
    {
        printf("\n�Ҳ������û���ɾ��ʧ��");
    }
}

void DeleteOneHobby(void)
{
    int id;
    char key;
    AVLtree temp, p;
    printf("������Ҫ�༭���û���ţ�");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //�������û�
    if(temp)   //�ҵ�
    {
        printf("\n��ǰ�û���ϲ���У�");
        g_i = 0;     //�ѱ�������������
        TraverseAVL(temp->data.hobby, PrintIDName);
        printf("\n������Ҫɾ��ϲ�õı�ţ�");
        scanf("%d",&id);
        p = SearchAVL(temp->data.hobby, id);  //���� ��ϲ����
        if (p)     //�ҵ�
        {
            printf("\n\n�Ƿ�ɾ�������밴Y�����������\n");
            scanf(" %c",&key);
            if(key == 'Y' || key == 'y')
            {
                temp->data.hobby = DeleteAVL(temp->data.hobby, p);
                printf("\nɾ���ɹ���");
            }
        }
        else   //û���ҵ�
        {
            printf("\n�Ҳ������û���ɾ��ʧ��");
        }
    }
    else  //û���ҵ�
    {
        printf("\n�Ҳ������û���ɾ��ʧ��");
    }
}

void RandName(void)
{
    char *chinese[] = {"��","��","��","��","��","��","��","��","��","��","��","��","ʮ","��",
    "��","��","��","��","��","��","��","��","��","Ů","��","��","��","��","Ҳ","��","߮","��",
    "أ","��","��","��","��","ʿ","Ϧ","ǧ","��","��","С","ɽ","��","��","��","��","��","��",
    "��","��","��","֮","��","��","��","��","��","��","̫","��","��","��","��","ţ","��","֧",
    "��","Ԫ","��","��","��","��","��","��","��","��","��","��","��","��","��","ţ","��","��",
    "��","ʲ","��","��","��","��","��","��","��","��","��","ˮ","��","��","˫","��","��","ֹ",
    "��","��","��","��","ƥ","��","��","��","��","��","��","��","��","��","��","ľ","��","ë",
    "��","��","��","Ƭ","��","��","��","��","��","��","��","��","٤","��","��","��","��","��",
    "��","��","��","��","��","��","�","��","��","�","��","��","��","��","��","ס","ռ","��",
    "��","��","��","��","��","��","��","Ŭ","��","��","��","׳","��","�","��","Ū","͢","��",
    "ͮ","־","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","١",
    "��","��","��","�","��","��","��","λ","��","��","ұ","��","��","��","��","��","β","��",
    "��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","Щ","٤",
    "Щ","��","��","��","��","Т","��","�","ϣ","�","��","��","Ѳ","��","��","��","��","��",
    "ɼ","��","��","�","��","��","ϫ","��","˽","��","��","��","��","��","��","ϵ","ռ","��",
    "ס","��","��","ۿ","۾","��","��","��","׳","ױ","��","��","־","��","��","��","��","��",
    "ȴ","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ÿ",
    "��","ĵ","��","��","��","Т","β","��","ϣ","��","��","æ","��","��","��","Ѵ","��","��"};
    //�ֿ�һ��320������

    int i,j,k, n;
    char newname[20];

    printf("\n������Ҫ������ɶ��ٸ��û��ǳƣ�");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        //��һ���ַ�
        strcpy(newname, chinese[GetRand(320-1)]);
        //�������������������
        j = GetRand(4);
        for(k=0; k<j; k++)
        {
            strcat(newname, chinese[GetRand(320-1)]);
        }

        printf("\n�ǳ�����Ϊ��%-15s",newname);
        gp_all_name = NameInit(gp_all_name, newname);   //����NameInit���������������ֵļ���
        printf("��ǰ�û���ţ�%d",g_count);
    }

    printf("\n\n������ɣ�������%d���û�����Ϣ",g_count);

}

void RandOneInfo(Info *data)
{
    int ra_num, i, ra_id;
    AVLtree temp;
    //10��������ɰ���
    char *hobby[] = {"����", "����","ƹ����","��ë��","����","����","ѧϰ","������","����Ӱ","��Ӱ"};
    Info ho;

    if(!data->friends)  //����ýڵ�Ϊ��
    {
        printf("\n\n����������� %s ��������Ϣ", data->nickname);
        ra_num = GetRand(MAX_RAND);   //����������������
        for(i=0;i<ra_num; i++ )
        {
            ra_id = GetRand(g_count);  //��Ŀǰ������Ϣ������
            temp = SearchAVL(gp_all_name, ra_id);
            data->friends = InsertAVL(data->friends, temp->data);  //���ҵ������ݴ���
            printf("\n��ǰ���ɣ�%s  �ĵ�%dλ���� %s  !",data->nickname,i+1, temp->data.nickname);
        }
    }
    if(!data->attentions)  //����ýڵ�Ϊ��
    {
        printf("\n\n����������� %s �Ĺ�ע��Ϣ", data->nickname);
        ra_num = GetRand(MAX_RAND);   //����������������
        for(i=0;i<ra_num; i++ )
        {
            ra_id = GetRand(g_count);  //��Ŀǰ������Ϣ������
            temp = SearchAVL(gp_all_name, ra_id);
            data->attentions = InsertAVL(data->attentions, temp->data);  //���ҵ������ݴ���
            printf("\n��ǰ���ɣ�%s  �ĵ�%d����ע %s  !",data->nickname,i+1, temp->data.nickname);
        }
    }
    if(!data->fans)  //����ýڵ�Ϊ��
    {
        printf("\n\n����������� %s �ķ�˿��Ϣ", data->nickname);
        ra_num = GetRand(MAX_RAND);   //����������������
        for(i=0;i<ra_num; i++ )
        {
            ra_id = GetRand(g_count);  //��Ŀǰ������Ϣ������
            temp = SearchAVL(gp_all_name, ra_id);
            data->fans = InsertAVL(data->fans, temp->data);  //���ҵ������ݴ���
            printf("\n��ǰ���ɣ�%s  �ĵ�%dλ��˿ %s  !",data->nickname,i+1, temp->data.nickname);
        }
    }
    if(!data->hobby)  //����ýڵ�Ϊ��
    {
        printf("\n\n����������� %s �İ�����Ϣ", data->nickname);
        ra_num = GetRand(3);   //����������������  3����
        for(i=0;i<ra_num; i++ )
        {
            strcpy(ho.nickname, hobby[GetRand(10)-1]);   //���ѡ�񰮺�
            ho.id = GetRand(100);   //������ɰ���id���ڴ���������
            data->hobby = InsertAVL(data->hobby, ho);  //���ҵ������ݴ���
            printf("\n��ǰ���ɣ�%s  �ĵ�%d������ %s  !",data->nickname,i+1, ho.nickname);
        }
    }
}

void RandAllInfo(AVLtree tree)
{
    if(!tree)       //Ϊ�շ���
        return;
    //����������������Ϣ
    RandAllInfo(tree->lchild);
    RandOneInfo(&tree->data);      //������������
    RandAllInfo(tree->rchild);
}

void SameAtt(void)
{
    AVLtree newtree, p1, p2;
    int id;
    printf("������Ҫ�鿴��ͬ��ע�ĵ�һλ�û�ID��");
    scanf("%d",&id);
    p1 = SearchAVL(gp_all_name, id);

    printf("\n������Ҫ�鿴��ͬ��ע�ĵڶ�λ�û�ID��");
    scanf("%d",&id);
    p2 = SearchAVL(gp_all_name, id);

    if(p1 && p2)  //���p1��p2���ҵ�
    {
        set_intersection(p1->data.attentions, p2->data.attentions, &newtree);   //ȡ���߽���
        if(newtree)  //��Ϊ�ռ�
        {
            printf("\n\n��ǰ�û� %s �� %s ��ͬ��ע�ˣ�",p1->data.nickname, p2->data.nickname);
            g_i = 0;
            TraverseAVL(newtree, PrintIDName);
            DestroyAVL(&newtree);   //��newtree�ÿշ�ֹ�ڴ�й©
        }
        else  //Ϊ�ռ�
        {
            printf("\n\n��ǰ���û�û�й�ͬ��ע��");
        }
    }
    else //û���ҵ�
    {
        printf("\n\nû���ҵ��û���");
    }
}


void SameHobby(void)
{
    AVLtree  p1, p2;
    int id;
    printf("������Ҫ�鿴��ͬϲ�õĵ�һλ�û�ID��");
    scanf("%d",&id);
    p1 = SearchAVL(gp_all_name, id);

    printf("\n������Ҫ�鿴��ͬϲ�õĵڶ�λ�û�ID��");
    scanf("%d",&id);
    p2 = SearchAVL(gp_all_name, id);

    if(p1 && p2)  //���p1��p2���ҵ�
    {
        printf("\n���û��Ĺ�ͬϲ��Ϊ��������������û�û�й�ͬϲ�ã�\n");
        FindHobby(p1->data.hobby, p2->data.hobby);
    }
    else //û���ҵ�
    {
        printf("\n\nû���ҵ��û���");
    }
}

void FindHobby(AVLtree T1, AVLtree T2)
{
    if(T1 == NULL) return;  //����T1

    FindHobby(T1->lchild, T2);
    if(FindName(T2, T1->data.nickname))  //�ҵ���ͬϲ��
    {
        printf("%-15s", T2->data.nickname);  //ֱ�����
    }
    FindHobby(T1->rchild, T2);

}

bool FindName(AVLtree tree, char *name)
{
    if(tree == NULL)
        return false;
    bool boo1,boo2;

    boo1 = FindName(tree->lchild, name);
    if(!strcmp(tree->data.nickname, name))      //�ҵ��ַ���������
        return true;
    boo2 = FindName(tree->rchild, name);

    if(boo1 || boo2)   //��һ������
        return true;
    else
        return false;
}

void TwoFriend(void)
{
    AVLtree  p1, temp;
    int id, i=0, array[100], j;
    printf("������Ҫ�鿴���Ⱥ��ѵ��û�ID��");
    scanf("%d",&id);
    p1 = SearchAVL(gp_all_name, id);
    FILE *fp;

    if (p1)   //����ҵ�p1
    {
        fp = fopen("temp", "w");  //���ļ��������õ�������Ϣ
        if(fp)
            SaveInOrderTraverse(p1->data.friends, fp);
        fclose(fp);
        fp = fopen("temp", "r");  //��ȡ���ļ��е���Ϣ
        if(fp)
        {
            while(fscanf(fp,"%d",&array[i++]) != EOF);   //��������
            fclose(fp);
        }
        for(j=1; j<i; j++)   //������Ⱥ���
        {
            temp = SearchAVL(gp_all_name, array[j-1]);
            if(temp)
            {
                printf("\n\n%s�ĺ���%s�ĺ����У�", p1->data.nickname, temp->data.nickname);
                g_i = 0;
                TraverseAVL(temp->data.friends, PrintIDName);   //��������Ⱥ���
            }
        }
    }
    else
    {
        printf("\n\nû���ҵ��û���");
    }
}

/** \brief  �������ֵ��ļ�  nickname.dat
 *
 *         �����ʽ   ID  ����\n
 */

void SaveName(void)
{
    FILE *fp;
    fp = fopen("nickname.dat","w");  //ֻд��ʽ���ļ�

    if(fp)   //�ļ��򿪳ɹ�
    {
        SaveTraverseName(gp_all_name, fp);
        printf("\n nickname.dat�ļ�����ɹ���\n");
        printf("��ǰ�����û���%d����", g_count);
        fclose(fp);  //�ر��ļ�
    }
    else   //�ļ���ʧ��
    {
        printf("�ļ���ʧ��!");
    }
}

void SaveTraverseName(AVLtree T, FILE *fp)
{
    if(T == NULL) return;

    SaveTraverseName(T->lchild, fp);   //����������
    fprintf(fp,"%d %s\n",T->data.id ,T->data.nickname);               //���ʸ��ڵ�
    SaveTraverseName(T->rchild, fp);   //����������
}

/** \brief   ����������Ϣ���ļ�   info.dat
 *
 *      �����ʽ
 *     ��Ϣ����
 *      ������Ϣ�� ����
 *      ��˿��Ϣ�� ����
 *   ��ע��Ϣ��  ����
 *    ������Ϣ��  ����
 *
 */

void SaveInfo(void)
{
    FILE *fp;
    fp = fopen("info.dat","w");  //ֻд��ʽ���ļ�

    if(fp)   //�ļ��򿪳ɹ�
    {
        fprintf(fp, "%d\n", set_size(gp_all_name));   //���浱ǰ���ڵĸ���
        SaveTraverseInfo(gp_all_name, fp);
        printf("\ninfo.dat �ļ�����ɹ���\n");
        fclose(fp);   //�ر��ļ�
    }
    else   //�ļ���ʧ��
    {
        printf("�ļ���ʧ��!");
    }
}

void SaveTraverseInfo(AVLtree T, FILE *fp)
{
    if(T == NULL) return;

    SaveTraverseInfo(T->lchild, fp);   //����������

    //����������Ϣ
    fprintf(fp,"\n\n%d      ", set_size(T->data.friends));
    SaveInOrderTraverse(T->data.friends, fp);
    //�����˿��Ϣ
    fprintf(fp,"\n%d      ", set_size(T->data.fans));
    SaveInOrderTraverse(T->data.fans, fp);
    //�����ע��Ϣ
    fprintf(fp,"\n%d      ", set_size(T->data.attentions));
    SaveInOrderTraverse(T->data.attentions, fp);
    //���氮����Ϣ
    fprintf(fp,"\n%d      ", set_size(T->data.hobby));
    SaveTraverseHobby(T->data.hobby, fp);

    SaveTraverseInfo(T->rchild, fp);   //����������
}

void SaveTraverseHobby(AVLtree T, FILE *fp)
{
    if(T == NULL) return;

    SaveTraverseHobby(T->lchild, fp);   //����������
    fprintf(fp,"%s  ",T->data.nickname);               //���ʸ��ڵ�
    SaveTraverseHobby(T->rchild, fp);   //����������
}


void LoadName(void)
{
    FILE *fp;
    fp = fopen("nickname.dat","r");  //ֻ����ʽ���ļ�
    char name[20];
    Info data;

    if(fp)   //�ļ��򿪳ɹ�
    {
        while(fscanf(fp,"%d %s",&data.id, name) != EOF)
        {
            strcpy(data.nickname, name);
            data.attentions = NULL;   //����ȫ����ʼ��Ϊ��
            data.fans = NULL;
            data.friends = NULL;
            data.hobby = NULL;
            g_count = data.id;   //��ȫ�ֱ�����ֵ������ִ���

            gp_all_name = InsertAVL(gp_all_name, data);
        }
        printf("nickname.dat �ļ���ȡ�ɹ���, ��ǰ������%d���û�\n", g_count);
        fclose(fp);
    }
    else   //�ļ���ʧ��
    {
        printf("�ļ���ʧ��!");
    }
}

void LoadInfo(void)
{
    FILE *fp;
    int num, i, j = 0 ;
    AVLtree tree;
    fp = fopen("info.dat","r");  //ֻ����ʽ���ļ�

    if(fp)   //�ļ��򿪳ɹ�
    {
        fscanf(fp,"%d",&num);
        for(i=0; i<num; j++)   //��ȡÿһλ��Ա��ÿһ����Ϣ
        {
            tree = SearchAVL(gp_all_name, j);
            if (tree)
            {
                //����������Ϣ
                LoadEachInfo(&tree->data.friends, fp);
                //�����˿��Ϣ
                LoadEachInfo(&tree->data.fans, fp);
                //�����ע��Ϣ
                LoadEachInfo(&tree->data.attentions, fp);
                //���밮����Ϣ
                LoadEachHobby(&tree->data.hobby, fp);
                i++;  //�ɹ�i��++
            }
        }
        fclose(fp);   //�ر��ļ�
        printf("������Ϣ���سɹ���");
    }
    else   //�ļ���ʧ��
    {
        printf("�ļ���ʧ��!");
    }
}

void LoadEachInfo(AVLtree *T, FILE *fp)
{
    int length, i,  id;
    AVLtree temp;

    fscanf(fp, "%d", &length);  //��ȡ����

    for(i=0; i<length; i++)  //��ȡÿһ����Ϣ
    {
        fscanf(fp, "%d", &id);
        temp = SearchAVL(gp_all_name, id);  //����
        if(temp)     //�ҵ�
        {
            *T = InsertAVL(*T, temp->data);   //������������
        }
    }
}

void LoadEachHobby(AVLtree *T, FILE *fp)
{
    int length, i;
    Info hobby;

    fscanf(fp, "%d", &length);  //��ȡ����

    for(i=0; i<length; i++)  //��ȡÿһ����Ϣ
    {
        fscanf(fp, "%s", hobby.nickname);
        hobby.id = i+1;  //����100�ڵ�α�������֧�ֶ������Ĵ���
        *T = InsertAVL(*T, hobby);   //������������
    }
}
