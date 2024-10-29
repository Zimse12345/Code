#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int s[N],t[N];

int get_sg(int a,int x){
    if(a==1){
        return x%2;
    }
    int t=1;
    while(t<=a)t*=2;
    x%=t;
    if(x==0)x=t;
    int sg=0;
    if(x<=t/2){
        if(x<=t/4)sg=get_sg(t/4,x);
        else{
            sg=get_sg(t/4,x-t/4);
            if(x!=t/2)sg++;
        }
    }
    else{
        if(x-t/2<=t/4)sg=get_sg(t/4,x-t/2);
        else{
            sg=get_sg(t/4,x-t/2-t/4);
            if(x-t/2!=t/2)sg++;
        }
        if(x<=a){
            if(x==t)sg=1;
            else ++sg;
        }
        else if(x==t-1&&a!=t/2)sg++;
        else sg^=1;
        if(x==a+1)sg=0;
    }
    return sg;
}

int n,A[N],X[N];
signed main(){
//    int T;
//    cin>>T;
//    while(T--){
//        cin>>n;
//    for(int i=1;i<=n;i++)cin>>A[i];
//    int sg=0;
//    for(int i=1;i<=n;i++){
//        cin>>X[i];
//        sg^=get_sg(A[i],X[i]);
//    }
//    if(sg)printf("Alice\n");
//    else printf("Bob\n");
//    }
    
    for(int a=1;a<16;a++){
        printf("a=%2d | ",a);
        for(int x=1;x<32;x++){
            for(int i=0;i<32;i++)t[i]=0;
            for(int y=1;y<=a;y++)if((y&x)==y)t[s[x-y]]=1;
            s[x]=0;
            while(t[s[x]])++s[x];
//            if(s[x]!=get_sg(a,x))printf("!\n");
            printf("%d.%d ",s[x],get_sg(a,x));
        }
        printf("\n");
    }
    return 0;
}


