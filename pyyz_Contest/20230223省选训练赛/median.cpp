/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define pb push_back
#define ll long long
// #define int long long
#define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
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

int n,k,a[N],b[N],s[N],f[24][N],tg[N],c[N],B[N];
int que[N],ql,qr,v[N];

bool check(int x){
    int tag=1;
    for(int i=0;i<=n*2;i++)B[i]=0;
    for(int i=1;i<=n;i++){
        b[i]=(a[i]>=x?1:-1);
        s[i]=s[i-1]+b[i];
        B[n+s[i]]=i;
        if(a[i]<x)tag=0;
    }
    for(int i=n*2;i>=0;i--)_max(B[i],B[i+1]);
    if(tag)return true;
    for(int i=1;i<=n;i++)f[0][i]=i-1;
    for(int i=1,lim=INF;i<=n;i++){
        if(s[i-1]<lim)lim=s[i-1],tg[i]=1;
        else tg[i]=0;
    }
    for(int t=1;t<=min(k,21);t++){
        int V=INF,ed=n;
        ql=1,qr=0;
        for(int i=n;i>=1;i--){
            f[t][i]=0;
            if(!tg[i])continue;
            int C=(f[t-1][i]-i+1)-(s[f[t-1][i]]-s[i-1]);
            while(ql<=qr&&C>=v[qr])--qr;
            v[++qr]=C,que[qr]=f[t-1][i];
            while(ql<=qr){
                int p=B[max(0,s[i-1]-v[ql]+1+n)];
                if(p>=que[ql]){
                    f[t][i]=p;
                    break;
                }
                ++ql;
            }
        }
        if(f[t][1]==n)return true;
    }
    return f[min(k,21)][1]==n;
}

signed main(){
	// ifile("median.in");
	// ofile("median.out");
	
    n=read(),k=read();
    int L=1,R=0,ans=0;
    for(int i=1;i<=n;i++)a[i]=read(),_max(R,a[i]);
    while(L<=R){
        if(check(M))ans=M,L=M+1;
        else R=M-1;
    }
    _write(ans);
    return 0;
}
