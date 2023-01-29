/************************
*FileName:
*Author: Zimse
*Data: 2023-01-
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
// #define M ((L+R)/2)
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

int T,n,fa[N],lc[N],rc[N],tag[N],rev[N],ans[N];

void dfs(int u){
    if(!u)return;
    dfs(lc[u]),dfs(rc[u]);
    if(rc[u]){
        if(tag[rc[u]]<tag[lc[u]])swap(lc[u],rc[u]);
        if(tag[lc[u]]==1){
            if(tag[rc[u]]==1&&(lc[lc[u]]||lc[rc[u]])){
                tag[u]=1;
                if(lc[lc[u]])rev[rc[u]]^=1;
                else rev[lc[u]]^=1;
            }
            else{
                tag[u]=4-tag[rc[u]];
                rev[lc[u]]^=1,rev[rc[u]]^=1;
            }
        }
        else if(tag[lc[u]]==2){
            if(tag[rc[u]]==2)tag[u]=1,rev[lc[u]]^=1,rev[rc[u]]^=1;
            else tag[u]=2,rev[lc[u]]^=1;
        }
        else tag[u]=1,rev[lc[u]]^=1;
    }
    else if(lc[u]){
        if(tag[lc[u]]==1)tag[u]=2,rev[lc[u]]^=1;
        else if(tag[lc[u]]==2)tag[u]=1,rev[lc[u]]^=1;
        else{
            if(u==1)rev[lc[u]]^=1;
            else tag[u]=2;
        }
    }
    else tag[u]=1;
    return;
}

void dfs2(int u,int pre){
    pre^=rev[u];
    ans[u]=pre;
    if(lc[u])dfs2(lc[u],pre);
    if(rc[u])dfs2(rc[u],pre);
    return;
}

signed main(){
    T=read();
    while(T--){
        n=read();
        lc[1]=rc[1]=rev[1]=0;
        for(int i=2;i<=n;i++){
            lc[i]=rc[i]=rev[i]=0;
            fa[i]=read();
            if(!lc[fa[i]])lc[fa[i]]=i;
            else rc[fa[i]]=i;
            if(i==4&&fa[3]==2&&fa[4]==2)_write(2);
            else _write(i&1);
        }
        dfs(1);
        dfs2(1,0);
        for(int i=1;i<=n;i++)pc(ans[i]?'w':'b');
        pc(10);
    }
    return 0;
}
