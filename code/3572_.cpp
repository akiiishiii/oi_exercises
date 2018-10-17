#include <cstring>
#include <iostream>
using namespace std;
int n, m, h[1000005], cnt, dfn[2005], low[2005], top, stack[2005], sign, SCC, belong[2005], opp[2005];
bool Instack[2005], x[2005];
struct edge
{
    int next, to;
} a[1000005];
void add(int x, int y)
{
    cnt++;
    a[cnt].next = h[x];
    a[cnt].to = y;
    h[x] = cnt;
}
void build(int a, int b, int c, string S)
{
    if (S == "AND")
    {
        if (c == 1)
        {
            add(a, a + n);
            add(b, b + n);
        }
        else
        {
            add(a + n, b);
            add(b + n, a);
        }
    }
    if (S == "OR")
    {
        if (c == 1)
        {
            add(a, b + n);
            add(b, a + n);
        }
        else
        {
            add(a + n, a);
            add(b + n, b);
        }
    }
    if (S == "XOR")
    {
        if (c == 1)
        {
            add(a, b + n);
            add(b, a + n);
            add(a + n, b);
            add(b + n, a);
        }
        else
        {
            add(a, b);
            add(b, a);
            add(a + n, b + n);
            add(b + n, a + n);
        }
    }
}

void Tarjan(int x)
{
    dfn[x] = low[x] = ++sign;
    stack[++top] = x;
    Instack[x] = true;
    int i, j;
    for (i = h[x]; i; i = a[i].next)
    {
        j = a[i].to;
        if (!dfn[j])
        {
            Tarjan(j);
            low[x] = min(low[x], low[j]);
        }
        else if (Instack[j])
            low[x] = min(low[x], dfn[j]);
    }
    if (dfn[x] == low[x])
    {
        int t;
        SCC++;
        do
        {
            t = stack[top--];
            Instack[t] = false;
            belong[t] = SCC;
        } while (t != x);
    }
}

int main()
{
    cin >> n >> m;
    string S;
    for (int i = 1, a, b, c; i <= m; i++)
    {
        cin >> a >> b >> c >> S;
        build(a, b, c, S);
    }
    for (i = 1; i <= n * 2; i++)
        if (!dfn[i])
            Tarjan(i);
    for (i = 1; i <= n; i++)
    {
        if (belong[x] == belong[y])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}