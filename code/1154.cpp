// 1154.cpp
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
/*
桃花源记

东晋 陶渊明

晋太元中，武陵人捕鱼为业。缘溪行，忘路之远近。忽逢桃花林，夹岸数百
步，中无杂树，芳草鲜美，落英缤纷。渔人甚异之，复前行，欲穷其林。

林尽水源，便得一山，山有小口，仿佛若有光。便舍船，从口入。初极狭，
才通人。复行数十步，豁然开朗。土地平旷，屋舍俨然，有良田美池桑竹之
属。阡陌交通，鸡犬相闻。其中往来种作，男女衣着，悉如外人。黄发垂髫
，并怡然自乐。

见渔人，乃大惊，问所从来。具答之。便要还家，设酒杀鸡作食。村中闻有
此人，咸来问讯。自云先世避秦时乱，率妻子邑人来此绝境，不复出焉，遂
与外人间隔。问今是何世，乃不知有汉，无论魏晋。此人一一为具言所闻，
皆叹惋。余人各复延至其家，皆出酒食。停数日，辞去。此中人语云：“不
足为外人道也。”

既出，得其船，便扶向路，处处志之。及郡下，诣太守，说如此。太守即遣
人随其往，寻向所志，遂迷，不复得路。

南阳刘子骥，高尚士也，闻之，欣然规往。未果，寻病终，后遂无问津者。
*/
int const Maxn = 1005;
int head[Maxn], tot;
int ver[Maxn * 40], edge[Maxn * 40], Next[Maxn * 40];
int n, m, p, status;
int f[Maxn][1 << 6], sta[Maxn], g[Maxn];
bool inqueue[Maxn][1 << 6];
std::queue<std::pair<int, int>> q;

inline void add(int u, int v, int w) { ver[++tot] = v, edge[tot] = w, Next[tot] = head[u], head[u] = tot; }
void spfa();
bool chk(int s);
void steiner_tree();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> p;
        int tmp = m;
        m = n - p, n = p, p = tmp;
        memset(head, 0, sizeof(head));
        memset(sta, 0, sizeof(sta));
        memset(inqueue, 0, sizeof(inqueue));
        tot = 0, status = 1 << (n * 2);
        for (int i = 0; i < n + m; i++)
            for (int j = 0; j < status; j++)
                f[i][j] = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            sta[i] = 1 << i;
            f[i][sta[i]] = 0;
            f[m + i][sta[m + i] = 1 << (n + i)] = 0;
        }
        for (int i = 1, u, w, v; i <= p; i++) {
            std::cin >> u >> v >> w;
            add(--u, --v, w), add(v, u, w);
        }
        steiner_tree();
        if (g[status - 1] == 0x3f3f3f3f)
            std::cout << "No solution\n";
        else
            std::cout << g[status - 1] << '\n';
    }
    return 0;
}

void spfa() {
    while (!q.empty()) {
        std::pair<int, int> x = q.front();
        q.pop();
        inqueue[x.first][x.second] = false;
        for (int i = head[x.first]; i; i = Next[i]) {
            int y = ver[i], s = x.second | sta[y];
            if (f[x.first][x.second] + edge[i] < f[y][s]) {
                f[y][s] = f[x.first][x.second] + edge[i];
                if (s == x.second && !inqueue[y][s])
                    q.push(std::make_pair(y, s)),
                        inqueue[y][s] = true;
            }
        }
    }
}

bool chk(int s) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (s & (1 << i))
            sum++;
        if (s & (1 << (n + i)))
            sum--;
    }
    return !sum;
}

void steiner_tree() {
    for (int i = 0; i < status; i++) {
        for (int j = 0; j < n + m; j++) {
            for (int k = i; k; k = (k - 1) & i)
                f[j][i] = std::min(f[j][i], f[j][k | sta[j]] + f[j][(i - k) | sta[j]]);
            if (f[j][i] != 0x3f3f3f3f)
                q.push(std::make_pair(j, i)), inqueue[j][i] = true;
        }
        spfa();
    }
    for (int i = 0; i < status; i++) {
        g[i] = 0x3f3f3f3f;
        for (int j = 0; j < n + m; j++)
            g[i] = std::min(g[i], f[j][i]);
    }
    for (int i = 1; i < status; i++) {
        if (chk(i))
            for (int j = (i - 1) & i; j; j = (j - i) & i)
                if (chk(j))
                    g[i] = std::min(g[i], g[j] + g[i - j]);
    }
}