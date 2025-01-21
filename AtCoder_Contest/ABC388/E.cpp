#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N],ans;

bool ck(int x){
    for(int i=1;i<=x;i++){
        if(a[i]*2>a[n-x+i])return false;
    }
    return true;
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int L=1,R=n/2;
    while(L<=R){
        int M=(L+R)/2;
        if(ck(M))ans=M,L=M+1;
        else R=M-1;
    }
    printf("%d\n",ans);
    return 0;
}


