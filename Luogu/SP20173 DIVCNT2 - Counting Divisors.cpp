/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <algorithm>
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
#define pb push_back
#define inv fpow
#define int unsigned long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=50000007;

int T,n,_N,ans,qry[20000];
int prime[N/10],tot,d[N],mu[N];
bool isp[N];
map<int,int> mp,mp2;

inline int D(const int x){
    if(x<N)return d[x];
    if(mp[x])return mp[x];
    int res=0;
    for(int l=1,r=0;l<=x;l=r+1){
        r=x/(x/l);
        res+=(r-l+1)*(x/l);
    }
    mp[x]=res;
    return res;
}

inline int Calc(const int m){
    if(mp2[m])return mp2[m];
    int res=0;
    for(int l=1,r=0;l<=m;l=r+1){
        r=m/(m/l);
        res+=(m/l)*(D(r)-D(l-1));
    }
    mp2[m]=res;
    return res;
}

signed main(){
    _N=0;
    T=read();
    for(int i=1;i<=T;i++)qry[i]=read(),_max(_N,qry[i]*2);
    _min(_N,N);
    d[1]=mu[1]=1;
    for(int i=2;i<_N;i++){
        if(!isp[i])prime[++tot]=i,isp[i]=1,d[i]=2,mu[i]=-1;
        for(int j=1;j<=tot&&prime[j]*i<_N;j++){
            isp[prime[j]*i]=1;
            d[prime[j]*i]=d[i]*2;
            mu[prime[j]*i]=-mu[i];
            if(i%prime[j]==0){
                int c=0,x=i;
                while(x%prime[j]==0)x/=prime[j],++c;
                d[prime[j]*i]=d[i]/(c+1)*(c+2);
                mu[prime[j]*i]=0;
            }
        }
    }
    for(int i=1;i<_N;i++)d[i]+=d[i-1];
    for(int i=1;i<=T;i++){
        n=qry[i],ans=0;
        int _m=0,_c=0;
        for(int k=1;k*k<=n;k++){
            int m=n/k/k;
            if(m!=_m)_m=m,_c=Calc(m);
            ans+=mu[k]*_c;
        }
        _write(ans);
    }
    return 0;
}
