// 1631.cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

struct country {
    int a;
    std::string dist;
    std::string name;
    country() = default;
    ~country() = default;
    country(int ma, std::string md, std::string mn) : a(ma), dist(md), name(mn) {}
    bool operator<(country const &c) const;
};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<country> vc;
    int tmp, sum = 0, i = 0;
    std::string tmpd, tmpn;
    while(std::cin >> tmp >> tmpd >> tmpn)
        vc.push_back(country(tmp, tmpd, tmpn)), sum += tmp;
    std::sort(vc.begin(), vc.end());
    for (int t = 0; i < vc.size(); i++) {
        t += vc[i].a;
        if (t >= (sum + 1) / 2)
            break;
    }
    std::cout << vc[i].name << '\n';
    return 0;
}

bool country::operator<(country const &c) const {
    int la = dist.length(), lb = c.dist.length();
    if (la < lb)
        return true;
    else if (la > lb)
        return false;
    else
        return dist < c.dist;
}