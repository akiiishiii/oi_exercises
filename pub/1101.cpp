// 1101.cpp
#include <iostream>
#include <cmath>

long long Reverse(long long num);

int main(int argc, const char * argv[]) {
    long long num,cnt = 0;
    std::cin >> num;
    bool flag = false;
    while (log10(num) <= 15){
        if (num == Reverse(num)) {
            flag = true;
            break;
        } else {
            num += Reverse(num);
            cnt++;
        }
    }
    if (flag)
        std::cout << cnt;
    else
        std::cout << "Fail!";
    std::cout << std::endl;
    return 0;
}

long long Reverse(long long num) {
    long long dig, len = log10(num);
    long long renum = 0;
    while (num) {
        dig = num % 10;
        long long pro = 1;
        for (int i = 0; i != len; ++i)
            pro *= 10;
        renum += dig * pro;
        num /= 10;
        len--;
    }
    return renum;
}