// 1133.cpp
#include <cstring>
#include <iostream>

int const chash = 4001, Maxs = 20000;
int n, m, li, lj;
int cnt, now, last = 0, k;
int map[15][15];
int state[2][Maxs], sum[2];
int head[chash], Next[Maxs], ver[Maxs];
long long f[2][Maxs];

void update(int s);
void trans(int x, int y, int s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char ch;
    int ans = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            std::cin >> ch;
            map[i][j] = (ch == '.');
            if (map[i][j])
                li = i, lj = j;
        }
    sum[0] = f[0][1] = 1;
    state[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            now = !last;
            memset(head, 0, sizeof(head));
            sum[now] = cnt = 0;
            for (k = 1; k <= sum[last]; k++)
                trans(i, j, state[last][k]);
            last = now;
        }
        for (k = 1; k <= sum[now]; k++)
            state[now][k] <<= 2;
    }
    for (int i = 1; i <= sum[now]; i++)
        ans += f[now][i];
    std::cout << ans << '\n';
    return 0;
}

void update(int s) {
    int i, hash = s % chash;
    for (i = head[hash]; i; i = Next[i])
        if (ver[i] == s)
            break;
    if (i) {
        f[now][i] += f[last][k];
        return;
    }
    ver[i] = s, Next[i] = head[hash], head[hash] = ++cnt;
    f[now][i] = f[last][k];
    sum[now]++;
    state[now][i] = s;
}

void trans(int x, int y, int s) {
    int p1 = (y - 1) << 1, p2 = y << 1, t1 = (s >> p1) & 3, t2 = (s >> p2) & 3;
    if (!map[x][y]) {
        if (!t1 && !t2)
            update(s);
        return;
    }
    if (!t1 && !t2 && map[x + 1][y] && map[x][y + 1])
        update(s + (1 << p1) + (2 << p2));
    if (t1 == 1 && t2 == 1) {
        int i = y;
        for (int top = 0; i <= m; i++) {
            int j = (s >> (i << 1)) & 3;
            if (j == 1)
                top++;
            else if (j == 2)
                top--;
            if (!top)
                break;
        }
        update(s - (t1 << p1) - (t2 << p2) - (1 << (i << 1)));
    } else if (t1 == 2 && t2 == 2) {
        int i = y - 1;
        for (int top = 0; i >= 0; i--) {
            int j = (s >> (i << 1)) & 3;
            if (j == 2)
                top++;
            else if (j == 1)
                top--;
            if (!top)
                break;
        }
        update(s - (t1 << p1) - (t2 << p2) + (1 << (i << 1)));
    } else if (t1 == 2 && t2 == 1)
        update(s - (t1 << p1) - (t2 << p2));
    else if (t1 == 1 && t2 == 2 && x == li && y == lj)
        update(s - (t1 << p1) - (t2 << p2));
    else if (!t1 && t2 > 0) {
        if (map[x][y + 1])
            update(s);
        if (map[x + 1][y])
            update(s - (t2 << p2) + (t2 << p1));
    } else if (t1 > 0 && !t2) {
        if (map[x + 1][y])
            update(s);
        if (map[x][y + 1])
            update(s - (t1 << p1) + (t1 << p2));
    }
}