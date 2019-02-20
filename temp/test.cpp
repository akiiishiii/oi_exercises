#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=100005;
struct FrontStar
{struct Bian{int next,num,v;}l[maxn*2];
 int bt[maxn],cnt;
 void lian(int a,int b,int v)
 {l[++cnt].num=b;
  l[cnt].next=bt[a];
  l[cnt].v=v;
  bt[a]=cnt;
  //cout<<a<<"->"<<b<<" "<<v<<endl;
 }
 void Init()
 {memset(bt,0,sizeof(bt));
  cnt=0;
 }
}r;
int N,dfs[maxn]={0},tot=0,fa[maxn]={0},d[maxn]={0},dl[maxn]={0};
void DFS(int x)
{dfs[x]=++tot;
 for(int i=r.bt[x];i;i=r.l[i].next)
    {int next=r.l[i].num;
     if(!dfs[next])
       {fa[next]=x;
        d[next]=d[x]+1;
        dl[next]=dl[x]+r.l[i].v;
	    DFS(next);
       }
    }
}
struct LowComAnc
{int p[maxn][50];
 void ST()
 {memset(p,-1,sizeof(p));
  for(int i=1;i<=N;i++)p[i][0]=fa[i];
  for(int j=1;(1<<j)<=N;j++)
     {for(int i=1;i<=N;i++)
         if(~p[i][j-1])p[i][j]=p[p[i][j-1]][j-1];
     }
 }
 int LCA(int a,int b)
 {if(d[a]<d[b])swap(a,b);
  int k=log(d[a])/log(2);
  for(int i=k;i>=0;i--)
     if(d[a]-(1<<i)>=d[b])a=p[a][i];
  if(a==b)return b;
  for(int i=k;i>=0;i--)
     if(p[a][i]!=-1&&p[a][i]!=p[b][i])
       {a=p[a][i];
        b=p[b][i];
       }
  return p[a][0];
 }
}rl;
bool comp(int a,int b)
{return dfs[a]<dfs[b];
}
int p[maxn],st[maxn];
void SVT()
{int k;
 scanf("%d",&k);
 //u.Init();
 for(int i=1;i<=k;i++)
    scanf("%d",&p[i]);
 sort(p+1,p+1+k,comp);
 tot=1;
 int top=0;
 for(int i=2;i<=k;i++)
    {if(rl.LCA(p[top],p[i])!=p[tot])p[++tot]=p[i];
    }
 st[++top]=1;
 int ans=0;
 for(int i=1;i<=k;i++)
    {int lca=rl.LCA(p[i],st[top]);
     if(lca==st[top])
       {st[++top]=p[i];
        continue;
       }
     while(1)
     {if(d[st[top-1]]<=d[lca])
        {//u.lian(lca,st[top],abs(dl[st[top]]-dl[lca]));
         ans+=abs(dl[st[top]]-dl[lca]);
		 top--;
         if(st[top]!=p[i])st[++top]=lca;
         break;
        }
      //u.lian(st[top-1],st[top],abs(dl[st[top-1]]-dl[st[top]]));
      ans+=abs(dl[st[top-1]]-dl[st[top]]);
	  top--;
     }
     if(st[top]!=p[i])st[++top]=p[i];
    }
 //while(--top)u.lian(st[top],st[top+1],abs(dl[st[top]]-dl[st[top+1]]));
 while(--top)ans+=abs(dl[st[top]]-dl[st[top+1]]);
 printf("%d\n",ans);
}
int main()
{scanf("%d",&N);
 for(int i=1;i<N;i++)
    {int u,v,w;
     scanf("%d%d%d",&u,&v,&w);
     r.lian(u,v,w);
     r.lian(v,u,w);
    }
 d[1]=1;
 DFS(1);
 rl.ST();
 int M;
 scanf("%d",&M);
 while(M--)
 {SVT();
 }
}