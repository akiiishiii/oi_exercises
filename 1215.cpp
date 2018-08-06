// 1215.cpp
#include<cstdio>

int exp,max,ans,pc,lc,ln,cnt,t=1,c,n,cc;
double k[100005],num[100005],kk,nn;
int main(){
    scanf("%d",&exp);
    scanf("%d%d",&c,&n); pc=c;
    while(c!=-1&&n!=-1){
        lc=c,ln=n,num[c]=n;
        scanf("%d%d",&c,&n);
        k[lc]=(n-ln)/(c-lc);
    }
    scanf("%d",&cnt);
    for(int i=pc;i<=lc;++i)
        if(!num[i]) num[i]=kk*(i-cc)+nn;
        else kk=k[i],cc=i,nn=num[i];
    while(ln-cnt>0) lc++,ln-=cnt,num[lc]=ln;
    for(int i=pc;i<=lc;++i) if((i-pc)*num[i]>max) ans=i,max=(i-pc)*num[i];
    if(ans==exp) puts("0");
    else if(ans>exp){
        for(int x=1;;x++){
            max=ans=0;
            for(int i=pc;i<=lc;++i) if((i-pc+x)*num[i]>=max) ans=i,max=(i-pc+x)*num[i];
            if(ans==exp){printf("%d",x);return 0;}
        }
    }
    else{
        for(int x=-1;;x--){
            max=ans=0;
            for(int i=pc+1;i<=lc;++i) if((i-pc+x)*num[i]>=max) ans=i,max=(i-pc+x)*num[i];
            if(ans==exp){printf("%d",x);return 0;}
        }
    }
}
