#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int n,m,f[N],g[N];
struct line{
    int l,r,p;
    line(int l=0,int r=0,int p=0):l(l),r(r),p(p){}
    bool operator < (const line& _)const{return r<_.r;}
}a[N];

inline int fpow(long long x,int y=Mod-2)
{int z=1;while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}

signed main(){
    cin>>n>>m;
    f[0]=1;
    for(int i=0;i<=m;i++)g[i]=1;
    for(int i=1,p,q;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        cin>>p>>q;
        a[i].p=p*fpow(q)%Mod;
        (g[a[i].r]*=(1-a[i].p))%=Mod;
    }
    for(int i=1;i<=m;i++)(g[i]*=g[i-1])%=Mod;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        (f[a[i].r]+=f[a[i].l-1]*(a[i].p*fpow(1-a[i].p)%Mod*g[a[i].r]%Mod*fpow(g[a[i].l-1])%Mod))%=Mod;
    }
    (f[m]+=Mod)%=Mod;
    printf("%lld\n",f[m]);
    return 0;
}


