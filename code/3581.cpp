// 3581.cpp
#include <iostream>

struct node {
    int son[26] = {0};
    bool end = false;
    node() = default;
    ~node() = default;
} tree[30000];
int cnt = 0;
void insert(std::string &s);
long long dp(node *p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::string s;
    std::cin >> n;
    while (n--) {
        std::cin >> s;
        ::insert(s);
    }
    std::cout << ::dp(&tree[0]) << '\n';
    return 0;
}

void insert(std::string &s) {
    node *p = &tree[0];
    for (auto&& it : s) {
        if (it == '\0')
            break;
        int c = it - 'a';
        if (!(p->son[c]))
            p->son[c] = ++cnt;
        p = &tree[p->son[c]];
    }
    p->end = true;
}

long long dp(node *p) {
    long long t = 1;
    for (int i = 0; i < 26; i++)
        if (p->son[i])
            t *= ::dp(&tree[p->son[i]]);
    return t + (long long)(p->end);
}