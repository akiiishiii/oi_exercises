#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
struct node {
    int x, y;
} a[100001];
int n, d, ans = 1000001;
priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int>> q2;
bool sort1(node g1, node g2) { return g1.y < g2.y; }
inline int MIN(int g1, int g2) { return g1 <= g2 ? g1 : g2; }
int main() {
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + 1 + n, sort1);
    int j = 1;
    for (int i = 2; i <= n; ++i) {
        int down = a[i].y - d;
        while (a[j].y <= down) {
            q1.push(a[j].x);
            ++j;
        }
        if (!q1.empty()) {
            while (q1.top() > a[i].x) {
                q2.push(q1.top());
                q1.pop();
                if (q1.empty())
                    break;
            }
        }
        if (!q2.empty()) {
            while (q2.top() < a[i].x) {
                q1.push(q2.top());
                q2.pop();
                if (q2.empty())
                    break;
            }
        }
        if (!q1.empty())
            ans = MIN(ans, a[i].x - q1.top());
        if (!q2.empty())
            ans = MIN(ans, q2.top() - a[i].x);
    }
    if (ans < 1000001)
        printf("%d", ans);
    else
        printf("-1");
    return 0;
}