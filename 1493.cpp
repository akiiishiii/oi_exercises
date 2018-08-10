// 1493.cpp
#include <iostream>
#include <queue>

struct chess {
    int hash;
    int depth;
    chess() = default;
    ~chess() = default;
    chess(int mh, int md) : hash(mh), depth(md) {}
};

int cstart = 0, cend = 0;
bool vis[1 << 16] = {false};

void bfs();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    char temp;
    for (int i = 15; i >= 0; i--) {
        std::cin >> temp;
        if (temp != '0')
            cstart += 1 << i;
    }
    for (int i = 15; i >= 0; i--) {
        std::cin >> temp;
        if (temp != '0')
            cend += 1 << i;
    }
    if (cstart == cend)
        std::cout << "0\n";
    else
        bfs();
    return 0;
}

void bfs() {
    std::queue<chess> q;
    vis[cstart] = true;
    q.push(chess(cstart, 0));
    while (!q.empty()) {
        chess now = q.front();
        if (now.hash == cend) {
            std::cout << now.depth << '\n';
            return;
        }
        for (int i = 15; i >= 0; i--) {
            int col = (15 - i) / 4, row = (15 - i) % 4, pow2i = 1 << i;
            if (row < 3 && (now.hash & (1 << i)) != (now.hash & (1 << (i - 1)))) {
                int temp = 1 << (i - 1), res = now.hash ^ temp ^ pow2i;
                if(!vis[res] && (res >> (i & 1)) != res >> ((i - 1) & 1)) {
                    vis[res] = true;
                    q.push(chess(res, now.depth + 1));
                }
            }
            if (col < 3 && (now.hash & (1 << i)) != (now.hash & (1 << (i - 4)))) {
                int temp = 1 << (i - 4), res = now.hash ^ temp ^ pow2i;
                if(!vis[res] && ((res >> i) & 1) != ((res >> (i - 4)) & 1)) {
                    vis[res] = true;
                    q.push(chess(res, now.depth + 1));
                }
            }
        }
        q.pop();
    }
}