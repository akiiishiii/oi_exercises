// result.cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class bigInt {
    /*
    This class is capable of calculating big non-negative numbers of any length.
    You must include header files **iostream**,**algorithm**,**cstdio** and
    **vector** before using this class!
    */
    typedef std::vector<int> Container;

  protected:
    Container v; // Every Digit is stored in this vector in the reverse order
    static Container &bIsort(Container &v) {
        for (int i = 0; i < (int)v.size(); i++) {
            if (v[i] > 9) {
                if (i == (int)v.size() - 1)
                    v.push_back(v[i] / 10);
                else
                    v[i + 1] += v[i] / 10;
                v[i] %= 10;
            }
        }
        return v;
    }
    static Container lng2vec(unsigned long long v) {
        Container c;
        while (v) {
            c.push_back(v % 10);
            v /= 10;
        }
        return c;
    }
    static Container &trimPre0(Container &v) {
        int cnt = 0;
        int i = v.size() - 1;
        while (i >= 0 && v[i] == 0)
            i--, cnt++;
        v.resize(v.size() - cnt);
        if (v.size() == 0)
            v.push_back(0);
        return v;
    }
    static Container easyDiv(bigInt &bI1, const bigInt &bI2) {
        unsigned long long cnt = 0;
        while (bI1 >= bI2) {
            bI1 -= bI2;
            cnt++;
        }
        return lng2vec(cnt);
    }

  public:
    bigInt() {
        v.clear();
        v.push_back(0);
    }
    bigInt(long long n) { setV(n); }
    bigInt(const Container &c) { setV(c); }
    bigInt(const std::string &s) { setV(s); }
    void setV(long long n) {
        v = lng2vec(n);
        trimPre0(v);
    }
    void setV(const Container &c) {
        v = c;
        trimPre0(v);
    }
    void setV(const std::string &s) {
        for (int i = s.size() - 1; i >= 0; i--)
            v.push_back(s[i] - '0');
        trimPre0(v);
    }
    bigInt &operator=(const bigInt &bI) {
        this->v = bI.v;
        return *this;
    }
    bool operator<(const bigInt &bI2) const {
        if (v.size() != bI2.v.size())
            return v.size() < bI2.v.size();
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] != bI2.v[i])
                return v[i] < bI2.v[i];
        }
        return false;
    }
    bool operator>(const bigInt &bI2) const {
        if (v.size() != bI2.v.size())
            return v.size() > bI2.v.size();
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] != bI2.v[i])
                return v[i] > bI2.v[i];
        }
        return false;
    }
    bool operator<=(const bigInt &bI2) const {
        return (*this) < bI2 || (*this) == bI2;
    }
    bool operator>=(const bigInt &bI2) const {
        return (*this) > bI2 || (*this) == bI2;
    }
    bool operator==(const bigInt &bI2) const { return v == bI2.v; }
    bigInt &operator+=(const bigInt &bI2) {
        Container &s1 = v;
        const Container &s2 = bI2.v;
        if (s1.size() < s2.size())
            s1.resize(s2.size());
        int s1Len = s1.size(), s2Len = s2.size();
        for (int i = 0; i < s2Len; i++)
            s1[i] += s2[i];
        for (int i = 0; i < s1Len - 1; i++)
            if (s1[i] > 9) {
                s1[i + 1] += s1[i] / 10;
                s1[i] %= 10;
            }
        if (s1[s1Len - 1] > 9) {
            s1.push_back(s1[s1Len - 1] / 10);
            s1[s1Len - 1] %= 10;
        }
        return *this;
    }
    bigInt operator+(const bigInt &bI2) const {
        bigInt bI1 = *this;
        bI1 += bI2;
        return bI1;
    }
    bigInt &operator-=(const bigInt &bI2) {
        Container &s1 = v;
        const Container &s2 = bI2.v;
        bool flag = false;
        if ((*this) < bI2)
            flag = true, s1.resize(s2.size());
        int s1Len = s1.size(), s2Len = s2.size();
        for (int i = 0; i < s2Len; i++)
            s1[i] -= s2[i];
        if (flag)
            for (int i = 0; i < s2Len; i++)
                s1[i] = -s1[i];
        for (int i = 0; i < s1Len - 1; i++)
            if (s1[i] < 0) {
                s1[i + 1] -= 1;
                s1[i] += 10;
            }
        trimPre0(s1);
        return *this;
    }
    bigInt operator-(const bigInt &bI2) const {
        bigInt bI1 = *this;
        bI1 -= bI2;
        return bI1;
    }
    bigInt operator*(const bigInt &bI2) const {
        const Container &v1 = v;
        const Container &v2 = bI2.v;
        Container v3;
        v3.resize(v1.size() + v2.size(), 0);
        for (int i = 0; i < (int)v2.size(); i++) {
            for (int j = 0; j < (int)v1.size(); j++) {
                v3[i + j] += v2[i] * v1[j];
            }
        }
        bIsort(v3);
        return bigInt(trimPre0(v3));
    }
    bigInt &operator*=(const bigInt &bI2) {
        *this = (*this) * bI2;
        return *this;
    }
    bigInt operator/(const unsigned long long &bI2) const {
        const Container &v1 = v;
        long long v2 = bI2;
        Container v3;
        long long div = 0;
        for (int i = v1.size() - 1; i >= 0; i--) {
            div *= 10;
            div += v1[i];
            if (div < v2) {
                v3.push_back(0);
                continue;
            }
            Container tmp = lng2vec(div / v2);
            v3.insert(v3.end(), tmp.begin(), tmp.end());
            div %= v2;
        }
        std::reverse(v3.begin(), v3.end());
        return bigInt(trimPre0(v3));
    }
    unsigned long long operator%(const unsigned long long &bI2) const {
        const Container &v1 = v;
        unsigned long long v2 = bI2;
        unsigned long long div = 0;
        for (int i = v1.size() - 1; i >= 0; i--) {
            div *= 10;
            div += v1[i];
            if (div < v2)
                continue;
            div %= v2;
        }
        return div % v2;
    }
    bigInt operator/(const bigInt &bI2) const {
        const Container &v1 = v;
        const Container &v2 = bI2.v;
        Container v3;
        bigInt div = 0;
        for (int i = v1.size() - 1; i >= 0; i--) {
            div *= 10;
            div += v1[i];
            if (div < v2) {
                v3.push_back(0);
                continue;
            }
            Container tmp = easyDiv(div, v2);
            v3.insert(v3.end(), tmp.begin(), tmp.end());
        }
        std::reverse(v3.begin(), v3.end());
        return bigInt(trimPre0(v3));
    }
    bigInt &operator/=(const bigInt &bI2) {
        *this = (*this) / bI2;
        return *this;
    }
    bigInt operator%(const bigInt &bI2) const {
        const Container &v1 = v;
        const Container &v2 = bI2.v;
        bigInt div = 0;
        for (int i = v1.size() - 1; i >= 0; i--) {
            div *= 10;
            div += v1[i];
            if (div < v2)
                continue;
            easyDiv(div, v2);
        }
        return div;
    }
    bigInt &operator%=(const bigInt &bI2) {
        *this = (*this) % bI2;
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, bigInt &bI) {
        std::string s;
        in >> s;
        bI.v.clear();
        for (int i = s.size() - 1; i >= 0; i--)
            bI.v.push_back(s[i] - '0');
        trimPre0(bI.v);
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, bigInt &bI) {
        for (int i = bI.v.size() - 1; i >= 0; i--)
            out << (char)(bI.v[i] + '0');
        return out;
    }
    void scan() {
        v.clear();
        scanf(" ");
        char c;
        do {
            c = getchar();
            if (c <= '9' && c >= '0')
                v.push_back(c - '0');
            else {
                ungetc(c, stdin);
                break;
            }
        } while (1);
        std::reverse(v.begin(), v.end());
        trimPre0(v);
    }
    void print() {
        for (int i = v.size() - 1; i >= 0; i--) {
            printf("%d", v[i]);
        }
    }
    bool isZero() { return (v.size() == 1 && v[0] == 0); }
};

