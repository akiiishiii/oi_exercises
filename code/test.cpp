#include <cstdio>
using namespace std;
typedef long long LL;
const int MAXN = 35617;
int N, G, fact[MAXN + 5], mod = 999911658;
int prime[5] = {0, 2, 3, 4679, 35617}, Mod[5];

void get_fact() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = (LL)fact[i - 1] * i % mod;
}

int ex_t;
void exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    ex_t = x;
    x = y;
    y = ex_t - (a / b) * y;
}

int inv(int a, int p) {
    int x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}

int calc(int i, int p) {
    int ret = 1, x, y, n, m;
    for (x = N, y = i; y; x /= p, y /= p) {
        n = x % p;
        m = y % p;
        ret = (LL)ret * fact[n] % p * inv(fact[m], p) % p *
              inv(n < m ? 0 : fact[n - m], p) % p;
    }
    return ret;
}

LL qkpow(int x, int b) {
    int s = 1;
    while (b) {
        if (b & 1)
            s = (LL)s * x % mod;
        x = (LL)x * x % mod;
        b >>= 1;
    }
    return s;
}

int main() {
    scanf("%d%d", &N, &G);
    if (G % (mod + 1) == 0) //坑点
    {
        printf("0");
        return 0;
    }
    get_fact();                      //得到阶乘取模结果
    for (int i = 1; i * i <= N; i++) //枚举因数
    {
        if (N % i == 0) {
            for (int j = 1; j <= 4; j++)
                Mod[j] = (Mod[j] + calc(i, prime[j])) % prime[j];
            if (i * i != N)
                for (int j = 1; j <= 4; j++)
                    Mod[j] = (Mod[j] + calc(N / i, prime[j])) % prime[j];
        }
    }
    int x, y, b = 0;
    for (int i = 1; i <= 4; i++) //中国剩余定理
    {
        exgcd(mod / prime[i], prime[i], x, y);
        b = (b + (LL)Mod[i] % mod * (mod / prime[i]) % mod * x % mod) % mod;
    }
    b = (b % mod + mod) % mod;
    mod += 1; //记得mod+1
    printf("%lld", qkpow(G, b));
    return 0;
}