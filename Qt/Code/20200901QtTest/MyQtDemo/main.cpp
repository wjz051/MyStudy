#include "MyQtDemo.h"
#include "ListFile.h"
#include <QApplication>
#include <iostream>

extern "C"
{
//因为这个是.c文件，所以在c++编译器里面编译要加上extern“C”表示用c编译器编译，不然链接期会提示找不到函数
#include "externC.h"
}


void test1()
{
    int var = 1234;
    printf("%d\n",var);
    printf("%d%%\n",var);
    printf("%o\n",var);
    printf("%x\n",var);
    printf("=============\n");
    printf("%d\n",var);
    printf("%#o\n",var); // 八进制以 0 开头
    printf("%#x\n",var); // 十六进制以 0x 开头
    printf("=============\n");
    printf("%10d\n",var);
    printf("%010d\n",var); //前面的空间补以 0
    printf("%1d\n",var);
    printf("%-10d\n",var); //左对齐
    printf("=============\n");
    printf("%+d\n",var);
    var = -var;
    printf("%+d\n",var); //显示正负号
    printf("=============\n");
    var = -1;
    printf("%d\n",var);
    printf("%u\n",var); //很大很大的数哟
    printf("=============\n");
    // ////////////////////////////
    char c = '\x41';
    printf("%c\n",c);
    printf("%d\n",c);
    printf("%x\n",c);
    printf("%#x\n",c);
    printf("=============\n");
    // ////////////////////////////
    float f = 123.4567;
    printf("%f\n",f);
    printf("%7.2f\n",f);

    printf("%-7.2f\n",f);
    printf("%e\n",f);
    printf("%g\n",f);
    printf("=============\n");
    // ///////////////////////////
    short a = 32;
    long int b =64;
    long double cd = 100.001;
    printf("%hd\n",a);
    printf("%ld\n",b);
    printf("%Lf\n",cd); //32 位机下支持并不好， 64 适用
}

void test2()
{

//    int a = 1,b = 2,c = 3;
//    scanf("%d%d%d",&a,&b,&c);
//    printf("a = %d b = %d c = %d\n",a,b,c);
//    scanf("%d%*d%d",&a,&b,&c); // 忽略缓冲区中间的输入
//    printf("a = %d b = %d c = %d\n",a,b,c);
//    scanf("%5d",&a);
//    printf("a = %d\n",a);
//    scanf("%4d%4d",&a,&b);
//    printf("a = %d b = %d \n",a,b);
//    scanf("%c%c%c",&a,&b,&c);
//    printf("a = %c b = %c c = %c\n",a,b,c);
//    char a = 1,b = 2,c = 3;
//    scanf("%c, %c, %c",&a,&b,&c);
//    printf("a = %c b = %c c = %c\n",a,b,c);
//    char a = 1,b = 2,c = 3;
//    scanf("a=%c,b=%c,c=%c",&a,&b,&c);
//    printf("a = %c b = %c c = %c\n",a,b,c);
//    float var;
//    scanf("%d",&var); //编译没有问题， 但结果并不正确
//    printf("%f",var);
    int i=43;
    printf("%d\n",printf("%d",i));
    printf("%d\n",printf("%d",printf("%d",i)));

    int array[1]={1};
    printf("%d",array[0]);
}

void test3()
{
    enum meiju
    {
        mj_a,
        mj_b,
        mj_c,
        mj_d
    };
    printf("meiju size=%d\n",sizeof(meiju));
    printf("meiju_a size=%d\n",sizeof(mj_a));
}

void test4()
{
    struct stu
    {
    char a; //1
    short b; //2
    int c; //4
    char d; //1
    };
    printf("%d\n", sizeof(struct stu));
}

