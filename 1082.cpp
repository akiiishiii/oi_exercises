// 1082.cpp
#include <iostream>
#include <bitset>
#include <string>
 
int main(int argc, const char * argv[]) {
    int n;
    bool flag = false;
    std::cin >> n;
    std::bitset<16> num(n);
    std::string snum = num.to_string();
    for (int i = 0; i < snum.length(); i++)
        if (!flag) {
            if (snum[i] == '1') {
                flag = true;
                std::cout << snum[i];
            }
        } else
            std::cout << snum[i];
    std::cout << std::endl;
    return 0;
}
