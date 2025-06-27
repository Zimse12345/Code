#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=k;i++)printf("1");
        for(int i=k+1;i<=n;i++)printf("0");
        printf("\n");
    }
    return 0;
}


