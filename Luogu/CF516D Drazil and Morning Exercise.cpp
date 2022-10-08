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

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e18;
int n,hd[N],nxt[N],to[N],len[N],ec,Q,k,f[N];
int Mx=INF,rt=0,Tag,fa[N],pr[N],cnt[N],ans;
priority_queue<int> q,_q;

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& A)const{return y>A.y;}
}p[N];

inline void add(int u,int v,int w){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
    return;
}

inline int F(int x){
    if(pr[x]!=x)pr[x]=F(pr[x]);
    return pr[x];
}

void dfs0(int u,int from){
    fa[u]=from;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs0(v,u);
        if(Tag)f[u]=max(f[u],f[v]+len[i]);
    }
    return;
}

void dfs1(int u,int from,int fdis){
    f[u]=max(f[u],fdis);
    if(f[u]<Mx)Mx=f[u],rt=u;
    int mx=fdis,id=0,se=0;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        if(f[v]+len[i]>mx)se=mx,mx=f[v]+len[i],id=v;
        else if(f[v]+len[i]>se)se=f[v]+len[i];
    }
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        if(v==id)dfs1(v,u,se+len[i]);
        else dfs1(v,u,mx+len[i]);
    }
    return;
}

inline void link(int u,int v){
    u=F(u),v=F(v);
    if(cnt[u]<cnt[v])swap(u,v);
    _q.push(cnt[u]),_q.push(cnt[v]);
    pr[v]=u,cnt[u]+=cnt[v];
    q.push(cnt[u]);
    return;
}

inline void ins(int u){
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==fa[u])continue;
        link(u,v);
    }
    return;
}

inline void del(int u){
    u=F(u);
    _q.push(cnt[u]);
    --cnt[u];
    q.push(cnt[u]);
    return;
}

signed main(){
    n=read();
    for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
    Q=read();
    if(n==2){
        while(Q--)printf("2\n");
        return 0;
    }
    Tag=1,dfs0(1,0);
    dfs1(1,0,0);
    Tag=0,dfs0(rt,0);
    for(int i=1;i<=n;i++)p[i]=node(i,f[i]);
    sort(p+1,p+n+1);
    while(Q--){
        while(!q.empty())q.pop();
        while(!_q.empty())_q.pop();
        k=read(),ans=0;
        for(int i=1;i<=n;i++)pr[i]=i,cnt[i]=1,q.push(1);
        for(int l=1,r=1;r<=n;r++){
            ins(p[r].x);
            while(p[l].y-p[r].y>k)del(p[l].x),++l;
            while(!_q.empty()&&q.top()==_q.top())q.pop(),_q.pop();
            ans=max(ans,q.top());
        }
        printf("%lld\n",ans);
    }
	return 0;
}
