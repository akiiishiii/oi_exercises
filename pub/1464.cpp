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

// 1464.cpp
#include <queue>
#include <vector>
#include <iostream>
#include <functional>

std::vector<int> v[100001], ans;
int n, m, indeg[100001] = {0}, outdeg[100001] = {0};
std::priority_queue<int, std::vector<int>, std::greater<int> > q;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int t = 1, i, j; t <= m; t++) {
        std::cin >> i >> j;
        v[i].push_back(j);
        outdeg[i]++;
        indeg[j]++;
    }
    for (int i = 1; i <= n; i++)
        if (!indeg[i])
            q.push(i);
    while (!q.empty()) {
        ans.push_back(q.top());
        for (auto &&it : v[q.top()]) {
            indeg[it]--;
            if (!indeg[it])
                q.push(it);
        }
        q.pop();
    }
    if (ans.size() != n)
        std::cout << "NO SOLUTION";
    else
        for (auto &&it : ans)
            std::cout << it << ' ';
    std::cout << '\n';
    return 0;
}

