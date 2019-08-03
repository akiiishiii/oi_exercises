#include<bits/stdc++.h>
using namespace std;
const int MAXN=2005,mod=998244353;
int f[MAXN][MAXN],s[MAXN],g[MAXN];
int C[MAXN][MAXN];
vector<int> T[MAXN];
void Dfs(int u,int p)
{
    s[u]=1;f[u][1]=1;
    for(int i=0;i<T[u].size();i++)
    {
        int v=T[u][i];
        if(v==p)continue;
        Dfs(v,u);
        fill(g,g+s[u]+s[v]+1,0);
        for(int k=1;k<=s[u];k++)
            for(int d=0;d<=s[v];d++)
                g[k+d]=(g[k+d]+1ll*C[k+d-1][d]*f[u][k]%mod*f[v][d])%mod;
        s[u]+=s[v];
        for(int k=1;k<=s[u];k++)f[u][k]=g[k];
    }
    for(int i=s[u];i>=0;i--)f[u][i]=(f[u][i]+f[u][i+1])%mod;
}
int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    for(int i=0;i<MAXN;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        T[u].push_back(v);T[v].push_back(u);
    }
    Dfs(1,0);
    cout<<f[1][1]<<'\n';

    return 0;
}
