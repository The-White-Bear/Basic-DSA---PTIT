#include <bits/stdc++.h>
using namespace std;
void record(vector<char> path, vector<string> v)
{
    string s(path.begin(), path.end());
    v.push_back(s);
}
void duongdi(int x, int y, int n, int a[][100], vector<char> path, vector<string> v)
{
    if (x == n - 1 && y == n - 1)
    {
        record(path, v);
        return;
    }
    if (x + 1 < n && a[x + 1][y] == 1)
    {
        path.push_back('D');
        duongdi(x + 1, y, n, a, path, v);
        path.pop_back();
    }
    if (y + 1 < n && a[x][y + 1] == 1)
    {
        path.push_back('R');
        duongdi(x, y + 1, n, a, path, v);
        path.pop_back();
    }
}
void print()
{
    cout << "[";
    for (int i = 0; i < x.size() - 1; i++)
    {
        cout << x[i] << " ";
    }
    cout << x.back() << "]";
}
void tong_bang_k(int start, int sum = 0)
{
    if (sum == k)
    {
        print();
    }
    if (sum > k)
    {
        return;
    }
    for (int i = start; i <= n; i++)
    {
        x.emplace_back(a[i]);
        tong_bang_k(i, sum + a[i]);
        x.popback();
    }
}
int dem_so_duong_di(int mat[100][100], int x, int y, int n, int m)
{
    if (x == m - 1 && y == n - 1)
    {
        return 1;
    }
    int count = 0;
    if (x < m - 1)
    {
        count += dem_so_duong_di(mat, x + 1, y, n, m);
    }
    if (y < n - 1)
    {
        count += dem_so_duong_di(mat, x, y + 1, n, m);
    }
    return count;
}
int n, result;
int columns[20], diagonal1[40], diagonal2[40];
void back_track_hau(int row)
{
    if (row == n)
    {
        res++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!columns[i] && !diagona1[row + i] && !diagona2[n - 1 + row - i])
        {
            // Nếu ô (row, i) chưa được đặt quân hậu
            // và không có quân hậu nào trên đường chéo đi qua ô này
            colums[i] = diagona1[row + i] = diagonal2[n - 1 + row - i] = 1; // Đánh dấu đã đặt quân hậu ở ô này
             solve(row + 1); // Đệ quy để đặt quân hậu lên hàng tiếp theo
             columns[i] = diagonal1[row + i] = diagonal2[n - 1 + row - i] = 0;// Đánh dấu bỏ quân hậu ở ô này sau khi quay lui 
        }
    }
}
void hanoi_tower(int n,char A,char B,char C)
{
    if(n==1)
    {
        cout<<A<<"->"<<C<<endl;
    }
    else
    {
        hanoi_tower(n-1,A,C,B);
        cout<<A<<"->"<<C<<endl;
        hanoi_tower(n-1,B,A,C);
    }
}
vector<string> result;
int cnt = 0;
void gen(string current, char nextChar, int remain)
{
    if (remain == 0)
    {
        reverse(current.begin(),current.end());
        result.push_back(current);
        cnt++;
        return;
    }

    for (char c = 'A'; c <= nextChar; c++)
    {
        
            gen(current + c, c, remain - 1);  
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[100][100];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> a[i][j];
            }
        }
        vector<char> path;
        vector<string> v;
        if (a[0][0] == 1)
        {
            backtrack(0, 0, n, a, path, v);
        }
        if (!v.empty())
        {
            for (int i = 0; i < v.size(); ++i)
            {
                cout << v[i];
                if (i != v.size() - 1)
                {
                    cout << " ";
                }
            }
        }
        else
        {
            cout << "-1";
        }
        cout << endl;
    }

    return 0;
}