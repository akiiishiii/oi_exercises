// 1058.cpp
#include <iostream>
#include <cmath>

int main(int argc, const char * argv[]) {
    for (int i = 1; i <= 10000; i++) {
        int a = 0, temp = i;
        while (temp) {
            a += pow(temp % 10, 3);
            temp /= 10;
        }
        if (a == i)
            std::cout << i << '\n';
    }
    return 0;
}
