#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,b[N],a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<n;i++){
            cin>>b[i];
        }
        a[1]=b[1],a[n]=b[n-1];
        for(int i=2;i<n;i++)a[i]=(b[i-1]|b[i]);
        int tag=1;
        for(int i=1;i<n;i++)if((a[i]&a[i+1])!=b[i])tag=0;
        if(tag){
            for(int i=1;i<=n;i++)printf("%d ",a[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}


