// 1460.cpp
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>

bool x[25], y[25];
int n, my[25], xx1[25], xx2[25], yy1[25], yy2[25];
double a[25][25], lx[25], ly[25];

bool dfs(int v);
void adjust();
void km();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> xx1[i] >> yy1[i];
    for (int i = 1; i <= n; i++)
        std::cin >> xx2[i] >> yy2[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = sqrt((xx1[i] - xx2[j]) * (xx1[i] - xx2[j]) + (yy1[i] - yy2[j]) * (yy1[i] - yy2[j]));
    double ans = 0;
    km();
    for (int i = 1; i <= n; i++)
        if (my[i])
            ans += a[my[i]][i];
    std::cout << std::fixed << std::setprecision(3) << ans << '\n';
    return 0;
}

bool dfs(int v) {
    x[v] = true;
    for (int i = 1; i <= n; i++)
        if (!y[i] && fabs(a[v][i] - lx[v] - ly[i]) <= 0.00001) {
            y[i] = true;
            if (!my[i] || dfs(my[i])) {
                my[i] = v;
                return true;
            }
        }
    return false;
}

void adjust() {
    double d = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        if (x[i])
            for (int j = 1; j <= n; j++)
                if (!y[j])
                    d = std::min(d, a[i][j] - lx[i] - ly[j]);
    for (int i = 1; i <= n; i++) {
        if (x[i])
            lx[i] += d;
        if (y[i])
            ly[i] -= d;
    }
}

void km() {
    memset(ly, 0, sizeof(ly));
    memset(my, 0, sizeof(my));
    for (int i = 1; i <= n; i++) {
        lx[i] = 0x3f3f3f3f;
        for (int j = 1; j <= n; j++)
            lx[i] = std::min(lx[i], a[i][j]);
    }
    for (int i = 1; i <= n; i++)
        while (true) {
            memset(x, 0, sizeof(x));
            memset(y, 0, sizeof(y));
            if (dfs(i))
                break;
            adjust();
        }
}