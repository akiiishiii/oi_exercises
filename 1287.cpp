// 1287.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    char a[101][101];
    int n, m, sum = 0;
    std::cin >> n;
    for(int i = 0;i < n; i++)
        for(int j = 0; j < n; j++)
            std::cin >> a[i][j];
    std::cin >> m;
    for(int d = 1; d <= m; d++) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n;j++)
                if(a[i][j] == '!')
                    a[i][j] = '@';
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n;j++)
                if(a[i][j] == '@') {
                    if(i + 1 <n && a[i + 1][j] == '.')
                        a[i + 1][j]='!';
                    if(j - 1 >= 0 && a[i][j - 1] == '.')
                        a[i][j - 1] = '!';
                    if(j + 1 < n && a[i][j + 1] == '.')
                        a[i][j + 1]='!';
                    if(i - 1 >= 0 && a[i - 1][j] == '.')
                        a[i - 1][j] = '!';
                }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] == '@')
                sum++;
    std::cout << sum << std::endl;
    return 0;
}