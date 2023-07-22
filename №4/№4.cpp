#include <iostream> 
using namespace std;

int binsearch(int a[], int left, int right, int Key) 
{
    int m;
    do 
    {
        m = (left + right) / 2;
        if (a[m] == Key) 
        {
            while (Key == a[m]) 
            {
                m++;
            }
            m--;
            return m;
        }
        else 
        {
            if (a[m] < Key)
                left = m + 1;
            else
                right = m- 1;
        }

    } 
    while (left <= right);
    return -1;
}

void input_massive(int a[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
}

int main() 
{
    int N, Key;
    cin >> N;
    int* a;
    a = (int*)malloc(N * sizeof(int));
    input_massive(a, N);
   
    int left = 0;
    int right = N - 1;
    int K;
    int y, d = 0;
    int c  = 0;
    cin >> K;
    while (c < K) 
    {
        cin >> Key;
        if (c == 0) 
        {
            y = Key;
            d = binsearch(a, left, right, Key);
        }
        else
        {
            if (Key + d != y)
            {
                y = Key + d;
                d = binsearch(a, left, right, Key + d);
            }
        }
        cout << d << "\n";
        c++;
    }
    free(a);
}