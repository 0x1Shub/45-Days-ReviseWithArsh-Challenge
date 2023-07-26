#include <bits/stdc++.h>
using namespace std;

int minCostToMakeElementEqual(int a[], int n)
{

    int y;
    if (n % 2 == 1)
        y = a[n / 2];
    else
        y = (a[n / 2] + a[(n - 2) / 2]) / 2;
    int s = 0;
    for (int i = 0; i < n; i++)
        s += abs(a[i] - y);

    return s;
}

int main()
{
    int a[] = {1, 100, 101};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);

    cout << (minCostToMakeElementEqual(a, n));
}
