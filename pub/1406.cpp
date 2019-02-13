// 1406.cpp
#include <iostream>
#include <string>

std::string st;

std::string iszm(int left, int right) {
    std::string data;
    for(int i = left; i <= right; i++) {
        if (st[i] >= 'a' && st[i] <= 'z')
            data += st[i];
        else
            return "-1";
    }
    return data;
}

int findlow(int left, int right) {
    int t = 0, k = -1;
    for(int i = right; i >= left; i--) {
        if ((st[i] >= '0' && st[i] <= '9'))
            continue;
        if (st[i] == '(')
            t++;
        if (st[i] == ')')
            t--;
        if ((st[i] == '+' || st[i] == '-') && t == 0)
            return i;
        if ((st[i] == '*' || st[i] == '/') && t == 0 && k == -1)
            k = i;
    }
    return k;
}

int poskh(int left, int right){
    int t = 0;
    for(int i = left; i <= right; i++){
        if (st[i] == '(')
            t++;
        if (st[i] == ')')
            t--;
        if (!t)
            return i;
    }
    return -1;
}

std::string tree(int left, int right, char &low) {
    std::string s1, s2, s;
    char lowl, lowr;
    s = iszm(left, right);
    if (s != "-1")
        return s;
    if (st[left] == '(' && poskh(left, right) == right)
        return tree(left + 1, right - 1, low);
    int p = findlow(left, right);
    low = st[p];
    s1 = tree(left, p - 1, lowl);
    s2 = tree(p + 1, right, lowr);
    if ((low == '*' || low == '/') && (lowl == '+' || lowl == '-'))
        s1 = '(' + s1 + ')';
    if ((low == '*' || low == '-') && (lowr == '+' || lowr == '-'))
        s2 = '(' + s2 + ')';
    if ((low == '/') && (lowr != ' '))
        s2 = '(' + s2+ ')';
    return s1 + low + s2;
}

int main(int argc, char const *argv[]) {
    std::cin >> st;
    char low = ' ';
    int t = 0;
    for (int i = st.length() - 1; i >= 0; i--)
        if (st[i] < 'a' || st[i] > 'z') {
            if (st[i] == ')')
                t++;
            else if (st[i] == '(')
                t--;
            else if (!t) {
                if (low == '+' || low == '-')
                    break;
                else
                    low = st[i];
            }
        }
    std::cout << tree(0, st.length() - 1, low);
    return 0;
}
