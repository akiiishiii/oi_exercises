// 1341.cpp
#include <iostream>
#include <queue>

struct farmer {
    int pos;
    int time;
    farmer() = default;
    ~farmer() = default;
    farmer(int x, int t) : pos(x), time(t) {}
};

void bfs();
int n, k;
bool vis[100005] = {false};

int main(int argc, char const *argv[]) {
    std::cin >> n >> k;
    bfs();
    return 0;
}

void bfs() {
    std::queue<farmer> q;
    q.push(farmer(n, 0));
    vis[n] = true;
    while (!q.empty()) {
        farmer now(q.front().pos + 1, q.front().time + 1);
        if (now.pos >= 0 && now.pos <= 100000 && !vis[now.pos]) {
            q.push(now);
            vis[now.pos] = true;
        }
        if (q.front().pos == k) {
            std::cout << q.front().time << '\n';
            return;
        }
        now = farmer(q.front().pos - 1, q.front().time + 1);
        if (now.pos >= 0 && now.pos <= 100000 && !vis[now.pos]) {
            q.push(now);
            vis[now.pos] = true;
        }
        if (q.front().pos == k) {
            std::cout << q.front().time << '\n';
            return;
        }
        now = farmer(2 * q.front().pos, q.front().time + 1);
        if (now.pos >= 0 && now.pos <= 100000 && !vis[now.pos]) {
            q.push(now);
            vis[now.pos] = true;
        }
        if (q.front().pos == k) {
            std::cout << q.front().time << '\n';
            return;
        }
        q.pop();
    }
}