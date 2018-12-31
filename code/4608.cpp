// 4608.cpp
#include <iostream>

int const Maxn = 1000005;
int chi[Maxn * 35][2], val[Maxn * 35];
int st[40], s[40];
int np, rt, n, l, top;

void insert(int t);
void query(int a, int b);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int cnt = 0;
    char op;
    np = rt = 1;
    chi[0][0] = chi[1][0] = chi[0][1] = chi[1][1] = 0;
    val[0] = val[1] = 0;
    std::cin >> n;
    int woc = 0;
    for (int i = 1, x, y; i <= n; i++) {
        op = std::cin.get();
        while (op != 'A' && op != 'Q')
            op = std::cin.get();
        if (op == 'A') {
            cnt++;
            int tmp = 0;
            for (int i = 1, x; i <= 4; i++) {
                std::cin >> x;
                for (int j = 7; j >= 0; j--) {
                    s[++tmp] = (1 & (x >> j));
                }
            }
            std::cin >> l;
            insert(cnt);
        } else {
            woc++;
            int tmp = 0;
            for (int i = 1, x; i <= 4; i++) {
                std::cin >> x;
                for (int j = 7; j >= 0; j--) {
                    s[++tmp] = (1 & (x >> j));
                }
            }
            std::cin >> x >> y;
            query(x, y);
        }
    }
    return 0;
}

void insert(int t) {
    int now = rt, d;
    for (int i = 1; i <= l; i++) {
        d = s[i];
        if (!chi[now][d]) {
            chi[now][d] = ++np;
            chi[np][0] = chi[np][1] = 0;
            val[np] = 0;
        }
        now = chi[now][d];
    }
    val[now] = t;
}

void query(int a, int b) {
    top = 0;
    int d, t, now = rt;
    for (int i = 1; i <= 32; i++) {
        d = s[i];
        if (!chi[now][d])
            break;
        now = chi[now][d];
        if (val[now]) {
            t = val[now];
            if (t > b)
                continue;
            while (top > 0 && st[top] > t) {
                top--;
            }
            st[++top] = t;
        }
    }
    int c = 0;
    while (c < top && st[c + 1] < a)
        c++;
    std::cout << top - c << '\n';
}