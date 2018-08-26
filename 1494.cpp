// 1494.cpp
#include <iostream>
#include <queue>
#include <cstring>

struct digit {
    digit() = default;
    ~digit() = default;
    digit(int const mnum[3][3], int md) : depth(md) { memcpy(num, mnum, sizeof(num)); }
    int num[3][3];
    int depth;
    static int cantorexp(int const num[3][3]);
    int cantor() { return cantorexp(num); }
};

int const Fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
int const goal[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
int start[3][3];
int dist[2][365000], ans;
bool vis[2][365000];
std::queue<digit> q[2];

int check(int const num[3][3]);
void bfs();
bool expand(int k);
void read(int &x);
void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    memset(dist, 0, sizeof(dist));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            read(start[i][j]);
    if (digit::cantorexp(goal) == digit::cantorexp(start))
        std::cout.put('0');
    else if ((check(goal) % 2) ^ (check(start) % 2)) {
        std::cout.put('-');
        std::cout.put('1');
    } else {
        bfs();
        write(ans);
    }
    std::cout.put('\n');
    return 0;
}

int digit::cantorexp(int const num[3][3]) {
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        int temp = 0;
        for (int j = i + 1; j < 9; j++)
            if (num[i / 3][i % 3] > num[j / 3][j % 3])
                temp++;
        ans += temp * Fact[8 - i];
    }
    return ans;
}

int check(int const num[3][3]) {
    int ans = 0;
    for (int i = 0; i < 9; i++)
        if (num[i / 3][i % 3])
            for (int j = i + 1; j < 9; j++)
                if (num[i / 3][i % 3] > num[j / 3][j % 3] && num[j / 3][j % 3])
                    ans++;
    return ans;
}

void bfs() {
    q[0].push(digit(start, 0));
    q[1].push(digit(goal, 0));
    vis[0][q[0].front().cantor()] = vis[1][q[1].front().cantor()] = true;
    while (!(q[0].empty() || q[1].empty())) {
        if (q[0].size() < q[1].size()) {
            if (expand(0))
                return;
            else
                q[0].pop();
        } else {
            if (expand(1))
                return;
            else
                q[1].pop();
        }
    }
}

bool expand(int k) {
    for (int i = 1; i <= 4; i++) {
        digit now = q[k].front();
        now.depth++;
        int zx, zy;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (!now.num[i][j]) {
                    zx = i;
                    zy = j;
                }
        if ((i == 1 && zx == 0) || (i == 2 && zy == 2) || (i == 3 && zx == 2) || (i == 4 && zy == 0))
            continue;
        else {
            switch (i) {
                case 1:
                    std::swap(now.num[zx][zy], now.num[zx - 1][zy]);
                    break;
                case 2:
                    std::swap(now.num[zx][zy], now.num[zx][zy + 1]);
                    break;
                case 3:
                    std::swap(now.num[zx][zy], now.num[zx + 1][zy]);
                    break;
                case 4:
                    std::swap(now.num[zx][zy], now.num[zx][zy - 1]);
                    break;
                default:
                    break;
            }
            int cantor = now.cantor();
            if (!vis[k][cantor]) {
                q[k].push(now);
                vis[k][cantor] = true;
                dist[k][cantor] = now.depth;
                if (vis[1 - k][cantor]) {
                    ans = dist[k][cantor] + dist[1 - k][cantor];
                    return true;
                }
            }
        }
    }
    return false;
}

void read(int &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
}

void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        std::cout.put(x / y + 48);
        x %= y;
    }
}