// overtaking.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>

std::ifstream in("overtaking.in");
std::ofstream out("overtaking.out");

typedef std::pair<int, int> car;

class compare : std::binary_function<car, car, bool> {
public:
    bool operator() (const car &a, const car &b) { return a.first < b.first; }
};

void merge(int l, int r);

long long ans = 0;
car arr[300005], temp[300005];

int main(int argc, char const * argv[]) {
    std::ios::sync_with_stdio(false);
    in.tie(NULL);
    int n;
    in >> n;
    for (int i = 0; i < n; i++)
        in >> arr[i].first >> arr[i].second;
    std::sort(arr, arr + n, compare());
    merge(0, n - 1);
    out << ans << '\n';
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