#include"AVL.h"
#include"weibo.h"

int g_count;
int g_i;
AVLtree gp_all_name;

int GetRand(int n) //生成n以内的伪随机数
{
    return rand()%n+1;
}

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


void WriteOneName(void)
{
    char name[20];

    printf("当前输入一个名字：");
    scanf("%s",name);

    gp_all_name = NameInit(gp_all_name, name);   //调用NameInit函数加入所有名字的集合
        printf("\n用户加入集合成功！\n当前用户编号：%d",g_count);
}


void TraverseAllName(void)
{
    printf("当前录入的所有用户名为：");
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
    printf("请输入要查看的用户编号：");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //搜索该用户
    if (temp)//找到
    {
        printf("\n该用户的ID为：%-5d该用户昵称为：%s",temp->data.id, temp->data.nickname);
        printf("\n\n该用户的好友有：");
        g_i = 0;     //把遍历的整数置零
        TraverseAVL(temp->data.friends, PrintName);
        printf("\n\n该用户的粉丝有：");
        g_i = 0;     //把遍历的整数置零
        TraverseAVL(temp->data.fans, PrintName);
        printf("\n\n该用户的关注有：");
        g_i = 0;     //把遍历的整数置零
        TraverseAVL(temp->data.attentions, PrintName);
        printf("\n\n该用户的个人喜好有：");
        g_i = 0;     //把遍历的整数置零
        TraverseAVL(temp->data.hobby, PrintName);
    }
    else  //没有找到
    {
        printf("\n找不到该用户！");
    }
}

void DeleteUser(void)
{
    int id;
    AVLtree temp;
    char key;
    printf("请输入要删除的用户编号：");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //搜索该用户
    if (temp)
    {
        printf("\n该用户的信息为:");
        printf("\n该用户的ID为：%-5d该用户昵称为：%s",temp->data.id, temp->data.nickname);
        printf("\n\n该用户的好友有：");
        g_i = 0;     //把遍历的整数置零
        TraverseAVL(temp->data.friends, PrintName);
        printf("\n\n该用户的粉丝有：");
        g_i = 0;     //把遍历的整数置零
        TraverseAVL(temp->data.fans, PrintName);
        printf("\n\n该用户的关注有：");
        g_i = 0;     //把遍历的整数置零
        TraverseAVL(temp->data.attentions, PrintName);
        printf("\n\n该用户的个人喜好有：");
        g_i = 0;     //把遍历的整数置零
        TraverseAVL(temp->data.hobby, PrintName);
        printf("\n\n是否删除？是请按Y，否则按任意键\n");
        scanf(" %c",&key);
        if(key == 'Y' || key == 'y')
        {
            gp_all_name = DeleteAVL(gp_all_name, temp);
            printf("\n删除成功！");
        }

    }
    else
    {
        printf("\n找不到该用户!");
    }
}

void AddOnesFriend(void)
{
    int id;
    AVLtree temp, p;
    printf("请输入要编辑的用户编号：");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //搜索该用户
    if(temp)   //找到
    {
        printf("\n请输入要添加好友的用户编号：");
        scanf("%d",&id);
        p = SearchAVL(gp_all_name, id);  //搜索
        if (p)     //找到
        {
            temp->data.friends = InsertAVL(temp->data.friends, p->data);  //相当于在此处新建树
            printf("\n%s       添加成功！",p->data.nickname);
        }
        else   //没有找到
        {
            printf("\n找不到该用户！添加失败");
        }
    }
    else  //没有找到
    {
        printf("\n找不到该用户！添加失败");
    }
}

void AddOnesFans(void)
{
    int id;
    AVLtree temp, p;
    printf("请输入要编辑的用户编号：");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //搜索该用户
    if(temp)   //找到
    {
        printf("\n请输入要添加粉丝的用户编号：");
        scanf("%d",&id);
        p = SearchAVL(gp_all_name, id);  //搜索
        if (p)     //找到
        {
            temp->data.fans = InsertAVL(temp->data.fans, p->data);  //相当于在此处新建树
            printf("\n%s       添加成功！",p->data.nickname);
        }
        else   //没有找到
        {
            printf("\n找不到该用户！添加失败");
        }
    }
    else  //没有找到
    {
        printf("\n找不到该用户！添加失败");
    }
}

