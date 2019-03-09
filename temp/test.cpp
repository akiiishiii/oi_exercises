#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <utility>
#include <string>
using namespace std;

int n = 0, m = 0;
string const a = "imp0", b = ".in";
pair<int, int> e[1000005];   // 保存数据
map<pair<int, int>, bool> h; // 防止重边

int random(int n) { return (long long)rand() * rand() % n; }

int main(int argc, char const *argv[]) {
    freopen((a + argv[1] + b).c_str(), "w", stdout);
    srand(unsigned(time(NULL)));
    n = atoi(argv[2]), m = atoi(argv[3]);
    // 实例：随机生成图
    // 无向图，连通，不含重边、自环

    // 先生成一棵树，保证连通
    for (int i = 1; i < n; i++) {
        int fa = random(i) + 1;
        e[i] = make_pair(fa, i + 1);
        h[e[i]] = h[make_pair(i + 1, fa)] = 1;
    }
    // 再生成剩余的 m-n+1 条边
    for (int i = n; i <= m; i++) {
        int x, y;
        do {
            x = random(n) + 1, y = random(n) + 1;
        } while (x == y || h[make_pair(x, y)]);
        e[i] = make_pair(x, y);
        h[e[i]] = h[make_pair(y, x)] = 1;
    }
    // 随机打乱，输出
    random_shuffle(e + 1, e + m + 1);
    printf("%d %d\n", n, m);
    for (int i = 1; i <= m; i++)
        printf("%d %d\n", e[i].first, e[i].second);
    return 0;
}