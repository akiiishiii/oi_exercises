// 5250.cpp
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
    friend double atan2(point const &a, point const &b);
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
    point operator*(line const &l) const;
    friend std::istream &operator>>(std::istream &is, line &l);
    friend bool chk(line const &l1, line const &l2, line const &l3);
};

double const eps = 1e-8;
point a[20005];
line l[20005];
int dq[20005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int tmp = 1, n = 0, head = 1, tail = 0, acnt = 0;
    double ans = 0.0;
    point o(0, 0);
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> l[i];
    l[n++] = line(point(0, 10000), point(-10000, 0));
    l[n++] = line(point(0, 0), point(10000, 0));
    l[n++] = line(point(0, 0), point(0, -10000));
    l[n++] = line(point(10000, 0), point(0, 10000));
    std::sort(l, l + n);
    for (int i = 1; i < n; i++)
        if (l[i] - l[i - 1] > eps)
            l[tmp++] = l[i];
    n = tmp;
    dq[0] = 0, dq[1] = 1;
    for (int i = 2; i < n; i++) {
        while (tail < head && chk(l[i], l[dq[head - 1]], l[dq[head]]))
            head--;
        while (tail < head && chk(l[i], l[dq[tail + 1]], l[dq[tail]]))
            tail++;
        dq[++head] = i;
    }
    while (tail < head && chk(dq[tail], l[dq[head - 1]], l[dq[head]]))
        head--;
    while (tail < head && chk(dq[head], l[dq[tail + 1]], l[dq[tail]]))
        tail++;
    dq[--tail] = dq[head];
    for (int i = tail + 1; i <= head; i++)
        a[++acnt] = l[dq[i - 1]] * l[dq[i]];
    a[acnt + 1] = a[1];
    for (int i = 1; i <= acnt; i++)
        ans += o.cross(a[i], a[i + 1]);
    std::cout << std::fixed << std::setprecision(1) << fabs(ans) / 2
              << '\n';
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

point line::operator*(line const &l) const {
    double d1 = fabs(l.a.cross(b, a)), d2 = fabs(b.cross(l.b, a));
    return point((d2 * l.a.x + d1 * l.b.x) / (d1 + d2),
                 (d2 * l.a.y + d1 * l.b.y) / (d1 + d2));
}

bool line::operator<(line const &l) const {
    return (fabs(ang - l.ang) < eps) ?  (a.cross(l.a, l.b) > eps) : (ang < l.ang);
}

std::istream &operator>>(std::istream &is, line &l) {
    is >> l.a >> l.b;
    l.ang = atan2(l.a, l.b);
    return is;
}

bool chk(line const &l1, line const &l2, line const &l3) {
    return point(l2 * l3).cross(l1.a, l1.b) < -eps;
}