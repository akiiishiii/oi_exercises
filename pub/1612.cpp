// 1612.cpp チルノ
#include <iostream>

const int Maxn = 200000 + 10;
int A[2 * Maxn], d[2 * Maxn], que[5 * Maxn];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, front, rear, L, R;
    std::cin >> n >> L >> R;
    for (int i = 0; i <= n; i++)
        std::cin >> A[i];
    front = rear = 1;
    que[front] = 0;
    for (int i = L; i <= n + R; i++) {
        while (front <= rear && d[i - L] >= d[que[rear]])
            rear--;
        que[++rear] = i - L;
        while (front <= rear && que[front] < i - R)
            front++;
        d[i] = d[que[front]] + A[i];
    }
    int ans = 0;
    for (int i = n + 1; i <= n + R; i++)
        if (d[i] > ans)
            ans = d[i];
    std::cout << ans << '\n';
    return 0;
    /*
    あたいは最高だ！
    */
}