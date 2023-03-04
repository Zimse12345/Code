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

int T,n,k,m,c,d,a[N],nd[N];

struct FenwickTree{
    int tr[N];
    inline void ub(int &x){x+=(x&(-x));return;}
    inline void db(int &x){x-=(x&(-x));return;}
    inline void add(int x,int y){x+=200000;if(x<=0||x>=N)return;
        for(;x<N;ub(x))addmod(tr[x],y);return;}
    inline int sum(int x){x+=200000;
        int res=0;for(;x;db(x))addmod(res,tr[x]);return res;}
    inline void clear(){for(int i=0;i<N;i++)tr[i]=0;return;}
}t;

bool check(int x){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x){
            if(d==0){
                if(a[i]+c>=x)nd[i]=1;
                else nd[i]=INF;
            }
            else{
                int rm=max(0ll,x-a[i]-c);
                nd[i]=1+rm/d+(rm%d?1:0);
            }
        }
        else nd[i]=0,++cnt;
    }
    for(int i=1;i<m;i++)if(nd[i])t.add(nd[i]-i,1);
    bool res=false;
    for(int i=m;i<=n;i++){
        if(nd[i])t.add(nd[i]-i,1);
        int s=t.sum(m-i);
        if(s+cnt>=k){
            res=true;
            break;
        }
        if(nd[i-m+1])t.add(nd[i-m+1]-(i-m+1),-1);
    }
    t.clear();
    return res;
}

signed main(){
    T=1;
    while(T--){
        n=read(),k=read(),m=read(),c=read(),d=read();
        for(int i=1;i<=n;i++)a[i]=read();
        int L=1,R=INF*INF,ans=0;
        while(L<=R){
            int M=(L+R)/2;
            if(check(M))ans=M,L=M+1;
            else R=M-1;
        }
        _write(ans);
    }
    return 0;
}
