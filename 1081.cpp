// 1081.cpp
#include <iostream>
#include <bitset>
 
int main(int argc, const char * argv[]) {
    int n, total = 0;
    std::cin >> n;
    std::bitset<5001> door = {false};
    for (int i = 0; i < n; i++)
        for (int j = i; j <= n; j += (i + 1))
            door.flip(j);
    for (int i = 0; i < n; i++)
        if (door[i])
            total++;
    std::cout << total << std::endl;
    return 0;
}
