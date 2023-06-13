#include <bits/stdc++.h>
using namespace std;
int n, k;
int x[1000];
bool unused[1000];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        x[i] = i;
        unused[i] = true;
    }
}
void in(int x[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << (char)(x[i]-1 + 'A');
    }
    cout << endl;
}

void backtrack_binary(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n)
        {
            in(x, n);
        }
        else
        {
            backtrack_binary(i + 1);
        }
    }
}
void backtrack_combination(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if (i == k)
        {
            in(x, k);
        }
        else
        {
            backtrack_combination(i + 1);
        }
    }
}
void backtrack_permutation(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!unused[j])
        {
            unused[j] = true;
            x[i] = j;
            if (i == n)
            {
                in(x, n);
            }
            else
                backtrack_permutation(i + 1);
            unused[j] = false;
        }
    }
}
int main()
{
    init();
    cin >> n >> k;
    backtrack_combination(1);
    // cout<<cnt;
}