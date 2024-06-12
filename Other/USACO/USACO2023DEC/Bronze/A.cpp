#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,m,a[N]; 

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(m--){
        int l=0,r;
        cin>>r;
        for(int i=1;i<=n;i++){
            if(a[i]>l){
                int x=a[i];
                a[i]+=min(r,a[i])-l,l=x;
            }
            if(l>=r)break;
        }
    }
    for(int i=1;i<=n;i++)printf("%lld\n",a[i]);
    return 0;
}


