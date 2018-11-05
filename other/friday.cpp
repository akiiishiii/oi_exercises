// friday.cpp
#include <fstream>
#include <iostream>

std::ifstream fin("friday.in");
std::ofstream fout("friday.out");

int const days_per_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// 预处理每月份的天数
bool is_leap(int const year) { return ((!(year % 400)) || ((!(year % 4)) && (year % 100))); }
// 判断闰年的函数(也可以放在下面判断)
int main(int argc, char const *argv[]) {
    int n, days = 0 /* 累计正在计算的月份的1号与1900/1/1的日期差 */, ans[8] = {0} /* 统计答案 */;
    fin >> n;
    for (int i = 0; i < n; i++) /* 按年份递推 */ {
        int leap = is_leap(1900 + i); // 判断闰年
        for (int j = 1; j <= 12; j++) /* 处理每一个月 */ {
            ans[((days + 12) % 7) + 1]++;
            days += days_per_month[j] + ((2 == j) ? leap : 0 /* 判断闰年的二月 */);
            // 递加日期, 判断日期差除以7的余数(对7取模)，因1900/1/1是星期一，
            // 所以利用同余关系计算该月13号是星期几并统计个数
        }
    }
    fout << ans[6] << ' ' << ans[7] << ' ' << ans[1] << ' ' << ans[2] << ' '
         << ans[3] << ' ' << ans[4] << ' ' << ans[5] << '\n';
    // 依次输出答案
    return 0;
}