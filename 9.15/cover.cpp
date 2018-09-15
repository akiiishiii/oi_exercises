// cover.cpp
#include <iostream>
#include <fstream>
#include <stack>

//#define debug

#ifndef debug

std::ifstream in("cover.in");
std::ofstream out("cover.out");

#else

#define in std::cin
#define out std::cout

#endif // debug


int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int n, h[100001] = {0}, ans;
    std::stack<int> s;
    in >> n;
    ans = n;
    for (int i = 1; i <= n; i++)
        in >> h[i];
    s.push(h[1]);
    for (int i = 2; i <= n; i++) {
        while (s.size() && s.top() >= h[i]) {
            if(s.top() == h[i])
                ans--;
            s.pop();
        }
        s.push(h[i]);
    }
    out << ans << '\n';
    return 0;
}