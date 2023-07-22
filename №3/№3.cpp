#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

int seek_substring_BM(string s, string q)

{
	int d[256];

	int i, j, k, N, M;

	N = s.length();

	M = q.length();

	/* построение d */

	for (i = 0; i < 256; i++)

		d[i] = M; /* изначально М во всех позициях */

	for (i = 0; i < M - 1; i++)/* M – i - 1 - расстояние до конца d */

		d[(unsigned char)q[i]] = M - i - 1;/* кроме последнего символа*/

	/* поиск */

	i = M - 1;

	do {

		j = M - 1; /* сравнение строки и шаблона */

		k = i; /* j – по шаблону, k – по строке */

		while ((j >= 0) && (q[j] == s[k])) {

			k--; j--;

		}

		if (j < 0) 
			return k + 1; /* шаблон просмотрен полностью */

		i += d[(unsigned)s[i]];/*сдвиг на расстояние d[s[i]]вправо*/

	} while (i < N);

	return -1;

}

int main()
{
	string s;
	string q;
	int k;
	
	cin >> s;
	cin >> q;
	k = seek_substring_BM(s, q);
	cout << k;
}