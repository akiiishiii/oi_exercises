// 1713_.cpp
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
    double cross(point const &a, point const &b) const;
    friend std::istream &operator>>(std::istream &is, point &p);
    friend void cut(point const &a, point const &b, int &n, point p[]);
    friend double atan2(point const &a, point const &b);
    friend point addcross(point const &a, point const &b, point const &c, point const &d, int &tmp, point q[]);
    friend class line;
};

class line {
  private:
    point a, b;
    double ang;
  public:
    line() = default;
    ~line() = default;
    line(point _a, point _b) : a(_a), b(_b) { ang = atan2(a, b); }
    bool operator<(line const &l) const;
    double operator-(line const &l) const { return ang - l.ang; }
    friend std::istream &operator>>(std::istream &is, line &l);
};

double const eps = 1e-8;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    point p[1005];
    line l[1005];
    int n, tmp = 1, lcnt = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> p[i];
    for (int i = 0; i < n - 1; i++)
        l[lcnt++] = line(p[i], p[i - 1]);
    l[lcnt++] = line(p[n - 1], p[0]);
    std::sort(l, l + lcnt);
    for (int i = 1; i < lcnt; i++)
        if (l[i] - l[i - 1] > eps)
            l[tmp++] = l[i];
    lcnt = tmp;
    return 0;
}

double point::cross(point const &a, point const &b) const {
    return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
}

std::istream &operator>>(std::istream &is, point &p) {
    is >> p.x >> p.y;
    return is;
}

double atan2(point const &a, point const &b) {
    return atan2(b.y - a.y, b.x - a.x);
}

point addcross(point const &a, point const &b, point const &c, point const &d, int &tmp, point q[]) {
    double c1 = fabs(a.cross(d, b)), c2 = fabs(a.cross(c, b));
    tmp++;
    return point((c1 * c.x + c2 * d.x) / (c1 + c2),
                 (c1 * c.y + c2 * d.y) / (c1 + c2));
}

bool line::operator<(line const &l) const {
    return (fabs(ang - l.ang) < eps) ?  (a.cross(l.a, l.b) < eps) : (ang < l.ang);
}

std::istream &operator>>(std::istream &is, line &l) {
    is >> l.a >> l.b;
    l.ang = atan2(l.a, l.b);
    return is;
}