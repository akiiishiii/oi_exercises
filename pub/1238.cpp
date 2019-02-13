// 1238.cpp
#include <iostream>

unsigned Ack(unsigned m, unsigned n);

int main(int argc, const char * argv[]) {
    unsigned m, n;
    std::cin >> m >> n;
    std::cout << Ack(m, n) << std::endl;
}

unsigned Ack(unsigned m, unsigned n) {
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return Ack(m - 1, 1);
    else
        return Ack(m - 1, Ack(m, n - 1));
}