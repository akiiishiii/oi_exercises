// 2979.cpp
#include <iostream>
#include <vector>
#include <string>

struct node {
    int son[130] = {0};
    node() = default;
    ~node() = default;
} tree[100000];
int cnt = 0, ans = 0;
void insert(std::string &s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::string s;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        s += '/';
        ::insert(s);
        std::cout << ans << '\n';
    }
    return 0;
}

void insert(std::string &s) {
    node *p = &tree[0];
    for (int i = 1; i < s.length(); i++) {
        if (!(p->son[int(s[i])])) {
            p->son[int(s[i])] = ++cnt;
            if (int(s[i]) == int('/'))
                ans++;
        }
        p = &tree[p->son[int(s[i])]];
    }
}
