// 1552.cpp
#include <iostream>

struct node {
    int data;
    node *parent = nullptr, *lchild = nullptr, *rchild = nullptr;
};

void visit(const node *no);

int main(int argc, char const *argv[]) {
    int n;
    node btree[105], *root;
    bool aru[105];
    std::cin >> n;
    for (int i = 0, x, y, z; i < n; i++) {
        std::cin >> x >> y >> z;
        aru[x] = true;
        btree[x].data = x;
        btree[x].lchild = y ? btree + y : nullptr;
        btree[x].rchild = z ? btree + z : nullptr;
        if (y)
            btree[y].parent = btree + x;
        if (z)
            btree[z].parent = btree + x;
    }
    for (int i = 1; i <= 100; i++)
        if (aru[i] && btree[i].parent == nullptr)
            root = &btree[i];
    visit(root);
    return 0;
}

void visit(const node *no) {
    if (no -> lchild != nullptr)
        visit(no -> lchild);
    std::cout << no -> data << '\n';
    if (no -> rchild != nullptr)
        visit(no -> rchild);
    return;
}
