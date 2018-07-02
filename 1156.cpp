// 1156.cpp
#include <iostream>
#include <fstream>
#include <vector>

struct block{
    int color, num;
};

long long solve(std::vector<block>::iterator x, std::vector<block>::iterator z, std::vector<block> & b);

int main(int argc, const char * argv[]) {
    int m, n, temp;
    long long tot = 0L;
    std::vector<block> bls;
    std::cin >> n >> m;
    bls.resize(n);

    for (std::vector<block>::iterator it = bls.begin(); it != bls.end(); it++) {
        std::cin >> temp;
        it -> num = temp;
    }
    for (std::vector<block>::iterator it = bls.begin(); it != bls.end(); it++) {
        std::cin >> temp;
        it -> color = temp;
    }

    for (std::vector<block>::iterator it = bls.begin(); it != bls.end(); it++)
        for (std::vector<block>::iterator ite = it + 2; ite < bls.end(); ite += 2) {
            temp = solve(it, ite, bls);
            tot = (tot % 10007 + temp % 10007) % 10007;
        }

    tot %= 10007;
    std::cout << tot;
    return 0;
}

long long solve(std::vector<block>::iterator x, std::vector<block>::iterator z, std::vector<block> & b) {
    int _x = int(x - b.begin()) + 1;
    int _z = int(z - b.begin()) + 1;
    if ((x -> color == z -> color) && !((z - x) % 2))
        return ((((_x + _z) % 10007) * ((x -> num + z -> num) % 10007)) % 10007);
    else
        return 0L;
}
