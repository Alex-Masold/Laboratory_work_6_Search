#include <iostream> 
using namespace std;

int bin_search(int a[], int N, int Key)
{
	int left = 0;
	int right = N;
	int middle;
	do
	{
		middle = (left + right) / 2;
		if (Key == a[middle])
			return middle;
		else
			if (a[middle] < Key)
				left = middle + 1;
			else
				right = middle - 1;
	} 
	while (left <= right);
	return -1;
}
int count_bin_search(int a[], int N, int Key)
{
	int left = 0;
	int right = N;
	int middle;
	int count = 0;
	do
	{
		middle = (left + right) / 2;
		if (Key == a[middle])
		{
			count++;
			return count;
		}
		else
			if (a[middle] < Key)
			{
				left = middle + 1;
				count++;
			}
			else
			{
				right = middle - 1;
				count++;
			}
	} while (left <= right);
	return -1;
}

void input_massive(int a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
}
void output_massive(int a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << ' ';
	}
}

int main()
{
	int N; // Размер массива
	int Key; // Ключ
	int* a;
	int index_Key;
	int count;

	cin >> N >> Key; // Ввод размера массива и ключа через пробел

	a = new int[N];

	input_massive(a, N); // Ввод элементов в массив
	//output_massive(a, N); // Ввывод массива
	index_Key = bin_search(a, N, Key);
	count = count_bin_search(a, N, Key);
	cout << index_Key << endl;
	cout << count;
}