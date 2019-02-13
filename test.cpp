#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<stack>
#include<vector>
#define JD 0.0000005
using namespace std;
int n,m,d[405],gap[405],head[405],cnt,S,T,vst[405],num=0,ANS[405];
//double
struct bianji{
	int x,y;
	double z;
}b[405];
struct edge{
	int next,to;
	double flow;
}a[4005];
void add(int x,int y,double z)
{
	a[++cnt].next=head[x];
	a[cnt].to=y;
	a[cnt].flow=z;
	head[x]=cnt;
	a[++cnt].next=head[y];
	a[cnt].to=x;
	a[cnt].flow=0.0;
	head[y]=cnt;
}
double dfs(int x,double maxf,int to)
{
	if(x==to)return maxf;
	double ans=0,dlt;
	for(int i=head[x];i;i=a[i].next)
	{
		int t=a[i].to;
		if(a[i].flow&&d[x]==d[t]+1)
		{
			dlt=dfs(t,min(maxf,a[i].flow),to);
			ans+=dlt;
			maxf-=dlt;
			a[i].flow-=dlt;
			a[i^1].flow+=dlt;
			if(!maxf||d[S]==n)return ans;
		}
	}
	gap[d[x]]--;
	if(!gap[d[x]])d[S]=n;
	gap[++d[x]]++;
//	cout<<ans<<"\n";
	return ans;
}
double sap(int st,int to)
{
	gap[0]=n;
	double ans=0;
	while(d[st]<n)ans+=dfs(st,0x3f3f3f,to);
//	cout<<ans<<"\n";
	return ans;
}
double ojbk(double mid)
{
	double ans=0.0;
	memset(a,0,sizeof(a));
	memset(head,0,sizeof(head));
	memset(gap,0,sizeof(gap));
	memset(d,0,sizeof(d));
	cnt=1;
	for(int i=1;i<=m;i++)
	{
		if(b[i].z<=mid)
			ans+=b[i].z-mid;
		else
		{
			add(b[i].x,b[i].y,b[i].z-mid);
			add(b[i].y,b[i].x,b[i].z-mid);
		}
	}
//	cout<<ans<<"\n";
	return ans+sap(S,T);
}
void DFS(int x)
{
	vst[x]=1;
	for(int i=head[x];i;i=a[i].next)
	{
		int t=a[i].to;
		if(a[i].flow>JD&&!vst[t])
			DFS(t);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	double l=0.0,r=0.0,mid;
	for(int i=1;i<=m;i++)
		scanf("%d%d%lf",&b[i].x,&b[i].y,&b[i].z),r+=b[i].z;
	S=1;T=n;
	while(r-l>JD)
	{
		mid=(l+r)/2.0;
		if(ojbk(mid)>JD)l=mid;
		else r=mid;
	}
	ojbk(mid);
	DFS(S);
	for(int i=1;i<=m;i++)
	{
		if(b[i].z<mid||vst[b[i].x]!=vst[b[i].y])
			ANS[++num]=i;
	}
	printf("%d\n",num);
	for(int i=1;i<=num;i++)
		printf("%d ",ANS[i]);
	return 0;
}