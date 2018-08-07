// 1562.cpp
#include <iostream>
#include <vector>

int nthUglyNumber(int n);

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::cout << nthUglyNumber(n) << '\n';
    return 0;
}


int nthUglyNumber(int n) {
    int p2 = 0;
    int p3 = 0;
    int p5 = 0;
    int p7 = 0;
    std::vector<int> ugly;
    ugly.push_back(1);
    int count = 1;
    while (count < n) {
        int ugly2 = ugly[p2] * 2;
        int ugly3 = ugly[p3] * 3;
        int ugly5 = ugly[p5] * 5;
        int ugly7 = ugly[p7] * 7;
        if (ugly2 <= ugly3 && ugly2 <= ugly5 && ugly2 <= ugly7) {
            ++p2;
            if(ugly2 == ugly[count - 1])
                continue;
            ugly.push_back(ugly2);
        } else if (ugly3 <= ugly2 && ugly3 <= ugly5 && ugly3 <= ugly7){
            ++p3;
            if (ugly3 == ugly[count - 1])
                continue;
            ugly.push_back(ugly3);
        } else if (ugly5 <= ugly2 && ugly5 <= ugly3 && ugly5 <= ugly7) {
            ++p5;
            if(ugly5 == ugly[count - 1])
                continue;
            ugly.push_back(ugly5);
        } else {
            ++p7;
            if(ugly7 == ugly[count - 1])
                continue;
            ugly.push_back(ugly7);
        }
        //std::cout << ugly[count - 1] << '\n';
        ++count;
    }
    return ugly[n-1];
}