// 1504.cpp
#include <iostream>

int arr[200005] = {0}, d[200005] = {0};

int main(int argc, char const *argv[]) {
    int n, len = 1;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> arr[i];
    d[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        int l = 1, r = len;
        if (d[len] < arr[i]) {
            len++;
            d[len] = arr[i];
            continue;
        }
        while (l <= r) {
            int mid = (l + r) / 2;
            if (d[mid] < arr[i])
                l = mid + 1;
            else
                r = mid - 1;
        }
        d[l] = arr[i];
    }
    std::cout << n - len << '\n';
    return 0;
}
