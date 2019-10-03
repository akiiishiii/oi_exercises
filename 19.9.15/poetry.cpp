// poetry.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("poetry.in");
std::ofstream out("poetry.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long const Mod = 1000000007, Maxn = 5005;
long long f[Maxn], cnt[Maxn], s[Maxn], c[Maxn], num[105];
long long ans = 1;
int n, m, k;
char e[2];

long long power(long long a,long long b);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
	in >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		in >> s[i] >> c[i];
	for (int i = 1; i <= m; i++)
		in >> e, num[e[0]-'A']++;
	f[0] = 1;
	for (int i = 1; i < k; i++)
		for (int j = 1; j <= n; j++) {
			if (s[j] > i)
				continue;
			f[i] = (f[i] + f[i - s[j]]) % Mod;
		}
	for (int i = 1; i <= n; i++)
		cnt[c[i]] = (cnt[c[i]] + f[k-s[i]]) % Mod;
	for (int i = 0; i < 26; i++) {
		if (!num[i])
			continue;
		long long sum = 0;
		for (int j = 1; j <= n; j++)
			if (cnt[j])
				sum = (sum + power(cnt[j], num[i])) % Mod;
		ans = (ans * sum) % Mod;
	}
	out << ans << '\n';
    return 0;
}

long long power(long long a,long long b) {
	long long ans = 1;
	while (b) {
		if (b & 1)
			ans = ans * a % Mod;
		a = a * a % Mod;
		b >>= 1;
	}
	return ans;
}
