#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        if(n==6){
            printf("1 1 2 3 1 2\n");
            continue;
        }
        for(int i=1;i<=n-2;i++)printf("%d ",i);
        printf("1 2\n");
    }
    return 0;
}


