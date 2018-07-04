// 1323.cpp
#include <iostream>
#include <algorithm>
#include <map>

int main(int argc, const char * argv[]) {
    int n;
    std::map<int, int> m;
    std::cin >> n;
    for (int i = 0, temp; i < n; i++) {
        std::cin >> temp;
        m[temp]++;
    }
    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        std::cout << (*it).first << ' ' << (*it).second << std::endl;
    }
    return 0;
}