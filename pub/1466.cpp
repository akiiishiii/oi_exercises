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

// 1466.cpp
#include <queue>
#include <vector>
#include <iostream>

struct slide {
    int xmin;
    int xmax;
    int ymin;
    int ymax;
    friend std::istream &operator>>(std::istream &is, slide &s);
};

struct number {
    int x;
    int y;
    friend std::istream &operator>>(std::istream &is, number &s);
};

inline bool check(slide const &s, number const &n) { return ((n.x > s.xmax || n.x < s.xmin || n.y > s.ymax || n.y < s.ymin) ? false : true); }

int main(int argc, char const *argv[]) {
    int n, indeg[26] = {0};
    std::vector<slide> vs;
    std::vector<number> vn;
    std::vector<int> v[26];
    std::queue<int> q;
    std::cin >> n;
    vs.resize(n);
    vn.resize(n);
    for (auto &&it : vs)
        std::cin >> it;
    for (auto &&it : vn)
        std::cin >> it;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (check(vs[i], vn[j])) {
                v[i].push_back(j);
                indeg[j]++;
            }
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 1)
            q.push(i);
    while (!q.empty()) {
        ans.push_back(q.front());
        for (auto &&it : v[q.front()]) {
            indeg[it]--;
            if (indeg[it] == 1)
                q.push(it);
        }
        q.pop();
    }
    return 0;
}


std::istream &operator>>(std::istream &is, slide &s) {
    is >> s.xmin >> s.xmax >> s.ymin >> s.ymax;
    return is;
}

std::istream &operator>>(std::istream &is, number &n) {
    is >> n.x >> n.y;
    return is;
}