void test5()
{
    FILE* fp = fopen("ascii.txt","w");
    if(fp == NULL)
    {
        printf("open error\n");
        return ;
    }
    for(char ch = 'a'; ch<='z'; ch++)
    {
        printf("%3c",fputc(ch,fp));
    }
    fclose(fp);
}
//文件读写-字节
void test6()
{
    FILE* fp = fopen("ascii.txt","w+");
    if(fp == NULL)
    {
        printf("open error\n");
        return ;
    }
    for(char ch = 'a'; ch<='z'; ch++)
    {
        fputc(ch,fp);
    }
    rewind(fp);
    char ch;
    while((ch = fgetc(fp))&& !feof(fp)) //这才是正确的姿势
    {
        printf("%3c",ch);
    }
    fclose(fp);
}
//文件读写-条
void test7()
{
    FILE* fp = fopen("text.txt","w+");
    if(fp == NULL)
        return ;
    fputs("aaaaaaaaaaaaaaaaaaaaaaaaaaa\n",fp);
    fputs("bbbbbbbbbbbbbbbbbbbbbbbbbbb\n",fp);
    fputs("ccccccccccccccccccccccccccc\n",fp);
    fputs("ddddddddddddddddddddddddddd\n",fp);
    fputs("eeeeeeeeeeeeeeeeeeeeeeeeeee\n",fp);
    fputs("fffffffffffffffffffffffffff\n",fp);
    rewind(fp);
    char buf[10] = {0};
    while(fgets(buf,10,fp)&&!feof(fp))//取最后一行的时候 feof 己经认为空了。
    {
        printf("%s",buf);
    }
    fclose(fp);
}

//文件读写-块
void test8()
{
    int a[10] = {0xff,0x0,10,2,3,4,5,6,7,8};
    FILE * fp = fopen("xx.txt","wb+"); //xx.txt 文件打开是乱码
    if(fp == NULL)
        return ;
    fwrite(a,sizeof(int[10]),1,fp);
    rewind(fp);
    int n=0;
    int data;
    while((n = fread(&data,sizeof(int),1,fp)) > 0)
    {
        printf("n = %d data = %x \n",n,data);
    }
    fclose(fp);
}

//宏定义
void test9()
{
#define XNAME(n) x##n
#define PRINT_XN(n) printf("x"#n" = %d\n", x##n)

    int XNAME(1) = 14;
    int XNAME(2) = 20;
    printf("x1 = %d,x2 = %d\n",x1,x2);
    PRINT_XN(1); //隐藏了变量的声明和使用 点赞
    PRINT_XN(2);
}

//结构体大小
void test10()
{
#pragma pack(4)
    typedef struct _stu
    {
        char a; //1
        short b[1]; //2-2
        double c; //8
        char d; //1
    }stu;

    typedef struct _teach
    {
        char a; //1
        short b[3]; //2-6
        stu s; //8-16
        int c; //4
        char d; //1
    }teach;

    stu s;
    printf("%d\n", sizeof(s));
    printf("%p\n", &s.a);
    printf("%p\n", &s.b);
    printf("%p\n", &s.c);

    teach t;
    printf("%d\n", sizeof(t));
    printf("%p\n", &t.a);
    printf("%p\n", &t.b);
    printf("%p\n", &t.c);
    printf("%p\n", &t.s);
    printf("%p\n", &t.d);
}

void test11()
{
    StuNode *head =createListFromFile("stu.data");
    while(1)
    {
        system("cls");
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
            return ;
        default:
            printf("您输错了\n");
        }
    }
}
//无符号相加
void test12()
{
    unsigned int a=1;
    int b=-2;
    if(a+b>0)
    {
        printf("xxxx\n");
    }
    else
    {
        printf("oooo\n");
    }
}
//数组指针
void test13()
{
    int arr[3][4]={1,2,3,4,5,6,7,8,9,10};
    int *p=(int *)arr;
//    int (*p)[3][4]=&arr;

    printf("&arr=%p\n",&arr);
    printf("&arr[0]=%p\n",&arr[0]);
    printf("&arr[0][0]=%p\n",&arr[0][0]);

    for(int i=0;i<sizeof(arr)/sizeof(int);++i)
    {
        printf("%d\n",*p++);
    }
}
void test14()
{
    char c = 'm';
    char *pc = &c;
    char * *pp = &pc;
    printf("c = %c\n",c);
    printf("*pc = %c\n",*pc);
    printf("&c = %p\n",&c);
    printf("pc = %p\n",pc);
    printf("*pp = %p\n",*pp);
    printf("**pp = %c\n",**pp);
}

//extern"C"
void test15()
{
    int sum=addInt(1,2);
    printf("sum=%d\n",sum);
}

//split
void test16()
{
    QString str="0,1,2";
    QStringList list=str.split(",");
    list.prepend("8");
    QStringList tmp=str.split(";");
    std::cout<<tmp.size()<<std::endl;

}

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MyQtDemo w;
//    w.show();
//    return a.exec();

    test16();
    return 0;
}

