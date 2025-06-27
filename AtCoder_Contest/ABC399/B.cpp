#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,p[N],rk[N],r=1;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    while(r<=n){
        int mx=0,cnt=0;
        for(int i=1;i<=n;i++)if(!rk[i])mx=max(mx,p[i]);
        for(int i=1;i<=n;i++){
            if(p[i]==mx){
                rk[i]=r;
                ++cnt;
            }
        }
        r+=cnt;
    }
    for(int i=1;i<=n;i++)printf("%d\n",rk[i]);
    return 0;
}


