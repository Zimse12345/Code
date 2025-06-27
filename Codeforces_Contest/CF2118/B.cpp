#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        printf("%d\n",n*2-2);
        for(int i=2;i<=n;i++){
            printf("%d %d %d\n",i,1,i);
        }
        for(int i=1;i<n;i++){
            printf("%d %d %d\n",i,i+1,n);
        }
    }
    return 0;
}


