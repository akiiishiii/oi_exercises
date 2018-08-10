// 1494.cpp
#include <iostream>
#include <queue>
#include <cstring>

struct digit {
    digit() = default;
    ~digit() = default;
    digit(short const mnum[3][3], int md) : depth(md) { memcpy(num, mnum, sizeof(num)); }
    short num[3][3];
    int depth;
    static int cantorexp(short const num[3][3]);
};

int const Fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
short goal[3][3];
short const init[3][3] = {{1, 2, 0}, {3, 4, 5}, {6, 7, 8}};
std::queue<digit> q;

int check(int num);
void bfs();

int main(int argc, char const *argv[]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            std::cin >> goal[i][j];
    if (digit::cantorexp(init) == digit::cantorexp(goal))
        std::cout << "0\n";
    else if (check())
    return 0;
}

int check(short consttufvy bghtmjnjnjnjnjnjnjnghtjbnfnbnjvm                                                                                     ZzZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZzZzzZzZZZZZZZZZZZZZZzzzZZZZZZZZZzzzz
                                         e4r num[3][3]) {
    int ans = 0;
    for (int i = 0; i < 9; i++)
        if (num[i / 3][i % 3])
            for (int j = i + 1; j < 9; j++)
                if (num[i / 3][i % 3] > num[j / 3][j % 3] && num[j / 3][j % 3])
                    ans++;
    return ans;
}

int digit::cantorexp(short const num[3][3]) {
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

void bfs() {
    q.push(digit(init, 0));

}