void AddOnesAtt(void)
{
    int id;
    AVLtree temp, p;
    printf("请输入要编辑的用户编号：");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //搜索该用户
    if(temp)   //找到
    {
        printf("\n请输入要添加关注的用户编号：");
        scanf("%d",&id);
        p = SearchAVL(gp_all_name, id);  //搜索
        if (p)     //找到
        {
            temp->data.attentions = InsertAVL(temp->data.attentions, p->data);  //相当于在此处新建树
            printf("\n%s       添加成功！",p->data.nickname);
        }
        else   //没有找到
        {
            printf("\n找不到该用户！添加失败");
        }
    }
    else  //没有找到
    {
        printf("\n找不到该用户！添加失败");
    }
}

void AddOnesHobby(void)
{
    int id;
    AVLtree temp;
    Info hobby;
    printf("请输入要编辑的用户编号：");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //搜索该用户
    if(temp)   //找到
    {
        printf("\n请输入该用户的喜好之一：");
        scanf("%s",hobby.nickname);   //以nickname来做hobby
        hobby.id = GetRand(100);  //生成100内的伪随机数来支持二叉树的创建
        temp->data.hobby = InsertAVL(temp->data.hobby, hobby);  //创建兴趣二叉树
        printf("\n添加成功！");
    }
    else  //没有找到
    {
        printf("\n找不到该用户！添加失败");
    }
}

void DeleteOneFriend(void)
{
    int id;
    char key;
    AVLtree temp, p;
    printf("请输入要编辑的用户编号：");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //搜索该用户
    if(temp)   //找到
    {
        printf("\n当前用户的好友有：");
        g_i = 0;     //把遍历的整数置零
        TraverseAVL(temp->data.friends, PrintIDName);
        printf("\n请输入要删除好友的用户编号：");
        scanf("%d",&id);
        p = SearchAVL(temp->data.friends, id);  //搜索 在好友中
        if (p)     //找到
        {
            printf("\n\n是否删除？是请按Y，否则按任意键\n");
            scanf(" %c",&key);
            if(key == 'Y' || key == 'y')
            {
                temp->data.friends = DeleteAVL(temp->data.friends, p);
                printf("\n删除成功！");
            }
        }
        else   //没有找到
        {
            printf("\n找不到该用户！删除失败");
        }
    }
    else  //没有找到
    {
        printf("\n找不到该用户！删除失败");
    }
}


void DeleteOneFans(void)
{
    int id;
    char key;
    AVLtree temp, p;
    printf("请输入要编辑的用户编号：");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //搜索该用户
    if(temp)   //找到
    {
        printf("\n当前用户的粉丝有：");
        g_i = 0;     //把遍历的整数置零
        TraverseAVL(temp->data.fans, PrintIDName);
        printf("\n请输入要删除粉丝的用户编号：");
        scanf("%d",&id);
        p = SearchAVL(temp->data.fans, id);  //搜索 在粉丝中
        if (p)     //找到
        {
            printf("\n\n是否删除？是请按Y，否则按任意键\n");
            scanf(" %c",&key);
            if(key == 'Y' || key == 'y')
            {
                temp->data.fans = DeleteAVL(temp->data.fans, p);
                printf("\n删除成功！");
            }
        }
        else   //没有找到
        {
            printf("\n找不到该用户！删除失败");
        }
    }
    else  //没有找到
    {
        printf("\n找不到该用户！删除失败");
    }
}

void DeleteOneAtt(void)
{
    int id;
    char key;
    AVLtree temp, p;
    printf("请输入要编辑的用户编号：");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //搜索该用户
    if(temp)   //找到
    {
        printf("\n当前用户的关注有：");
        g_i = 0;     //把遍历的整数置零
        TraverseAVL(temp->data.attentions, PrintIDName);
        printf("\n请输入要删除关注的用编号：");
        scanf("%d",&id);
        p = SearchAVL(temp->data.attentions, id);  //搜索 在关注中
        if (p)     //找到
        {
            printf("\n\n是否删除？是请按Y，否则按任意键\n");
            scanf(" %c",&key);
            if(key == 'Y' || key == 'y')
            {
                temp->data.attentions = DeleteAVL(temp->data.attentions, p);
                printf("\n删除成功！");
            }
        }
        else   //没有找到
        {
            printf("\n找不到该用户！删除失败");
        }
    }
    else  //没有找到
    {
        printf("\n找不到该用户！删除失败");
    }
}

