/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int T,n,k,q,a[N],f[N],g[N],que[N],ql,qr,ff[N];
char str[N];

void dp(int *F){
    ql=qr=1,que[1]=0;
    for(int i=1;i<=n;i++){
        while(i-que[ql]>k)++ql;
        F[i]=F[que[ql]]+a[i];
        while(ql<=qr&&F[i]<=F[que[qr]])--qr;
        que[++qr]=i;
        if(str[i]&1)ql=qr;
    }
    return;
}

signed main(){
//	ifile("t.in"),ofile("t.out");
    T=read();
    while(T--){
        n=read(),k=read();
        for(int i=1;i<=n;i++)a[i]=read();
        scanf("%s",str+1);
        a[n+1]=0,str[n+1]='0';
        ++n,dp(f),--n;
        for(int i=1;i<=n/2;i++)swap(str[i],str[n-i+1]),swap(a[i],a[n-i+1]);
        dp(g),g[n+1]=0;
        for(int i=1;i<=n/2;i++)swap(g[i],g[n-i+1]),swap(str[i],str[n-i+1]),swap(a[i],a[n-i+1]);
        ++n;
//         for(int i=1;i<=n;i++)printf("F[%lld]=%lld G[%lld]=%lld\n",i,f[i],i,g[i]);
        q=read();
        while(q--){
            int p=read(),v=read();
            int L=max(1ll,p-k-1),R=min(n,p+k+1);
            ql=qr=1,que[1]=0;
            for(int i=L;i<p;i++){
                ff[i]=f[i];
                while(ql<=qr&&f[i]<=f[que[qr]])--qr;
                que[++qr]=i;
                if(str[i]&1)ql=qr;
            }
            int ans=INF*INF;
            for(int i=p;i<=R;i++){
                while(i-que[ql]>k)++ql;
                ff[i]=ff[que[ql]]+(i==p?v:a[i]);
                _min(ans,ff[i]+g[i]-a[i]);
                // printf("i=%lld ff=%lld g=%lld v=%lld s=%lld\n",i,ff[i],g[i],(i==p?v:a[i]),
                // ff[i]+g[i]-a[i]);
                while(ql<=qr&&ff[i]<=ff[que[qr]])--qr;
                que[++qr]=i;
                if(str[i]&1)ql=qr;
            }
            _write(ans);
        }
    }
    return 0;
}
