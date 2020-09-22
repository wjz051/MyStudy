#include "ListFile.h"

void initData2File()
{
    Stu s[4] =
    {
        "liudehua",'x',50,100,
        "zhangxueyou",'x',60,98,
        "liming",'f',50,88,
        "guofucheng",'m',49,90,
    };
    FILE*pf = fopen("stu.data","w+");
    if(NULL == pf)
        exit(-1);
    fwrite((void*)s,sizeof(s),1,pf);
    fclose(pf);
    return ;
}

StuNode *createListFromFile(char *filePath)
{
    FILE *pf = fopen(filePath,"r+");
    if(NULL == pf)
        exit(-1);
    StuNode *head = (StuNode *)malloc(sizeof(StuNode));
    head->next = NULL;
    StuNode *cur = (StuNode *)malloc(sizeof(StuNode));
    while(fread((void*)&cur->data,sizeof(Stu),1,pf)) // 1 0
    {
        cur->next = head->next;
        head->next = cur;
        cur = (StuNode *)malloc(sizeof(StuNode));
    }
    free(cur);
    return head;
}

void traverseStuList(StuNode * head)
{
    printf("\t\t\t Student Management System\n\n");
    printf("\t\t\t\t\t\t\t\tCopyLeft\n\n");
    printf("\tname\t\t\tsex\t\tage\t\tscore\n");
    head = head->next;
    while(head)
    {
        printf("\t%-10s\t\t%c\t\t%d\t\t%.2f\n",
               head->data.name,head->data.sex,
               head->data.age,head->data.score);
        head = head->next;
    }
    putchar(10);
}

void addListStu(StuNode *head)
{
    StuNode * cur = (StuNode *)malloc(sizeof(StuNode));
    printf("name :");
    scanf("%s",cur->data.name);
    getchar();
    printf("sex :");
    scanf("%c",&cur->data.sex);
    printf("age :");
    scanf("%d",&cur->data.age);
    printf("score:");
    scanf("%f",&cur->data.score);
    cur->next = head->next;
    head->next = cur;
}

StuNode * searchListStu(StuNode *head)
{
    char name[30];
    printf("pls input your search name:");
    scanf("%s",name);
    head = head->next;
    while(head)
    {
        if(strcmp(head->data.name,name) == 0)
            break;
        head = head->next;
    }
    return head;
}

void deleteListNodeStu(StuNode *head)
{
    StuNode *pfind = searchListStu(head);
    if(pfind == NULL)
    {
        printf("您要删除的人不存在\n");
        getchar();getchar();
        return ;
    } while(head->next != pfind)
        head = head->next;
    head->next = pfind->next;
    free(pfind);
    return ;
}

int lenListStu(StuNode *head)
{
    int len =0;
    head = head->next;
    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}

void sortListStu(StuNode *head)
{
    int len = lenListStu(head);
    StuNode *prep,*p,*q;
    for(int i=0; i<len-1; i++)
    {
        prep = head;
        p = prep->next;
        q = p->next;
        for(int j=0; j<len-1-i; j++)
        {
            if(strcmp(p->data.name,q->data.name)>0)
            {
                prep->next = q;
                p->next = q->next;
                q->next = p;
                prep = q;
                q = p->next;
                continue;
            }
            prep = prep->next;
            p = p->next;
            q = p->next;
        }
    }
}

void saveListStu2File(StuNode *head,char *filePath)
{
    FILE* pf = fopen(filePath,"w+");
    if(NULL == pf)
        exit(-1);
    head = head->next;
    while(head)
    {
        fwrite((void*)&head->data,sizeof(Stu),1,pf);
        head = head->next;
    }
    fclose(pf);
}

void destroyListStu(StuNode *head)
{
    StuNode *t;
    while(head)
    {
        t = head;
        head = head->next;
        free(t);
    }
}
