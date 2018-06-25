// 1059.cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct student {
    student() { num = score = 0;}
    ~student() { num = score = 0;}
    student(int n, int s) { num = n;score = s;}
    int num;
    int score;
    bool operator<(const student & s) const { return score < s.score;}
    bool operator>(const student & s) const { return score > s.score;}
};

bool comp(const student & s1, const student & s2) { return s1 > s2;}

std::ostream & operator<<(std::ostream & os, student & s) {
    os << s.num << std::endl << s.score << std::endl;
    return os;
}

int main(int argc, const char * argv[]) {
    int n;
    std::vector<student> s;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        int temp = 0, combo = 0;
        while ((c = std::cin.get()) != 'E') {
            if (c == 'Y') {
                temp++;
                combo++;
            } else if (c == 'N')
                combo = 0;
            if (combo == 3) {
                temp++;
                combo = 0;
            }
        }
        s.push_back(student(i, temp));
    }
    std::sort(s.begin(), s.end(), comp);
    std::cout << s[0];
    return 0;
}
