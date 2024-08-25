#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        if(n&1){
            int l=1,r=n;
            for(int i=1;i<=n;i++){
                if(i&1)a[l]=i,++l;
                else a[r]=i,--r;
            }
            for(int i=1;i<=n;i++)printf("%d ",a[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}


