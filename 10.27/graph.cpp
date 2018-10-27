// graph.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("graph.in");
std::ofstream out("graph.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int m, n, rotate = 0;
int img[105][105];
std::string s;

void upsize_down(int arr[105][105], int &heigth, int &width);
void ls_r(int arr[105][105], int &heigth, int &width);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            in >> img[i][j];
    in >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A')
            rotate++;
        else if (s[i] == 'B')
            rotate--;
        else if (s[i] == 'C') {
            if (rotate & 1)
                upsize_down(img, m, n);
            else
                ls_r(img, m, n);
        } else if(s[i] == 'D') {
            if (rotate & 1)
                ls_r(img, m, n);
            else
                upsize_down(img, m, n);
        }
    }
    switch (rotate % 4) {
    case 0:
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++)
                out << img[i][j] << ' ';
            out << '\n';
        }
        break;
    case 1:
        for (int j = 1; j <= n; j++) {
            for (int i = m; i >= 1; i--)
                out << img[i][j] << ' ';
            out << '\n';
        }
        break;
    case 2:
        for (int i = m; i >= 1; i--) {
            for (int j = n; j >= 1; j--)
                out << img[i][j] << ' ';
            out << '\n';
        }
        break;
    case 3:
        for (int j = n; j >= 1; j--) {
            for (int i = 1; i <= m; i++)
                out << img[i][j] << ' ';
            out << '\n';
        }
        break;
    default:
        break;
    }
    return 0;
}

void upsize_down(int arr[105][105], int &heigth, int &width) {
    for (int i = 1; i <= heigth >> 1; i++)
        for (int j = 1; j <= width; j++)
            std::swap(arr[i][j], arr[m - i + 1][j]);
}

void ls_r(int arr[105][105], int &heigth, int &width) {
    for (int j = 1; j <= width >> 1; j++)
        for (int i = 1; i <= heigth; i++)
            std::swap(arr[i][j], arr[i][width - j + 1]);
}