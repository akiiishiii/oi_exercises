#include <deque>
#include <iostream>

int n, t, a[100005];
long long sum[100005], f[100005];
std::deque<long long> q;

inline long double slope(int j, int k) {
    return ((f[j] - sum[j] * j) - (f[k] - sum[k] * k)) / ((long double)(k - j));
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> t;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], sum[i] = sum[i - 1] + a[i];
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        while (q.size() && (slope(q.front(), *(q.begin() + 1)) <= sum[1]))
            q.pop_front();
        if (q.size())
            f[i] = f[q.front()] + (sum[i] - sum[q.front()]) * q.front() - t;
        while (q.size() &&
               slope(*(q.end() - 1), q.back()) >= slope(q.back(), i))
            q.pop_back();
        q.push_back(i);
    }
    std::cout << f[n] << '\n';
    return 0;
}

// https://blog.csdn.net/sin_Yang/article/details/82973013