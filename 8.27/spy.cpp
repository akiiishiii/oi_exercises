// spy.cpp
#include <iostream>
#include <fstream>
#include <string>

//#define debug

#ifndef debug

std::ifstream in("spy.in");
std::ofstream out("spy.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    std::string a, b, c;
    bool mark[26] = {false};
    char key[26] = {'\0'};
    in >> a >> b >> c;
    for (int i = 0; i < a.length(); i++)
        if (!mark[a[i] - 'A']) {
            key[a[i] - 'A'] = b[i];
            mark[a[i] - 'A'] = true;
        } else
            if (key[a[i] - 'A'] != b[i]) {
                out << "Failed\n";
                return 0;
            }
    for (int i = 0; i < 26; i++)
        if (!mark[i]) {
            out << "Failed\n";
            return 0;
        }
    for (int i = 0; i < c.length(); i++)
        out.put(key[c[i] - 'A']);
    out.put('\n');
    return 0;
}
