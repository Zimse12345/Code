#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int T,n,m,f[N],fac[N],ifac[N],ans;
set<int> g[N]; 

inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

inline int C(int x,int y){
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

void dfs(int l,int r){
    int s=0;
    for(int i=r;i>=l;){
        if(g[i].empty())++s,--i;
        else{
            int L=*g[i].begin();
            g[i].erase(g[i].begin());
            dfs(L,i);
            i=L-1,++s;
        }
    }
    (ans*=f[s])%=Mod;
    return;
}

signed main(){
    fac[0]=ifac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod;
    ifac[N-1]=fpow(fac[N-1]);
    for(int i=N-2;i>=1;i--)ifac[i]=ifac[i+1]*(i+1)%Mod;
    f[0]=f[1]=f[2]=1;
    for(int i=3;i<N/2;i++){
        f[i]=C(i*2-2,i-1)*fpow(i)%Mod;
    }
    cin>>T;
    while(T--){
        cin>>n>>m;
        ans=1;
        for(int i=1,l,r;i<=m;i++){
            cin>>l>>r;
            g[r].insert(l);
        }
        dfs(1,n);
        printf("%lld\n",ans);
    }
    return 0;
}


