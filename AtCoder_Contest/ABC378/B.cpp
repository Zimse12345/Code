#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,q[N],r[N],Q,t,d;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>q[i]>>r[i];
    cin>>Q;
    while(Q--){
        cin>>t;
        cin>>d;
        if(d%q[t]>r[t])d+=q[t]-d%q[t];
        if(d%q[t]<=r[t])d+=r[t]-d%q[t];
        printf("%d\n",d);
    }
    return 0;
}


