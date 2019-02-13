// 1261.cpp
#include <iostream>

struct fraction {
    fraction();
    ~fraction();
    int a, b;
    void reduce();
    const fraction operator+(const fraction &f) const;
    const fraction operator+=(const fraction &f) { return *this = *this + f;}
};

std::istream &operator>>(std::istream &is, fraction &f);
std::ostream &operator<<(std::ostream &os, fraction &f);

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a;}

int main(int argc, const char * argv[]) {
    int n;
    fraction sum, temp;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        sum += temp;
    }
    std::cout << sum << std::endl;
    return 0;
}

fraction::fraction() {
    a = 0;
    b = 1;
}

fraction::~fraction() {
    a = 0;
    b = 1;
}

void fraction::reduce() {
    int gcdab = gcd(a, b);
    a /= gcdab;
    b /= gcdab;
}

const fraction fraction::operator+(const fraction &f) const {
    fraction sum = fraction();
    sum.b = b * f.b / gcd(b, f.b);
    sum.a = a * sum.b / b + f.a * sum.b / f.b;
    sum.reduce();
    return sum;
}

std::istream &operator>>(std::istream &is, fraction &f) {
    char c;
    is >> f.a >> c >> f.b;
    f.reduce();
    return is;
}

std::ostream &operator<<(std::ostream &os, fraction &f) {
    f.reduce();
    if (f.b != 1)
        os << f.a << '/' << f.b;
    else
        os << f.a;
    return os;
}