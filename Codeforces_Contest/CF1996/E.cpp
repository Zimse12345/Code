#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=1000000007;
int T,n;
char s[N];
map<int,int> mp;

signed main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        mp.clear();
        mp[0]=1;
        int ans=0;
        for(int i=1,sum=0;i<=n;i++){
            if(s[i]=='1')++sum;
            else --sum;
            ans=(ans+(n-i+1)*mp[sum])%Mod;
            mp[sum]=(mp[sum]+i+1)%Mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