void DeleteOneHobby(void)
{
    int id;
    char key;
    AVLtree temp, p;
    printf("请输入要编辑的用户编号：");
    scanf("%d",&id);

    temp = SearchAVL(gp_all_name, id);  //搜索该用户
    if(temp)   //找到
    {
        printf("\n当前用户的喜好有：");
        g_i = 0;     //把遍历的整数置零
        TraverseAVL(temp->data.hobby, PrintIDName);
        printf("\n请输入要删除喜好的编号：");
        scanf("%d",&id);
        p = SearchAVL(temp->data.hobby, id);  //搜索 在喜好中
        if (p)     //找到
        {
            printf("\n\n是否删除？是请按Y，否则按任意键\n");
            scanf(" %c",&key);
            if(key == 'Y' || key == 'y')
            {
                temp->data.hobby = DeleteAVL(temp->data.hobby, p);
                printf("\n删除成功！");
            }
        }
        else   //没有找到
        {
            printf("\n找不到该用户！删除失败");
        }
    }
    else  //没有找到
    {
        printf("\n找不到该用户！删除失败");
    }
}

void RandName(void)
{
    char *chinese[] = {"乙","乃","了","力","丁","刀","刁","二","又","人","入","七","十","几",
    "口","干","工","弓","久","己","土","大","丈","女","己","巾","勺","丸","也","于","弋","巳",
    "兀","三","下","上","乞","士","夕","千","子","寸","小","山","川","巳","才","凡","公","孔",
    "亢","勾","中","之","丹","井","介","今","内","及","太","天","屯","斗","斤","牛","丑","支",
    "允","元","勿","午","友","尤","尹","引","文","月","日","牙","王","云","匀","牛","四","丑",
    "仁","什","切","升","收","壬","少","心","手","日","氏","水","尤","仍","双","尺","仇","止",
    "才","不","互","分","匹","化","卡","卞","肥","反","夫","巴","幻","户","方","木","比","毛",
    "仆","丰","火","片","克","告","改","攻","更","杆","谷","况","伽","估","君","吴","吸","吾",
    "圻","均","坎","研","完","局","岐","我","扣","杞","江","究","见","角","言","住","占","低",
    "佃","况","里","冷","伶","利","助","努","君","吝","昌","壮","妓","妞","局","弄","廷","弟",
    "彤","志","托","杖","杜","呆","李","江","男","究","良","见","角","具","皂","里","舟","佟",
    "体","足","甸","町","豆","吞","玎","位","佐","佘","冶","吾","吟","吴","吻","完","尾","巫",
    "役","忘","我","修","言","邑","酉","吟","吴","研","呆","角","七","伸","佐","作","些","伽",
    "些","初","吹","呈","坐","孝","宋","岐","希","岑","床","序","巡","形","忍","成","杏","材",
    "杉","束","村","杞","步","汝","汐","池","私","秀","赤","足","身","车","辰","系","占","伺",
    "住","余","助","劭","劬","邵","吸","坐","壮","妆","局","床","志","汕","江","灶","见","即",
    "却","克","早","何","布","伯","伴","佛","兵","判","别","含","坊","坂","吵","宏","旱","每",
    "甫","牡","况","免","孚","孝","尾","巫","希","庇","形","忙","杏","呆","步","汛","贝","儿"};
    //字库一共320个汉字

    int i,j,k, n;
    char newname[20];

    printf("\n请输入要随机生成多少个用户昵称：");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        //第一个字符
        strcpy(newname, chinese[GetRand(320-1)]);
        //后面的五个字内随机起名
        j = GetRand(4);
        for(k=0; k<j; k++)
        {
            strcat(newname, chinese[GetRand(320-1)]);
        }

        printf("\n昵称生成为：%-15s",newname);
        gp_all_name = NameInit(gp_all_name, newname);   //调用NameInit函数加入所有名字的集合
        printf("当前用户编号：%d",g_count);
    }

    printf("\n\n生成完成，共生成%d个用户名信息",g_count);

}

