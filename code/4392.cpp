// 4392.cpp
#include <iostream>

int c[100005], Next[100005], ft[1000005], head[1000005], s[1000005],
    st[1000005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, ans = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
        ft[c[i]] = c[i];
        if (c[i] != c[i - 1])
            ans++;
        if (!head[c[i]])
            st[c[i]] = i;
        s[c[i]]++;
        Next[i] = head[c[i]];
        head[c[i]] = i;
    }
    for (int i = 1, x, a, b; i <= m; i++) {
        std::cin >> x;
        if (x == 1) {
            std::cin >> a >> b;
            if (a == b)
                continue;
            if (s[ft[a]] > s[ft[b]])
                std::swap(ft[a], ft[b]);
            a = ft[a];
            b = ft[b];
            if (!s[a])
                continue;
            for (int i = head[a]; i; i = Next[i]) {
                if (c[i + 1] == b)
                    ans--;
                if (c[i - 1] == b)
                    ans--;
            }
            for (int i = head[a]; i; i = Next[i])
                c[i] = b;
            Next[st[a]] = head[b];
            head[b] = head[a];
            s[b] += s[a];
            head[a] = st[a] = s[a] = 0;
        } else
            std::cout << ans << '\n';
    }
    return 0;
}