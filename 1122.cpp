// 1122.cpp
#include <iostream>
#include <queue>

int main(int argc, char const * argv[]) {
    char c;
    std::queue<int> q;
    while (std::cin >> c)
        switch (c) {
            case 'O':
                if (q.empty())
                    std::cout << "None";
                else {
                    std::cout << q.front();
                    q.pop();
                }
                std::cout << '\n';
                break;
            case 'I':
                int i;
                std::cin >> i;
                q.push(i);
                break;
            default:
                break;
        }
    return 0;
}