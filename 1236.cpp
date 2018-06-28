// 1236.cpp
#include <iostream>

struct carpet {
    int a,b,g,k;
};

struct position {
    int x,y;
};

int main(int argc, const char * argv[])
{
    const int NONE = -1;
    int n;
    bool yn = false;
    carpet ca[10000];
    position point;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> ca[i].a >> ca[i].b >> ca[i].g >> ca[i].k;
    }
    std::cin >> point.x >> point.y;
    for (int i = n - 1; i >= 0; i--) {
        if (point.x >= ca[i].a && point.x <= (ca[i].a + ca[i].g) && point.y >= ca[i].b && point.y <= (ca[i].b + ca[i].k)) {
            yn = true;
            std::cout << i + 1 << '\n';
            break;
        }
    }
    if (yn == false)
        std::cout << NONE << '\n';
    return 0;
}