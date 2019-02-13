// 1503.cpp
#include <iostream>

int arr[200005] = {0}, copy[200005] = {0}, d[200005] = {0};

int main(int argc, char const *argv[]) {
    int n, k, len = 0, lenn = 1;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        if (i < k && arr[i] < arr[k])
            copy[++len] = arr[i];
        else if (i > k && arr[i] > arr[k])
            copy[++len] = arr[i];
        else if (i == k)
            copy[++len] = arr[i];
    }
    d[1] = copy[1];
    for (int i = 2; i <= len; i++) {
        int l = 1, r = lenn;
        if (d[lenn] < copy[i]) {
            lenn++;
            d[lenn] = copy[i];
            continue;
        }
        while (l <= r) {
            int mid = (l + r) / 2;
            if (d[mid] < copy[i])
                l = mid + 1;
            else
                r = mid - 1;
        }
        d[l] = copy[i];
    }
    std::cout << lenn << '\n';
    return 0;
}
