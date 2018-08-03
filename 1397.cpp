// 1397.cpp
#include <iostream>

int main(int argc, char const * argv[]) {
    int n, seq[1005];
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> seq[i];
    if (n >= 3)
        for (int i = 0; i < n - 2; i++)
            for (int j = i + 1; j < n - 1; j++)
                if (seq[i] > seq[j])
                    for (int k = j + 1; k < n; k++)
                        if (seq[j] < seq[k]) {
                            std::cout << "NO\n";
                            return 0;
                        }
    if (n >= 1)
        std::cout << "YES\n";
    return 0;
}
