// 1442.cpp
#include <iostream>

struct BST {
    int l, r;
    int val, num;
} a[100005];
int tot, root, INF = 1 << 30;

int New(int val);
void Build();
void Insert(int &p, int val);
void Print(int no);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    Build();
    for (int i = 0, tmp; i < n; i++) {
        std::cin >> tmp;
        Insert(root, tmp);
    }
    Print(root);
    std::cout << '\n';
    return 0;
}

int New(int val) {
    a[++tot].val = val;
    a[tot].num = 1;
    return tot;
}

void Build() {
    New(-INF), New(INF);
    root = 1, a[1].r = 2;
}

void Insert(int &p, int val) {
    if (p == 0) {
        p = New(val);
        return;
    }
    if (val == a[p].val) {
        a[p].num++;
        return;
    }
    if (val < a[p].val)
        Insert(a[p].l, val);
    else
        Insert(a[p].r, val);
}

void Print(int no) {
    if (a[no].l)
        Print(a[no].l);
    if (a[no].val != INF && a[no].val != -INF)
        for (int i = 0; i < a[no].num; i++)
            std::cout << a[no].val << ' ';
    if (a[no].r)
        Print(a[no].r);
}