// count.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

int main(int argc, const char * argv[]) {
    std::ifstream fin("count.in");
    std::ofstream fout("count.out");

    int n, cnt = 0;
    bool ex[10001] = {false};
    std::vector<int> s;
    fin >> n;
    s.resize(n);
    for (std::vector<int>::iterator it = s.begin(); it != s.end(); it++)
        fin >> *it;

    std::sort(s.begin(), s.end());
    for (std::vector<int>::iterator it1 = s.begin(); it1 != s.end(); it1++)
        for (std::vector<int>::iterator it2 = it1 + 1; it2 != s.end(); it2++)
            if (std::binary_search(s.begin(), s.end(), *it1 + *it2) && !ex[*it1 + *it2]) {
                ex[*it1 + *it2] = true;
                cnt++;
            }

    fout << cnt << std::endl;
    return 0;
}
