#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k,x[N];
map<int,int> mp;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        mp.clear();
        int m=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(mp[k-x[i]]>0)--mp[k-x[i]],++m;
            else ++mp[x[i]];
        }
        printf("%d\n",m);
    }
    return 0;
}


