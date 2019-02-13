// 1555.cpp
#include <iostream>

struct node {
    char data;
    node *parent = nullptr, *lchild = nullptr, *rchild = nullptr;
};

void visit1(const node * no);
void visit2(const node * no);
void visit3(const node * no);

int main(int argc, char const * argv[]) {
    node btree[26];
    bool aru[26] = {false};
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        char x, y, temp1, temp2;
        std::cin >> x >> y;
        aru[x - 'A'] = true;
        btree[x - 'A'].data = x;
        if (y == '0')
            continue;
        btree[x - 'A'].lchild = &btree[y - 'A'];
        btree[y - 'A'].parent = &btree[x - 'A'];
        temp1 = y;
        while (std::cin >> temp2)
            if (temp2 == '0')
                break;
            else {
                btree[temp1 - 'A'].rchild = &btree[temp2 - 'A'];
                btree[temp2 - 'A'].parent = &btree[temp1 - 'A'];
                temp1 = temp2;
            }
    }
    const node *root;
    for (int i = 0; i < 26; i++)
        if (btree[i].parent == nullptr && aru[i])
            root = &btree[i];
    visit1(root);
    std::cout << '\n';
    visit2(root);
    std::cout << '\n';
    visit3(root);
    std::cout << '\n';
    return 0;
}

void visit1(const node * no) {
    std::cout << no -> data;
    if (no -> lchild != nullptr)
        visit1(no -> lchild);
    if (no -> rchild != nullptr)
        visit1(no -> rchild);
    return;
}

void visit2(const node * no) {
    if (no -> lchild != nullptr)
        visit2(no -> lchild);
    std::cout << no -> data;
    if (no -> rchild != nullptr)
        visit2(no -> rchild);
    return;
}

void visit3(const node * no) {
    if (no -> lchild != nullptr)
        visit3(no -> lchild);
    if (no -> rchild != nullptr)
        visit3(no -> rchild);
    std::cout << no -> data;
    return;
}