void RandOneInfo(Info *data)
{
    int ra_num, i, ra_id;
    AVLtree temp;
    //10种随机生成爱好
    char *hobby[] = {"篮球", "足球","乒乓球","羽毛球","排球","看书","学习","听音乐","看电影","摄影"};
    Info ho;

    if(!data->friends)  //如果该节点为空
    {
        printf("\n\n正在随机创建 %s 的朋友信息", data->nickname);
        ra_num = GetRand(MAX_RAND);   //随机生成随机的条数
        for(i=0;i<ra_num; i++ )
        {
            ra_id = GetRand(g_count);  //在目前所有信息条数下
            temp = SearchAVL(gp_all_name, ra_id);
            data->friends = InsertAVL(data->friends, temp->data);  //将找到的数据存入
            printf("\n当前生成：%s  的第%d位朋友 %s  !",data->nickname,i+1, temp->data.nickname);
        }
    }
    if(!data->attentions)  //如果该节点为空
    {
        printf("\n\n正在随机创建 %s 的关注信息", data->nickname);
        ra_num = GetRand(MAX_RAND);   //随机生成随机的条数
        for(i=0;i<ra_num; i++ )
        {
            ra_id = GetRand(g_count);  //在目前所有信息条数下
            temp = SearchAVL(gp_all_name, ra_id);
            data->attentions = InsertAVL(data->attentions, temp->data);  //将找到的数据存入
            printf("\n当前生成：%s  的第%d个关注 %s  !",data->nickname,i+1, temp->data.nickname);
        }
    }
    if(!data->fans)  //如果该节点为空
    {
        printf("\n\n正在随机创建 %s 的粉丝信息", data->nickname);
        ra_num = GetRand(MAX_RAND);   //随机生成随机的条数
        for(i=0;i<ra_num; i++ )
        {
            ra_id = GetRand(g_count);  //在目前所有信息条数下
            temp = SearchAVL(gp_all_name, ra_id);
            data->fans = InsertAVL(data->fans, temp->data);  //将找到的数据存入
            printf("\n当前生成：%s  的第%d位粉丝 %s  !",data->nickname,i+1, temp->data.nickname);
        }
    }
    if(!data->hobby)  //如果该节点为空
    {
        printf("\n\n正在随机创建 %s 的爱好信息", data->nickname);
        ra_num = GetRand(3);   //随机生成随机的条数  3条内
        for(i=0;i<ra_num; i++ )
        {
            strcpy(ho.nickname, hobby[GetRand(10)-1]);   //随机选择爱好
            ho.id = GetRand(100);   //随机生成爱好id用于创建二叉树
            data->hobby = InsertAVL(data->hobby, ho);  //将找到的数据存入
            printf("\n当前生成：%s  的第%d个爱好 %s  !",data->nickname,i+1, ho.nickname);
        }
    }
}

void RandAllInfo(AVLtree tree)
{
    if(!tree)       //为空返回
        return;
    //遍历来生成所有信息
    RandAllInfo(tree->lchild);
    RandOneInfo(&tree->data);      //调用名字生成
    RandAllInfo(tree->rchild);
}

void SameAtt(void)
{
    AVLtree newtree, p1, p2;
    int id;
    printf("请输入要查看共同关注的第一位用户ID：");
    scanf("%d",&id);
    p1 = SearchAVL(gp_all_name, id);

    printf("\n请输入要查看共同关注的第二位用户ID：");
    scanf("%d",&id);
    p2 = SearchAVL(gp_all_name, id);

    if(p1 && p2)  //如果p1和p2都找到
    {
        set_intersection(p1->data.attentions, p2->data.attentions, &newtree);   //取两者交集
        if(newtree)  //不为空集
        {
            printf("\n\n当前用户 %s 与 %s 共同关注了：",p1->data.nickname, p2->data.nickname);
            g_i = 0;
            TraverseAVL(newtree, PrintIDName);
            DestroyAVL(&newtree);   //讲newtree置空防止内存泄漏
        }
        else  //为空集
        {
            printf("\n\n当前两用户没有共同关注！");
        }
    }
    else //没有找到
    {
        printf("\n\n没有找到用户！");
    }
}