class sBigInt {
    /*
    This class is capable of calculating big signed numbers of any length.
    The "sBigInt" class is dependent on the "bigInt" class.
    */
  protected:
    bigInt bI;
    bool sign; // T:Negetive,F:Positive
  public:
    sBigInt() {
        bI.setV(0);
        sign = false;
    }
    sBigInt(long long n) {
        if (n < 0) {
            sign = true;
            n = -n;
        } else
            sign = false;
        bI.setV(n);
    }
    sBigInt(std::string s) {
        if (s[0] == '+' || s[0] == '-') {
            sign = (s[0] == '-');
            s.erase(s.begin());
        }
        bI.setV(s);
    }
    sBigInt &operator=(const sBigInt &bI) {
        this->bI = bI.bI;
        this->sign = bI.sign;
        return *this;
    }
    bool operator<(const sBigInt &bI2) const {
        if (this->sign != bI2.sign)
            return this->sign;
        if (this->sign)
            return this->bI > bI2.bI;
        else
            return this->bI < bI2.bI;
    }
    bool operator>(const sBigInt &bI2) const {
        if (this->sign != bI2.sign)
            return !(this->sign);
        if (this->sign)
            return this->bI < bI2.bI;
        else
            return this->bI > bI2.bI;
    }
    bool operator==(const sBigInt &bI2) const {
        return this->sign == bI2.sign && this->bI == bI2.bI;
    }
    bool operator<=(const sBigInt &bI2) const {
        return (*this) < bI2 || (*this) == bI2;
    }
    bool operator>=(const sBigInt &bI2) const {
        return (*this) > bI2 || (*this) == bI2;
    }
    sBigInt operator+(const sBigInt &bI2) const {
        sBigInt result(0);
        if (this->sign == bI2.sign) {
            result.sign = this->sign;
            result.bI = this->bI + bI2.bI;
            return result;
        }
        result.bI = this->bI - bI2.bI;
        result.sign = ((this->bI) > (bI2.bI)) ? this->sign : bI2.sign;
        return result;
    }
    sBigInt operator-(const sBigInt &bI2) const {
        sBigInt result(0);
        if (this->sign != bI2.sign) {
            result.sign = this->sign;
            result.bI = this->bI + bI2.bI;
            return result;
        }
        result.bI = this->bI - bI2.bI;
        bool flag1 = this->sign, flag2 = ((this->bI) > (bI2.bI));
        result.sign = ((flag1 && flag2) || (!flag1 && !flag2));
        return result;
    }
    sBigInt operator*(const sBigInt &bI2) const {
        sBigInt result(0);
        result.sign = (this->sign) ^ (bI2.sign);
        result.bI = (this->bI) * (bI2.bI);
        return result;
    }
    sBigInt operator/(const sBigInt &bI2) const {
        sBigInt result(0);
        result.sign = (this->sign) ^ (bI2.sign);
        result.bI = (this->bI) / (bI2.bI);
        return result;
    }
    sBigInt operator%(const sBigInt &bI2) const {
        sBigInt result(0);
        result.sign = false;
        result.bI = (this->bI) % (bI2.bI);
        return result;
    }
    sBigInt &operator+=(const sBigInt &bI2) {
        *this = (*this) + bI2;
        return *this;
    }
    sBigInt &operator-=(const sBigInt &bI2) {
        *this = (*this) - bI2;
        return *this;
    }
    sBigInt &operator*=(const sBigInt &bI2) {
        *this = (*this) * bI2;
        return *this;
    }
    sBigInt &operator/=(const sBigInt &bI2) {
        *this = (*this) / bI2;
        return *this;
    }
    sBigInt &operator%=(const sBigInt &bI2) {
        *this = (*this) % bI2;
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, sBigInt &bI) {
        bI.sign = false;
        do {
            char c = in.peek();
            if (c <= '9' && c >= '0')
                break;
            else if (c == '-')
                bI.sign ^= true;
            in.get();
        } while (1);
        in >> (bI.bI);
        if (bI.sign && bI.bI == bigInt(0))
            bI.sign = false;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, sBigInt &bI) {
        if (bI.sign)
            out << "-";
        out << (bI.bI);
        return out;
    }
    void scan() {
        this->sign = false;
        do {
            char c = getchar();
            if (c <= '9' && c >= '0') {
                ungetc(c, stdin);
                break;
            } else if (c == '-')
                this->sign ^= true;
        } while (1);
        bI.scan();
        if (this->sign && this->bI == bigInt(0))
            this->sign = false;
    }
    void print() {
        if (this->sign)
            printf("-");
        bI.print();
    }
    bool isZero() { return bI.isZero(); }
};

