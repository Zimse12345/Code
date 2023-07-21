#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        if(n==1){
            printf("1\n");
            continue;
        }
        if(n==2){
            printf("1 2\n");
            continue;
        }
        int cur=0;
        a[(n+1)/2]=++cur;
        a[1]=++cur;
        a[n]=++cur;
        for(int i=1;i<=n;i++){
            if(!a[i])a[i]=++cur;
            printf("%d ",a[i]);
            a[i]=0;
        }
    }
    return 0;
}


