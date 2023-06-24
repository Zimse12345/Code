// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=65536;
int n,a[N],mn,ans;
int f[2][N],T,g[N][4];

inline bool dfs(vector<int> val){
    if(!val.size())return true;
    int sz=val.size(),mx=val[sz-1];
    for(int i=1;i<=mx;i++){
        vector<int> _val;
        for(int j=0;j<sz;j++)if(val[j]%i)_val.pb(val[j]%i);
        sort(_val.begin(),_val.end());
        _val.erase(unique(_val.begin(),_val.end()),_val.end());
        if(!dfs(_val))return true;
    }
    return false;
}

signed main(){
    iF("candy.in");
    oF("candy.out");

    f[T][0]=1,g[0][0]=1;
    n=read(),mn=INF,ans=1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        mn=min(mn,a[i]),ans=1ll*ans*a[i]%Mod;
        T^=1;
        for(int j=0;j<N;j++)f[T][j]=0;
        for(int j=0;j<N;j++){
            for(int k=0;k<a[i]/12;k++)_mod(f[T][j|(1<<k)],f[T^1][j]);
        }
        for(int j=0;j<4;j++){
            if(a[i]>=4)_mod(g[i][j|1],g[i-1][j]);
            if(a[i]>=8)_mod(g[i][j|2],g[i-1][j]);
        }
    }
    _mod(ans,-min(2,mn)-g[n][3]);
    for(int i=0;i<N;i++)if(f[T][i]){
        vector<int> val;
        for(int j=0;j<16;j++)if(i&(1<<j))val.pb((j+1)*12);
        if(!dfs(val))_mod(ans,-f[T][i]);
    }
    _mod(ans,Mod),_wri(ans);
    return 0;
}

