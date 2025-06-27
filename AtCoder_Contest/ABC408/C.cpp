#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m,t[N];

signed main(){
    cin>>n>>m;
    for(int i=1,l,r;i<=m;i++){
        cin>>l>>r;
        ++t[l],--t[r+1];
    }
    int ans=m;
    for(int i=1;i<=n;i++){
        t[i]+=t[i-1];
        ans=min(ans,t[i]);
    }
    printf("%d\n",ans);
    return 0;
}


