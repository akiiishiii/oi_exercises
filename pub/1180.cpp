// 1180.cpp
#include <iostream>

int n, m1, m2, s, ans, num[30001], a[30001], c[30001][2], maxx, cnt;
bool b[30001], flag;

void chk();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m1 >> m2;
    ans = -1;
    chk();
    while (n--) {
        cnt++;
        flag = false;
        std::cin >> s;
        maxx = 0;
        for (int i = 1; i <= c[0][0]; i++)
            if (s % c[i][0]) {
                flag = true;
                break;
            } else {
                int k = c[i][0], t = c[i][1], tmp1 = 0, tmp2 = 0;
                while (!(s % k))
                    s /= k, tmp1++;
                tmp2 = t * m2 / tmp1;
                if (t * m2 % tmp1)
                    tmp2++;
                maxx = std::max(maxx, tmp2);
            }
        if (flag)
            continue;
        if (ans == -1) {
            ans = maxx;
        } else
            ans = std::min(ans, maxx);
    }
    std::cout << ans << '\n';
    return 0;
}

void chk() {
    int tmp = m1;
    for (int i = 2; i <= m1; i++) {
        if (!b[i]) {
            a[++a[0]] = i;
            if (!(tmp % i)) {
                c[++c[0][0]][0] = i;
                while (!(tmp % i))
                    tmp /= i, c[c[0][0]][1]++;
            }
        }
        for (int j = 1; j <= a[0] && a[j] * i <= m1; j++) {
            b[i * a[j]] = 1;
            if (!(i % a[j]))
                break;
        }
    }
}