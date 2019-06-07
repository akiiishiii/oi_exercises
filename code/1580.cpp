// 1580.cpp
#include <cstring>
#include <iostream>

int n, tot;
int const Mod = 99991;
int snow[100010][6], head[100010], Next[100010];

int hash(int *a);
bool equal(int *a, int *b);
bool insert(int *a);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a[10];
        for (int j = 0; j < 6; j++)
            std::cin >> a[j];
        if (insert(a)) {
            std::cout << "Twin snowflakes found.\n";
            return 0;
        }
    }
    std::cout << "No two snowflakes are alike.\n";
    return 0;
}

int hash(int *a) {
    int sum = 0, mul = 1;
    for (int i = 0; i < 6; i++) {
        sum = (sum + a[i]) % Mod;
        mul = (long long)mul * a[i] % Mod;
    }
    return (sum + mul) % Mod;
}

bool equal(int *a, int *b) {
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            bool flag = true;
            for (int k = 0; k < 6; k++)
                if (a[(i + k) % 6] != b[(j + k) % 6])
                    flag = false;
            if (flag)
                return true;
            flag = true;
            for (int k = 0; k < 6; k++)
                if (a[(i + k) % 6] != b[(j - k + 6) % 6])
                    flag = false;
            if (flag)
                return true;
        }
    return 0;
}

bool insert(int *a) {
    int val = hash(a);
    for (int i = head[val]; i; i = Next[i]) {
        if (equal(snow[i], a))
            return true;
    }
    memcpy(snow[++tot], a, 6 * sizeof(int));
    Next[tot] = head[val];
    head[val] = tot;
    return 0;
}