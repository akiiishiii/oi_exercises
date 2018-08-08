// save.cpp
#include <iostream>
#include <fstream>

std::ifstream in("save.in");
std::ofstream out("save.out");

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    double mom = 0;
    int money = 0, pay;
    for (int i = 1; i <= 12; i++) {
        money += 300;
        in >> pay;
        money -= pay;
        if (money >= 100) {
            int save = (money / 100) * 100;
            mom += save;
            money -= save;
        } else if (money >= 0) {
            continue;
        } else {
            out << '-' << i << '\n';
            return 0;
        }
    }
    out << 1.2 * mom + money << '\n';
    return 0;
}