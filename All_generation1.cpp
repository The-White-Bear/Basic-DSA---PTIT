#include <bits/stdc++.h>
using namespace std;

int x[100];
int n, k;
int ok = 1;

void init_1()
{
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
}
void init_2(int l)
{
    for (int i = 1; i <= l; i++)
    {
        x[i] = i;
    }
}
void in(int l)
{
    for (int i = 1; i <= l; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void gen_binary()
{
    int i = n;
    while (i != 0 && x[i] == 1)
    {
        x[i] = 0;
        i--;
    }
    if (i <= 0)
    {
        ok = 0;
    }
    else
    {
        x[i] = 1;
    }
}
void gen_combination()
{
    int i = k;
    while (i != 0 && x[i] == n - k + i)
    {
        i--;
    }
    if (i <= 0)
    {
        ok = 0;
    }
    x[i]++;
    for (int j = i + 1; j <= k; j++)
    {
        x[j] = x[i] + j - i;
    }
}
void gen_permutation()
{
    int i = n - 1;
    int j = n;
    while (i > 0 && x[i] > x[i + 1])
    {
        i--;
    }
    if (i == 0)
    {
        ok = 0;
    }
    while (x[j] < x[i])
    {
        j--;
    }
    reverse(x + i, x + j + 1);
}
int main()
{
    cin >> n;
    init_2(n);
    while (ok)
    {
        in(n);
        gen_permutation();
    }

    return 0;
}
