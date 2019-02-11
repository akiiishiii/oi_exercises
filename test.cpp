#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=0x7fffffff/2;
int map[205][205],tmp[205][205],dis[205],GAP[205];
int n,m,S,T;
void Read()//读入数据，建立图
{  int i,x,y;
   scanf("%d%d%d%d",&n,&m,&S,&T);S=S+n;
   for(i=1;i<=m;i++)
   {  scanf("%d%d",&x,&y);
      map[x][x+n]=1;map[y][y+n]=1;
	  map[x+n][y]=maxn;map[y+n][x]=maxn;
   }
   memcpy(tmp,map,sizeof(map));
}
int DFS(int v,int maxflow)
{  if(v==T)return maxflow;
   int tmp=0;
   for(int i=1;i<=n*2;i++)
      if(map[v][i] && dis[i]+1==dis[v])
      {  int dlt=DFS(i,min(maxflow,map[v][i]));
         tmp += dlt;maxflow-=dlt;
         map[v][i] -= dlt;
         map[i][v] += dlt;
         if(dis[S]==n*2||!maxflow)return tmp;
      }
   if(--GAP[dis[v]]==0)dis[S]=n*2;
   GAP[++dis[v]]++;
   return tmp;
}
int SAP()
{  int Ans=0;
   memset(dis,0,sizeof(dis));
   memset(GAP,0,sizeof(GAP));
   GAP[0]=n*2;
   while(dis[S]<n*2)Ans+=DFS(S,1<<30);
   return Ans;
}
void Solve()
{  int i,flow;
   flow=SAP();//求最大流
   printf("%d\n",flow);
   for(i=1;i<=n;i++)//枚举断点
     if(map[i][i+n]==0)//边满流，则可能是最小割的边
     {  memcpy(map,tmp,sizeof(tmp));
        map[i][i+n]=0;//断边
        if(flow==SAP()+1)//满足要求，则i为要求的点
        {  printf("%d ",i);
		   tmp[i][i+n]=0;//真正断掉
		   flow--;if(flow==0)break;
	    }
     }
}
int main()
{  Read();
   Solve();
   return 0;
}
