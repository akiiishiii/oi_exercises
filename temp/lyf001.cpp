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
    if(is_fu(s[now])){
        switch(s[now][0]){
            case '+': return dfs(++head) + dfs(++head);
            case '-': return dfs(++head) - dfs(++head);
            case '*': return dfs(++head) * dfs(++head);
            case '/': return dfs(++head) / dfs(++head);
        }
    }else{
        switch(s[now][0]){
            case '+': return stof(s[++head]) + stof(s[++head]);
            case '-': return stof(s[++head]) - stof(s[++head]);
            case '*': return stof(s[++head]) * stof(s[++head]);
            case '/': return stof(s[++head]) / stof(s[++head]);
        }
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
