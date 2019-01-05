// 1918.cpp
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

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    point ps[105];
    int n;
    long long ans = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> ps[i];
    for (int i = 1; i <= n - 2; i++)
        ans += ps[0].cross(ps[i], ps[i + 1]);
    std::cout << (ans >> 1) << '\n';
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