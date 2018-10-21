// 2848.cpp
#include <iostream>
#include <queue>
#include <string>
#include <cstring>

struct node {
    int son[27] = {0};
    int fail = 0;
    bool end = false;
    int ans = 0;
} tree[400005];

int tot = 1, n, m;
int q[400005], num[400005];
std::string s1, s2, s[400005];

void insert(std::string s, int k);
void build();
void search(std::string s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> s[i];
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> s1 >> s2;
        insert(s2 + '{' + s1, i);
    }
    build();
    for (int i = 1; i <= n; i++)
        search(s[i] + '{' + s[i]);
    for (int i = 1; i <= m; i++)
        std::cout << tree[num[i]].ans << "\n";
    return 0;
}

void insert(std::string s, int k) {
    int p = 1;
    for (int i = 0; i < s.length(); i++) {
        int c = s[i] - 'a';
        if (!(tree[p].son[c]))
            tree[p].son[c] = ++tot;
        p = tree[p].son[c];
    }
    tree[p].end = true;
    num[k] = p;
}

void build() {
    int l = 0, r = 1;
    q[1] = 1;
    while (l < r) {
        int x = q[++l];
        for (int i = 0; i <= 26; i++) {
            int y = tree[x].son[i];
            if (!y)
                continue;
            q[++r] = y;
            int t = tree[x].fail;
            while (t && !tree[t].son[i])
                t = tree[t].fail;
            tree[y].fail = (t ? tree[t].son[i] : 1);
        }
    }
}

void search(std::string s) {
    int t = 1;
    for (int i = 0; i < s.length(); i++) {
        int j = s[i] - 'a';
        while (t && !tree[t].son[j])
            t = tree[t].fail;
        t = (t ? tree[t].son[j] : 1);
        for (j = t; j; j = tree[j].fail)
        if (tree[j].end)
            tree[j].ans++;
    }
}
