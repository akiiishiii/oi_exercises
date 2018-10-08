#include <cstdlib>
#include <cstdio>
#include <ctime>

int main() {
    for (int T = 1; T <= 10000; T++) {
        system("C:\\random");
        double st = clock();
        system("C:\\restore");
        double ed = clock();
        if (system("fc C:\\restore.out C:\\restore.ans")) {
            printf("Wrong Answer, #%d, %.0lfms\n", T, ed - st);
            system("pause");
        } else
            printf("Accepted, #%d, %.0lfms\n", T, ed - st);
    }
    return 0;
}
