#include <algorithm>
#include <iostream>

int da, db, cnt;
long long now, ans, md[15], l, r;
long long a[10010], b[10010];

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void search(int d);
void dfs(int j);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    md[0] = 1;
    for (int i = 1; i <= 10; i++)
        md[i] = md[i - 1] * 10;
    scanf("%lld %lld", &l, &r);
    search(0);
    std::sort(a + 1, a + da + 1);
    for (int i = 1; i <= da; i++) {
        b[++db] = a[i];
        for (int j = 1; j < db; j++)
            if (!(a[i] % b[j])) {
                db--;
                break;
            }
    }
    for (int i = 1; i <= db / 2; i++)
        std::swap(b[i], b[db - i + 1]);
    now = 1;
    dfs(1);
    std::cout << ans << '\n';
    return 0;
}

void search(int d) {
    if (now > r)
        return;
    long long tmp = now;
    now = tmp + 6 * md[d];
    search(d + 1);
    now = tmp + 8 * md[d];
    search(d + 1);
    if (tmp)
        a[++da] = tmp;
    now = tmp;
}

void dfs(int j) {
    if (j == db + 1) {
        if (!cnt)
            return;
        if (cnt & 1)
            ans += r / now - (l - 1) / now;
        else
            ans -= r / now - (l - 1) / now;
        return;
    }
    dfs(j + 1);
    long long tmp = now;
    cnt++;
    now = tmp / gcd(tmp, b[j]);
    if ((double)now * b[j] <= r) {
        now *= b[j];
        if (now <= r)
            dfs(j + 1);
    }
    cnt--;
    now = tmp;
}