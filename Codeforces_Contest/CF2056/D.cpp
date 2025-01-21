#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N],ans,b[N];
map<int,int> mp; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        ans=n*(n+1)/2;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int v=1;v<10;v++){
            for(int i=1;i<=n;i++){
                if(a[i]<=v)b[i]=1;
                else b[i]=-1;
            }
            mp.clear();
            mp[0]++;
            for(int i=1,s=0;i<=n;i++){
                s+=b[i];
                ans-=mp[s];
                mp[s]++;
            }
            
            for(int i=1;i<=n;i++){
                if(a[i]<v)b[i]=1;
                else if(a[i]==v)b[i]=n*100;
                else b[i]=-1;
            }
            mp.clear();
            mp[0]++;
            for(int i=1,s=0;i<=n;i++){
                s+=b[i];
                ans+=mp[s];
                mp[s]++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}


