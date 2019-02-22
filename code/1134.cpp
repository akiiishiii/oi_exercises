
#include <iostream>

int const HashSize = 4001, MaxS = 50000;
long long f[2][MaxS], ans = 0;
int h[HashSize], nxt[MaxS], w[MaxS];
int state[2][MaxS], tot[2];
int N, M, now, last = 0, k, h0 = 0;

void update(int s2) {
    int i, hash = s2 % HashSize;
    for (i = h[hash]; i; i = nxt[i])
        if (w[i] == s2)
            break;
    if (i) {
        f[now][i] += f[last][k];
        return;
    }
    i = ++h0;
    w[i] = s2;
    nxt[i] = h[hash];
    h[hash] = i;
    f[now][i] = f[last][k];
    tot[now]++;
    state[now][i] = s2;
}

int FindRightBracket(int s1, int x) {
    int i, top = 0;
    for (i = x; i <= M; i++) {
        int j = (s1 >> (i << 1)) & 3;
        if (j == 1)
            top++;
        if (j == 2)
            top--;
        if (!top)
            break;
    }
    return i;
}

int FindLeftBracket(int s1, int x) {
    int i, top = 0;
    for (i = x; i >= 0; i--) {
        int j = (s1 >> (i << 1)) & 3;
        if (j == 2)
            top++;
        if (j == 1)
            top--;
        if (!top)
            break;
    }
    return i;
}

void Transit(int x, int y, int s1) {
    int i, t1, t2, p1, p2, indep = 0;
    p1 = (y - 1) << 1;
    p2 = y << 1;
    t1 = (s1 >> p1) & 3;
    t2 = (s1 >> p2) & 3;
    for (i = 0; i <= M; i++)
        if (((s1 >> (i << 1)) & 3) == 3)
            indep++;
    if (t1 == 0 && t2 == 0) {
        if (x < N && y < M)
            update(s1 + (1 << p1) + (2 << p2));
        if (x < N && indep < 2)
            update(s1 + (3 << p1));
        if (y < M && indep < 2)
            update(s1 + (3 << p2));
    }

    if (t1 == 3 && t2 == 3 && x == N && y == M)
        update(s1 - (t1 << p1) - (t2 << p2));
    if (t1 == 3 && t2 > 0 && t2 < 3) {
        if (t2 == 1) {
            i = FindRightBracket(s1, y);
            update(s1 - (t1 << p1) - (t2 << p2) + (1 << (i << 1)));
        } else {
            i = FindLeftBracket(s1, y);
            update(s1 - (t1 << p1) - (t2 << p2) + (2 << (i << 1)));
        }
    }
    if (t1 > 0 && t1 < 3 && t2 == 3) {
        if (t1 == 1) {
            i = FindRightBracket(s1, y - 1);
            update(s1 - (t1 << p1) - (t2 << p2) + (1 << (i << 1)));
        } else {
            i = FindLeftBracket(s1, y - 1);
            update(s1 - (t1 << p1) - (t2 << p2) + (2 << (i << 1)));
        }
    }
    if (t1 == 2 && t2 == 1)
        update(s1 - (t1 << p1) - (t2 << p2));
    if (t1 == 1 && t2 == 1) {
        i = FindRightBracket(s1, y);
        update(s1 - (t1 << p1) - (t2 << p2) - (1 << (i << 1)));
    }
    if (t1 == 2 && t2 == 2) {
        i = FindLeftBracket(s1, y - 1);
        update(s1 - (t1 << p1) - (t2 << p2) + (1 << (i << 1)));
    }

    if (t1 > 0 && t2 == 0) {
        if (x < N)
            update(s1);
        if (y < M)
            update(s1 - (t1 << p1) + (t1 << p2));
        if (t1 == 1 && indep < 2) {
            i = FindRightBracket(s1, y - 1);
            update(s1 - (t1 << p1) + (1 << (i << 1)));
        }
        if (t1 == 2 && indep < 2) {
            i = FindLeftBracket(s1, y - 1);
            update(s1 - (t1 << p1) + (2 << (i << 1)));
        }
        if (t1 == 3 && x == N && y == M)
            update(s1 - (t1 << p1));
    }
    if (t1 == 0 && t2 > 0) {
        if (y < M)
            update(s1);
        if (x < N)
            update(s1 - (t2 << p2) + (t2 << p1));
        if (t2 == 1 && indep < 2) {
            i = FindRightBracket(s1, y);
            update(s1 - (t2 << p2) + (1 << (i << 1)));
        }
        if (t2 == 2 && indep < 2) {
            i = FindLeftBracket(s1, y);
            update(s1 - (t2 << p2) + (2 << (i << 1)));
        }
        if (t2 == 3 && x == N && y == M)
            update(s1 - (t2 << p2));
    }
}
void Dp() {
    int i, j;
    tot[0] = 1;
    f[0][1] = 1;
    state[0][1] = 0;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            now = !last;
            memset(h, 0, sizeof(h));
            tot[now] = h0 = 0;
            for (k = 1; k <= tot[last]; k++)
                Transit(i, j, state[last][k]);
            last = now;
        }
        for (k = 1; k <= tot[now]; k++)
            state[now][k] <<= 2;
    }
    for (i = 1; i <= tot[now]; i++)
        ans += f[now][i];
    printf("%I64d\n", ans);
}
int main() {
    scanf("%d%d", &N, &M);
    Dp();
    return 0;
}
