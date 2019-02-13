// 1470.cpp
#include <iostream>
#include <algorithm>

int arr[1000005] = {0};
int binary_search(int l, int r, int target);

int main(int argc, char const * argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, temp;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    for (int i = 0; i < m; i++) {
        std::cin >> temp;
        std::cout << binary_search(0, n - 1, temp) << '\n';
    }
    return 0;
}

int binary_search(int l, int r, int target) {
    int mid, ans;
    while (l <= r) {
        mid = (l + r) / 2;
        if (target <= arr[mid]) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return arr[ans] == target ? ans + 1 : -1;
}