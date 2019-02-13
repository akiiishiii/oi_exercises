// 1214.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

int main(int argc, const char * argv[]) {
    std::__cxx11::basic_string<char> s;
    bool nminus = true, varv = false;
    int temp = 0, a = 0, b = 0;
    char var;
    std::vector<int> ratioa, ratiob;
    std::cin >> s;
    __gnu_cxx::__normal_iterator<char *, std::__cxx11::basic_string<char>> eq = std::search_n(s.begin(), s.end(), 1, '=');
    for ( __gnu_cxx::__normal_iterator<char *, std::__cxx11::basic_string<char> > it = s.begin(); it != s.end(); it++) {
        if (it < eq) {
            if (*it == '+' || *it == '-') {
                ratiob.push_back(nminus ? temp : -temp);
                temp = 0;
                if (*it == '-')
                    nminus = false;
                else
                    nminus = true;
            } else if (*it >= '0' && *it <= '9')
                temp = 10 * temp + *it - '0';
            else {
                if (!varv) {
                    var = *it;
                    varv = true;
                }
                ratioa.push_back(nminus ? temp : -temp);
                nminus = true;
                temp = 0;
            }
        } else if (it > eq) {
            if (*it == '+' || *it == '-') {
                ratiob.push_back(nminus ? -temp : temp);
                temp = 0;
                if (*it == '-')
                    nminus = false;
                else
                    nminus = true;
            } else if (*it >= '0' && *it <= '9')
                temp = 10 * temp + *it - '0';
            else {
                ratioa.push_back(nminus ? -temp : temp);
                nminus = true;
                temp = 0;
            }
        } else {
            ratiob.push_back(nminus ? temp : -temp);
            temp = 0;
            nminus = true;
        }
    }
    for (std::vector<int>::iterator it = ratioa.begin(); it != ratioa.end(); it++)
        a += *it;
    for (std::vector<int>::iterator it = ratiob.begin(); it != ratiob.end(); it++)
        b += *it;
    std::cout << var << '=' << std::fixed << std::setprecision(3) << double(-b) / a << std::endl;
    return 0;
}