// fastio.h

#ifndef _FASTIO_H_
#define _FASTIO_H_

#include <iostream>

namespace fastio {
    void read(int &x) {
        x = 0;
        char c = std::cin.get();
        while (c < '0' || c > '9')
            c = std::cin.get();
        while (c >= '0' && c <= '9') {
            x = x * 10 + c - '0';
            c = std::cin.get();
        }
    }

    void write(int x) {
        int y = 10, len = 1;
        while (y <= x) {
            y *= 10;
            len++;
        }
        while (len--) {
            y /= 10;
            std::cout.put(x / y + 48);
            x %= y;
        }
    }
};
#endif