/*
ID: patrick103
TASK: friday
LANG: C++14
*/
#include <fstream>

std::ifstream in("friday.in");
std::ofstream out("friday.out");

int const days_per_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int const year) { return ((!(year % 400)) || ((!(year % 4)) && (year % 100))); }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int n, days = 0, ans[8] = {0};
    in >> n;
    for (int i = 0; i < n; i++) {
        int leap = is_leap(1900 + i);
        for (int j = 1; j <= 12; j++) {
            ans[((days + 12) % 7) + 1]++;
            days += days_per_month[j] + ((2 == j) ? leap : 0);
        }
    }
    out << ans[6] << ' ' << ans[7] << ' ' << ans[1] << ' ' << ans[2] << ' '
         << ans[3] << ' ' << ans[4] << ' ' << ans[5] << '\n';
    return 0;
}