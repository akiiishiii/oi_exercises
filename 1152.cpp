//  1152.cpp

#include <iostream>
#include <vector>
#include <algorithm>

struct ship {
    ship();
    int time, peo;
    std::vector<int> nat;
    friend std::istream & operator>>(std::istream & is, ship & s);
};

unsigned long uniq(std::vector<ship> & s, int x);

int main(int argc, const char * argv[]) {
    std::vector<ship> sh;
    int n;

    std::cin >> n;
    sh.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sh[i];
        unsigned long outp = uniq(sh, i);
        if (outp != 0)
            std::cout << outp << std::endl;
    }
    return 0;
}

ship::ship() {
    time = peo = 0;
    nat.clear();
}

std::istream & operator>>(std::istream & is, ship & s) {
    is >> s.time >> s.peo;
    s.nat.resize(s.peo);
    for (int i = 0; i < s.peo; i++)
        is >> s.nat[i];
    return is;
}

unsigned long uniq(std::vector<ship> & s, int x) {
    if (x > s.size() || x < 0)
        return 0;
    int i;
    std::vector<int> iv;
    for (i = x; i >= 0; i--)
        if (s[i].time + 86400 <= s[x].time)
            break;
    i++;
    for (; i <= x; i++)
        iv.insert(iv.end(), s[i].nat.begin(), s[i].nat.end());
    std::sort(iv.begin(), iv.end());
    std::vector<int>::iterator it;
    it = std::unique(iv.begin(), iv.end());
    iv.resize(std::distance(iv.begin(), it));
    return iv.size();
}