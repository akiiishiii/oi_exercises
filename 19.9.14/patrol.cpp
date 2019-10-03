// patrol.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("patrol.in");
std::ofstream out("patrol.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 100001;
int m, n, a[Maxn], tot = 1, num = 1;
bool vis[Maxn];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    for (int i = 1; i <= m; i++)
        in >> a[i], vis[a[i]] = true;
    while (tot <= m)
        if (vis[num] && a[tot] != num)
			num++;
		else if (a[tot] == num)
			out << a[tot++] << '\n', num++;
        else if (a[tot] < num)
			out << a[tot++] << '\n';
        else 
			out << num++ << '\n';
    while (num <= n)
		out << num++ << '\n';
    return 0;
}
