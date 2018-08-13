// 1502.cpp
#include <iostream>
#include <functional>
#include <algorithm>
#include <utility>
#include <vector>

struct compSmaller : public std::binary_function<std::pair<int, int>, std::pair<int, int>, bool> {
    bool operator()(std::pair<int, int> const &a, std::pair<int, int> const &b) { return a.first == b.first ? a.second < b.second : a.first < b.first; }
};

double const bypass = 141.4;

int main(int argc, char const *argv[]) {
    int n, m, k, f[10100] = {0}, maxn = 0;
    std::vector<std::pair<int, int> > arr;
    arr.push_back(std::make_pair(0, 0));
    std::cin >> n >> m >> k;
    for (int i = 0, nx, ny; i < k; i++) {
        std::cin >> nx >> ny;
        arr.push_back(std::make_pair(nx, ny));
    }
    std::sort(arr.begin(), arr.end(), compSmaller());
    for (int i = 1; i < arr.size(); i++)
        for (int j = 0; j < i; j++)
            if (arr[j].second < arr[i].second && arr[j].first < arr[i].first && f[j] < f[i] + 1)
                f[i] = f[j] + 1;
    for (int i = 1; i <= n; i++)
        maxn = f[i] > maxn ? f[i] : maxn;
    std::cout << (n + m - maxn * 2) * 100LL + (long long)(maxn * bypass + 0.5);
    return 0;
}
