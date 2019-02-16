// 2693.cpp
#include <string>
#include <iostream>
#include <queue>

struct status {
    int l, r, p;
    status() = default;
    ~status() = default;
    status(int _l, int _r, int _p) : l(_l), r(_r), p(_p) {}
};

int const Maxn = 100010;
int n, l, p;
long double f[Maxn], s[Maxn];
std::string str;
std::deque<status> q;

long double qpow(long double x, int y);
inline long double calc(int i, int j);
long double binary_search(status x, int y);
template <typename T> inline T abs(T const t) { return t > 0 ? t : -t; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        while (q.size())
            q.pop_back();
        std::cin >> n >> l >> p;
        for (int i = 1; i <= n; i++)
            std::cin >> str, s[i] = s[i - 1] + str.length();
        q.push_back(status(0, n, 0));
        for (int i = 1; i <= n; i++) {
            if (q.size() && i > q.front().r)
                q.pop_front();
            f[i] = calc(q.front().p, i);
            if (q.empty() || calc(i, n) <= calc(q.back().p, n)) {
                while (q.size() && calc(i, q.back().l) <= calc(q.back().p, q.back().l))
                    q.pop_back();
                if (q.empty())
                    q.push_back(status(i, n, i));
                else {
                    int pos = binary_search(q.back(), i);
                    q.back().r = pos - 1;
                    q.push_back(status(pos, n, i));
                }
            }
        }
        if (f[n] > 1e18)
            std::cout << "Too hard to arrange\n";
        else
            std::cout << (long long)f[n] << '\n';
    }
    return 0;
}

long double qpow(long double x, int y) {
    long double ret = 1;
    while (y) {
        if (y & 1)
            ret = ret * x;
        x = x * x;
        y >>= 1;
    }
    return ret;
}

inline long double calc(int i, int j) {
    return f[i] + qpow(/*std*/::abs((long double)(s[j] - s[i] + (j - i - 1) - l)), p);
}

long double binary_search(status x, int y) {
    int l = x.l, r = x.r, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (calc(x.p, mid) < calc(y, mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}