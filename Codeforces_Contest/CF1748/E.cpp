/********************************
*FileName:
*Author: Zimse
*Data: 2022-11-
*Description:
*Other:
********************************/

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
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

using namespace std;

namespace Zimse{
// const int Mod=998244353;
const int Mod=1000000007;

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
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1000007;

int T,n,m,a[N],rt,lc[N],rc[N],tot,ans;
set<int> pos[N];
vector<int> f[N];

int build(int L,int R){
    if(R<L)return 0;
    int id=++tot;
    for(int i=m;i>=1;i--){
        int p=*pos[i].lower_bound(L);
        if(p>R)continue;
        lc[id]=build(L,p-1),rc[id]=build(p+1,R);
        break;
    }
    return id;
}

void dp(int u){
    if(!u)return;
    dp(lc[u]),dp(rc[u]);
    for(int i=1,s0=0,s1=0;i<=m;i++){
        if(lc[u])addmod(s0,f[lc[u]][i-1]);
        else s0=1;
        if(rc[u])addmod(s1,f[rc[u]][i]);
        else s1=1;
        f[u][i]=s0*s1%Mod;
    }
    return;
}

signed main(){
    T=read();
    while(T--){
        n=read(),m=read();
        for(int i=1;i<=m;i++)pos[i].insert(n+1);
        for(int i=1;i<=n;i++)a[i]=read(),pos[a[i]].insert(i),f[i].resize(m+1);
        rt=build(1,n);

        dp(1);
        for(int i=1;i<=m;i++)addmod(ans,f[1][i]);
        _write(ans);

        for(int i=1;i<=m;i++)pos[i].clear();
        for(int i=1;i<=n;i++)lc[i]=rc[i]=0,f[i].resize(0);
        rt=tot=ans=0;
    }
    return 0;
}
