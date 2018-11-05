#include <iostream>
#define M 500005
using namespace std;
int n, m, x, y, z, k, id, top, ans = 2e9;
int dis[M], fa[M], head[M];
bool mark[M];
struct edge
{
    int to, w, nxt;
} E[M << 1];
void add(int u, int v, int w)
{
    E[++id] = ((edge){v, w, head[u]});
    head[u] = id; //´æÍ¼
}
void dfs(int f, int x)
{
    fa[x] = f;
    if (dis[x] > dis[k])
        k = x;
    for (int i = head[x]; i; i = E[i].nxt)
    {
        int y = E[i].to;
        if (y == f || mark[y])
            continue;
        dis[y] = dis[x] + E[i].w;
        dfs(x, y);
    }
}
int main()
{
    // int size=40<<20;
    //  __asm__ ("movq %0,%%rsp\n"::"r"((char*)malloc(size)+size));
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z), add(y, x, z);
    }
    dis[1] = 1, dfs(0, 1);
    dis[k] = 0, dfs(0, k);
    //k±íÊ¾×îÔ¶µÄ¶Ëµã
    top = k; //ÕÒÖ±¾¶
    for (int i = top, j = top; i; i = fa[i])
    {
        while (dis[j] - dis[i] > m)
            j = fa[j];
        //½øÐÐ³ßÈ¡£¬Ñ¡Â·¾¶¡£
        x = max(dis[top] - dis[j], dis[i]);
        //Â·¾¶Á½¶Ëµãµ½Ö±¾¶¶ËµãµÄ×îÐ¡¹±Ï×.
        ans = min(ans, x);
    }
    for (int i = top; i; i = fa[i])
        mark[i] = 1;
    //±ê¼ÇÖ±¾¶£¬ÖØÐÂ¼ÆËãÃ¿¸öµãµÄ¹±Ï×¡£
    for (int i = top; i; i = fa[i])
    {
        k = i, dis[k] = 0;
        dfs(fa[i], i);
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dis[i]);
    //Ã¿¸öµãµÄ¹±Ï×£¬×ÐÏ¸ÏëÏëÎªÊ²Ã´ÊÇ¶ÔµÄ¡£
    printf("%d\n", ans);
    exit(0);
}