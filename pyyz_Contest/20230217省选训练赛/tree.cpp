#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

#define gc getchar
#define pc putchar
#define pb push_back

using namespace std;
inline int read(){int x=0;char c=gc();while(c<48||57<c)c=gc();
while(47<c&&c<58)x=x*10+c-48,c=gc();return x;}
inline void write(int x){if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline int rd(){int x=rand()&4095,y=rand()&4095;return x*4096+y;}

const int N=100007;
int n,q,w[N],P[N],_n,mx[N],fa[N],dep[N],dfn[N],Time;
int stk[N],top,tag[N],Fa[N],Id[N],rt[N],ch[N*60][2],sum[N*60],tot;
vector<int> g[N];

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return y<_.y;}
};
vector<node> p;

void dfs(int u,int from){
    fa[u]=from,dep[u]=dep[from]+1,dfn[u]=++Time;
    for(unsigned i=0;i<g[u].size();i++)dfs(g[u][i],u),_max(mx[u],mx[g[u][i]]+1);
    if(mx[u]>2500)P[++_n]=u,mx[u]=0;
    return;
}

inline int getlca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    while(dep[u]>dep[v])u=fa[u];
    while(u!=v)u=fa[u],v=fa[v];
    return u;
}

inline void link(int u,int v){
    tag[u]=tag[v]=1,Fa[v]=u;
    return;
}

inline void ins(int p,int v,int t){
    for(int i=29;i>=0;i--){
        if(v&(1<<i)){
            if(!ch[p][1])ch[p][1]=++tot;
            p=ch[p][1];
        }
        else{
            if(!ch[p][0])ch[p][0]=++tot;
            p=ch[p][0];
        }
        sum[p]+=t;
    }
    return;
}

inline int qmax(int p,const int& v){
    int res=0;
    for(int i=29;i>=0;i--){
        if(v&(1<<i)){
            if(sum[ch[p][0]]>0)p=ch[p][0],res|=(1<<i);
            else p=ch[p][1];
        }
        else{
            if(sum[ch[p][1]]>0)p=ch[p][1],res|=(1<<i);
            else p=ch[p][0];
        }
    }
    return res;
}

signed main(){
    srand(time(0));
    n=read(),q=read();
    for(int i=1;i<=n;i++)w[i]=read();
    for(int i=1,f;i<n;i++)f=read(),g[f].pb(i+1);
    dfs(1,0),P[++_n]=1;
    for(int i=1;i<=_n;i++)p.pb(node(P[i],dfn[P[i]]));
    sort(p.begin(),p.end());
    top=0,stk[++top]=1;
    if(p[0].x!=1)stk[++top]=p[0].x;
    for(unsigned i=1;i<p.size();i++){
        int lca=getlca(p[i].x,p[i-1].x);
        while(top>1&&dep[lca]<=dep[stk[top-1]])link(stk[top-1],stk[top]),--top;
        if(dep[lca]<dep[stk[top]])link(lca,stk[top]),stk[top]=lca;
        if(p[i].x!=stk[top])stk[++top]=p[i].x;
    }
    for(int i=1;i<top;i++)link(stk[i],stk[i+1]);
    tag[0]=1;
    for(int i=1;i<=n;i++)if(tag[i]){
        Id[i]=i,rt[i]=++tot,ins(rt[i],w[i],1);
        int j=fa[i];
        while(!tag[j])Id[j]=i,ins(rt[i],w[j],1),j=fa[j];
    }
    while(q--){
        int ty=read(),x=read();
        if(ty==0){
            int y=read();
            ins(rt[Id[x]],w[x],-1);
            ins(rt[Id[x]],y,1);
            w[x]=y;
        }
        else{
            int ans=0,_w=w[x];
            while(!tag[x])_max(ans,_w^w[x]),x=fa[x];
            while(x)_max(ans,qmax(rt[x],_w)),x=Fa[x];
            write(ans),pc(10);
        }
    }
    return 0;
}
