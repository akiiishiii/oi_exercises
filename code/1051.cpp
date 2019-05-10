// 1051.cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

struct student {
    std::string name;
    int avg = 0, cavg = 0, paper = 0, money = 0;
    bool np = false, west = false;
    void calc();
} stu[105];

struct comp : public std::binary_function<bool, student, student> {
    bool operator()(student const &s1, student const &s2) {
        return s1.money > s2.money;
    }
};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        char tmp;
        std::cin >> stu[i].name >> stu[i].avg >> stu[i].cavg;
        std::cin >> tmp;
        stu[i].np = (tmp == 'Y');
        std::cin >> tmp >> stu[i].paper;
        stu[i].west = (tmp == 'Y');
        stu[i].calc();
    }
    std::stable_sort(stu + 1, stu + n + 1, comp());
    std::cout << stu[1].name << '\n' << stu[1].money << '\n';
    int tot = 0;
    for (int i = 1; i <= n; i++)
        tot += stu[i].money;
    std::cout << tot << '\n';
    return 0;
}

void student::calc() {
    if (paper >= 1 && avg > 80)
        money += 8000;
    if (avg > 85 && cavg > 80)
        money += 4000;
    if (avg > 90)
        money += 2000;
    if (west && avg > 85)
        money += 1000;
    if (np && cavg > 80)
        money += 850;
}