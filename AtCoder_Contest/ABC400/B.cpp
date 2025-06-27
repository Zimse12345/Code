#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,m,ans;

signed main(){
    cin>>n>>m;
    int v=1;
    for(int i=0;i<=m;i++){
        ans+=v;
        v*=n;
        if(ans>1000000000){
            printf("inf\n");
            return 0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}


