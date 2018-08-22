
// The MIT License (MIT)

// Copyright (c) 2018 何秋杰

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

//1464_.cpp
#include <functional>
#include <iostream>
#include <vector>
#include <queue>

struct did {
    int to, next;
} e[500005];

int n, m, cnt, h[500005], rd[100005], ans[100005];
std::priority_queue<int, std::vector<int>, std::greater<int>> q;

void add_edge(int x, int y);
bool top_sort();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        add_edge(a, b);
        rd[b]++;
    }
    if (top_sort())
        for (int i = 1; i <= n; i++)
            std::cout << ans[i] << " ";
    else
        std::cout << "NO SOLUTION";
    std::cout << '\n';
    return 0;
}

void add_edge(int x, int y) {
    e[++cnt].to = y;
    e[cnt].next = h[x];
    h[x] = cnt;
}

bool top_sort() {
    for (int i = 1; i <= n; i++)
        if (!rd[i])
            q.push(i);
    for (int i = 1; i <= n; i++) {
        if (q.empty())
            return false;
        int top = q.top();
        q.pop();
        ans[++ans[0]] = top;
        for (int j = h[top]; j; j = e[j].next) {
            int to = e[j].to;
            rd[to]--;
            if (!rd[to])
                q.push(to);
        }
    }
    return true;
}