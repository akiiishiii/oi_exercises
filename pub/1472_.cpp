// 1472_.cpp
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

class CmpByValue {
public:
    bool operator()(std::pair<std::string, int> const & lhs, std::pair<std::string, int> const & rhs) {
        return lhs.second > rhs.second;
    }
};

int main(int argc, char const * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::map<std::string, int> cls;
    std::string s;
    int n, m, temp;
    for (int i = 0; i < n; i++)
        std::cin >> s;
    std::cin >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> s >> temp;
        cls.insert(std::make_pair(s, temp));
    }
    for (int i = 1; i < m; i++)
        for (int i = 0; i < n; i++) {
            std::cin >> s >> temp;
            cls[s] += temp;
        }
    std::sort(cls.begin(), cls.end(), CmpByValue());
    std::cout << cls.find("JLY") - cls.begin() << '\n';
    return 0;
}
