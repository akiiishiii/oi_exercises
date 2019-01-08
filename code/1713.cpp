// 1713.cpp
#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>

class point {
  private:
    double x, y;
  public:
    point() = default;
    ~point() = default;
    point(double _x, double _y) : x(_x), y(_y) {}
    inline double cross(point const &a, point const &b) const;
    friend std::istream &operator>>(std::istream &is, point &p);
    friend double dist(point const &a, point const &b);
    friend void cut(point const &a, point const &b, int &n, point p[]);
    friend void addcross(point const &a, point const &b, point const &c, point const &d, int &tmp, point q[]);
};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    point ps[1005], a, b, c, o(0.0, 0.0);
    int k, n, m;
    double ans = 0.0;
    std::cin >> k >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> ps[i];
    for (int t = 1; t < k; t++) {
        std::cin >> m >> a, c = a;
        for (int i = 2; i <= m; i++) {
            std::cin >> b;
            cut(a, b, n, ps);
            a = b;
        }
        cut(a, c, n, ps);
    }
    ps[n + 1] = ps[1];
    for (int i = 1; i <= n; i++)
        ans += o.cross(ps[i], ps[i + 1]);
    std::cout << std::fixed << std::setprecision(3) << (fabs(ans) / 2.0) << '\n';
    return 0;
}

inline double point::cross(point const &a, point const &b) const {
    return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
}

std::istream &operator>>(std::istream &is, point &p) {
    is >> p.x >> p.y;
    return is;
}

double dist(point const &a, point const &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void cut(point const &a, point const &b, int &n, point p[]) {
    int tmp = 0;
    point q[1005];
    p[n + 1] = p[1];
    for (int i = 2; i <= n + 1; i++)
        if (a.cross(p[i - 1], b) <= 0) {
            q[++tmp] = p[i - 1];
            if (a.cross(p[i], b) > 0)
                addcross(a, b, p[i - 1], p[i], tmp, q);
        } else if (a.cross(p[i], b) < 0)
            addcross(a, b, p[i - 1], p[i], tmp, q);
    for (int i = 1; i <= tmp; i++)
        p[i] = q[i];
    n = tmp;
}

void addcross(point const &a, point const &b, point const &c, point const &d, int &tmp, point q[]) {
    double c1 = fabs(a.cross(d, b)), c2 = fabs(a.cross(c, b));
    tmp++;
    q[tmp] = point((c1 * c.x + c2 * d.x) / (c1 + c2),
                   (c1 * c.y + c2 * d.y) / (c1 + c2));
}