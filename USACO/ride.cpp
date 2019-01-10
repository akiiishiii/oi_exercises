/*
ID: patrick103
TASK: ride
LANG: C++14
*/
#include <fstream>
#include <string>

std::ifstream in("ride.in");
std::ofstream out("ride.out");

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    std::string s1, s2;
    in >> s1 >> s2;
    long long l1 = 1, l2 = 1;
    for (auto &&it : s1)
        l1 *= it - 'A' + 1;
    for (auto &&it : s2)
        l2 *= it - 'A' + 1;
    out << (((l1 % 47) == (l2 % 47)) ? "GO\n" : "STAY\n");
    return 0;
}
