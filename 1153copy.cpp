// 1153copy.cpp
#include <bits/stdc++.h>
#define bnd_cnt 40010
#define bnd_mag 15010

using namespace std;

int max_mag, cnt_obj, cnt_num, cnt[4][bnd_mag], mag[bnd_cnt], ust_mag[bnd_cnt], cnt_mag[bnd_mag];

void in() {
    cin >> max_mag >> cnt_obj;
    int wst_mag[bnd_cnt];
    memset(wst_mag, 0, sizeof(wst_mag));
    for (int i = 1; i <= cnt_obj; i++) {
        scanf("%d", &ust_mag[i]);
        wst_mag[i] = ust_mag[i];
        cnt_mag[ust_mag[i]]++;
    }
    sort(wst_mag + 1, wst_mag + cnt_obj + 1);
    for (int i = 1; i <= cnt_obj; i++)
        if (wst_mag[i] > wst_mag[i - 1])
            mag[++cnt_num] = wst_mag[i];
    return;
}

void work() {
    for (int gap = 1; gap * 9 < max_mag; gap++) {
        int cnt_left[bnd_mag];
        int cnt_right[bnd_mag];
        memset(cnt_left, 0, sizeof(cnt_left));
        memset(cnt_right, 0, sizeof(cnt_right));
        for (int a = 1; a + gap * 9 < max_mag; a++) {
            int b = a + gap * 2;
            int least_c = b + gap * 6 + 1;
            cnt_left[least_c] += cnt_mag[a] * cnt_mag[b];
        }
        for (int c = gap * 8 + 2; c + gap <= max_mag; c++) {
            int d = c + gap;
            int least_b = c - gap * 6 - 1;
            cnt_right[least_b] += cnt_mag[c] * cnt_mag[d];
            cnt_left[c] += cnt_left[c - 1];
            cnt[2][c] += cnt_left[c] * cnt_mag[d];
            cnt[3][d] += cnt_left[c] * cnt_mag[c];
        }
        for (int a = max_mag - 9 * gap - 1; a >= 1; a--) {
            int b = a + gap * 2;
            cnt_right[b] += cnt_right[b + 1];
            cnt[1][b] += cnt_right[b] * cnt_mag[a];
            cnt[0][a] += cnt_right[b] * cnt_mag[b];
        }
    }
    return;
}

void out() {
    for (int i = 1; i <= cnt_obj; i++) {
        for (int j = 0; j <= 3; j++)
            cout << cnt[j][ust_mag[i]] << " ";
        cout << endl;
    }
    return;
}

int main() {
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    in();
    work();
    out();
    return 0;
}