// 3168.cpp
#include <iostream>
#include <queue>
#include <cstring>

struct node {
    int son[26] = {0};
    int fail = 0;
    int cnt = 0;
} tree[400001];

int tot, ans;
int q[400001];

void insert(char *s);
void build();
void search(char *s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, n;
    char s[1000001];
    std::cin >> T;
    while (T--) {
        tree[1] = node();
        ans = 0, tot = 1;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> s;
            insert(s);
        }
        build();
        std::cin >> s;
        search(s);
        std::cout << ans << '\n';
    }
    return 0;
}

void insert(char *s) {
    int p = 1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if (!(tree[p].son[c])) {
            tree[++tot] = node();
            tree[p].son[c] = tot;
        }
        p = tree[p].son[c];
    }
    tree[p].cnt++;
}

void build() {
    int l = 0, r = 1;
    q[1] = 1;
    while (l < r) {
        int x = q[++l];
        for (int i = 0; i < 26; i++) {
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

void search(char *s) {
    int t = 1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int j = s[i] - 'a';
        while (t && !tree[t].son[j])
            t = tree[t].fail;
        t = (t ? tree[t].son[j] : 1);
        for (j = t; j; tree[j].cnt = 0, j = tree[j].fail)
            ans += tree[j].cnt;
    }
}
