#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
// luy thua
long long pow_mod(int n, int k)
{
    long long res = 1;
    while (k > 0)
    {
        if (k % 2 == 1)
        {
            res = ((long long)res * n) % MOD;
        }
        n = ((long long)n * n) % MOD;
        k /= 2;
    }
    return res;
}
int pow2(int n, int k)
{
    if (k == 0)
    {
        return 1;
    }
    int res = pow2(a, k / 2);
    res *= res;
    if (k % 2 == 1)
    {
        res *= a;
    }
    return res;
}
// binary search
int search(int a[100], int x, int l, int r)
{
    if (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] > x)
        {
            return search(a, x, l, mid - 1);
        }
        else
        {
            return search(a, x, mid + 1, r);
        }
    }
    return -1;
}
// gap doi day so
long long a[100];

void init()
{
    a[1] = 1;
    for (int i = 2; i < 60; i++)
    {
        a[i] = a[i - 1] * 2 + 1;
    }
}
long long find(long long n, long long i)
{
    if (n == 1)
    {
        return 1;
    }
    long long mid = a[n] / 2 + 1;
    if (i == mid)
    {
        return n;
    }
    else if (i > mid)
    {

        return find(n - 1, i - mid);
    }
    else
    {
        return find(n - 1, i);
    }
}
// day fibo
long long fibo[100];

void precomputefibo(int n)
{
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 3; i <= n; i +=)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}
char find(int n, long long i)
{
    if (n == 1)
    {
        return 'A';
    }
    if (n == 2)
    {
        return 'B';
    }
    if (i > fibo[n - 2])
    {
        return find(n - 1, i - fibo[n - 2]);
    }
    else
    {
        return find(n - 2, i);
    }
}
// dem so ky tu B trong day xau fibo
int val[100] = {0, 0, 1};
int dem_so_ki_tu_B(int n, int k)
{
    if (n < 3)
    {
        return val[n];
    }
    if (k <= fibo[n - 2])
    {
        return dem_so_ki_tu_B(n - 2, k);
    }
    return dem_so_ki_tu_B(n - 2, fibo[n - 2]) + dem_so_ki_tu_B(n - 1, k - fibo[n - 2]);
}
// day con lien tiep co tong lon nhat
int kadane(int arr[], int n)
{
    int max = INT_MIN;
    int max_end = 0;
    for (int i = 0; i < n; i++)
    {
        max_end += arr[i];
        if (max < max_end)
        {
            max = max_end;
        }
        if (max_end < 0)
        {
            max_end = 0;
        }
    }
    return max;
}
// chuyen he co so k sang he co so 10
long long convertK(long long n, int k)
{
    long long res=0;
    int i=0;
    while(n>0)
    {
        res+=(n%k)*pow(10,i);
        n/=k;
        i++;
    }
    return res;
}
int main()
{
}