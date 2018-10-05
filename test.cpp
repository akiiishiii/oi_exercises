#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
struct ss{
    int next,to,val;
} data[500010];
int head[200010],qe[500010],used[500010],d[500010],color[500010],sum[500010];
int n,m,p,q,timeclock,ans,tot,top,S,s,t,P,jiu;
int x[500010],y[500010],dfn[500010],low[500010],instack[500010],stack[500010],money[500010];
void add(int a,int b)
{
    data[++p].to=b;
    data[p].next=head[a];
    head[a]=p;
}
void Add(int a,int b,int c)
{
    data[++p].to=b;
    data[p].next=head[a];
    data[p].val=c;
    head[a]=p;
}
void tarjan(int a)//标准tarjan
{
    dfn[a]=low[a]=++timeclock;
    instack[a]=1;
    stack[++top]=a;
    for(int i=head[a];i;i=data[i].next)
    {
        int v=data[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[a]=min(low[a],low[v]);
        }
        else
        if(instack[v])
        low[a]=min(low[a],dfn[v]);
    }
    if(dfn[a]==low[a])
    {
        tot++;
        while(stack[top+1]!=a)
        {
            color[stack[top]]=tot;
            sum[tot]+=money[stack[top]];
            instack[stack[top--]]=0;
        }
    }
}
void spfa()//标准spfa
{
    for(int i=1;i<=tot;i++)
    d[i]=0x7fffffff;
    int ts=color[S];
    d[ts]=-sum[ts];
    qe[0]=ts;p=q=0;
    while(p<=q)
    {
        s=qe[p%n];
        used[s]=0;
        t=head[s];
        while(t)
        {
            if(d[s]+data[t].val<d[data[t].to])
            {
                d[data[t].to]=d[s]+data[t].val;
                if(!used[data[t].to])
                {
                    qe[++q%n]=data[t].to;
                    used[data[t].to]=1;
                }
            }
            t=data[t].next;
        }
        p++;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        add(x[i],y[i]);
    }
    for(int i=1;i<=n;i++)
    scanf("%d",&money[i]);
    for(int i=1;i<=n;i++)
    if(!dfn[i])
    {
       tarjan(i);
    }
    memset(data,0,sizeof(data));
    memset(head,0,sizeof(head));
    p=0;
    for(int i=1;i<=m;i++)
    {
        if(color[x[i]]!=color[y[i]])
        Add(color[x[i]],color[y[i]],-(sum[color[y[i]]]));
    }
    scanf("%d",&S);
    spfa();
    scanf("%d",&P);
    for(int i=1;i<=P;i++)
    {
        scanf("%d",&jiu);
        if(-d[color[jiu]]>ans)
        ans=-d[color[jiu]];
    }
    printf("%d\n",ans);
    return 0;
}