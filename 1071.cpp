// 1071.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(int argc, const char * argv[]) {
    int n;
    std::vector<int> a, b;
    std::cin >> n;
    a.resize(n);
    b.resize(n - 1);
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
        std::cin >> *it;
    for (int i = 0; i < n - 1; i++)
        b[i] = abs(a[i + 1] - a[i]);
    std::sort(b.begin(), b.end());
    for (int i = 0; i < n - 1; i++)
        if (b[i] != i + 1) {
            std::cout << "Not jolly\n";
            return 0;
        }
    std::cout << "Jolly\n";
    return 0;
}
