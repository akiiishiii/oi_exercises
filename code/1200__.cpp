// 1200__.cpp
#include <iostream>

int const Maxn = 5000010;
int n, m, qid, aid;
int ans[Maxn];

struct query {
    int type, id, val;
    bool operator<(query const &q) const { return id == q.id ? type < q.type : id < q.id; }
} a[Maxn], tmp[Maxn];

void cdq(int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string op;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int q, y;
        std::cin >> op >> q >> y;
        if (op[1] == 'd') {
            a[++qid].type = 1;
            a[qid].id = q;
            a[qid].val = y;
        }
        if (op[1] == 'u') {
            a[++qid].type = 1;
            a[qid].id = q;
            a[qid].val = -y;
        }
        if (op[1] == 's') {
            a[++qid].type = 2;
            a[qid].id = q - 1;
            a[qid].val = ++aid;
            a[++qid].type = 3;
            a[qid].id = y;
            a[qid].val = aid;
        }
    }
    cdq(1, qid);
    for (int i = 1; i <= aid; i++)
        std::cout << ans[i] << '\n';
    return 0;
}

void cdq(int l, int r) {
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    int sum = 0, i = l, j = l, k = mid + 1;
    while (j <= mid && k <= r) {
        if (a[j] < a[k]) {
            if (a[j].type == 1)
                sum += a[j].val;
            tmp[i++] = a[j++];
        } else {
            if (a[k].type == 2)
                ans[a[k].val] -= sum;
            else if (a[k].type == 3)
                ans[a[k].val] += sum;
            tmp[i++] = a[k++];
        }
    }
    while (j <= mid)
        tmp[i++] = a[j++];
    while (k <= r) {
        if (a[k].type == 2)
            ans[a[k].val] -= sum;
        else if (a[k].type == 3)
            ans[a[k].val] += sum;
        tmp[i++] = a[k++];
    }
    for (int i = l; i <= r; i++)
        a[i] = tmp[i];
}