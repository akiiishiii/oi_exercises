// 1559.cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
const int M = 200000+5;
int tot=0,h[M],n,c[M],cnt;
long long ans;

struct edge
{
    int y,ne;
    long long v;
}e[M*2];

struct data
{
    int son;
    long long l;
}a[M];

void Addedge(int x,int y,long long l)
{
    e[++tot].y=y;
    e[tot].ne=h[x];
    e[tot].v=l;
    h[x]=tot;
}

void Prepare(int x,int fa)
{
    for (int i=h[x];i;i=e[i].ne)
    {
        int y=e[i].y;
        if (y==fa) continue;
        Prepare(y,x);
        a[x].son+=a[y].son;
        a[x].l=a[x].l+a[y].l+(1ll*e[i].v*a[y].son);
    }
    a[x].son+=c[x];
}

void dfs(int x,int fa,long long now)
{
    for (int i=h[x];i;i=e[i].ne)
    {
        int y=e[i].y;
        if (y==fa) continue;
        long long k=now+1ll*e[i].v*(cnt-a[y].son*2);
        ans=min(ans,k);
        dfs(y,x,k);
    }
}

int main()
{
    scanf("%d",&n);
    cnt=0;
    for (int i=1;i<=n;i++)
        scanf("%d",&c[i]),cnt+=c[i];
    for (int i=1;i<n;i++)
    {
        int x,y;
        long long l;
        scanf("%d%d%lld",&x,&y,&l);
        Addedge(x,y,l);
        Addedge(y,x,l);
    }
    Prepare(1,0);
    ans=a[1].l;
    dfs(1,0,a[1].l);
    cout<<ans<<endl;
    return 0;
}

