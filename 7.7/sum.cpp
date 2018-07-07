// sum.cpp
#include <iostream>
#include <fstream>

void dfs(int num);
bool chkprime(int t);

int n, k, num[21] = {0}, tot = 0, cnt = 0;
bool vi[21] = {false}, has[20000] = {false};

int main(int argc, const char *argv[]) {
    std::ifstream fin("sum.in");
    std::ofstream fout("sum.out");

    fin >> n >> k;
    for (int i = 1; i <= n; i++)
        fin >> num[i];

    dfs(1);

    fout << cnt << std::endl;
    return 0;
}

void dfs(int t) {
    if (t > k) {
        if (chkprime(tot) && !has[tot]) {
            cnt++;
            has[tot] = true;
        }
        return;
    } else
        for (int i = 1; i <= n; i++)
            if (!vi[i]) {
                vi[i] = true;
                tot += num[i];
                dfs(t + 1);
                tot -= num[i];
                vi[i] = false;
            }
}

bool chkprime(int num) {
    for (int i = 2; i * i <= num; i++)
        if (!(num % i))
            return false;
    return true;
}