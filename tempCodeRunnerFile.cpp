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
        int temp = now.hash;
        if (temp == cend) {
            std::cout << now.depth << '\n';
            return;
        }
        for (int i = 15; i >= 0; i--) {
            int x = (15 - i) / 4, y = (15 - i) % 4, w = 1 << i, z;
            if (y < 3 && (temp & (1 << i)) != (temp & (1 << (i - 1)))) {
                z = 1 << (i - 1);
                if(!vis[temp ^ z ^ w]) {
                    vis[temp ^ z ^ w] = true;
                    q.push(chess(temp ^ z ^ w, now.depth + 1));
                }
            }
                if (x < 3 && (temp & (1 << i)) != (temp & (1 << (i - 4)))) {
                z = 1 << (i - 4);
                if(!vis[temp ^ z ^ w]) {
                    vis[temp ^ z ^ w] = true;
                    q.push(chess(temp ^ z ^ w, now.depth + 1));
                }
            }
        }
        q.pop();
    }
}