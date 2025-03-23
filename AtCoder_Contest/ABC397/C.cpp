#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N],t[N],tt[N],ans,s;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!tt[a[i]])++s;
        ++tt[a[i]];
    }
    for(int i=1;i<=n;i++){
        if(!t[a[i]])++s;
        ++t[a[i]];
        --tt[a[i]];
        if(!tt[a[i]])--s;
        ans=max(ans,s);
    }
    printf("%d\n",ans);
    return 0;
}


