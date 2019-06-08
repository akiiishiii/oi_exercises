// 1941.cpp
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

struct function {
    int a, b, c;
    function() = default;
    ~function() = default;
    function(int ma, int mb, int mc) : a(ma), b(mb), c(mc) {}
    long long operator()(const int x) const { return a * x * x + b * x + c; }
};

struct value {
    function f;
    int x;
    value() = default;
    ~value() = default;
    value(int ma, int mb, int mc, int xx);
    long long val() const { return f(x); }
    value operator+(const int n) const;
    bool operator>(const value &v) const { return val() > v.val(); }
};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n;
    std::priority_queue<value, std::vector<value>, std::greater<value>> q;
    std::cin >> n >> m;
    for (int i = 0, ta, tb, tc; i < n; i++) {
        std::cin >> ta >> tb >> tc;
        q.push(value(ta, tb, tc, 1));
    }
    for (int i = 0; i < m; i++) {
        std::cout << q.top().val() << ' ';
        q.push(q.top() + 1);
        q.pop();
    }
    std::cout << '\n';
    return 0;
}

value::value(int ma, int mb, int mc, int xx) : x(xx) {
    f = function(ma, mb, mc);
}

value value::operator+(const int n) const {
    value sum = *this;
    sum.x += n;
    return sum;
}