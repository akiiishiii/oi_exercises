// editor.cpp
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

//#define debug

#ifndef debug

std::ifstream in("editor.in");
std::ofstream out("editor.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

std::deque<char> l, m, r;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int n;
    std::string s;
    char com, w, c;
    in >> s >> n;
    for (int i = 0; i < s.length(); i++)
        m.push_back(s[i]);
    while (n--) {
        in >> com;
        switch (com) {
        case '<':
            in >> w;
            if (w == 'L') {
                if (l.empty())
                    out << "F\n";
                else {
                    m.push_front(l.back());
                    l.pop_back();
                    out << "T\n";
                }
            } else {
                if (m.empty())
                    out << "F\n";
                else {
                    r.push_front(m.back());
                    m.pop_back();
                    out << "T\n";
                }
            }
            break;
        case '>':
            in >> w;
            if (w == 'L') {
                if (m.empty())
                    out << "F\n";
                else {
                    l.push_back(m.front());
                    m.pop_front();
                    out << "T\n";
                }
            } else {
                if (r.empty())
                    out << "F\n";
                else {
                    m.push_back(r.front());
                    r.pop_front();
                    out << "T\n";
                }
            }
            break;
        case 'I':
            in >> w >> c;
            if (w == 'L')
                l.push_back(c);
            else
                m.push_back(c);
            out << "T\n";
            break;
        case 'D':
            in >> w;
            if (w == 'L') {
                if (m.empty())
                    out << "F\n";
                else {
                    m.pop_front();
                    out << "T\n";
                }
            } else {
                if (r.empty())
                    out << "F\n";
                else {
                    r.pop_front();
                    out << "T\n";
                }
            }
            break;
        case 'R':
            if (m.empty())
                out << "F\n";
            else {
                std::reverse(m.begin(), m.end());
                out << "T\n";
            }
            break;
        case 'S':
            for (int i = l.size(); i > 0; i--) {
                l.push_back(l.front());
                out << l.front();
                l.pop_front();
            }
            for (int i = m.size(); i > 0; i--) {
                m.push_back(m.front());
                out << m.front();
                m.pop_front();
            }
            for (int i = r.size(); i > 0; i--) {
                r.push_back(r.front());
                out << r.front();
                r.pop_front();
            }
            break;
        default:
            break;
        }
    }
    return 0;
}