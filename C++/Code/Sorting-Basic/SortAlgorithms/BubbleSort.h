#ifndef __BubbleSort_H__
#define __BubbleSort_H__

#include <algorithm>

using namespace std;

//ð������
/*�����鳤��ΪN��
1�� �Ƚ����ڵ�ǰ��������ݣ����ǰ�����ݴ��ں�������ݣ��ͽ��������ݽ�
����
2�� ����������ĵ�0�����ݵ�N-1�����ݽ���һ�α���������һ�����ݾ�
�������������N-1��λ�á�
3�� N=N-1�����N��Ϊ0���ظ�ǰ�����������������ɡ�*/

//ð������1
void BubbleSort1(int a[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 1; j < n - i; j++)
			if (a[j - 1] > a[j])
				swap(a[j - 1], a[j]);
}

/*����һ����־�������һ�˷����˽�������Ϊtrue������Ϊ
false�����������һ��û�з���������˵�������Ѿ���ɡ�*/
//ð������2
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

//ð������3
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
