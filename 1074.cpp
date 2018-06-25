// 1074.cpp
#include <iostream>
#include <iomanip>
#include <vector>

struct Student {
    double score[3];
    double avr;
    void get_avr();
};

std::ostream & operator<<(std::ostream & os, Student & s);
std::istream & operator>>(std::istream & is, Student & s);

int main(int argc, const char * argv[]) {
    int n;
    std::vector<Student> st;
    std::cin >> n;
    st.resize(n);
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < n; i++) {
        std::cin >> st[i];
        std::cout << st[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}

void Student::get_avr() {
    avr = (score[0] + score[1] + score[2]) / 3;
    return;
}

std::ostream & operator<<(std::ostream & os, Student & s) {
    s.get_avr();
    os << s.avr;
    return os;
}

std::istream & operator>>(std::istream & is, Student & s) {
    for (int i = 0; i < 3; i++)
        is >> s.score[i];
    return is;
}
