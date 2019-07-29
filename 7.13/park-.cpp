#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<vector>
#define var register int
const int Max=1e4+7;
int t[Max],n,m,i,j;
int main() {
	freopen("park.in","r",stdin);
	freopen("park.out","w",stdout);
	scanf("%d%d",&n,&m);
	int maxt=0;
	for(i=1; i<=m; i++) {
		scanf("%d",&t[i]);
		maxt=std::max(maxt,t[i]);
	}
	long long L=1;
	long long R=(long long)(maxt)*n,num;
	while(L<R) {
		long long mid=(R+L)>>1;
		num=0;
		for(i=1; i<=m; i++)num+=(int)ceil(mid*1.0/t[i]);
		if(num>=n)R=mid;
		else L=mid+1;
	}
	L--;
	num=0;
	for(i=1; i<=m; i++)
		num+=(int)std::ceil(L*1.0/t[i]);
	for(i=1; i<=m; i++)
		if(L%t[i]==0) {
			num++;
			if(num==n) {
				printf("%d",i);
				break;
			}
		}
	return 0;
}
