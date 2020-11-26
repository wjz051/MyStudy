#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

// ������n��Ԫ�ص��������,ÿ��Ԫ�ص������ΧΪ[rangeL, rangeR]
int *generateRandomArray(int n, int rangeL, int rangeR) 
{
	assert(rangeL <= rangeR);

	int *arr = new int[n];
	//�����������
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
	return arr;
}

template<typename T>
void printArray(T arr[], int n) 
{

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return;
}


int main()
{
	// ���������㷨��������
	int N = 100;
	int *arr = generateRandomArray(N, 0, 100);
	//selectionSort(arr, N);
	printArray(arr, N);
	delete[] arr;


	cout << "Hello World!" << endl;
	system("pause");
	return 0;
}
