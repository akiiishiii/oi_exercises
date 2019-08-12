// 3063.cpp
#include <algorithm>
#include <fstream>
#include <iostream>
#include <utility>

class comp : std::binary_function<std::pair<long long, long long>,
                                  std::pair<long long, long long>, bool> {
  public:
    bool operator()(const std::pair<long long, long long> &a,
                    const std::pair<long long, long long> &b) {
        return a.first < b.first;
    }
};

void merge(int l, int r);

long long ans = 0;
std::pair<long long, long long> arr[300005], temp[300005];

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> arr[i].first >> arr[i].second;
    std::sort(arr, arr + n, comp());
    merge(0, n - 1);
    std::cout << ans << '\n';
    return 0;
}

void merge(int l, int r) {
    if (l == r)
        return;
    int mid = (l + r) / 2;
    merge(l, mid);
    merge(mid + 1, r);
    int i = l, j = mid + 1, p = l;
    while (i <= mid && j <= r)
        if (arr[i].second > arr[j].second) {
            temp[p++].second = arr[j++].second;
            ans += mid - i + 1;
        } else
            temp[p++].second = arr[i++].second;
    while (i <= mid)
        temp[p++].second = arr[i++].second;
    while (j <= r)
        temp[p++].second = arr[j++].second;
    for (i = l; i <= r; i++)
        arr[i].second = temp[i].second;
}