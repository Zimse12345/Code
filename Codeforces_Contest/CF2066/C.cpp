#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=1000000007;
int T,n,a[N];
map<int,int> mp;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        mp.clear();
        mp[0]=1;
        int p=1,sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]^=a[i-1];
            if(a[i]==a[i-1])p=p*3%Mod;
            else{
                (mp[a[i-1]]*=3)%=Mod;
                (mp[a[i-1]]+=mp[a[i]]*2)%=Mod;
            }
        }
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
            (sum+=it->second)%=Mod;
        }
        printf("%lld\n",sum*p%Mod);
    }
    return 0;
}


