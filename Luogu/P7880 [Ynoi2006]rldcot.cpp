// Author: Zimse
// Data: 2023-04-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)

namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=1.01e6;
int n,m,fa[N],sz[N],dep[N],ans[N];
int A[N],B[N],D[N],tot,_D[N],V;
struct edge{
    int to,w;
    edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N];
set<int> s[N];

map<int,int> mp;
inline void add(int a,int b,int d){
    if(b<a)swap(a,b);
    ++tot,A[tot]=a,B[tot]=b,D[tot]=_D[tot]=d;
    return;
}

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return x<_.x;}
};
vector<node> a[N],upt[N];

struct query{
    int l,r,id;
    query(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
    bool operator < (const query& _)const{return l<_.l;}
}q[N];

void dfs(int u,int from){
    add(u,u,dep[u]);
    s[u].insert(-INF),s[u].insert(INF);
    fa[u]=from,sz[u]=1,s[u].insert(u);
    for(unsigned i=0;i<g[u].size();i++){
        int v=g[u][i].to;
        if(v==from)continue;
        dep[v]=dep[u]+g[u][i].w;
        dfs(v,u);
        if(sz[u]<sz[v])swap(s[u],s[v]);
        sz[u]+=sz[v];
        for(set<int>::iterator it=s[v].begin();it!=s[v].end();it++){
            if(*it==-INF||*it==INF)continue;
            set<int>::iterator p=s[u].lower_bound(*it);
            if(1<=*p&&*p<=n)add(*p,*it,dep[u]);
            --p;
            if(1<=*p&&*p<=n)add(*p,*it,dep[u]);
        }
        for(set<int>::iterator it=s[v].begin();it!=s[v].end();it++){
            if(*it==-INF||*it==INF)continue;
            s[u].insert(*it);
        }
        s[v].clear();
    }
    return;
}

struct fenwick{
    int tr[N];
    inline void ub(int &x){x+=(x&(-x));return;}
    inline void db(int &x){x-=(x&(-x));return;}
    inline void add(int x,int y){for(;x<N;ub(x))tr[x]+=y;return;}
    inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}
}Tr;

signed main(){
    n=read(),m=read();
    for(int i=1,u,v,w;i<n;i++){
        u=read(),v=read(),w=read();
        g[u].pb(edge(v,w));
        g[v].pb(edge(u,w));
    }
    dfs(1,0);
    sort(_D+1,_D+tot+1);
    for(int i=1;i<=tot;i++)if(i==1||_D[i]!=_D[i-1])mp[_D[i]]=++V;
    for(int i=1;i<=tot;i++)D[i]=mp[D[i]],a[D[i]].pb(node(A[i],B[i]));
    for(int i=1;i<=V;i++){
        sort(a[i].begin(),a[i].end());
        int sz=a[i].size();
        for(int j=sz-2;j>=0;j--){
            _min(a[i][j].y,a[i][j+1].y);
            upt[a[i][j].x].pb(node(a[i][j].y,1));
            upt[a[i][j].x].pb(node(a[i][j+1].y,-1));
        }
        upt[a[i][sz-1].x].pb(node(a[i][sz-1].y,1));
    }
    for(int i=1,l,r;i<=m;i++){
        l=read(),r=read();
        q[i]=query(l,r,i);
    }
    sort(q+1,q+m+1);
    for(int i=m,j=n;i>=1;i--){
        while(j>=q[i].l){
            for(int t=0;t<upt[j].size();t++)Tr.add(upt[j][t].x,upt[j][t].y);
            --j;
        }
        ans[q[i].id]=Tr.sum(q[i].r);
    }
    for(int i=1;i<=m;i++)_write(ans[i]);
    return 0;
}

