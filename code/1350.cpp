// 1350.cpp
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
    void chk(point &minn, int &k, int const &i);
    bool operator<(point const &p) const;
} standard;

inline bool addcross(point const &a, point const &b, point const &c, point const &d);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    point ps[1005], minn(0x3f3f3f3f, 0x3f3f3f3f);
    int n, k, l, t = 2, b[1005] = {0, 1, 2};
    double ans = 0.0;
    std::cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        std::cin >> ps[i];
        ps[i].chk(minn, k, i);
    }
    std::swap(ps[1], ps[k]);
    standard = ps[1];
    std::sort(ps + 2, ps + n + 1);
    for (int i = 3; i <= n; i++) {
        while (t > 1 && ps[b[t - 1]].cross(ps[b[t]], ps[i]) <= 0)
            t--;
        b[++t] = i;
    }
    b[++t] = b[1];
    for (int i = 2; i <= t; i++)
        ans += dist(ps[b[i]], ps[b[i - 1]]);
    std::cout << std::fixed << std::setprecision(0) << ans + 2 * 3.1415926535 * l << '\n';
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

void point::chk(point &minn, int &k, int const &i) {
    if ((minn.y > y) || ((minn.y == y) && (minn.x > x)))
        minn = *this, k = i;
}

bool point::operator<(point const &p) const {
    double c = standard.cross(*this, p);
    if (c > 0)
        return true;
    else if (!c)
        return dist(*this, standard) < dist(p, standard);
    else
        return false;
}

inline bool addcross(point const &a, point const &b, point const &c, point const &d) {
    return ((a.cross(c, d) * b.cross(c, d) < 0) && (c.cross(a, b) * d.cross(a, b) < 0));
}