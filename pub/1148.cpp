// 1148.cpp
#include <iostream>

int num[6], m;
char ops[5];

void dfs(int n);
int chk(int a, char op);

int main(int argc, const char * argv[]) {
    for (int i = 1; i <= 5; i++)
        std::cin >> num[i];
    std::cin >> m;
    dfs(1);
    return 0;
}

void dfs(int n) {
    if (n == 5) {
        if ()
    }
}

int chk(int a, char op) {
    switch (op) {
        case '+':
            return num[a] + num[a + 1];
        case '-':
            return num[a] - num[a - 1];
        case '*':
            return num[a] * num[a - 1];
        case '/':
            return num[a] / num[a - 1];
        default:
            break;
    }
    return -1;
}