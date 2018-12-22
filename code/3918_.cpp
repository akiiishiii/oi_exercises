#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int k=2;
int n,d,cnt=0;
struct point{int x[2],minx[2],maxx[2];}
p[500001],a[1000001],now;
struct KDtree{int l,r;}
t[1000001];
int ans;
bool operator <(const point &a,const point &b)
{
	return a.x[d]<b.x[d];
}
void updata(int x,int y)
{
	a[x].minx[0]=min(a[x].minx[0],a[y].minx[0]);
	a[x].maxx[0]=max(a[x].maxx[0],a[y].maxx[0]);
	a[x].minx[1]=min(a[x].minx[1],a[y].minx[1]);
	a[x].maxx[1]=max(a[x].maxx[1],a[y].maxx[1]);
}
void build(int &x,int L,int r,int dep)
{
	if(!x)x=++cnt;
	d=dep%k;
	int mid=L+r>>1;
	nth_element(p+L,p+mid,p+r+1);
	a[x]=p[mid];

	if(L<=mid-1)
	{
		build(t[x].l,L,mid-1,dep+1);
		updata(x,t[x].l);
	}
	if(r>=mid+1)
	{
		build(t[x].r,mid+1,r,dep+1);
		updata(x,t[x].r);
	}
}
void insert(int &x,int dep)
{
	if(!x)
	{
		x=++cnt;
		a[x]=now;
		t[x]=(KDtree){0,0};
		return;
	}
	d=dep%k;
	if(now<a[x])
	{
		insert(t[x].l,dep+1);
		updata(x,t[x].l);
	}
	else
	{
		insert(t[x].r,dep+1);
		updata(x,t[x].r);
	}
}
int dis(point a,point b)
{
	return abs(a.x[0]-b.x[0])+abs(a.x[1]-b.x[1]);
}
int mindis(int x)
{
	int x0,x1;
	if(now.x[0]>=a[x].minx[0]&&now.x[0]<=a[x].maxx[0])
		x0=0;
	else
		x0=min(abs(now.x[0]-a[x].maxx[0]),abs(now.x[0]-a[x].minx[0]));
	if(now.x[1]>=a[x].minx[1]&&now.x[1]<=a[x].maxx[1])
		x1=0;
	else
		x1=min(abs(now.x[1]-a[x].maxx[1]),abs(now.x[1]-a[x].minx[1]));
	return x0+x1;
}
void reans1(point a)
{
	int tmp=dis(a,now);
	if(tmp<ans)ans=tmp;
}
void query1(int x,int dep)
{
	d=dep%k;
	int dl,dr;
	if(t[x].l)dl=mindis(t[x].l);
	     else dl=0x7fffffff/4;
	if(t[x].r)dr=mindis(t[x].r);
	     else dr=0x7fffffff/4;
	reans1(a[x]);
	if(dl<dr)
	{
		if(dl<ans)query1(t[x].l,dep+1);
		if(dr<ans)query1(t[x].r,dep+1);
	}
	else
	{
		if(dr<ans)query1(t[x].r,dep+1);
		if(dl<ans)query1(t[x].l,dep+1);
	}
}
int main()
{
	int T;
	scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++)
    	for(int j=0;j<k;j++)
    	{
			scanf("%d",&p[i].x[j]);
			p[i].maxx[j]=p[i].minx[j]=p[i].x[j];
		}
	int root=0;
	build(root,1,n,0);
	int way;
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d%d",&way,&now.x[0],&now.x[1]);
		now.maxx[0]=now.minx[0]=now.x[0];
		now.maxx[1]=now.minx[1]=now.x[1];
		if(way&1)insert(root,0);
		else
		{
			ans=0x7fffffff/2;
			query1(1,0);
			printf("%d\n",ans);
		}
	}
	return 0;
}