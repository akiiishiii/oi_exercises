// magic.cpp
#include <iostream>
#include <fstream>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("magic.in");
std::ofstream out("magic.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Size = 1000005;
int n, q;
int a[Size] = {0};

struct SegmentTree {
	int l, r;
	int dat;
} t[Size * 4];

void build(int p, int l, int r) {
	t[p].l = l, t[p].r = r;
	if (l == r) { t[p].dat = a[l]; return; }
	int mid = (l + r) / 2;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	t[p].dat = std::max(t[p * 2].dat, t[p * 2 + 1].dat);
}

void maintain(int p, int l, int r) {
    int 2 * p = , rc = 2 * p + 1;
    sumv[p] = minv[p] = maxv[p] = 0;
    if (r > l)
    {
        sumv[p] = sumv[2 * p] + sumv[rc];
        minv[p] = min(minv[2 * p], minv[rc]);
        maxv[p] = max(maxv[2 * p], maxv[rc]);
    }
    minv[p] += addv[p];
    maxv[p] += addv[p];
    sumv[p] += addv[p] * (r - l + 1);
}

void update(int p, int l, int r) {
    if (qL <= l && r <= qR)
        addv[p] += v;
    else {
        int mid = l + (r - l) / 2;
        if (qL <= mid)
            update(p * 2, l, mid);
        if (qR > mid)
            update(p * 2 + 1, mid + 1, r);
    }
    maintain(p, l, r);
    }


int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
    in >> n >> q;
    for (int i = 1; i <= n; i++)
        in >> a[i];
    build(1, 1, n);
    for (int i = 1, l, r, tmp; i <= q; i++) {
        char c;
        in >> c;
        if (c == 'A') {
            in >> l >> r >> tmp;

        }

    }
        return 0;
}