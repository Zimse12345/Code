/********************************
*FileName:
*Author: Zimse
*Data: 2022-10-
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
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

using namespace std;

namespace Zimse{
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
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000000000000114514;
}using namespace Zimse;

const int N=1000007;

int n,q,k,v[N],hd[N],nxt[N],to[N],ec;
int fa[N],dep[N],cnt[N],son[N],dfn[N],_dfn[N],top[N],tot,mn[N];

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs0(int u,int from){
    fa[u]=from,dep[u]=dep[from]+1,cnt[u]=1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs0(v,u);
        cnt[u]+=cnt[v];
        if(cnt[son[u]]<cnt[v])son[u]=v;
    }
    return;
}

void dfs1(int u,int t){
    dfn[u]=++tot,top[u]=t,_dfn[tot]=u;
    if(son[u])dfs1(son[u],t);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==fa[u]||v==son[u])continue;
        dfs1(v,v);
    }
    return;
}

struct mixtra{
    int f[3][3],len;
    void init_0(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)f[i][j]=0;
        }
        return;
    }
    void init_inf(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)f[i][j]=INF;
        }
        return;
    }
}tl[N],tr[N];
mixtra p1[N],p2[N];
int c1,c2;

mixtra merge(mixtra x,mixtra y){
    mixtra z;
    z.init_inf();
    z.len=x.len+y.len;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            for(int d1=0;d1<k;d1++){
                for(int d2=0;d1+d2+1<=k;d2++){
                    _min(z.f[i][j],x.f[i][d1]+y.f[d2][j]);
                }
            }
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j+y.len<k;j++){
            _min(z.f[i][j+y.len],x.f[i][j]);
        }
    }
    for(int i=0;i+x.len<k;i++){
        for(int j=0;j<k;j++){
            _min(z.f[i+x.len][j],y.f[i][j]);
        }
    }
    return z;
}

void build(int L,int R,int id){
    if(L==R){
        int p=_dfn[L];
        tl[id].init_inf();
        tl[id].len=1;
        tl[id].f[0][0]=v[p];
        tl[id].f[1][1]=mn[p];
        tr[id]=tl[id];
    }
    else{
        build(L,M,Lid),build(M+1,R,Rid);
        tl[id]=merge(tl[Lid],tl[Rid]);
        tr[id]=merge(tr[Rid],tr[Lid]);
    }
    return;
}

mixtra queryL(int L,int R,int id,int l,int r){
    if(l<=L&&r>=R)return tl[id];
    if(r<=M)return queryL(L,M,Lid,l,r);
    if(l>M)return queryL(M+1,R,Rid,l,r);
    return merge(queryL(L,M,Lid,l,r),queryL(M+1,R,Rid,l,r));
}

mixtra queryR(int L,int R,int id,int l,int r){
    if(l<=L&&r>=R)return tr[id];
    if(r<=M)return queryR(L,M,Lid,l,r);
    if(l>M)return queryR(M+1,R,Rid,l,r);
    return merge(queryR(M+1,R,Rid,l,r),queryR(L,M,Lid,l,r));
}

signed main(){
    n=read(),q=read(),k=read();
    for(int i=1;i<=n;i++)v[i]=read();
    for(int i=1,_u,_v;i<n;i++)_u=read(),_v=read(),add(_u,_v),add(_v,_u);
    for(int i=1;i<=n;i++){
        mn[i]=INF;
        for(int j=hd[i];j;j=nxt[j])_min(mn[i],v[to[j]]);
    }
    dfs0(1,0);
    dfs1(1,1);
    build(1,n,1);
    while(q--){
        int u=read(),v=read();
        while(top[u]^top[v]){
            if(dep[top[u]]>dep[top[v]]){
                p1[++c1]=queryR(1,n,1,dfn[top[u]],dfn[u]);
                u=fa[top[u]];
            }
            else{
                p2[++c2]=queryL(1,n,1,dfn[top[v]],dfn[v]);
                v=fa[top[v]];
            }
        }int ty=0;
        if(dep[u]>dep[v])p1[++c1]=queryR(1,n,1,dfn[v],dfn[u]),ty=1;
        else p2[++c2]=queryL(1,n,1,dfn[u],dfn[v]),ty=2;
        mixtra ans;
        if(c1)ans=p1[1];
        else ans=p2[c2];
        for(int i=2;i<=c1;i++)ans=merge(ans,p1[i]);
        for(int i=c2-(c1?0:1);i>=1;i--)ans=merge(ans,p2[i]);
        _write(ans.f[0][0]);
        c1=c2=0;
    }
    return 0;
}
