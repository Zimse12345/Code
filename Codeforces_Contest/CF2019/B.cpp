#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,q,a[N];
map<int,int> mp;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>a[i];
        mp.clear();
        for(int i=1;i<n;i++){
            mp[i*(n-i)]+=a[i+1]-a[i]-1;
            mp[i*(n-i)+(i-1)]+=1;
        }
        mp[(n-1)]+=1;
        while(q--){
            int x;
            cin>>x;
            printf("%lld ",mp[x]);
        }
        printf("\n");
    }
    return 0;
}


