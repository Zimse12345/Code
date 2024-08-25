#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a,mx,cnt[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        mx=0;
        for(int i=1;i<=n;i++)cnt[i]=0;
        for(int i=1;i<=n;i++){
            cin>>a;
            ++cnt[a];
            mx=max(mx,cnt[a]);
        }
        printf("%d\n",n-mx);
    }
    return 0;
}


