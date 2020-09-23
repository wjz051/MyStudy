#include<stdio.h>
#include<stdlib.h>

int binSearch(int *p,int low,int high,int find)
{
    while(low<=high)
    {
        int i=(low+high)/2;
        if(p[i]==find)
        {
            return i;
        }
        else if(p[i]>find)
        {
            high=i-1;
        }
        else
        {
            low=i+1;
        }
    }
    return -1;
}

//递归二分查找
int binSearch2(int *p,int low,int high,int find)
{
    if(low<=high)
    {
        int i=(low+high)/2;
        if(p[i]==find)
        {
            return i;
        }
        else if(p[i]>find)
        {
            return binSearch2(p,low,i-1,find);
        }
        else
        {
            return binSearch2(p,i+1,high,find);
        }
    }
    return -1;
}

void testSearch()
{
    int a[]={1,3,5,8,9,12,45,65,78};
    int find=5;
    int findIdx=binSearch2(a,0,8,find);
    if(findIdx==-1)
    {
        printf("no find\n");
    }
    else
    {
        printf("findInd=%d\n",findIdx);
    }
}

//二维数组，是一种二维空间，但是不代表，二维空间就是二维数组。二维空间，并 不一定就是二维数组，但具有数组的访问形式。但己经远远不是数组的定义了。
//一级指针作返值输出---依旧还是线性存储
void *alloc2Space(int base,int row,int coloum)
{
    void *p=(void *)malloc(base*row*coloum);
    return p;
}
void test2Space()
{
    int row=3,coloum=4;
    int (*p)[coloum]=(int (*)[coloum])alloc2Space(sizeof(int),row,coloum);
    for(int i=0;i<sizeof(int)*row*coloum/sizeof(int[coloum]);++i)
    {
        for(int j=0;j<coloum;++j)
        {
            p[i][j]=i+j;
        }
    }
    for(int i=0;i<sizeof(int)*row*coloum/sizeof(int[coloum]);++i)
    {
        for(int j=0;j<coloum;++j)
        {
            // printf("%d\t",p[i][j]);
            printf("%d\t",*(*(p+i)+j));
        }
        putchar(10);
    }
    free(p);
}

void free2Space(int **p,int row)
{
    for(int i=0;i<row;++i)
    {
        free(p[i]);
    }
    free(p);
}

//二级指针作返回值
void **alloc2Space2Ptr(int base,int row,int coloum)
{
    void **p=(void **)malloc(row*sizeof(void *));
    if(p!=NULL)
    {
        for(int i=0;i<row;++i)
        {
            p[i]=malloc(coloum*base);
        }
    }
    return p;
}
void test2Space2()
{
    int row=3,coloum=4;
    int **p=(int **)alloc2Space2Ptr(sizeof(int),row,coloum);
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<coloum;++j)
        {
            p[i][j]=i+j;
        }
    }
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<coloum;++j)
        {
            // printf("%d\t",p[i][j]);
            printf("%d\t",*(*(p+i)+j));
        }
        putchar(10);
    }

    free2Space(p,row);
}

//三级指针作参数输出
void alloc2Space3Ptr(void ***p,int base,int row,int coloum)
{
    *p = (void **)malloc(row*sizeof(void*)); 
    for(int i=0; i<row;i++) 
    { 
        (*p)[i] = malloc(base * coloum); 
    }
}

void test2Space3()
{
    int **p=NULL;
    int row=3,coloum=4;
    alloc2Space3Ptr((void ***)&p,sizeof(int),row,coloum);
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<coloum;++j)
        {
            p[i][j]=i+j;
        }
    }
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<coloum;++j)
        {
            // printf("%d\t",p[i][j]);
            printf("%d\t",*(*(p+i)+j));
        }
        putchar(10);
    }
    free2Space(p,row);
}

int main()
{
    // testSearch();
    test2Space3();
    return 0;
}