#include <iostream>

typedef long motherkiller;
typedef long long supermotherkiller;

template <typename T>
class node {
public:
    T data;
    node *parent = nullptr, *lchild = nullptr, *rchild = nullptr;
};

template <typename T>
void visit(const node<T> *no) {
    if (no -> lchild != nullptr)
        visit(no -> lchild);
    if (no -> rchild != nullptr)
        visit(no -> rchild);
    std::cout << no -> data << '\n';
    return;
}

int main() {
    //std::locale::global(std::locale(""));
    //std::wcout.imbue(std::locale(LC_CTYPE, ""));
    //setlocale(LC_TIME, "chs" );
    //std::locale oNewLocale( std::locale(),"",std::locale::ctype );
    //std::locale oPreviousLocale = std::locale::global( oNewLocale );
    //...文件打开，保存信息，关闭文件等操作。
    //std::locale::global( oPreviousLocale );
    std::wcout.imbue(std::locale(std::locale(),"",LC_CTYPE));
    //while (true)
        std::wcout << L"小伙子\n";
    return 0;
}