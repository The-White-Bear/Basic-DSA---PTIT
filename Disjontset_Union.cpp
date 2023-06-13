#include<bits/stdc++.h>
using namespace std;
int parent[1000005];
int rank[100005];
int n,m,ans;
void init() // khởi tạo
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        rank[i]=1;
    }
}
int find(int u)  // tìm đỉnh gốc của u
{
    if(u!=parent[u])
    {
        parent[u]=find(parent[u]);
    }
    return parent[u];
}
void union(int u,int v)
{
    int a=find(u),b=find(v);
    if(a==b) return;
    if(rank[a]<rank[b])
    {
        swap(a,b);  // rank a > rank b
    }
    parent[b]=a;
    rank[a]+=rank[b];
    ans=max(ans,rank[a]);  // so phan tu nhieu nhat trong 1 tap hop
}
bool check()  // bai mang xa hoi
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (Find(i) == Find(j))
                continue;
            if (Find(i) == Find(parent[j]) || Find(parent[i]) == Find(j))
            {
                Union(i, j);   // nếu có bạn chung thì kết bạn
            }
        }
    }
    for (int i = 1; i <= n; i++)  // check tất cả đã dùng 1 cha hay chưa
    {
        if (Find(i) != Find(1))
            return false;
    }
    return true;
}
int main()