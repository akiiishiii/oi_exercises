#include <cstdio>
const int __buffsize = 100000;
char __buff[__buffsize];
char *__buffs, *__buffe;

#define getc() (__buffs == __buffe ? fread(__buff, 1, __buffsize, stdin), __buffe = __buff + __buffsize, *((__buffs = __buff)++) : *(__buffs++))

template <typename T>
inline T &Read(T &x) {
    static char c;
    while (true) {
        c = getc();
        if (c == '-' || (c >= '0' && c <= '9'))
            break;
    }
    bool flag = c == '-';
    x = flag ? 0 : c - '0';
    while (true) {
        c = getc();
        if (c < '0' || c > '9')
            break;
        (x *= 10) += c - '0';
    }
    if (flag)
        x = -x;
    return x;
}
