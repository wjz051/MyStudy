#include <stdio.h>
#include "ListFile.h"

int main()
{
    printf("Hello World!\n");

    //initData2File();

    StuNode *head =createListFromFile("stu.data");
    while(1)
    {
        system("cls");//清屏
        traverseStuList(head);
        printf("1->add\t 2->search 3->delete 4->sort 5->exit\n");
        int choice;
        StuNode *pfind;
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addListStu(head);
            break;
        case 2:

            if(pfind = searchListStu(head))
            {
                printf("您要找的数据在本系统中\n");
                printf("\t%-10s\t\t%c\t\t%d\t\t%.2f\n",
                       pfind->data.name,pfind->data.sex,
                       pfind->data.age,pfind->data.score);
            }
            else
                printf("查无此人\n");
            getchar();getchar();
            break;
        case 3:
            deleteListNodeStu(head);
            break;
        case 4:
            sortListStu(head);
            break;
        case 5:
            saveListStu2File(head,"stu.data");
            destroyListStu(head);
            return 0;
        default:
            printf("您输错了\n");
        }
    }

    return 0;
}
