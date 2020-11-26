#ifndef __BubbleSort_H__
#define __BubbleSort_H__

#include <algorithm>

using namespace std;

//冒泡排序
/*设数组长度为N。
1． 比较相邻的前后二个数据，如果前面数据大于后面的数据，就将二个数据交
换。
2． 这样对数组的第0个数据到N-1个数据进行一次遍历后，最大的一个数据就
“沉”到数组第N-1个位置。
3． N=N-1，如果N不为0就重复前面二步，否则排序完成。*/

//冒泡排序1
void BubbleSort1(int a[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 1; j < n - i; j++)
			if (a[j - 1] > a[j])
				swap(a[j - 1], a[j]);
}

/*设置一个标志，如果这一趟发生了交换，则为true，否则为
false。明显如果有一趟没有发生交换，说明排序已经完成。*/
//冒泡排序2
void BubbleSort2(int a[], int n)
{
	int j, k;
	bool flag;
	k = n;
	flag = true;
	while (flag)
	{
		flag = false;
		for (j = 1; j < k; j++)
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1], a[j]);
				flag = true;
			}
		k--;
	}
}

//冒泡排序3
void BubbleSort3(int a[], int n)
{
	int j, k;
	int flag;
	flag = n;
	while (flag > 0)
	{
		k = flag;
		flag = 0;
		for (j = 1; j < k; j++)
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1], a[j]);
				flag = j;
			}
	}
}


#endif // __BubbleSort_H__
