#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#define maxn 1005
#define MAXN 20005
#define mod 1000000007
#define INF 0x3f3f3f3f
#define pi acos(-1.0)
#define eps 0.000001
using namespace std;

int n,m,ans,cnt,cap,s,e;
int cost[maxn],pp[maxn];
bool vis[maxn][maxn];
int dp[maxn][maxn];
struct Node {
	int v,next,w;
} edge[MAXN];
struct node {
	int u,oil,cst;
	bool operator <(const node &xx)const {
		return cst>xx.cst;
	}
} cur,now;
priority_queue<node>q;

void addedge(int u,int v,int w) {
	cnt++;
	edge[cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].next=pp[u];
	pp[u]=cnt;
}
bool bfs() {
	int i,j,u,v,w,oil,cst;
	memset(dp,0x3f,sizeof(dp));
	memset(vis,0,sizeof(vis));
	while(!q.empty()) q.pop();
	cur.u=s;
	cur.oil=0;
	cur.cst=0;
	dp[s][0]=0;
	q.push(cur);
	while(!q.empty()) {
		now=q.top();
		q.pop();
		u=now.u;
		oil=now.oil;
		cst=now.cst;
		if(u==e) {
			ans=cst;
			return true ;
		}
		if(vis[u][oil]) continue ;
		vis[u][oil]=1;
		if(oil<cap) {
			cur.u=now.u;
			cur.oil=oil+1;
			cur.cst=cst+cost[u];
			if(dp[cur.u][cur.oil]>cur.cst&&!vis[cur.u][cur.oil]) {
				dp[cur.u][cur.oil]=cur.cst;
				q.push(cur);
			}
		}
		for(i=pp[u]; i; i=edge[i].next) {
			v=edge[i].v;
			w=edge[i].w;
			if(oil>=w&&dp[v][oil-w]>cst&&!vis[v][oil-w]) {
				dp[v][oil-w]=cst;
				cur.u=v;
				cur.oil=oil-w;
				cur.cst=cst;
				q.push(cur);
			}
		}
	}
	return false ;
}
int main() {
	int i,j,t,u,v,w,q;
	while(~scanf("%d%d",&n,&m)) {
		for(i=0; i<n; i++) {
			scanf("%d",&cost[i]);
		}
		cnt=0;
		memset(pp,0,sizeof(pp));
		for(i=1; i<=m; i++) {
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		scanf("%d",&q);
		for(i=1; i<=q; i++) {
			scanf("%d%d%d",&cap,&s,&e);
			if(bfs()) printf("%d\n",ans);
			else printf("impossible\n");
		}
	}
	return 0;
}
