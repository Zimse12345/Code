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

const int N=8e5+7,Mod=998244353,INF=1e9+7;
int n,m,hd[N],nxt[N],to[N],ec,f[N],g[N],Sum,ans,k;
int fa[N],dep[N],sz[N],son[N],dfn[N],top[N],Time;
vector<int> ch[N];
int cl[N],tot;

inline void link(int u,int v){
    if(!ch[u].size())cl[++tot]=u;
    ch[u].push_back(v);
    return;
}

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){};
    bool operator < (const node& A)const{return y<A.y;}
}p[N];

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

void dfs0(int u,int from){
    dep[u]=dep[from]+1,sz[u]=1,fa[u]=from;
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs0(v,u);
        if(sz[son[u]]<sz[v])son[u]=v;
        f[u]+=f[v]+sz[v],sz[u]+=sz[v];
    }
    return;
}

void dfs1(int u,int from){
    if(u==1)g[u]=f[u];
    else g[u]=g[from]-sz[u]+n-sz[u];
    Sum+=g[u];
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from)continue;
        dfs1(v,u);
    }
    return;
}

void dfs2(int u,int from,int t){
    dfn[u]=++Time,top[u]=t;
    if(son[u])dfs2(son[u],u,t);
    for(int i=hd[u],v;i;i=nxt[i]){
        v=to[i];
        if(v==from||v==son[u])continue;
        dfs2(v,u,v);
    }
    return;
}

int LCA(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}

int F[N],S[N],stk[N],tp;
int Vis[N];

signed main(){
    n=read();
    for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
    dfs0(1,0);
    dfs1(1,0);
    dfs2(1,0,1);
    m=read();
    while(m--){
        k=read(),ans=Sum;
        vector<node> a;
        for(int i=1,x;i<=k;i++)x=read(),a.push_back(node(x,dfn[x]));
        sort(a.begin(),a.end()),tp=0;
        int rt=a[0].x;
        for(unsigned i=1;i<a.size();i++)rt=LCA(rt,a[i].x);
    	stk[++tp]=rt;
    	for(unsigned i=0;i<a.size();i++){
     	   	int p=a[i].x,lca=LCA(stk[tp],p);
    	    while(tp>1&&dep[lca]<=dep[stk[tp-1]])link(stk[tp-1],stk[tp]),link(stk[tp],stk[tp-1]),--tp;
     	   	if(dep[lca]<dep[stk[tp]])link(lca,stk[tp]),link(stk[tp],lca),--tp,stk[++tp]=lca;
    	    stk[++tp]=p;
    	}
    	for(int i=1;i<tp;i++)link(stk[i],stk[i+1]),link(stk[i+1],stk[i]);
    
    	int tag=0;
    	for(int i=1;i<=tot;i++){
    		int x=cl[i],c=0;
    		for(unsigned j=0;j<ch[x].size();j++)if(!Vis[ch[x][j]]&&ch[x][j]!=x)Vis[ch[x][j]]=1,++c;
    		if(c>2)tag=1;
    		for(unsigned j=0;j<ch[x].size();j++)Vis[ch[x][j]]=0;
		}
		if(tag)printf("No\n");
		else printf("Yes\n");
    
    	for(int i=1;i<=tot;i++)ch[cl[i]].resize(0);
    	tot=0;
    }

	return 0;
}
