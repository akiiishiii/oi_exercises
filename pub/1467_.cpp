
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

// 1467_.cpp
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[]) {
    int a, n, in[27] = {0}, id[27] = {0};
    bool vis[27] = {false};
    std::vector<int> w[27];
    std::queue<int> q;
    std::string s[50001], str;
    std::cin >> a >> n;
    for (int i = 0; i < a; i++)
        w[i].clear();
    for (int i = 0; i < n; i++)
        std::cin >> s[i];
    std::cin >> str;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < std::min((int)s[i - 1].length(), (int)s[i].length()); j++)
            if (s[i - 1][j] != s[i][j]) {
                int u = s[i - 1][j] - 'a';
                int v = s[i][j] - 'a';
                w[u].push_back(v);
                in[v]++;
                break;
            }
    for (int i = 0; i < a; i++)
        if (in[i] == 0)
            q.push(i);
    int cnt = 0;
    while (!q.empty()) {
        if (q.size() > 1)
            break;
        int x = q.front();
        id[x] = cnt++;
        vis[x] = true;
        q.pop();
        for (int i = 0; i < (int)w[x].size(); i++) {
            in[w[x][i]]--;
            if (!vis[w[x][i]] && in[w[x][i]] == 0)
                q.push(w[x][i]);
        }
    }
    if (cnt < a)
        std::cout << "0\n";
    else {
        for (int i = 0; i < str.length(); i++)
            std::cout << char(id[str[i] - 'a'] + 'a');
        std::cout << '\n';
    }
    return 0;
}
