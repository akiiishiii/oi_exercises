// magic.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

#define debug

#ifndef debug

std::ifstream in("magic.in");
std::ofstream out("magic.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Size = 1000005;
int n, q, bcnt, bsize;
int a[Size] = {0}, b[Size] = {0}, add[Size] = {0};
/*
struct SegmentTree {
    int l, r;
    int dat, add;
} t[Size * 4];

void build(int p, int l, int r);
void add(int p, int val, int l, int r);
int query(int p, int val, int l, int r);
*/
struct Block {
    int l;
    int r;
    int pos;
} bs[Size];
void copy_sort(int p);
void update(int l, int r, int c);
int bin_search(int p, int c);
int query(int l, int r, int c);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> q;
    for (int i = 1; i <= n; i++)
        in >> a[i];
    //build(1, 1, n);
    bsize = int(sqrt(n));
    bcnt = n / bsize + (n % bsize ? 1 : 0);
    for (int i = 1; i <= n; i++)
        bs[i].pos = (i - 1) / bsize + 1;
    for (int i = 1; i <= bcnt; i++) {
        bs[i].l = (i - 1) * bsize + 1;
        bs[i].r = i * bsize;
    }
    bs[bcnt].r = n;
    for (int i = 1; i <= bcnt; i++)
        copy_sort(i);
    for (int i = 1, l, r, tmp; i <= q; i++) {
        char c;
        in >> c >> l >> r >> tmp;
        if (c == 'M')
            update(l, r, tmp);
            //add(1, tmp, l, r);
        else
            out << query(l, r, tmp) << '\n';
            //query(1, tmp, l, r);
    }
    return 0;
}
/*
void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if (l == r) { t[p].dat = a[l]; return; }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    t[p].dat = std::max(t[p * 2].dat, t[p * 2 + 1].dat);
}

void add(int p, int val, int l, int r) {
    if (t[p].l >= l && t[p].r <= r) {
        t[p].add += val;
        return;
    }
    if (l >= t[p].l && r <= t[p].r)
        t[p].dat += val * (r - l + 1);
    else
        t[p].dat += val * (std::min(abs(t[p].r - l + 1), abs(r - t[p].l + 1)));
    if (t[p].add) {
        t[p].dat += (t[p].r - t[p].l + 1) * t[p].add;
        t[p * 2].add += t[p].add;
        t[p * 2 + 1].add += t[p].add;
        t[p].add = 0;
    }
    if (t[p * 2].r >= l)
        add(p * 2, val, l, r);
    if (t[p * 2 + 1].l <= r)
        add(p * 2 + 1, val, l, r);
}

int query(int p, int val, int l, int r) {
    if (l >= t[q].l && r >= t[q].r) {
        for (int i = 1; ...... )

    }
    int mid = (t[q].l + t[q].r) / 2;
    int ans = 0;
    if (t[q].l <= mid)
        ans += query(p * 2, val, l, mid);
    if (mid < t[q].r)
        ans += query(p * 2 + 1, val, mid + 1, t[q].r);
    return ans;
}
*/
void copy_sort(int p) {
    for (int i = bs[p].l; i <= bs[p].r; i++)
        b[i] = a[i];
    std::sort(b + bs[p].l, b + bs[p].r + 1);
}

void update(int l, int r, int c) {
    if(bs[l].pos == bs[r].pos) {
        for(int i = l; i <= r; i++) a[i] += c;
        copy_sort(bs[l].pos);
    } else {
        for(int i = l; i <= bs[bs[l].pos].r; i++)
            a[i] += c;
        for(int i = bs[bs[r].pos].l; i <= r; i++)
            a[i] += c;
        for(int i = bs[l].pos + 1; i < bs[r].pos; i++)
            add[i] += c;
        copy_sort(bs[l].pos);
        copy_sort(bs[r].pos);
    }
}

int bin_search(int p, int c) {
    int l = bs[p].l, r = bs[p].r;
    int ans = bs[p].r + 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (b[mid] >= c)
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    return bs[p].r - ans + 1;
}

int query(int l, int r, int c) {
    int ans = 0;
    if(bs[l].pos == bs[r].pos) {
        for(int i = l; i <= r; i++)
            if(a[i] + add[bs[l].pos] >= c)
                ans++;
    } else {
        for (int i = l; i <= bs[bs[l].pos].r; i++)
            if (a[i] + add[bs[l].pos] >= c)
                ans++;
        for (int i = bs[bs[r].pos].l; i <= r; i++)
            if (a[i] + add[bs[r].pos] >= c)
                ans++;
        for (int i = bs[l].pos + 1; i < bs[r].pos; i++)
            ans += bin_search(i, c - add[i]);
    }
    return ans;
}