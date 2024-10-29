#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N],b[N],f[N],s[N];
priority_queue<int> Q,_Q;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],f[i]=1e18,s[i]=s[i-1]+a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        int ans=0;
        f[1]=0;
        while(!Q.empty())Q.pop();
        while(!_Q.empty())_Q.pop();
        Q.push(0);
        for(int i=1;i<=n;i++){
            while(!Q.empty()&&!_Q.empty()&&Q.top()==_Q.top())Q.pop(),_Q.pop();
            if(b[i]>i&&!Q.empty()){
                int x=-Q.top()+a[i];
                if(x<f[b[i]])_Q.push(-f[b[i]]),Q.push(-x),f[b[i]]=x;
            }
            _Q.push(-f[i]);
        }
        for(int i=1;i<=n;i++)ans=max(ans,s[i]-f[i]);
        printf("%lld\n",ans);
    }
    return 0;
}


