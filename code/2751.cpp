// 2751.cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int Maxn = 10003;
struct Edge {
    int to, next;
} E[Maxn * 2];
int Cnt = 0, Mid, h[10003] = {0}, my[10003][505] = {0};
int Vst[10003] = {0}, vmy[10003] = {0}, N, M, bj = 0;
void AddEdge(int x, int y) {
    E[++Cnt].to = y;
    E[Cnt].next = h[x];
    h[x] = Cnt;
}
void Read() {
    int i;
    scanf("%d%d", &N, &M);
    for (i = 1; i <= M; i++) {
        int X, Y;
        scanf("%d%d", &X, &Y);
        AddEdge(i, X);
        AddEdge(i, Y);
    }
}
bool DFS(int u) {
    int i, j;
    for (i = h[u]; i; i = E[i].next) {
        int Y = E[i].to;
        if (Vst[Y] != bj) {
            Vst[Y] = bj;
            if (vmy[Y] < Mid) {
                my[Y][++vmy[Y]] = u;
                return true;
            }
            for (j = 1; j <= vmy[Y]; j++)
                if (DFS(my[Y][j])) {
                    my[Y][j] = u;
                    return true;
                }
        }
    }
    return false;
}
bool Try() {
    memset(my, 0, sizeof(my));
    memset(vmy, 0, sizeof(vmy));
    memset(Vst, 0, sizeof(Vst));
    for (int i = 1; i <= M; i++) {
        bj++;
        if (!DFS(i))
            return 0;
    }
    return 1;
}
int main() {
    Read();
    int L = 1, R = M;
    while (L <= R) {
        Mid = (L + R) / 2;
        if (Try())
            R = Mid - 1;
        else
            L = Mid + 1;
    }
    cout << L << endl;
    return 0;
}
