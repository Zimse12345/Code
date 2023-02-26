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

const int N=1000007,SZ=26;

char str[N];
int n;
unsigned long long ans;

struct edge{
    int to,w;
    edge(int to=0,int w=0):to(to),w(w){}
};

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return y<_.y;}
};

struct SAM{
    int lim,tot,pre,Id[N],s[N];
    vector<edge> g[N];
    struct nd{
        int to[SZ],len,link;
    }t[N];
    void init(){t[0].link=-1;return;}

    void ins(int c,int pos){
        int id=++tot,p=pre;
        t[id].len=t[p].len+1,Id[pos]=id;
        while(p!=-1&&!t[p].to[c])t[p].to[c]=id,p=t[p].link;
        if(p==-1)t[id].link=0;
        else{
            int q=t[p].to[c];
            if(t[q].len==t[p].len+1)t[id].link=q;
            else{
                int cp=++tot;
                t[cp]=t[q],t[cp].len=t[p].len+1;
                while(p!=-1&&t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
                t[q].link=t[id].link=cp;
            }
        }
        pre=id;
        return;
    }

    void build_tree(){
        for(int i=1;i<=tot;i++){
            if(t[i].len>lim)t[i].len=0;
            g[t[i].link].pb(edge(i,t[i].len-t[t[i].link].len));
        }
        return;
    }
}A,B;

struct virtual_tree{
    int tot,dep[N],_dep[N],dfn[N],Time,fa[N][20];
    int val[N],ty[N],stk[N],top;
    unsigned long long cnt1[N],cnt2[N],sum1[N],sum2[N],W;
    vector<edge> g[N];
    vector<node> p;
    vector<int> G[N];

    void dfs(int u){
        dep[u]=B.t[u].len,dfn[u]=++Time;
        for(unsigned i=0;i<g[u].size();i++){
            _dep[g[u][i].to]=_dep[u]+1;
            dfs(g[u][i].to),fa[g[u][i].to][0]=u;
        }
        return;
    }

