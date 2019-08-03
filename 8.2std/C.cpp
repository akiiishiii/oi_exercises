#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
typedef unsigned long long ull;
vector<ull> h[MAXN];
ull pw[MAXN];
char buf[MAXN];
int len[MAXN];
typedef pair<int,int> pt;
map<pt,int> mp;
ull getHash(int u,int L,int R)
{
    return h[u][R]-h[u][L-1]*pw[R-L+1];
}
int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    pw[0]=1;
    for(int i=1;i<MAXN;i++)pw[i]=131*pw[i-1];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",buf+1);
        len[i]=strlen(buf+1);
        h[i].resize(len[i]+1);
        for(int k=1;k<=len[i];k++)h[i][k]=131*h[i][k-1]+buf[k];
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(mp.count(pt(u,v)))cout<<mp[pt(u,v)]<<'\n';
        else
        {
            int Ans=0;
            for(int i=min(len[u],len[v]);i>0;i--)
                if(getHash(u,len[u]-i+1,len[u])==getHash(v,1,i)){Ans=i;break;}
            cout<<(mp[pt(u,v)]=Ans)<<'\n';
        }
    }
    return 0;
}
