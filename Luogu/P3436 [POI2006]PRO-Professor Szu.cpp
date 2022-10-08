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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,INF=36500;
int n,m,hd[N],nxt[N],to[N],ec,tag,ring[N];
int dfn[N],low[N],stk[N],top,Time,col[N],cc;
int deg[N],f[N],Tag[N],Hd[N];
vector<int> s[N];
vector<int> ans;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
inline void Add(int u,int v){if(!u||!v)return;++deg[v];nxt[++ec]=Hd[u],Hd[u]=ec,to[ec]=v;return;}

void tarjan(int u){
	dfn[u]=low[u]=++Time,stk[++top]=u;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(!col[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		++cc;
		while(stk[top+1]!=u)col[stk[top]]=cc,s[cc].push_back(stk[top]),--top;
		if(s[cc].size()>1||ring[u])Tag[cc]=1;
	}
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		if(u==v)ring[u]=1;
		else add(v,u);
	}
	tarjan(n+1);
	for(int i=1;i<=cc;i++)tag|=Tag[i];
	if(!tag){
		for(int u=1;u<=n+1;u++)if(dfn[u]){
			for(int i=hd[u];i;i=nxt[i]){
				++deg[to[i]];
			}
		}
		f[n+1]=1;
		queue<int> Q;
		Q.push(n+1);
		while(!Q.empty()){
			int u=Q.front();
			Q.pop();
			for(int i=hd[u],v;i;i=nxt[i]){
				v=to[i];
				f[v]+=f[u],--deg[v];
				if(f[v]>INF)f[v]=INF+1;
				if(deg[v]==0)Q.push(v);
			}
		}
		int mx=-INF;
		for(int i=1;i<=n;i++)mx=max(mx,f[i]);
		for(int i=1;i<=n;i++)if(f[i]==mx)ans.push_back(i);
		if(mx>INF)printf("zawsze\n");
		else printf("%d\n",mx);
	}
	else{
		for(int u=1;u<=n+1;u++){
			for(int i=hd[u],v;i;i=nxt[i]){
				v=to[i];
				if(col[u]^col[v])Add(col[u],col[v]);
			}
		}
		f[col[n+1]]=1;
		queue<int> Q;
		Q.push(col[n+1]);
		while(!Q.empty()){
			int u=Q.front();
			Q.pop();
			if(Tag[u])f[u]=INF+1;
			for(int i=Hd[u],v;i;i=nxt[i]){
				v=to[i];
				f[v]+=f[u],--deg[v];
				if(f[v]>INF)f[v]=INF+1;
				if(deg[v]==0)Q.push(v);
			}
		}
		printf("zawsze\n");
		for(int i=1;i<=cc;i++)if(f[i]==INF+1){
			for(unsigned j=0;j<s[i].size();j++)if(s[i][j]!=n+1)ans.push_back(s[i][j]);
		}
	}
	sort(ans.begin(),ans.end());
	printf("%llu\n",ans.size());
	for(unsigned i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}

