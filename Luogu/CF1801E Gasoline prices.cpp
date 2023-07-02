// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
namespace OI{const int INF=1.01e9,Mod=1000000007;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6;
int n,m,Llim[N],Rlim[N],ans;
int fa[N],hd[N],nxt[N],to[N],ec;
int dep[N],cnt[N],son[N],dfn[N],idfn[N],top[N],Time;
int pr[30][N],Lg2[N],sz[30][N];

struct node{
    int x,y,z;
    node(int x=0,int y=0,int z=0):x(x),y(y),z(x<=y?1:-1){}
};

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs0(int u,int from){
    dep[u]=dep[from]+1,cnt[u]=1;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs0(v,u),cnt[u]+=cnt[v];
        if(cnt[son[u]]<cnt[v])son[u]=v;
    }
    return;
}

void dfs1(int u,int t){
    top[u]=t,dfn[u]=++Time,idfn[Time]=u;
    if(son[u])dfs1(son[u],t);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==fa[u]||v==son[u])continue;
        dfs1(v,v);
    }
    return;
}

inline vector<node> getpath(int u,int v){
    vector<node> l,r;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]){
            r.pb(node(dfn[top[v]],dfn[v]));
            v=fa[top[v]];
        }
        else{
            l.pb(node(dfn[u],dfn[top[u]]));
            u=fa[top[u]];
        }
    }
    l.pb(node(dfn[u],dfn[v]));
    int sz=r.size();
    for(int i=sz-1;i>=0;i--)l.pb(r[i]);
    return l;
}

inline int Rev(int x){return n*2-x+1;}
inline int _abs(int x){return x<0?-x:x;}

inline int Find(int x,int h){
    if(pr[h][x]!=x)pr[h][x]=Find(pr[h][x],h);
    return pr[h][x];
}

inline void Link(int x,int y,int h){
    int X=Find(x,h),Y=Find(y,h);
    if(X!=Y){
        if(sz[h][X]<sz[h][Y])swap(X,Y);
        pr[h][Y]=pr[h][X],sz[h][X]+=sz[h][Y];
        if(h){
            int hl=(1<<(h-1));
            Link(x,y,h-1),Link(x-hl,y-hl,h-1);
        }
    }
    return;
}

signed main(){
    for(int i=2;i<N;i++)Lg2[i]=Lg2[i/2]+1;
    n=read();
    for(int i=2;i<=n;i++){
        fa[i]=read();
        add(fa[i],i),add(i,fa[i]);
    }
    dfs0(1,0),dfs1(1,1);
    for(int i=1;i<=n;i++)Llim[dfn[i]]=read(),Rlim[dfn[i]]=read();
    for(int i=n+1;i<=n+n;i++)Llim[i]=Llim[Rev(i)],Rlim[i]=Rlim[Rev(i)];
    m=read();
    for(int h=0;h<30;h++)for(int i=1;i<=n*2;i++)pr[h][i]=i,sz[h][i]=1;
    for(int i=n+1;i<=n+n;i++)pr[0][i]=Rev(i),sz[0][i-n]=2;
    while(m--){
        int l1=read(),r1=read(),l2=read(),r2=read();
        vector<node> p1=getpath(l1,r1),p2=getpath(l2,r2);
        int sz1=p1.size(),sz2=p2.size();
        int t1=0,t2=0,c1=p1[0].x,c2=p2[0].x;
        while(1){
            int len=min(_abs(c1-p1[t1].y),_abs(c2-p2[t2].y))+1,h=Lg2[len],Len=(1<<h);
            Link(p1[t1].z>0?c1+Len-1:Rev(c1-Len+1),p2[t2].z>0?c2+Len-1:Rev(c2-Len+1),h);
            if(len!=Len)Link(p1[t1].z>0?c1+len-1:Rev(c1-len+1),p2[t2].z>0?c2+len-1:Rev(c2-len+1),h);
            c1+=p1[t1].z*(len-1),c2+=p2[t2].z*(len-1);
            if(c1==p1[t1].y&&t1==sz1-1)break;
            if(c1==p1[t1].y)++t1,c1=p1[t1].x;
            else c1+=p1[t1].z;
            if(c2==p2[t2].y)++t2,c2=p2[t2].x;
            else c2+=p2[t2].z;
        }
        for(int i=1;i<=n*2;i++){
            int j=Find(i,0);
            _max(Llim[j],Llim[i]),_min(Rlim[j],Rlim[i]);
        }
        ans=1;
        for(int i=1;i<=n*2;i++)if(Find(i,0)==i){
            if(Llim[i]<=Rlim[i])ans=1ll*ans*(Rlim[i]-Llim[i]+1)%Mod;
            else ans=0;
        }
        _wri(ans);
    }
    return 0;
}

