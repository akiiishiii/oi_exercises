#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mk make_pair
using namespace std;
typedef long long ll;
const ll MOD = (ll)1e9 + 7;
const ll inv2 = 500000004;
const ll inv6 = 166666668;

pii find(ll x) {
    ll rnd = (ll)sqrt(x);
    if (rnd * rnd != x)
        rnd++;
    ll End = rnd * rnd;
    ll dif = End - x;
    ll posx, posy;
    if (rnd % 2 == 0) {
        posx = rnd;
        posy = 1;
        if (dif <= rnd - 1)
            posy += dif;
        else {
            posy = rnd;
            dif -= (rnd - 1);
            posx -= dif;
        }
    } else {
        posx = 1, posy = rnd;
        if (dif <= rnd - 1)
            posx += dif;
        else {
            posx = rnd;
            dif -= (rnd - 1);
            posy -= dif;
        }
    }
    return mk(posx, posy);
}

void fn(ll &x) { x = (x % MOD + MOD) % MOD; }

ll f(ll s1, ll s2, ll d1, ll d2, ll n) {
    if (n == 0)
        return 0;
    ll ret = n * s1 % MOD * s2 % MOD;
    fn(ret);
    ret = (ret +
           n * (n - 1) % MOD * inv2 % MOD * (s1 * d2 % MOD + s2 * d1 % MOD)) %
          MOD;
    fn(ret);
    ret = (ret + n * (n - 1) % MOD * (2 * n - 1) % MOD * inv6 % MOD * d1 % MOD *
                     d2 % MOD);
    fn(ret);
    return ret;
}

int main() {
    ll x, ans = 0;
    scanf("%lld", &x);
    pii pos = find(x);
    ll n = pos.first, m = pos.second;
    ll nowx = n, nowy = m;
    while (nowx > m) {
        if (nowx % 2 == 1) {
            ll k = n - nowx + 1;
            ll s1 = (nowx - 1) * (nowx - 1) + 1;
            ll d1 = 1;
            ll s2 = m;
            ll d2 = -1;
            ans = (ans + k * f(s1, s2, d1, d2, m)) % MOD;
        } else {
            ll k = n - nowx + 1;
            ll s1 = nowx * nowx;
            ll d1 = -1;
            ll s2 = m;
            ll d2 = -1;
            ans = (ans + k * f(s1, s2, d1, d2, m)) % MOD;
        }
        nowx--;
    }
    while (nowy > n) {
        if (nowy % 2 == 1) {
            ll k = m - nowy + 1;
            ll s1 = nowy * nowy;
            ll d1 = -1;
            ll s2 = n;
            ll d2 = -1;
            ans = (ans + k * f(s1, s2, d1, d2, n)) % MOD;
        } else {
            ll k = m - nowy + 1;
            ll s1 = (nowy - 1) * (nowy - 1) + 1;
            ll d1 = 1;
            ll s2 = n;
            ll d2 = -1;
            ans = (ans + k * f(s1, s2, d1, d2, n)) % MOD;
        }
        nowy--;
    }
    while (nowx > 0 && nowy > 0) {
        if (nowx % 2 == 1) {
            ll k = m - nowy + 1;
            ll s1 = nowy * nowy;
            ll d1 = -1;
            ll s2 = n;
            ll d2 = -1;
            ans = (ans + k * f(s1, s2, d1, d2, nowx)) % MOD;
            k = n - nowx + 1;
            s1 = (nowx - 1) * (nowx - 1) + 1;
            d1 = 1;
            s2 = m;
            d2 = -1;
            ans = (ans + k * f(s1, s2, d1, d2, nowy - 1)) % MOD;
        } else {
            ll k = m - nowy + 1;
            ll s1 = (nowy - 1) * (nowy - 1) + 1;
            ll d1 = 1;
            ll s2 = n;
            ll d2 = -1;
            ans = (ans + k * f(s1, s2, d1, d2, nowx)) % MOD;
            k = n - nowx + 1;
            s1 = nowx * nowx;
            d1 = -1;
            s2 = m;
            d2 = -1;
            ans = (ans + k * f(s1, s2, d1, d2, nowy - 1)) % MOD;
        }
        nowx--;
        nowy--;
    }
    cout << ans << endl;
    return 0;
}