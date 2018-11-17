// 1208_.cpp
#include <iostream>

int const Maxn = 100001;

enum dir { x = 0, y };

struct Rectangle {
    int x1, x2, y1, y2, c;
} rect[Maxn];

int tot = 0;

void add(int x1, int y1, int x2, int y2, int c) { rect[++tot].x1 = x1, rect[tot].x2 = x2, rect[tot].y1 = y1, rect[tot].y2 = y2, rect[tot].c = c; }
void cut(int v, int x1, int y1, int x2, int y2, dir d);

int main(int argc, char const *argv[]) {
    int a, b, n, c = 1, s[2505] = {0};
    std ::cin >> a >> b >> n;
    add(0, 0, a, b, 1);
    for (int i = 1, dc, x1, y1, x2, y2; i <= n; i++) {
        std::cin >> x1 >> y1 >> x2 >> y2 >> dc;
        c = std::max(c, dc);
        for (int j = 1; j <= tot; j++) {
            if (rect[j].x1 >= x2 || rect[j].y1 >= y2 || rect[j].x2 <= x1 || rect[j].y2 <= y1)
                continue;
            cut(j, x1, y1, x2, y2, x);
            rect[j--] = rect[tot--];
        }
        add(x1, y1, x2, y2, dc);
    }
    for (int i = 1; i <= tot; i++)
        s[rect[i].c] += (rect[i].x2 - rect[i].x1) * (rect[i].y2 - rect[i].y1);
    for (int i = 1; i <= c; i++)
        if (s[i])
            std::cout << i << ' ' << s[i] << '\n';
    return 0;
}

void cut(int v, int x1, int y1, int x2, int y2, dir d) {
    if (!d) {
        int k1 = std::max(x1, rect[v].x1), k2 = std::min(x2, rect[v].x2);
        if (rect[v].x1 < k1)
            add(rect[v].x1, rect[v].y1, k1, rect[v].y2, rect[v].c);
        if (k2 < rect[v].x2)
            add(k2, rect[v].y1, rect[v].x2, rect[v].y2, rect[v].c);
        cut(v, k1, y1, k2, y2, y);
    } else {
        int k1 = std::max(y1, rect[v].y1), k2 = std::min(y2, rect[v].y2);
        if (rect[v].y1 < k1)
            add(x1, rect[v].y1, x2, k1, rect[v].c);
        if (k2 < rect[v].y2)
            add(x1, k2, x2, rect[v].y2, rect[v].c);
    }
}