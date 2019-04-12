#include <cstring>
#include <iostream>
using namespace std;

struct node {
    int dir;
    string name;
} a[205];

int main() {
    int n, m, op, num, tmp = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].dir >> a[i].name;
    for (int i = 1; i <= n; i++)
        a[i + n] = a[i];
    /*for (int i = 1; i <= n * 2; i++)
        cout << a[i].name << " ";
    cout << "\n";*/
    while (m--) {
        cin >> op >> num;
        if (((!op) && (!a[tmp].dir)) ||
            (op && a[tmp].dir)) { //向里，往左数, //向wai，往you数
            tmp += n;
            tmp -= num;
        }
        if ((op && (!a[tmp].dir)) ||
            ((!op) && a[tmp].dir)) { //向里，往右数, 向wai，往zuo数
            tmp += num;
            if (tmp > n)
                tmp -= n;
        }
    }
    cout << a[tmp].name << "\n";
    return 0;
}
/*7 3
0 h
0 li
0 na
1 k
1 rb
0 cs
1 fr
0 3
1 1
0 2
*/