#include <iostream>
using namespace std;

int main() {
	float* a;
	int Key;
	int N; 
	int ind = -1;
	int left = 0;
	int right;
	cin >> N >> Key;

	a = (float*)malloc(N * sizeof(float));
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	
	right = N;
	int m;
	while (left < right) {
		m = (left + right) / 2;
		if (a[m] < Key)
			left = m + 1;
		else
			right = m;
		if (left > 0 && a[left] != Key && abs(a[left - 1] - Key) <= abs(a[left] - Key))
			ind = (left - 1);
		else
			ind = (left);
	}
	free(a);
	cout << ind;
}