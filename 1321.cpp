// 1321.cpp
#include <iostream>

void merge(int l, int r);
long long arr[100005] = {0}, temp[100005] = {0}, ans = 0;

int main(int argc, char const * argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
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
        if (arr[i] > arr[j]) {
            temp[p++] = arr[j++];
            ans += mid - i + 1;
        } else
            temp[p++] = arr[i++];
    while (i <= mid)
        temp[p++] = arr[i++];
    while (j <= r)
        temp[p++] = arr[j++];
    for (i = l; i <= r; i++)
        arr[i] = temp[i];
}