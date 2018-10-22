// 3459.cpp
#include <iostream>
#include <algorithm>

struct cow {
    bool ra;
    int x;
    bool operator<(cow const &c) const { return x < c.x; }
};

int main(int argc, char const *argv[]) {

    return 0;
}
