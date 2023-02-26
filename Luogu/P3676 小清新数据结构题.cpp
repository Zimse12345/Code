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
#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
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

int n,q,hd[N],nxt[N],to[N],ec,val[N],sum[N];
int fa[N],sz[N],dep[N],son[N],dfn[N],top[N],Time;

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs(int u,int from){
    sum[u]=val[u],fa[u]=from,sz[u]=1,dep[u]=dep[from]+1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs(v,u),sz[u]+=sz[v],sum[u]+=sum[v];
        if(sz[son[u]]<sz[v])son[u]=v;
    }
    return;
}

void dfs2(int u,int t){
    top[u]=t,dfn[u]=++Time;
    if(son[u])dfs2(son[u],t);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==fa[u]||v==son[u])continue;
        else dfs2(v,v);
    }
    return;
}

struct segmenttree{
    int v[N],sum[N],sum2[N],ad[N*4],len[N];
    
    void build(int id,int L,int R){
    	len[id]=R-L+1;
        if(L==R)sum[id]=v[L],sum2[id]=v[L]*v[L];
        else build(Lid,L,M),build(Rid,M+1,R),sum[id]=sum[Lid]+sum[Rid],sum2[id]=sum2[Lid]+sum2[Rid];
        return;
    }

    void pushdown(int id){
    	if(ad[id]){
    		sum2[id]+=2*sum[id]*ad[id]+ad[id]*ad[id]*len[id];
    		sum[id]+=ad[id]*len[id];
    		if(Rid<N)ad[Lid]+=ad[id],ad[Rid]+=ad[id];
    		ad[id]=0;
		}
        return;
    }

    void update(int id,int L,int R,int l,int r,int v){
        pushdown(id);
        if(l<=L&&r>=R)ad[id]+=v,pushdown(id);
        else if(r<L||R<l)return;
        else{
            update(Lid,L,M,l,r,v),update(Rid,M+1,R,l,r,v);
            sum[id]=sum[Lid]+sum[Rid],sum2[id]=sum2[Lid]+sum2[Rid];
        }
        return;
    }

    int query(int id,int L,int R,int l,int r){
        pushdown(id);
        if(l<=L&&r>=R)return sum2[id];
        if(r<L||R<l)return 0;
        return query(Lid,L,M,l,r)+query(Rid,M+1,R,l,r);
    }
}f,g;

void upt(int tag,int u,int v){
    while(u){
        if(tag)f.update(1,1,n,dfn[top[u]],dfn[u],v);
        else g.update(1,1,n,dfn[top[u]],dfn[u],v);
        u=fa[top[u]];
    }
    return;
}

int qry(int tag,int u){
    int res=0;
    while(u){
    	if(tag)res+=f.query(1,1,n,dfn[top[u]],dfn[u]);
        else res+=g.query(1,1,n,dfn[top[u]],dfn[u]);
        u=fa[top[u]];
    }
    return res;
}

signed main(){
    n=read(),q=read();
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
    for(int i=1;i<=n;i++)val[i]=read();
    dfs(1,0);
    dfs2(1,1);
    for(int i=1;i<=n;i++)f.v[dfn[i]]=sum[i],g.v[dfn[i]]=sum[1]-sum[i];
    f.build(1,1,n),g.build(1,1,n);
    for(int i=1,ty=0,x=0,y=0;i<=q;i++){
        ty=read(),x=read();
        if(ty==1){
            y=read();
            upt(1,x,y-val[x]);
            g.update(1,1,n,1,n,y-val[x]);
            upt(0,x,val[x]-y);
            sum[1]+=y-val[x];
            val[x]=y;
        }
        else{
            int ans=f.query(1,1,n,1,n)-qry(1,x)+qry(0,x);
            ans+=sum[1]*sum[1];
            _write(ans);
        }
    }
    return 0;
}
