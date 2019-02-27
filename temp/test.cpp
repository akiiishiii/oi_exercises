#include <iostream>
#include <string>

int ans = 0, n, k;
std::string s;

bool chk(int l);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> k >> s;
    int l = 0, r = n * 2;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (chk(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    std::cout << ans << '\n';
    return 0;
}

bool chk(int l) {
    int tmp = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1')
            i += l - 1, tmp++;
        if (tmp > k)
            return false;
    }
    return true;
}