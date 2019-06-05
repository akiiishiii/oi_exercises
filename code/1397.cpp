// 1397.cpp
#include <cstring>
#include <iostream>
#include <stack>

int sum[1000001], f[1000001];

inline int max(int const &a, int const &b) { return a > b ? a : b; }

int main(int const argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::stack<int> l, r;
    int Q, tmp;
    char c;
    while (std::cin >> Q) {
        while (Q--) {
            std::cin >> c;
            switch (c) {
            case 'I':
                std::cin >> tmp;
                l.push(tmp);
                sum[l.size()] = sum[l.size() - 1] + l.top();
                f[l.size()] = max(f[l.size() - 1], sum[l.size()]);
                break;
            case 'D':
                if (l.size())
                    l.pop();
                break;
            case 'L':
                if (l.size()) {
                    r.push(l.top());
                    l.pop();
                }
                break;
            case 'R':
                if (r.size()) {
                    l.push(r.top());
                    r.pop();
                    sum[l.size()] = sum[l.size() - 1] + l.top();
                    f[l.size()] = max(f[l.size() - 1], sum[l.size()]);
                }
                break;
            case 'Q':
                std::cin >> tmp;
                std::cout << f[tmp] << '\n';
                break;
            default:
                break;
            }
        }
    }
    return 0;
}