#include<bits/stdc++.h>
#define int long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7;
const int INF=1000114514;

int n,m,hd[N],nxt[N],to[N],ec=1;
int dfn[N],Time,low[N];
map<int,int> mp;
int vis[N],V,A[N],col[N];

inline void add_edge(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

struct ans{
	int u,v;
	ans(int u=0,int v=0):u(u),v(v){};
	bool operator < (const ans& A)const{if(u==A.u)return v<A.v;return u<A.u;}
}a[N];
int t;

void tarjan(int u,int from){
    dfn[u]=low[u]=++Time;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(!dfn[v]){
            tarjan(v,i);
            if(dfn[u]<low[v])a[++t]=ans(min(u,v),max(u,v));
        }
        if(i^from^1)low[u]=min(low[u],low[v]);
    }
    return;
}

int hs(int x,int y){
    return x*(n+1)+y;
}

int C,Tag;
void dfs(int u,int c){
    vis[u]=1;
    col[u]=c;
    if(A[u]!=-1){
        if(C==-1)C=A[u];
        else if(C!=A[u])C=-2;
    }
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(mp[hs(u,v)])continue;
        if(vis[v]){
            if(col[u]==col[v])Tag=1;
            continue;
        }
        dfs(v,c^1);
    }
    return;
}

signed main(){
    int T=0;
    T=read();
    while(T--){
        n=read(),m=read(),V=read();
        for(int i=1;i<=n;i++)A[i]=read();
        for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add_edge(u,v),add_edge(v,u);
        tarjan(1,0);
        sort(a+1,a+t+1);
    	for(int i=1;i<=t;i++)mp[hs(a[i].u,a[i].v)]=1,mp[hs(a[i].v,a[i].u)]=1;
    	int ans=1;
        for(int i=1;i<=n;i++)if(!vis[i]){
            C=-1,Tag=0;
            dfs(i,0);
            if(C==-1){
                if(!Tag)(ans*=V)%=998244353;
            }
            else if(C==-2)ans=0;
            else{
                if(Tag&&C!=0)ans=0;
            }
        }
        printf("%lld\n",ans);
        for(int i=1;i<=n;i++)hd[i]=0;
        ec=1,Time=0,t=0;
        for(int i=1;i<=n;i++)dfn[i]=low[i]=vis[i]=0;
        mp.clear();
    }
	return 0;
}

