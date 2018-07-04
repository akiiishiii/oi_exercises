#include <bits/stdc++.h>
using namespace std;
string s[100100];
int head = 0;
bool is_fu(string a){
    if(a == "*" || a == "+" || a == "-" || a == "/"){
        return true;
    }
    return false;
}//
double dfs(int now){
    switch(s[now][0]){
        case '+': return dfs(++head) + dfs(++head);
        case '-': return dfs(++head) - dfs(++head);
        case '*': return dfs(++head) * dfs(++head);
        case '/': return dfs(++head) / dfs(++head);
        default: return stof(s[now]);
    }
}
int main(){
    int len = 0;
    while(cin >> s[len]){
        len++;
    }// yes
    cout << dfs(head);
    return 0;
}
