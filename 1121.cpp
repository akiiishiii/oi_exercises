// 1121.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct subject {
    int deadline;
    int cut;
};

struct compare : public std::binary_function<subject, subject, bool> {
    bool operator()(subject const &a, subject const &b) { return a.cut > b.cut; }
};

int main(int argc, char const *argv[]) {
    std::vector<subject> vs;
    bool timetaken[505] = {false};
    int m, n, cuttot = 0;
    std::cin >> m >> n;
    vs.resize(n);
    for (std::vector<subject>::iterator it = vs.begin(); it != vs.end(); it++) {
        std::cin >> (*it).deadline;
    }
    for (std::vector<subject>::iterator it = vs.begin(); it != vs.end(); it++) {
        std::cin >> (*it).cut;
    }
    std::sort(vs.begin(), vs.end(), compare());
    for (std::vector<subject>::iterator it = vs.begin(); it != vs.end(); it++) {
        bool solve = false;
        for (int i = (*it).deadline - 1; i >= 0; i--)
            if (!timetaken[i]) {
                timetaken[i] = true;
                solve = true;
                break;
            }
        if (solve)
            continue;
        for (int i = n - 1; i >= 0; i--)
            if (!timetaken[i]) {
                timetaken[i] = true;
                break;
            }
        cuttot += (*it).cut;
    }
    std::cout << m - cuttot << '\n';
    return 0;
}
