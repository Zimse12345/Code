// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
namespace Zimse{const int INF=1.01e9,Mod=1000000007;
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

const int N=2.5e3;
int m,Tx[N],Ty[N],Px[N],Py[N],W[N];
int Id[N],vis[N],stk[N],top;

struct edge{
    int to,len;
    edge(int to=0,int len=0):to(to),len(len){}
    bool operator < (const edge &_)const{return len<_.len;}
};
vector<edge> G[N],p;

struct Tree{
    int sz,id[N],cnt,ans,sumdis[N];
    set<int> s;
    map<int,int> mp;
    vector<edge> g[N];
    
    inline void link(int u,int v,int w){
        if(u==v)return;
        w%=Mod;
        if(!mp[u])mp[u]=++cnt,id[cnt]=u;
        if(!mp[v])mp[v]=++cnt,id[cnt]=v;
        u=mp[u],v=mp[v];
        g[u].pb(edge(v,w)),g[v].pb(edge(u,w));
        return;
    }

    inline void ins(int x){
        if(!mp[x])mp[x]=++cnt,id[cnt]=x;
        return;
    }
}t[320];

int fa[N],dfn[N],Time,dep[N];
void dfs(int u,int from){
    dfn[u]=++Time,fa[u]=from;
    for(unsigned i=0;i<G[u].size();i++){
        int v=G[u][i].to;
        if(v==from)continue;
        dep[v]=dep[u]+G[u][i].len,dfs(v,u);
    }
    return;
}

map<int,int> Sumdis,Mp;
void Dfs(int tid,int u,int from,int d,int _sz,int _sum,int ad){
    Sumdis[t[tid].id[u]+ad]=(t[tid].sumdis[u]+d*(_sz%Mod)+_sum)%Mod;
    for(unsigned i=0;i<t[tid].g[u].size();i++){
        int v=t[tid].g[u][i].to;
        if(v==from)continue;
        Dfs(tid,v,u,(d+t[tid].g[u][i].len)%Mod,_sz,_sum,ad);
    }
    return;
}

signed main(){
    // ifile("loquat.in");
    // ofile("loquat.out");
    
    m=read();
    t[0].sz=1,t[0].s.insert(1);
    t[0].id[++t[0].cnt]=1,t[0].mp[1]=1;
    for(int i=1;i<=m;i++){
        Tx[i]=read(),Ty[i]=read(),Px[i]=read()+1,Py[i]=read()+1,W[i]=read();
        t[i].sz=t[Tx[i]].sz+t[Ty[i]].sz;
    }
    for(int i=m,x,y;i>=1;i--){
        x=Tx[i],y=Ty[i];
        t[x].s.insert(Px[i]),t[y].s.insert(Py[i]);
        for(set<int>::iterator it=t[i].s.begin();it!=t[i].s.end();it++){
            if(*it<=t[x].sz)t[x].s.insert(*it);
            else t[y].s.insert(*it-t[x].sz);
        }
    }
    for(int i=1,x,y,u,v;i<=m;i++){
        Sumdis.clear(),Mp.clear();
        x=Tx[i],y=Ty[i],u=t[x].mp[Px[i]],v=t[y].mp[Py[i]];
        t[i].ans=(t[x].ans+t[y].ans
        +t[x].sumdis[u]*(t[y].sz%Mod)
        +(t[x].sz%Mod)*t[y].sumdis[v]
        +(t[x].sz%Mod)*(t[y].sz%Mod)%Mod*W[i])%Mod;
        _write(t[i].ans);
        
        Dfs(x,u,0,W[i],t[y].sz%Mod,t[y].sumdis[v],0);
        Dfs(y,v,0,W[i],t[x].sz%Mod,t[x].sumdis[u],t[x].sz);
        for(int j=1;j<=t[x].cnt;j++)G[j]=t[x].g[j],Id[j]=t[x].id[j];
        for(int j=1;j<=t[y].cnt;j++){
            G[j+t[x].cnt]=t[y].g[j],Id[j+t[x].cnt]=t[y].id[j]+t[x].sz;
            for(unsigned k=0;k<G[j+t[x].cnt].size();k++)G[j+t[x].cnt][k].to+=t[x].cnt;
        }
        for(int j=1;j<=t[x].cnt+t[y].cnt;j++)Mp[Id[j]]=j;
        G[u].pb(edge(t[x].cnt+v,W[i]));
        G[t[x].cnt+v].pb(edge(u,W[i]));
        dfs(1,0);
        p.resize(0);
        p.pb(edge(1,dfn[1]));
        for(set<int>::iterator it=t[i].s.begin();it!=t[i].s.end();it++)p.pb(edge(Mp[*it],dfn[Mp[*it]]));
        sort(p.begin(),p.end());
        for(int j=1;j<=t[x].cnt+t[y].cnt;j++)vis[j]=0;
        top=stk[1]=vis[1]=1;
        for(unsigned j=1;j<p.size();j++){
            int lca=p[j].to;
            while(!vis[lca])vis[lca]=1,lca=fa[lca];
            while(top>1&&dep[lca]<dep[stk[top-1]])t[i].link(Id[stk[top]],Id[stk[top-1]],dep[stk[top]]-dep[stk[top-1]]),--top;
            if(dep[lca]<dep[stk[top]])t[i].link(Id[stk[top]],Id[lca],dep[stk[top]]-dep[lca]),stk[top]=lca;
            if(p[j].to!=stk[top])stk[++top]=p[j].to;
        }
        for(int j=1;j<top;j++)t[i].link(Id[stk[j]],Id[stk[j+1]],dep[stk[j+1]]-dep[stk[j]]);
        for(set<int>::iterator it=t[i].s.begin();it!=t[i].s.end();it++)if(!t[i].mp[*it])t[i].ins(*it);
        for(int j=1;j<=t[i].cnt;j++)t[i].sumdis[j]=Sumdis[t[i].id[j]];
    }
    return 0;
}
