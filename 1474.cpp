// 1474.cpp
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

struct point {
    double x;
    double y;
    bool operator<(const point & p) const { return x < p.x; }
} arr[60005], tmp[60005];

template <typename T>
T abs(T const & t) { return t < 0 ? -t : t; }
std::istream & operator>>(std::istream & is, point & p);
bool comp(const point & a, const point & b) { return a.y < b.y; }
inline double dist2(const point & a, const point & b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }
double find(int l, int r);

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> arr[i];
    std::sort(arr + 1, arr + n + 1);
    std::cout << std::fixed << std::setprecision(2) << sqrt(find(1, n)) << '\n';
    return 0;
}

std::istream & operator>>(std::istream & is, point & p) {
    is >> p.x >> p.y;
    return is;
}

double find(int l, int r) {
    if (l == r)
        return 1E20;
    else if (r - l == 1)
        return dist2(arr[l], arr[r]);
    int mid = (l + r) / 2, tot = 0;
    double t = find(mid + 1, r), ans = find(l, mid), xp = (arr[mid].x + arr[mid + 1].x) / 2;
    mid = mid > xp ? mid : xp;
    for (int i = l; i <= r; i++)
        if (abs(arr[i].x - xp) < ans) {
            tot++;
            tmp[tot].x = arr[i].x;
            tmp[tot].y = arr[i].y;
        }
    if (tot > 1)
        std::sort(tmp + 1, tmp + tot + 1, comp);
    for (int i = 1; i < tot; i++)
        for (int j = i + 1; j <= i + 8; j++) {
            if (j > tot)
                break;
            t = dist2(tmp[i], tmp[j]);
            ans = t < ans ? t : ans;
        }
    return ans;
}