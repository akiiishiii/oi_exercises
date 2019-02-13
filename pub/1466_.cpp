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

// 1466_.cpp
#include <vector>
#include <cstring>
#include <iostream>

int n, match[26], pptsize[26][4];
bool map[26][26];

int minDegreePPT();
void run(int step, int &ans);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    memset(match, -1, sizeof(match));
    memset(pptsize, 0, sizeof(pptsize));
    memset(map, false, sizeof(map));
    for (int i = 0; i < n; i++)
        std::cin >> pptsize[i][0] >> pptsize[i][1] >> pptsize[i][2] >> pptsize[i][3];
    int x, y;
    for (int i = 0; i < n; i++) {
        std::cin >> x >> y;
        for (int j = 0; j < n; j++)
            if (pptsize[j][0] <= x && x <= pptsize[j][1] && pptsize[j][2] <= y && y <= pptsize[j][3])
                map[j][i] = true;
    }
    int result = 0;
    run(1, result);
    if (result == 0 || result > 1)
        std::cout << "None" << '\n';
    return 0;
}

int minDegreePPT() {
    int point = -1;
    int minDegree = 26 + 1;
    for (int i = 0; i < n; i++)
        if (match[i] == -1) {
            int degree = 0;
            for (int j = 0; j < n; j++)
                if (map[i][j])
                    degree++;
            if (minDegree > degree) {
                minDegree = degree;
                point = i;
            }
        }
    return point;
}

void run(int step, int &ans) {
    if (step > n) {
        ans++;
        for (int i = 0; i < n; i++)
            std::cout << char(i + 'A') << ' ' << match[i] + 1 << '\n';
        std::cout << '\n';
        return;
    }
    int point = minDegreePPT();
    std::vector<int> matchPoint;
    for (int i = 0; i < n; i++)
        if (map[point][i]) {
            map[point][i] = false;
            matchPoint.push_back(i);
        }
    if (matchPoint.size())
        for (int i = 0; i < matchPoint.size(); i++) {
            int selectNum = matchPoint.at(i);
            match[point] = selectNum;
            std::vector<int> selectNumEdge;
            for (int i = 0; i < n; i++)
                if (map[i][selectNum]) {
                    selectNumEdge.push_back(i);
                    map[i][selectNum] = false;
                }
            run(step + 1, ans);
            for (int i = 0; i < selectNumEdge.size(); i++)
                map[selectNumEdge.at(i)][selectNum] = true;
            match[point] = -1;
        }
    for (int i = 0; i < matchPoint.size(); i++)
        map[point][matchPoint.at(i)] = true;
}