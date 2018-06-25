#include <iostream>
#include <string>

bool check(std::string &s);
int getalpha(std::string &s);

int main(int argc, const char * argv[]) {
    int n, tot = 0;
    std::cin >> n;
    return 0;
}

bool check(std::string &s) {
    bool result = false;
    if (s.substr(0, 3) == "con")
        result = true;
    return result;
}

int getalpha(std::string &s) {

}