/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-27
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
#define ll long long
//#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1e6+7;

int n,q,hd[N],nxt[N],to[N],ec;
int fa[N],dep[N],cnt[N],son[N],dfn[N],_dfn[N],top[N],Time;
int s[N];

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs0(int u,int from){
    fa[u]=from,dep[u]=dep[from]+1,cnt[u]=1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs0(v,u),cnt[u]+=cnt[v];
        if(cnt[son[u]]<cnt[v])son[u]=v;
    }
    return;
}

void dfs1(int u,int t){
    dfn[u]=++Time,_dfn[Time]=u,top[u]=t;
    // printf("dfn[%d]=%d\n",u,dfn[u]);
    if(son[u])dfs1(son[u],t);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==fa[u]||v==son[u])continue;
        dfs1(v,v);
    }
    return;
}

struct treearray{
    int t[N];
    inline void _init(){for(int i=0;i<N;i++)t[i]=0;return;}
    inline void ub(int& x){x+=(x&(-x));}
    inline void db(int& x){x-=(x&(-x));}
    inline void add(int x,int v){for(;x<N;ub(x))t[x]+=v;return;}
    inline int sum(int x){int res=0;for(;x;db(x))res+=t[x];return res;}
}tree;

void update(int L,int R,int id,int l,int r,int x){
    // if(id==1)printf("[%d,%d] x=%d\n",l,r,x);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)s[id]+=x;
    else update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x);
    return;
}

int query(int L,int R,int id,int x){
    if(L==R)return s[id];
    if(x<=M)return s[id]+query(L,M,Lid,x);
    return s[id]+query(M+1,R,Rid,x);
}

signed main(){
    tree._init();
    n=read(),q=read();
    for(int i=1,u,v;i<n;i++){
        u=read(),v=read();
        add(u,v),add(v,u);
    }
    dfs0(1,0);
    dfs1(1,1);
    while(q--){
        int op=read(),u=read();
        if(!op){
            int x=read(),d=read();
            if(u==1){
                tree.add(d+1,x);
                continue;
            }
            update(1,n,1,dfn[u],dfn[u]+min(cnt[u]-1,d),x);
            update(1,n,1,dfn[u]-min(dep[u]-2,d),dfn[u]-1,x);
            d-=dep[u]-2;
            if(d>0){
                tree.add(d,x);
                if(d>1){
                    u=_dfn[dfn[u]-dep[u]+2];
                    update(1,n,1,dfn[u],dfn[u]+min(d-2,cnt[u]-1),-x);
                }
            }
        }
        else{
            _write(query(1,n,1,dfn[u])+tree.sum(n*2)-tree.sum(dep[u]-1));
        }
    }
    return 0;
}
