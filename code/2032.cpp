/*
ID: patrick103
TASK: gift1
LANG: C++14
*/
#include <iostream>
#include <string>
#include <map>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int np, m, ng, na;
    std::map<std::string, int> nps;
    std::string s, npp[11];
    std::cin >> np;
    for (int i = 0; i < np; i++)
        std::cin >> npp[i], nps[npp[i]] = 0;
    while (std::cin >> s) {
        std::cin >> m >> ng;
        na = m / ng;
        nps[s] -= m - (m - ng * na);
        for (int i = 0; i < ng; i++)
            std::cin >> s, nps[s] += na;
    }
    for (int i = 0; i < np; i++)
        std::cout << npp[i] << ' ' << nps[npp[i]] << '\n';
    return 0;
}