    void init(){
        tot=B.tot;
        for(int i=0;i<=tot;i++)g[i]=B.g[i];
        dfs(0);
        for(int i=1;i<20;i++){
            for(int j=0;j<=tot;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
        }
        return;
    }

    int getlca(int u,int v){
        if(_dep[u]<_dep[v])swap(u,v);
        for(int i=19;i>=0;i--)if(_dep[fa[u][i]]>=_dep[v])u=fa[u][i];
        for(int i=19;i>=0;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
        return u==v?u:fa[u][0];
    }

    void link(int u,int v){
        G[u].pb(v);
        return;
    }

    void dp(int u){
        cnt1[u]=cnt2[u]=sum1[u]=sum2[u]=0;
        if(ty[u]==1)cnt1[u]++,sum1[u]=val[u];
        if(ty[u]==2)cnt2[u]++,sum2[u]=val[u];
        for(unsigned i=0;i<G[u].size();i++){
            int v=G[u][i];
            dp(v);
            ans+=dep[u]*(cnt1[u]*sum2[v]+sum1[u]*cnt2[v]+cnt2[u]*sum1[v]+sum2[u]*cnt1[v])/2;
            ans-=dep[u]*W*(cnt1[u]*cnt2[v]+cnt2[u]*cnt1[v])/2;
            cnt1[u]+=cnt1[v],cnt2[u]+=cnt2[v],sum1[u]+=sum1[v],sum2[u]+=sum2[v];
        }
        G[u].resize(0);
        return;
    }

    void sol(const vector<node>& a,const vector<node>& b,int w){
        p.resize(0),W=w;
        for(unsigned i=0;i<a.size();i++)ty[a[i].x]=1,val[a[i].x]=a[i].y,p.pb(a[i]);
        for(unsigned i=0;i<b.size();i++)ty[b[i].x]=2,val[b[i].x]=b[i].y,p.pb(b[i]);
        for(unsigned i=0;i<p.size();i++)p[i].y=dfn[p[i].x];
        if(p.empty())return;
        sort(p.begin(),p.end());
        top=0,stk[++top]=0;
        if(p[0].x)stk[++top]=p[0].x;
        for(unsigned i=1;i<p.size();i++){
            int lca=getlca(p[i].x,p[i-1].x);
            while(top>1&&_dep[lca]<=_dep[stk[top-1]])link(stk[top-1],stk[top]),--top;
            if(_dep[lca]<_dep[stk[top]])link(lca,stk[top]),stk[top]=lca;
            if(p[i].x!=stk[top])stk[++top]=p[i].x;
        }
        for(int i=1;i<top;i++)link(stk[i],stk[i+1]);
        dp(0);
        for(unsigned i=0;i<p.size();i++)ty[p[i].x]=0;
        return;
    }
}Tree2;

struct edge_divide{
    int tot,tag[N],dep[N];
    int sz[N],_n,U,V,mn;
    vector<edge> g[N];
    vector<node> L,R;

    void link(int u,int v,int w){
        g[u].pb(edge(v,w)),g[v].pb(edge(u,w));
        dep[v]=dep[u]+w;
        return;
    }

    void remake_tree(int u){
        int U=u;
        for(unsigned i=0;i<A.g[u].size();i++){
            if(i)link(U,++A.tot,0),U=A.tot;
            link(U,A.g[u][i].to,A.g[u][i].w);
            remake_tree(A.g[u][i].to);
        }
        if(!u){
            tot=A.tot+1;
            for(int i=1;i<=n;i++)tag[A.Id[i]]=i;
        }
        return;
    }

    void findedge(int u,int from){
        sz[u]=1;
        for(unsigned i=0;i<g[u].size();i++){
            int v=g[u][i].to;
            if(v==from||g[u][i].w==INF)continue;
            findedge(v,u),sz[u]+=sz[v];
        }
        if(max(sz[u],_n-sz[u])<mn)mn=max(sz[u],_n-sz[u]),U=from,V=u;
        return;
    }

    void dfs(int u,int from,int dis,int t){
        if(tag[u]){
            if(!t)L.pb(node(B.Id[tag[u]],dep[u]-dis));
            else R.pb(node(B.Id[tag[u]],dep[u]-dis));
        }
        for(unsigned i=0;i<g[u].size();i++){
            int v=g[u][i].to;
            if(v==from||g[u][i].w==INF)continue;
            dfs(v,u,dis+g[u][i].w,t);
        }
        return;
    }

    void divide(int u,int v){
        int szv=sz[v],szu=_n-szv,w=0;
        for(unsigned i=0;i<g[u].size();i++)if(g[u][i].to==v)w=g[u][i].w,g[u][i].w=INF;
        for(unsigned i=0;i<g[v].size();i++)if(g[v][i].to==u)g[v][i].w=INF;
        dfs(u,v,0,0);
        dfs(v,u,0,1);
        Tree2.sol(L,R,w);
        L.resize(0),R.resize(0);
        if(szu>1)_n=szu,mn=INF,findedge(u,-1),divide(U,V);
        if(szv>1)_n=szv,mn=INF,findedge(v,-1),divide(U,V);
        return;
    }

    void sol(){
        _n=tot,mn=INF,findedge(0,-1);
        divide(U,V);
        return;
    }
}Tree1;

signed main(){
    A.init(),B.init();
    scanf("%s",str+1);
    n=strlen(str+1),A.lim=read(),B.lim=read();
    for(int i=1;i<=n;i++)A.ins(str[i]-'a',i);
    for(int i=n;i>=1;i--)B.ins(str[i]-'a',i);
    A.build_tree(),B.build_tree();
    Tree2.init();
    Tree1.remake_tree(0);
    Tree1.sol();
    printf("%llu\n",ans);
    return 0;
}