void SameHobby(void)
{
    AVLtree  p1, p2;
    int id;
    printf("请输入要查看共同喜好的第一位用户ID：");
    scanf("%d",&id);
    p1 = SearchAVL(gp_all_name, id);

    printf("\n请输入要查看共同喜好的第二位用户ID：");
    scanf("%d",&id);
    p2 = SearchAVL(gp_all_name, id);

    if(p1 && p2)  //如果p1和p2都找到
    {
        printf("\n两用户的共同喜好为：（空则代表两用户没有共同喜好）\n");
        FindHobby(p1->data.hobby, p2->data.hobby);
    }
    else //没有找到
    {
        printf("\n\n没有找到用户！");
    }
}

void FindHobby(AVLtree T1, AVLtree T2)
{
    if(T1 == NULL) return;  //遍历T1

    FindHobby(T1->lchild, T2);
    if(FindName(T2, T1->data.nickname))  //找到共同喜好
    {
        printf("%-15s", T2->data.nickname);  //直接输出
    }
    FindHobby(T1->rchild, T2);

}

bool FindName(AVLtree tree, char *name)
{
    if(tree == NULL)
        return false;
    bool boo1,boo2;

    boo1 = FindName(tree->lchild, name);
    if(!strcmp(tree->data.nickname, name))      //找到字符串返回真
        return true;
    boo2 = FindName(tree->rchild, name);

    if(boo1 || boo2)   //有一真则真
        return true;
    else
        return false;
}

void TwoFriend(void)
{
    AVLtree  p1, temp;
    int id, i=0, array[100], j;
    printf("请输入要查看二度好友的用户ID：");
    scanf("%d",&id);
    p1 = SearchAVL(gp_all_name, id);
    FILE *fp;

    if (p1)   //如果找到p1
    {
        fp = fopen("temp", "w");  //用文件来保存获得的朋友信息
        if(fp)
            SaveInOrderTraverse(p1->data.friends, fp);
        fclose(fp);
        fp = fopen("temp", "r");  //读取在文件中的信息
        if(fp)
        {
            while(fscanf(fp,"%d",&array[i++]) != EOF);   //读入数组
            fclose(fp);
        }
        for(j=1; j<i; j++)   //输出二度好友
        {
            temp = SearchAVL(gp_all_name, array[j-1]);
            if(temp)
            {
                printf("\n\n%s的好友%s的好友有：", p1->data.nickname, temp->data.nickname);
                g_i = 0;
                TraverseAVL(temp->data.friends, PrintIDName);   //遍历其二度好友
            }
        }
    }
    else
    {
        printf("\n\n没有找到用户！");
    }
}

/** \brief  保存名字到文件  nickname.dat
 *
 *         保存格式   ID  名字\n
 */

void SaveName(void)
{
    FILE *fp;
    fp = fopen("nickname.dat","w");  //只写方式打开文件

    if(fp)   //文件打开成功
    {
        SaveTraverseName(gp_all_name, fp);
        printf("\n nickname.dat文件保存成功！\n");
        printf("当前存入用户共%d名！", g_count);
        fclose(fp);  //关闭文件
    }
    else   //文件打开失败
    {
        printf("文件打开失败!");
    }
}

void SaveTraverseName(AVLtree T, FILE *fp)
{
    if(T == NULL) return;

    SaveTraverseName(T->lchild, fp);   //访问左子树
    fprintf(fp,"%d %s\n",T->data.id ,T->data.nickname);               //访问根节点
    SaveTraverseName(T->rchild, fp);   //访问右子树
}

/** \brief   保存所有信息到文件   info.dat
 *
 *      保存格式
 *     信息个数
 *      好友信息： 个数
 *      粉丝信息： 个数
 *   关注信息：  个数
 *    爱好信息：  个数
 *
 */

void SaveInfo(void)
{
    FILE *fp;
    fp = fopen("info.dat","w");  //只写方式打开文件

    if(fp)   //文件打开成功
    {
        fprintf(fp, "%d\n", set_size(gp_all_name));   //保存当前存在的个数
        SaveTraverseInfo(gp_all_name, fp);
        printf("\ninfo.dat 文件保存成功！\n");
        fclose(fp);   //关闭文件
    }
    else   //文件打开失败
    {
        printf("文件打开失败!");
    }
}

