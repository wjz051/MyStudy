#ifndef LISTFILE_H
#define LISTFILE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//1,初始化数据库， 此时的数据库是文件
//2,读数据库， 生成内存数据模型,链表
//3,增,查， 改， 删， 排序
//4,更新数据库。
typedef struct student
{
    char name[30];
    char sex;
    int age;
    float score;
}Stu;

typedef struct _StuNode
{
    Stu data;
    struct _StuNode *next;
}StuNode;

void initData2File();
StuNode *createListFromFile(char *filePath);
void traverseStuList(StuNode * head);
void addListStu(StuNode *head);
StuNode * searchListStu(StuNode *head);
void deleteListNodeStu(StuNode *head);
int lenListStu(StuNode *head);
void sortListStu(StuNode *head);
void saveListStu2File(StuNode *head,char *filePath);
void destroyListStu(StuNode *head);

#endif // LISTFILE_H
