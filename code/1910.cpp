// 1910.cpp
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct s : public std::binary_function<int, int, bool> {
};

struct huffman_tree {
    int l, r, v, d, dad;
} a[105];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
int n;

void build(int x);
void print(int x, std::string s);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i].v, q.push(std::make_pair(a[i].v, i));
    build(n + 1);
    print(2 * n - 1, "");
    return 0;
}

void build(int x) {
    std::pair<int, int> y;
    y = q.top();
    q.pop();
    a[x].l = y.second;
    a[y.second].dad = x;
    a[x].v += y.first;
    y = q.top();
    q.pop();
    a[x].r = y.second;
    a[y.second].dad = x;
    a[x].v += y.first;
    q.push(std::make_pair(a[x].v, x));
    if (x < 2 * n - 1)
        build(x + 1);
}

void print(int x, std::string s) {
    if (x <= n)
        std::cout << s + '\n';
    if (a[x].l)
        print(a[x].l, s + '0');
    if (a[x].r)
        print(a[x].r, s + '1');
}