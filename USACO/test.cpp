/*
ID: patrick103
TASK: test
LANG: C++14
*/
#include <fstream>

int main(int argc, char const *argv[]) {
    std::ifstream in("test.in");
    std::ofstream out("test.out");
    int a, b;
    in >> a >> b;
    out << a + b << '\n';
    return 0;
}