// 2460.cpp
#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int minn = 0x3f3f3f3f, maxx = 0xcfcfcfcf, n, tmp;
    std::cin >> n;
    while (n--) {
        std::cin >> tmp;
        minn = std::min(tmp, minn);
        maxx = std::max(tmp, maxx);
    }
    std::cout << maxx << ' ' << minn << '\n';
    return 0;
}
