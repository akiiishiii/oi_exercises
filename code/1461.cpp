// 1461.cpp
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

int a[100], v[100], n, len, cnt;

bool dfs(int stick, int cab, int last);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	while (std::cin >> n) {
    	int sum = 0, val = 0;
    	for (int i = 1; i <= n; i++) {
    	    std::cin >> a[i], sum += a[i];
    	    val = std::max(val, a[i]);
    	}
    	std::sort(a + 1, a + n + 1, std::greater<int>());
    	for (len = val; len <= sum; len++) {
    	    if (sum % len)
    	        continue;
    	    cnt = sum / len;
    	    memset(v, 0, sizeof(v));
    	    if (dfs(1, 0, 1))
    	        break;
    	}
    	std::cout << len << '\n';
	}
    return 0;
}

bool dfs(int stick, int cab, int last) {
    if (stick > cnt)
        return true;
    if (cab == len)
        return dfs(stick + 1, 0, 1);
    int fail = 0;
    for (int i = last; i <= n; i++)
        if (!v[i] && cab + a[i] <= len && fail != a[i]) {
            v[i] = 1;
            if (dfs(stick, cab + a[i], i + 1))
                return true;
            fail = a[i];
            v[i] = 0;
            if (!cab)
                return false;
        }
    return false;
}
