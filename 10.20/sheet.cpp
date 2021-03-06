// sheet.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define debug

#ifndef debug

std::ifstream in("sheet.in");
std::ofstream out("sheet.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

struct student {
    std::string name;
    int score = 0;
    int sheet[101] = {0};
    bool operator<(student const &s) const { return ((score == s.score) ? (name < s.name) : (score > s.score)); }
} vs[101];

struct answer {
    int full, half;
    int ans = 0;
} va[101];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    std::string s;
    int n, m;
    in >> n >> m;
    for (int i = 0; i < n; i++)
        in >> vs[i].name;
    for (int i = 0; i < m; i++) {
        in >> va[i].full >> va[i].half >> s;
        for (int j = 0; j < s.length(); j++)
            va[i].ans |= (1 << (int(s[j]) - 65));
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 4; k++) {
            in >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] == 'X')
                    vs[i].sheet[j] |= (1 << k);
            }
        }
        for (int j = 0; j < m; j++)
            if (vs[i].sheet[j] == va[j].ans)
                vs[i].score += va[j].full;
            else if (vs[i].sheet[j] && ((vs[i].sheet[j] | va[j].ans) == va[j].ans))
                vs[i].score += va[j].half;
    }
    std::sort(vs, vs + n);
    for (int i = 0; i < n; i++)
        out << vs[i].name << ' ' << vs[i].score << '\n';
    return 0;
}