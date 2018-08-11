// 1395.cpp
#include <iostream>
#include <cstring>

bool flag = false;
long long a, b, minn, limit, ans[100001] = {0}, d[100001] = {0};

template <typename T>
T max(T const &ta, T const &tb) { return ta > tb ? ta : tb; }
template <typename T>
T min(T const &ta, T const &tb) { return ta < tb ? ta : tb; }
long long gcd(long long const ga, long long const gb) { return gb ? gcd(gb, ga % gb) : ga; }

void dfs(long long nx, long long ny, long long depth);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> a >> b;
    flag = false;
    d[0] = 1;
    minn = 0x3F3F3F3F;
    while (!flag) {
        limit++;
        dfs(a / gcd(a, b), b / gcd(a, b), 1);
    }
    for(long long i = 1; i <= limit; i++)
        std::cout << ans[i] <<" ";
    return 0;
}

void dfs(long long nx, long long ny, long long depth) {
    long long upper_bound = max(d[depth - 1] + 1 , ny / nx), lower_bound = min(ny * (limit -depth + 1) / nx , minn - 1);
    for(int i = upper_bound; i <= lower_bound; i++) {
        if(nx < 0)
            continue;
        int dx = nx, dy = ny;
        d[depth] = i;
        dx = dx * i - dy;
        dy = dy * i;
        if(depth < limit)
            dfs(dx / gcd(dx, dy), dy / gcd(dx, dy), depth + 1);
        if(i < minn && dx == 0) {
            flag = true;
            minn = i;
            for(int j = 1; j <= limit; j++)
                ans[j] = d[j];
        }
    }
}