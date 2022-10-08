/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-26
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

const int N=2e6+7;

int n,m,hd[N],nxt[N],to[N],len[N],ec,pre[N],tag[N],ans[N];
int fa[N],cnt[N],dep[N],son[N],dfn[N],top[N],Time,fw[N];
int a[N],mx[N],mn[N];

struct edge{
    int u,v,w,id;
    edge(int u=0,int v=0,int w=0,int id=0):u(u),v(v),w(w),id(id){}
    bool operator < (const edge& _)const{return w<_.w;}
}e[N];

int F(int x){
    if(pre[x]!=x)pre[x]=F(pre[x]);
    return pre[x];
}

inline void add(int u,int v,int w){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
    return;
}

void dfs0(int u,int from){
    dep[u]=dep[from]+1,cnt[u]=1,fa[u]=from;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs0(v,u),cnt[u]+=cnt[v],fw[v]=len[i];
        if(cnt[son[u]]<cnt[v])son[u]=v;
    }
    return;
}

void dfs1(int u,int t){
    dfn[u]=++Time,top[u]=t,a[Time]=fw[u];
    if(son[u])dfs1(son[u],t);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==fa[u]||v==son[u])continue;
        dfs1(v,v);
    }
    return;
}

void build(int L,int R,int id){
    if(L==R)mx[id]=a[L];
    else{
        build(L,M,Lid),build(M+1,R,Rid);
        mx[id]=max(mx[Lid],mx[Rid]);
    }
    // printf("mx[%d]=%d\n",id,mx[id]);
    return;
}

int query(int L,int R,int id,int l,int r){
    if(r<L||R<l)return 0;
    if(l<=L&&r>=R)return mx[id];
    return max(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

int qmax(int u,int v){
    int res=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        _max(res,query(1,n,1,dfn[top[u]],dfn[u])),u=fa[top[u]];
    }
    if(dfn[v]<dfn[u])swap(u,v);
    if(u!=v)_max(res,query(1,n,1,dfn[u]+1,dfn[v]));
    // printf("max(%d,%d)=%d\n",u,v,res);
    return res;
}

void _build(int L,int R,int id){
    mn[id]=1000000000;
    if(L!=R)_build(L,M,Lid),_build(M+1,R,Rid);
    return;
}

void update(int L,int R,int id,int l,int r,int x){
    if(r<L||R<l)return;
    if(l<=L&&r>=R)_min(mn[id],x);
    else update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x);
    return;
}

int _query(int L,int R,int id,int x){
    if(L==R)return mn[id];
    if(x<=M)return min(mn[id],_query(L,M,Lid,x));
    return min(mn[id],_query(M+1,R,Rid,x));
}

void upt(int u,int v,int w){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        update(1,n,1,dfn[top[u]],dfn[u],w),u=fa[top[u]];
    }
    if(dfn[v]<dfn[u])swap(u,v);
    if(u!=v)update(1,n,1,dfn[u]+1,dfn[v],w);
    return;
}

signed main(){
     ifile("easy.in");
     ofile("easy.out");
    n=read(),m=read();
    for(int i=1;i<=m;i++){
        e[i].u=read(),e[i].v=read(),e[i].w=read(),e[i].id=i;
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++)pre[i]=i;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v;
        u=F(u),v=F(v);
        if(u!=v){
            pre[v]=u;
            add(e[i].u,e[i].v,e[i].w),add(e[i].v,e[i].u,e[i].w);
            tag[i]=1;
        }
    }
    dfs0(1,0);
    dfs1(1,1);
    build(1,n,1);
    for(int i=1;i<=m;i++){
        if(!tag[i])ans[e[i].id]=qmax(e[i].u,e[i].v);
    }
    _build(1,n,1);
    for(int i=1;i<=m;i++){
        if(!tag[i])upt(e[i].u,e[i].v,e[i].w);
    }
    for(int i=1;i<=m;i++){
        if(tag[i]){
            if(fa[e[i].u]==e[i].v)swap(e[i].u,e[i].v);
            if(fa[e[i].v]==e[i].u)ans[e[i].id]=_query(1,n,1,dfn[e[i].v]);
        }
    }
    for(int i=1;i<=m;i++)_write(ans[i]);
    return 0;
}

