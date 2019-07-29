// complexity.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <string>
#include <stack>

//#define debug

#ifndef debug

std::ifstream in("complexity.in");
std::ofstream out("complexity.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

bool hash[128];
char alps[101];
int f[101];

bool chkcom(int res, std::string com);
bool operator>(std::string const &x, std::string const &y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int T, l, ans, tot, mark;
    bool unexe, error;
    std::string com;
    char ord;
    in >> T;
    while (T--) {
        memset(alps, 0, sizeof alps);
        memset(f, 0, sizeof f);
        memset(hash, false, sizeof hash);
        ans = tot = mark = 0;
        unexe = error = false;
        in >> l >> com;
        while (l--) {
            in >> ord;
            if (ord == 'F') {
                char i;
                std::string x, y;
                in >> i >> x >> y;
                if (hash[i])
                    error = true;
                else {
                    alps[++tot] = i;
                    hash[i] = true;
                }
                if (!unexe) {
                    if (x != "n" && y == "n") {
                        f[tot] = f[tot - 1] + 1;
                        ans = std::max(ans, f[tot]);
                    } else if (x > y) {
                        unexe = true;
                        mark = tot;
                    } else
                        f[tot] = f[tot - 1];
                }
            } else {
                if(tot == mark)
                    unexe = false;
                hash[alps[tot--]] = false;
            }
        }
        if (error || tot)
            out << "ERR" << '\n';
        else if ((ans && chkcom(ans, com)) || (!ans && com[2] == '1'))
            out << "Yes" << '\n';
        else
            out << "No" << '\n';
    }
	return 0;
}

bool chkcom(int res, std::string com) {
    for (std::string::iterator it = com.end() - 2; it >= com.begin() + 4; it--, res /= 10)
        if ((*it)- '0' != res % 10)
            return false;
    return true;
}

bool operator>(std::string const &x, std::string const &y) {
    if(x == "n" && y != "n")
        return true;
    if(x.length() > y.length())
        return true;
    if(x.length() < y.length())
        return false;
    for(int i = 0; i < x.length(); i++) {
        if(x[i] > y[i])
            return true;
        if(x[i] < y[i])
            return false;
    }
    return false;
}
