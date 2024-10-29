#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int n,a[N],fac[N],ifac[N];
vector<int> g[N];

inline int fpow(long long x,int y=Mod-2){
int z=1;while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

int C(int x,int y){
    return fac[x]*ifac[y]%Mod*ifac[x-y]%Mod;
}

int sol(int l,int r){
    if(l==r)return 1;
    g[l].push_back(r+1);
    int res=1,pre=0;
    for(unsigned i=0;i+1<g[l].size();i++){
        res=res*sol(g[l][i],g[l][i+1]-1)%Mod;
        int len=g[l][i+1]-g[l][i];
        res=res*C(len-1+pre,pre)%Mod;
        pre+=len;
    }
    return res;
}

signed main(){
    cin>>n;
    fac[0]=ifac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%Mod;
        ifac[i]=fpow(fac[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        g[a[i]].push_back(i);
    }
    printf("%lld\n",sol(0,n));
    return 0;
}


