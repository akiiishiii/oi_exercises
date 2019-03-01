#pragma GCC optimize (2)
#pragma G++ optimize (2)
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
#define MAX 25
#define JD 1e-9
using namespace std;
int n,m,x,y,d[MAX];
double g[MAX][MAX],ans=1.0;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&x,&y),d[x]++,d[y]++,g[x][y]=g[y][x]=-1;
	for(int i=1;i<=n;i++)
		g[i][i]=d[i];
	for(int i=1;i<n;i++)
	{
		int j=i;
		for(;j<n&&g[j][i]<JD;j++);
		if(j==n)
		{
			ans=0;
			break;
		}
		ans*=g[i][i];
		for(int k=1;k<n;k++)
			swap(g[i][k],g[j][k]);
		for(j=i+1;j<n;j++)
			for(int k=i+1;k<n;k++)
				g[j][k]-=g[j][i]*g[i][k]/g[i][i];
	}
	printf("%.0lf",ans);
	return 0;
}