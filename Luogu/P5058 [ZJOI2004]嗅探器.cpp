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
int n,hd[N],nxt[N],to[N],ec,s,t,ans=INF;
int dfn[N],low[N],ct;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void tarjan(int u){
	dfn[u]=low[u]=++ct;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v]){
			tarjan(v),low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]&&u!=s&&dfn[t]>=dfn[v])ans=min(ans,u);
		}
		else low[u]=min(low[u],dfn[v]);
	}
	return;
}

signed main(){
	n=read();
	for(int u,v;;){
		u=read(),v=read();
		if(!(u+v))break;
		add(u,v),add(v,u);
	}
	s=read(),t=read();
	tarjan(s);
	if(ans==INF)printf("No solution\n");
	else printf("%d\n",ans);
	return 0;
}

