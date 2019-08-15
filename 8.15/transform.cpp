// transform.cpp
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>
#include <utility>

#define Pi M_PI
//#define M_PI 3.14159265358979323846

struct func {
    char type;
    double x, y;
    double the;
    func() {}
    func(char c, int _x, int _y, int _the) : type(c), x(_x), y(_y), the(_the) {}
    void operator()() const;
};

int n, loops;
double x, y, the;
std::pair<double, double> ps[101];

void trans(double dx, double dy);
void scale(double sx, double sy);
void rotate(double theta, double x0, double y0);
inline double deg2arc(double deg) { return (deg / 180.0) * Pi; }

int main(int argc, char const *argv[]) {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf %lf\n", &ps[i].first, &ps[i].second);
    char c;
    c = getchar();
    while (c == 'T' || c == 'S' || c == 'R' || c == 'L') {
        if (c == 'T') {
            scanf("rans(%lf,%lf)\n", &x, &y);
            trans(x, y);
        } else if (c == 'S') {
            scanf("cale(%lf,%lf)\n", &x, &y);
            scale(x, y);
        } else if (c == 'R') {
            scanf("otate(%lf,%lf,%lf)\n", &the, &x, &y);
            rotate(the, x, y);
        } else if (c == 'L') {
            scanf("oop(%d)\n", &loops);
            std::queue<func> q;
            while ((c = getchar()) != 'E') {
                if (c == 'T') {
                    scanf("rans(%lf,%lf)\n", &x, &y);
                    q.push(func(c, x, y, 0));
                } else if (c == 'S') {
                    scanf("cale(%lf,%lf)\n", &x, &y);
                    q.push(func(c, x, y, 0));
                } else if (c == 'R') {
                    scanf("otate(%lf,%lf,%lf)\n", &the, &x, &y);
                    q.push(func(c, x, y, the));
                }
            }
            scanf("nd\n");
            for (int i = 1; i <= loops; i++)
                for (int j = 1; j <= q.size(); j++) {
                    q.front()();
                    q.push(q.front());
                    q.pop();
                }
            while (q.size())
                q.pop();
        }
        c = getchar();
        if (c == EOF)
            break;
    }
    for (int i = 1; i <= n; i++)
        printf("%.4lf %.4lf\n", ps[i].first, ps[i].second);
    return 0;
}

void func::operator()() const {
    if (type == 'T')
        trans(x, y);
    else if (type == 'C')
        scale(x, y);
    else
        rotate(the, x, y);
}

void trans(double dx, double dy) {
    for (int i = 1; i <= n; i++)
        ps[i] = std::make_pair(ps[i].first + dx, ps[i].second + dy);
}

void scale(double sx, double sy) {
    for (int i = 1; i <= n; i++)
        ps[i] = std::make_pair(ps[i].first * sx, ps[i].second * sy);
}

void rotate(double theta, double x0, double y0) {
    for (int i = 1; i <= n; i++) {
        double dx = ps[i].first - x0, dy = ps[i].second - y0;
        ps[i] = std::make_pair(ps[i].first + dx * cos(-deg2arc(theta)) +
                                   dy * (-sin(-deg2arc(theta))),
                               ps[i].second + dx * sin(-deg2arc(theta)) +
                                   dy * cos(-deg2arc(theta)));
    }
}