int const C = 2009;

void mul(sBigInt a[4][4], sBigInt b[4][4]);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int p;
    sBigInt n, mat[4][4], ans[4][4];
    std::cin >> n >> p;
    mat[1][1] = 1, mat[1][2] = 0, mat[1][3] = 0;
    mat[2][1] = p, mat[2][2] = p, mat[2][3] = 0;
    mat[3][1] = p, mat[3][2] = p, mat[3][3] = p;
    ans[1][1] = ans[2][2] = ans[3][3] = 1;
    while (!(n.isZero())) {
        if (n % 2 == 1)
            mul(ans, mat);
        mul(mat, mat);
        n /= 2;
    }
    ans[3][1] %= C;
    std::cout << ans[3][1] << '\n';
    return 0;
}

void mul(sBigInt a[4][4], sBigInt b[4][4]) {
    sBigInt tmp[4][4];
    for (int m = 1; m <= 3; m++)
        for (int n = 1; n <= 3; n++) {
            tmp[m][n] = (a[m][1] % C * b[1][n] % C) % C +
                        (a[m][2] % C * b[2][n] % C) % C +
                        (a[m][3] % C * b[3][n] % C) % C;
        }
    for (int m = 1; m <= 3; m++)
        for (int n = 1; n <= 3; n++)
            a[m][n] = tmp[m][n];
}