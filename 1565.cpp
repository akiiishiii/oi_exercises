// 1565.cpp
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    int m, n;
    std::vector<int> v, f;
    std::cin >> n >> m;
    v.resize()
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::cout <<  << '\n';
    return 0;
}

#include<iostream>
#include<cstdio>
#include<deque>
#define inf 999999999999999LL
using namespace std;
long long a[1000005];
struct node{
	long long n;
	long long w;
};
deque<node>q;
void pushq(long long x,long long y){
	node temp;
	temp.w=x;
	temp.n=y;
	q.push_back(temp);
}
long long f[1000005];
int main(){
	long long n,m,i,j,k,ans;
	ans=inf;
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for(i=0;i<=n;i++){
		f[i]=a[i]+q.front().w;
		while(q.size()&&q.back().w>f[i])q.pop_back();
		pushq(f[i],i);
		while(q.size()&&q.front().n<i-m+1)q.pop_front();
	}
	for(i=n;i>n-m;i--)ans=min(ans,f[i]);
	cout<<ans;
    return 0;
}