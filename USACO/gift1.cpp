/*
ID: patrick103
TASK: gift1
LANG: C++14
*/
#include <fstream>
#include <string>
#include <map>

std::ifstream in("gift1.in");
std::ofstream out("gift1.out");

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int np, m, ng, na;
    std::map<std::string, int> nps;
    std::string s, npp[11];
    in >> np;
    for (int i = 0; i < np; i++)
        in >> npp[i], nps[npp[i]] = 0;
    while (in >> s) {
        in >> m >> ng;
        na = m / ng;
        nps[s] -= m - (m - ng * na);
        for (int i = 0; i < ng; i++)
            in >> s, nps[s] += na;
    }
    for (int i = 0; i < np; i++)
        out << npp[i] << ' ' << nps[npp[i]] << '\n';
    return 0;
}