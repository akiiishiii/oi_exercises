// wall.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("wall.in");
std::ofstream out("wall.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, ans = 6;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n;
    n--;
    for (int i = 1; n > 0; i++) {
        n -= (i - 1), ans++;
        for (int j = 1; j <= 4; j++)
            if (n > 0)
                n -= i, ans++;
        if (n > 0)
            n -= (i + 1), ans++;
    }
    out << ans << '\n';
    return 0;
}

/*
1   6
2   8
3   9
4   10
5   11
6   12
7   12
8   13
9   14
10  14
11  15
12  15
13  16
14  16
15  17
16  17
17  18
18  18
19  18
20  19
21  19
22  20
23  20
24  20
25  21
26  21
27  21
28  22
29  22
30  22
31  23
32  23
33  23
34  24
35  24
36  24
37  24
*/