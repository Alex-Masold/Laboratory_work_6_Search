#include <iostream>
using namespace std;

int ind = 0;
static int BinarySearch(long double array[], int key, int N)
{
	int left = 0;
	int right = N;
	int mid = 0;
	int ind = -1;

	while (!(left >= right))
	{
		mid = (left + right) / 2;

		if (array[mid] > key)
			right = mid;
		else
			left = mid + 1;
		if (left > 0 && array[left] != key && abs(array[left - 1] - key) <= abs(array[left] - key))
		{
			ind = left - 1;
		}
		else
		{
			ind = left;
		}
	}

	return ind;
}

void input_massive(long double a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
}

int main()
{
	int N; // Размер массива
	int Key; // Ключ
	long double* a;
	int index_Key;

	cin >> N >> Key; // Ввод размера массива и ключа через пробел

	a = (long double*)malloc(N * sizeof(long double));

	input_massive(a, N); // Ввод элементов в массив
	index_Key = BinarySearch(a, Key, N);
	cout << index_Key;
	free(a);
}