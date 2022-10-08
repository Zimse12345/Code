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
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,q,ans,hd[N],nxt[N],to[N],ec;
int dfn[N],low[N],Time,stk[N],top,col[N],ecnt;
int dis[N];
vector<int> g[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void Init_Graph(){
	for(int i=1;i<=ec;i++)nxt[i]=to[i]=0;
	for(int i=1;i<=n;i++)hd[i]=dfn[i]=low[i]=stk[i]=col[i]=0;
	top=Time=n=0,ec=1;
	return;
}

void tarjan(int u,int from){
	dfn[u]=low[u]=++Time,stk[++top]=u;
	for(int i=hd[u],v;i;i=nxt[i]){
		if(i==from||(i^1)==from)continue;
		v=to[i];
		if(!dfn[v])tarjan(v,i);
		low[u]=min(low[u],low[v]); 
	}
	if(dfn[u]==low[u]){
		++ecnt;
		while(stk[top+1]^u)col[stk[top]]=ecnt,--top;
	}
	return;
}

void dp(int u,int from){
	dis[u]=dis[from]+1;
	for(int i=0;i<signed(g[u].size());i++)if(g[u][i]^from){
		if(i==0||g[u][i]^g[u][i-1]){
			dp(g[u][i],u);
		}
	}
	return;
}

signed main(){
	freopen("d.in","r",stdin);
	freopen("cmd.out","w",stdout);
	dis[0]=-1;
	Init_Graph();
	n=read(),m=read(),q=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v),add(v,u);
	for(int I=1;I<=q;I++){
		tarjan(1,0);
		if(ecnt==1){
			for(int J=I;J<=q;J++)printf("%d\n",ans);
			break;
		}
		for(int i=1;i<=ecnt;i++)g[i].resize(0);
		for(int u=1;u<=n;u++){
			for(int i=hd[u],v;i;i=nxt[i]){
				v=to[i];
				if(col[u]^col[v])g[col[u]].push_back(col[v]);
			}
		}
		for(int i=1;i<=ecnt;i++)sort(g[i].begin(),g[i].end());
		dp(1,0);
		int mx=0,p1=1,p2=1;
		for(int i=1;i<=ecnt;i++)if(dis[i]>mx)mx=dis[i],p1=i;
		dp(p1,0);
		for(int i=1;i<=ecnt;i++)if(dis[i]>mx)mx=dis[i],p2=i;
		Init_Graph();
		n=ecnt;
		for(int u=1;u<=ecnt;u++){
			for(int i=0;i<signed(g[u].size());i++){
				if(i==0||g[u][i]^g[u][i-1]){
					if(u<g[u][i]){
						add(u,g[u][i]);
						add(g[u][i],u);
					}
				}
			}
		}
		add(p1,p2),add(p2,p1);
		ecnt=0,ans+=mx;
		printf("%d\n",ans);
	}
	return 0;
}

