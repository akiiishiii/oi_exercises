// 1115.cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct item {
    int times;
    int timea;
    int timeb;
    int id;
    char machine;
    bool operator<(const item &i) const { return (times == i.times ? id < i.id : times < i.times);}
};

int main(int argc, const char * argv[]) {
    std::vector<item> obj;
    std::vector<std::vector<item>::iterator> put;
    int n, timetot = 0;
    std::cin >> n;
    int p = 0, q = n - 1;
    obj.resize(n);
    put.resize(n);
    for (std::vector<item>::iterator it = obj.begin(); it != obj.end(); it++) {
        std::cin >> (*it).timea;
        (*it).id = it - obj.begin() + 1;
    }
    for (std::vector<item>::iterator it = obj.begin(); it != obj.end(); it++) {
        std::cin >> (*it).timeb;
        (*it).times = ((*it).timea < (*it).timeb ? (*it).timea : (*it).timeb);
        (*it).machine = ((*it).timea < (*it).timeb ? 'A' : 'B');
    }
    std::sort(obj.begin(), obj.end());
    for (std::vector<item>::iterator it = obj.begin(); it != obj.end(); it++) {
        if ((*it).machine == 'B')
            put[q--] = it;
        else if ((*it).machine == 'A')
            put[p++] = it;
    }
    for (std::vector<std::vector<item>::iterator>::iterator it = put.begin(); it != put.end(); it++)
        timetot += (**it).timea;
    timetot += (*put[n - 1]).timeb;
    std::cout << timetot << std::endl;
    for (std::vector<std::vector<item>::iterator>::iterator it = put.begin(); it != put.end(); it++)
        std::cout << (**it).id << ' ';
    std::cout << std::endl;
    return 0;
}