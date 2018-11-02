#pragma clang optimize on
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
#define MAX 500005
#define INF 0x3f3f3f3f3f
using namespace std;
struct edge{
	long long next,to,value;
}a[MAX*2];
struct point{
	long long d,belong;
}b[MAX];
long long n,maxl,minl,head[MAX],size[MAX],vst[MAX],cnt=1;
long long ans=INF,d[MAX],maxx[MAX],center,sum,tot=0;
void addedge(long long x,long long y,long long z)
{
	a[++cnt].next=head[x];
	a[cnt].to=y;
	a[cnt].value=z;
	head[x]=cnt;
}
void getcenter(long long x,long long fa)
{
	size[x]=1;
	for(long long i=head[x];i;i=a[i].next)
	{
		long long t=a[i].to;
		if(vst[t]||t==fa)continue;
		getcenter(t,x);
		size[x]+=size[t];
		maxx[x]=max(maxx[x],size[t]);
	}
	maxx[x]=max(maxx[x],sum-size[x]);
	if(maxx[x]<maxx[center])center=x;
}
void getdis(long long x,long long fa,long long belong)
{
	for(long long i=head[x];i;i=a[i].next)
	{
		long long t=a[i].to;
		if(vst[t]||t==fa)continue;
		d[t]=d[x]+a[i].value;
		if(!belong)getdis(t,x,t);
		else getdis(t,x,belong);
	}
	b[++tot].belong=belong;
	b[tot].d=d[x];
}
bool cmp(point x,point y)
{
	return x.d<y.d;
}
void getans()
{
	sort(b+1,b+tot+1,cmp);
	long long l=1,r=tot,dis;
	while(l<r)
	{
		dis=b[l].d+b[r].d;
		if(b[l].belong==b[r].belong)
		{
			if(b[l].d+b[r-1].d<minl)l++;
			else r--;
		}
		else
		{
			if(dis>=minl)ans=min(ans,dis),r--;
			else l++;
		}
	}
}
void dfs(long long x,long long fa)
{
	vst[x]=1;
	d[x]=0;
	tot=0;
	getdis(x,fa,0);
	getans();
	for(long long i=head[x];i;i=a[i].next)
	{
		long long t=a[i].to;
		if(vst[t]||t==fa)continue;
		center=0;
		sum=size[t];
		getcenter(t,x);
		dfs(center,0);
	}
}
int main()
{
	long long x,y,z;
	scanf("%lld%lld%lld",&n,&minl,&maxl);
	for(long long i=1;i<=n-1;i++)
		scanf("%lld%lld%lld",&x,&y,&z),addedge(x,y,z),addedge(y,x,z);
	center=0;
	maxx[center]=INF;
	sum=n;
	getcenter(1,0);
	dfs(center,0);
	if(ans>maxl)ans=-1;
	printf("%lld",ans);
	return 0;
}