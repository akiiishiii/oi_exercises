#include <iostream>
#include <cstdlib>
using namespace std;

string const a = "test.exe ", b = "te.exe ";

int main() {
    for (int i = 5, n = 50000, m = 100000; i > 0; i--, n /= 5, m /= 5) {
        system((a + to_string(i) + ' ' + to_string(n) + ' ' + to_string(m) + '\n').c_str());
        system((b + to_string(i) + '\n').c_str());
    }
}