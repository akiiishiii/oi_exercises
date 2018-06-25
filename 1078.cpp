#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
    std::vector<std::string> s;
    int n;
    std::cin >> n;
    s.resize(n);
    for (std::vector<std::string>::iterator it = s.begin(); it != s.end(); it++)
        std::cin >> *it;
    std::sort(s.begin(), s.end());
    for (std::vector<std::string>::iterator it = s.begin(); it != s.end(); it++)
        std::cout << *it << std::endl;
    return 0;
}