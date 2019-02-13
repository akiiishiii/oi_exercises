// 1472.cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

std::vector<std::pair<std::string, int> > ss;

int binary_search(int l, int r, std::string x);

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m, temp, jlys, ans = 1;
    std::string s;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        ss.push_back(std::make_pair(s, 0));
    }
    std::sort(ss.begin(), ss.end());
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        for (int i = 0; i < n; i++) {
            std::cin >> temp >> s;
            ss[binary_search(0, n - 1, s)].second += temp;
        }
        jlys = ss[binary_search(0, n - 1, "JLY")].second;
        ans = 1;
        for (std::vector<std::pair<std::string, int> >::iterator it = ss.begin(); it != ss.end(); it++)
            if (it -> second > jlys)
                ans++;
        std::cout << ans << '\n';
    }

    return 0;
}

int binary_search(int l, int r, std::string x) {
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (ss[mid].first == x)
            return mid;
        else if (ss[mid].first > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}