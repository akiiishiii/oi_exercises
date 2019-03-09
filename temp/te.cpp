#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a) for(int i=lst[a];i;i=nxt[i])
using namespace std;

typedef long long ll;

int read() {
    char ch;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
    int x=ch-'0';
    for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x;
}

void write(ll x) {
    if (!x) {putchar('0');return;}
    char ch[20];int tot=0;
    for(;x;x/=10) ch[++tot]=x%10+'0';
    fd(i,tot,1) putchar(ch[i]);
}

const int N=5*1e4+5;

typedef vector<int> vec;
#define pb(a) push_back(a)
vec pre[N],dom[N];

int lst[N],nxt[N<<1],t[N<<1],l;
void add(int x,int y) {
    t[++l]=y;nxt[l]=lst[x];lst[x]=l;
}

int n,m,x,y,semi[N],idom[N];

int id[N],dfn[N],fa[N],tot;
void dfs(int x) {
    dfn[x]=++tot;id[tot]=x;
    rep(i,x) {
        pre[t[i]].pb(x);
        if (!dfn[t[i]]) {
            fa[t[i]]=x;
            dfs(t[i]);
        }
    }
}

int father[N],val[N];
int get(int x) {
    if (father[x]==x) return x;
    int y=get(father[x]);
    if (dfn[semi[val[father[x]]]]<dfn[semi[val[x]]]) val[x]=val[father[x]];
    return father[x]=y;
}

int smin(int x,int y) {return dfn[x]<dfn[y]?x:y;}

void solve() {
    fd(i,tot,2) {
        int x=id[i];
        if (!pre[x].empty())
            fo(j,0,pre[x].size()-1)
                if (dfn[pre[x][j]]<dfn[x]) semi[x]=smin(semi[x],pre[x][j]);
                else {
                    get(pre[x][j]);
                    semi[x]=smin(semi[x],semi[val[pre[x][j]]]);
                }
        father[x]=fa[x];dom[semi[x]].pb(x);
        if (!dom[fa[x]].empty())
            fo(j,0,dom[fa[x]].size()-1) {
                int v=dom[fa[x]][j];get(v);
                int u=val[v];
                idom[v]=(dfn[semi[u]]<dfn[semi[v]])?u:fa[x];
            }
    }
    fo(i,2,tot) {
        int x=id[i];
        if (idom[x]!=semi[x]) idom[x]=idom[idom[x]];
    }
}

ll ans[N];
void calc() {
    fo(i,1,n) ans[i]=0;
    fo(i,1,tot) {
        int x=id[i];
        ans[x]+=x;
        if (idom[x]) ans[x]+=ans[idom[x]];
    }
}

string const a = "imp0", b = ".in", c = ".out";


int main(int argc, char const *argv[]) {
    freopen((a + argv[1] + b).c_str(), "r", stdin);
    freopen((a + argv[1] + c).c_str(), "w", stdout);
    //freopen("dominator-tree.in","r",stdin);
    //freopen("dominator-tree.out","w",stdout);
    for(;scanf("%d%d",&n,&m)!=EOF;) {
        fo(i,1,n) lst[i]=0;l=0;
        fo(i,1,n) pre[i].clear();
        fo(i,1,n) dom[i].clear();
        fo(i,1,m) {
            x=read();y=read();
            add(x,y);
        }

        fo(i,1,n) dfn[i]=idom[i]=0;tot=0;
        fo(i,1,n) father[i]=val[i]=semi[i]=i;
        dfs(n);solve();

        calc();
        fo(i,1,n) {
            write(ans[i]);
            if (i!=n) putchar(' ');
        }
        puts("");
    }
}