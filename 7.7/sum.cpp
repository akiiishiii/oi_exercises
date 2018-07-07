// sum.cpp
#include <iostream>
#include <fstream>

void dfs(int num);
bool isprime(int t);

int dfs(int csum, int asum, int l, int r);

int n, k, num[21] = {0}, tot = 0, cnt = 0;
bool vi[21] = {false}, has[20000] = {false};

int main(int argc, const char *argv[]) {
    std::ifstream fin("sum.in");
    std::ofstream fout("sum.out");

    fin >> n >> k;
    for (int i = 0; i < n; i++)
        fin >> num[i];

    fout << dfs(k, 0, 0, n - 1) << std::endl;
    return 0;
}

bool isprime(int num) {
    for (int i = 2; i * i <= num; i++)
        if (!(num % i))
            return false;
    return true;
}

int dfs(int csum, int asum, int l, int r) {
    if (csum == 0)
        return isprime(asum);
    int sum = 0;
    for (int i = l; i <= r; i++)
        sum += dfs(csum - 1, asum + num[i], i + 1, r);
    return sum;
}