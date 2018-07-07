// sum.cpp
#include <iostream>
#include <fstream>

bool isprime(int t);
void dfs(int step, int sum, int cnt);

int n, k, num[21] = {0}, tot = 0;
bool vi[21] = {false}, has[20000] = {false};

int main(int argc, const char *argv[]) {
    std::ifstream fin("sum.in");
    std::ofstream fout("sum.out");

    fin >> n >> k;
    for (int i = 0; i < n; i++)
        fin >> num[i];

    dfs(1, 0, 0);
    fout << tot << std::endl;
    return 0;
}

bool isprime(int num) {
    for (int i = 2; i * i <= num; i++)
        if (!(num % i))
            return false;
    return true;
}

void dfs(int step, int sum, int cnt) {
    if (step == n + 1 || cnt == k) {
        if (isprime(sum) && cnt == k)
            tot++;
        return;
    }
    dfs(step + 1, sum + num[step], cnt + 1);
    dfs(step + 1, sum, cnt);
}