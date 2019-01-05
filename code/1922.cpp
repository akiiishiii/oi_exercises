// 1701.cpp
#include <iostream>
#include <iomanip>
#include <cmath>

class point {
  private:
    int x, y;
  public:
    point() = default;
    ~point() = default;
    point(int _x, int _y) : x(_x), y(_y) {}
    inline long long cross(point const &a, point const &b) const;
    friend std::istream &operator>>(std::istream &is, point &p);
    friend double calc(point const &a, point const &b);
};

inline bool addcross(point const &a, point const &b, point const &c, point const &d);
int prim(double &ans, int const &n, double map[201][201]);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    point a[201], b[201][2];
    double map[201][201], ans = 0;
    int n, m;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::cin >> m;
    for (int i = 1; i <= m; i++)
        std::cin >> b[i][0] >> b[i][1];
    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++) {
            bool chk = true;
            for (int k = 1; k <= m; k++)
                if (addcross(a[i], a[j], b[k][0], b[k][1])) {
                    map[i][j] = map[j][i] = 0x3f3f3f3f;
                    chk = false;
                    break;
                }
            if (chk)
                map[i][j] = map[j][i] = calc(a[i], a[j]);
        }
    std::cout << std::fixed << std::setprecision(3) << (prim(ans, n, map) ? ans : -1) << '\n';
    return 0;
}

inline long long point::cross(point const &a, point const &b) const {
    return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
}

std::istream &operator>>(std::istream &is, point &p) {
    is >> p.x >> p.y;
    return is;
}

double calc(point const &a, point const &b) {
    return sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline bool addcross(point const &a, point const &b, point const &c, point const &d) {
    return ((a.cross(c, d) * b.cross(c, d) < 0) && (c.cross(a, b) * d.cross(a, b) < 0));
}

int prim(double &ans, int const &n, double map[201][201]) {
    int vis[201] = {0};
    double minn, d[201];
    for (int i = 1; i <= n; i++)
        d[i] = 0x3f3f3f3f;
    d[1] = 0;
    for (int i = 1, k; i <= n; i++) {
        minn = 0x3f3f3f3f;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && d[j] < minn) {
                minn = d[j];
                k = j;
            }
        if (minn == 0x3f3f3f3f)
            return false;
        vis[k] = 1;
        ans += minn;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && map[k][j] < d[j])
                d[j] = map[k][j];
    }
    return true;
}