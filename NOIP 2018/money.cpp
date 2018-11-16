// money.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

//#define debug

#ifndef debug

std::ifstream in("money.in");
std::ofstream out("money.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, ans = 0;
int a[105];
bool v[105] = {false};

bool chk(int a, int b, int c);
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	
	int T;
	in >> T;
	
	while (T--) {
		memset(a, 0, sizeof(a));
		memset(v, false, sizeof(v));
		in >> n;
		for (int i = 1; i <= n; i++)
			in >> a[i];
		
		std::sort(a + 1, a + n + 1);
		
		if (n == 1) {
			ans = 1;
		} else if (n == 2) {
			int g = gcd(a[1], a[2]);
			ans = (g == a[1] || g == a[2]) ? 1 : 2;
		} else {
			ans = n;
			if (gcd(a[1], a[2]) == a[1])
				ans--, v[2] = true;
			for (int i = 3; i <= n; i++)
				for (int j = 1; j < i - 1; j++)
					for (int k = j + 1; k < i; k++)
						if (chk(a[j], a[k], a[i]) && !v[i])
							ans--, v[i] = true;
			for (int i = 1; i <= n; i++)
				if (!v[i])
					for (int j = 1; j < i; j++)
						if (!v[j])
							for (int k = 1; k < j; k++)
								if (!v[k])
									for (int l = 1; l < k; l++)
										if (!v[l])
											if (a[l] + a[k] + a[j] == a[i])
												ans--, v[i] = true;
		}
		/*
		for (int i = 1; i <= n; i++)
			std::cout << a[i] << ' ';
		std::cout << '\n';
		for (int i = 1; i <= n; i++)
			std::cout << (v[i] ? "no " : "yes ");
		std::cout << '\n';
		for (int i = 1; i <= n; i++)
			if (!v[i])
				std::cout << a[i] << ' ';
		std::cout << '\n';
		*/
		out << ans << '\n';
	}
	
	return 0;
}

bool chk(int a, int b, int c) {
	if (gcd(c, a) == a || gcd(c, b) == b)
		return true;
	while (c > 0) {
		c -= a;
		if (!(c % b))
			return true;
	}
	return false;
}
