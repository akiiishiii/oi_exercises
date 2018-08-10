// 1491.cpp
#include <iostream>
#include <queue>
#include <string>
#include <cstring>

struct board {
    board() = default;
    ~board() = default;
    board(short mindex[2][4], std::string ms) : s(ms) { memcpy(index, mindex, sizeof(index)); }
    short index[2][4];
    std::string s;
    int const cantorexp() const;
    static int const cantorexp(short m[2][4]);
    board change(char c) const;
};

int const fact[] = {1, 1, 2, 6, 24, 120, 720, 5040};
int goal;
bool vis[50005] = {false};
std::queue<board> q;

void bfs();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    short res[2][4];
    for (int i = 0; i < 4; i++)
        std::cin >> res[0][i];
    for (int i = 3; i >= 0; i--)
        std::cin >> res[1][i];
    goal = board::cantorexp(res);
    if (!goal)
        std::cout << "0\n\n";
    else
        bfs();
    return 0;
}

int const board::cantorexp() const {
    int arr[8], ans = 0;
    for (int i = 0; i < 4; i++)
       arr[i] = index[0][i];
    for (int i = 4; i < 8; i++)
        arr[i] = index[1][7 - i];
    for (int i = 0, temp; i < 8; i++) {
        temp = 0;
        for (int j = i + 1; j < 8; j++)
            if (arr[i] > arr[j])
                temp++;
        ans += temp * fact[7 - i];
    }
    return ans;
}

int const board::cantorexp(short m[2][4]) {
    board temp(m, "");
    return temp.cantorexp();
}

board board::change(char c) const {
    board res = *this;
    switch (c) {
        case 'A':
            for (int i = 0; i < 4; i++)
                res.index[0][i] = this->index[1][i];
            for (int i = 0; i < 4; i++)
                res.index[1][i] = this->index[0][i];
            break;
        case 'B':
            for (int i = 0; i < 4; i++) {
                res.index[0][(i + 1) % 4] = this->index[0][i];
                res.index[1][(i + 1) % 4] = this->index[1][i];
            }
            break;
        case 'C':
            res.index[0][1] = this->index[1][1];
            res.index[0][2] = this->index[0][1];
            res.index[1][2] = this->index[0][2];
            res.index[1][1] = this->index[1][2];
    }
    res.s += c;
    return res;
}

void bfs() {
    short m[2][4] = {{1, 2, 3, 4}, {8, 7, 6, 5}};
    q.push(board(m, ""));
    vis[q.front().cantorexp()] = true;
    while (!q.empty()) {
        for (char tc = 'A'; tc <= 'C'; tc++) {
            board now = q.front().change(tc);
            int cantor = now.cantorexp();
            if (vis[cantor])
                continue;
            else if (cantor == goal) {
                std::cout << now.s.length() << '\n' << now.s << '\n';
                return;
            } else {
                q.push(now);
                vis[cantor] = true;
            }
        }
        q.pop();
    }
}