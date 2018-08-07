// 1561.cpp
#include <iostream>
#include <queue>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::priority_queue<int> q;
    int m;
    std::cin >> m;
    for (int i = 0, temp, input; i < m; i++) {
        std::cin >> temp;
        switch (temp) {
            case 1:
                std::cin >> input;
                q.push(input);
                break;
            case 2:
                q.pop();
                break;
            case 3:
                std::cout << q.top() << '\n';
                break;
            default:
                break;
        }
    }
    return 0;
}
