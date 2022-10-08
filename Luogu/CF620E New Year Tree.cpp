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

#define ll long long
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)>>1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,q,col[N],hd[N],nxt[N*2],to[N*2],ec;
int dfn[N],cnt[N],Time;
ll s[N*8],tag[N*8];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs(int u,int from){
    cnt[u]=1,dfn[u]=++Time;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs(v,u),cnt[u]+=cnt[v];
    }
    return;
}

void pushdown(int id){
    if(tag[id]){
        s[id]=tag[id];
        tag[Lid]=tag[id],tag[Rid]=tag[id];
        tag[id]=0;
    }
    return;
}

void update(int L,int R,int id,int l,int r,ll v){
    pushdown(id);
    if(R<l||r<L)return;
    if(l<=L&&r>=R)tag[id]=v,pushdown(id);
    else{
        update(L,M,Lid,l,r,v),update(M+1,R,Rid,l,r,v);
        s[id]=s[Lid]|s[Rid];
    }
    return;
}

ll query(int L,int R,int id,int l,int r){
    pushdown(id);
    if(R<l||r<L)return 0;
    if(l<=L&&r>=R)return s[id];
    return query(L,M,Lid,l,r)|query(M+1,R,Rid,l,r);
}

signed main(){
    n=read(),q=read();
    for(int i=1;i<=n;i++)col[i]=read();
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
    dfs(1,0);
    for(int i=1;i<=n;i++)update(1,n,1,dfn[i],dfn[i],1ll<<col[i]);
    while(q--){
        int op=read();
        if(op==1){
            int x=read(),y=read();
            update(1,n,1,dfn[x],dfn[x]+cnt[x]-1,1ll<<y);
        }
        else{
            int x=read(),ans=0;
            ll y=query(1,n,1,dfn[x],dfn[x]+cnt[x]-1);
            for(int i=0;i<61;i++)if(y&(1ll<<i))++ans;
            printf("%d\n",ans);
        }
    }
    return 0;
}