void SaveTraverseInfo(AVLtree T, FILE *fp)
{
    if(T == NULL) return;

    SaveTraverseInfo(T->lchild, fp);   //访问左子树

    //保存朋友信息
    fprintf(fp,"\n\n%d      ", set_size(T->data.friends));
    SaveInOrderTraverse(T->data.friends, fp);
    //保存粉丝信息
    fprintf(fp,"\n%d      ", set_size(T->data.fans));
    SaveInOrderTraverse(T->data.fans, fp);
    //保存关注信息
    fprintf(fp,"\n%d      ", set_size(T->data.attentions));
    SaveInOrderTraverse(T->data.attentions, fp);
    //保存爱好信息
    fprintf(fp,"\n%d      ", set_size(T->data.hobby));
    SaveTraverseHobby(T->data.hobby, fp);

    SaveTraverseInfo(T->rchild, fp);   //访问右子树
}

void SaveTraverseHobby(AVLtree T, FILE *fp)
{
    if(T == NULL) return;

    SaveTraverseHobby(T->lchild, fp);   //访问左子树
    fprintf(fp,"%s  ",T->data.nickname);               //访问根节点
    SaveTraverseHobby(T->rchild, fp);   //访问右子树
}


void LoadName(void)
{
    FILE *fp;
    fp = fopen("nickname.dat","r");  //只读方式打开文件
    char name[20];
    Info data;

    if(fp)   //文件打开成功
    {
        while(fscanf(fp,"%d %s",&data.id, name) != EOF)
        {
            strcpy(data.nickname, name);
            data.attentions = NULL;   //其他全部初始化为空
            data.fans = NULL;
            data.friends = NULL;
            data.hobby = NULL;
            g_count = data.id;   //将全局变量赋值以免出现错误

            gp_all_name = InsertAVL(gp_all_name, data);
        }
        printf("nickname.dat 文件读取成功！, 当前加载了%d个用户\n", g_count);
        fclose(fp);
    }
    else   //文件打开失败
    {
        printf("文件打开失败!");
    }
}

void LoadInfo(void)
{
    FILE *fp;
    int num, i, j = 0 ;
    AVLtree tree;
    fp = fopen("info.dat","r");  //只读方式打开文件

    if(fp)   //文件打开成功
    {
        fscanf(fp,"%d",&num);
        for(i=0; i<num; j++)   //读取每一位成员的每一个信息
        {
            tree = SearchAVL(gp_all_name, j);
            if (tree)
            {
                //加入朋友信息
                LoadEachInfo(&tree->data.friends, fp);
                //加入粉丝信息
                LoadEachInfo(&tree->data.fans, fp);
                //加入关注信息
                LoadEachInfo(&tree->data.attentions, fp);
                //加入爱好信息
                LoadEachHobby(&tree->data.hobby, fp);
                i++;  //成功i才++
            }
        }
        fclose(fp);   //关闭文件
        printf("所有信息加载成功！");
    }
    else   //文件打开失败
    {
        printf("文件打开失败!");
    }
}

void LoadEachInfo(AVLtree *T, FILE *fp)
{
    int length, i,  id;
    AVLtree temp;

    fscanf(fp, "%d", &length);  //读取长度

    for(i=0; i<length; i++)  //读取每一条信息
    {
        fscanf(fp, "%d", &id);
        temp = SearchAVL(gp_all_name, id);  //搜索
        if(temp)     //找到
        {
            *T = InsertAVL(*T, temp->data);   //将其加入二叉树
        }
    }
}

void LoadEachHobby(AVLtree *T, FILE *fp)
{
    int length, i;
    Info hobby;

    fscanf(fp, "%d", &length);  //读取长度

    for(i=0; i<length; i++)  //读取每一条信息
    {
        fscanf(fp, "%s", hobby.nickname);
        hobby.id = i+1;  //生成100内的伪随机数来支持二叉树的创建
        *T = InsertAVL(*T, hobby);   //将其加入二叉树
    }
}
