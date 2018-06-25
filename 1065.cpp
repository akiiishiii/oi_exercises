// 1065.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int happle[10], htao, num = 0;
    const int CHAIR = 30;
    for (int i = 0; i < 10; i++)
        std::cin >> happle[i];
    std::cin >> htao;
    for (int i = 0; i < 10; i++)
        if (happle[i] <= htao + CHAIR)
            num++;
    std::cout << num << std::endl;
    return 0;
}
