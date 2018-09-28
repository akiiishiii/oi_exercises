#include <iostream>
#include <cstring>
#include <fstream>

std::ofstream out("prime.txt");

// 线性筛法
int const MAX_N = 50001;
int v[MAX_N], prime[MAX_N];
int m;
void primes(int n) {
	memset(v, 0, sizeof(v)); // 最小质因子
	m = 0; // 质数数量
	for (int i = 2; i <= n; i++) {
		if (v[i] == 0) { // i是质数
			v[i] = i;
			prime[++m] = i;
		}
		// 给当前的数i乘上一个质因子
		for (int j = 1; j <= m; j++) {
			// i有比prime[j]更小的质因子，或者超出n的范围
			if (prime[j] > v[i] || prime[j] > n/i) break;
			// prime[j]是合数i*prime[j]的最小质因子
			v[i*prime[j]] = prime[j];
		}
	}
	for (int i = 1; i <= m; i++)
		out << prime[i] << ", ";
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    out << "int prime[] = {";
    primes(50000);
    out << "\b};\n";
    return 0;
}
