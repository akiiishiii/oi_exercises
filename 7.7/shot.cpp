// shot.cpp
#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, const char * argv[]) {
    std::ifstream fin("shot.in");
    std::ofstream fout("shot.out");

    int n;
    double h, hs[201] = {0}, ss[201] = {0}, tots = 0;
    fin >> h >> n;
    for (int i = 1; i <= n; i++)
        fin >> hs[i] >> ss[i];

    for (int i = 1; i <= n; i++) {
        tots += ss[i];
        if (hs[i] >= h)
            break;
    }

    fout << std::fixed << std::setprecision(1) << tots << std::endl;
    return 0;
}