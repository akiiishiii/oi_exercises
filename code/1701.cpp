// 1701.cpp
#include <iostream>

class point {
  private:
    int x, y;
  public:
    point() = default;
    ~point() = default;
    point(int _x, int _y) : x(_x), y(_y) {}
    inline long long cross(point const &a, point const &b) const;
    friend std::istream &operator>>(std::istream &is, point &p);
};

inline bool addcross(point const &a, point const &b, point const &c, point const &d);
bool chk(point a[], int b[], int k, int x);
void dfs(point a[], bool vis[], int b[], int dep, int const &n, int &ans);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    point a[11] = {point()};
    int b[11] = {0}, n = 0, ans = 0;
    bool vis[11] = {false};
    while (std::cin >> a[++n]);
    n--;
    vis[1] = true;
    b[1] = 1;
    dfs(a, vis, b, 2, n, ans);
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

inline bool addcross(point const &a, point const &b, point const &c, point const &d) {
    return ((a.cross(c, d) * b.cross(c, d) < 0) && (c.cross(a, b) * d.cross(a, b) < 0));
}

bool chk(point a[], int b[], int k, int x) {
    for (int i = 1; i <= k - 2; i++)
        if (addcross(a[b[i]], a[b[i + 1]], a[b[k - 1]], a[x]))
            return false;
    return true;
}

void dfs(point a[], bool vis[], int b[], int dep, int const &n, int &ans) {
    if (dep == n + 1) {
        if (chk(a, b, dep, 1))
            ans++;
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (!vis[i] && chk(a, b, dep, i)) {
            vis[i] = true;
            b[dep] = i;
            dfs(a, vis, b, dep + 1, n, ans);
            vis[i] = false;
        }
    }
}