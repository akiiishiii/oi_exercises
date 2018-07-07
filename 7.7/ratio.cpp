// ratio.cpp
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

int gcd(int a, int b) { return a % b ? gcd(b, a % b) : b; }

int main(int argc, const char * argv[]) {
    std::ifstream fin("ratio.in");
    std::ofstream fout("ratio.out");

    int a, b, l;
    std::vector<double> res;
    std::map<double, std::pair<int, int> > p;
    fin >> a >> b >> l;

    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= l; j++)
            if (gcd(i, j) == 1 && double(i) / j >= double(a) / b) {
                double temp = double(i) / j - double(a) / b;
                res.push_back(temp);
                p[temp] = std::make_pair(i, j);
            }
    std::sort(res.begin(), res.end());

    fout << p[res.front()].first << ' ' << p[res.front()].second << std::endl;
    return 0;
}