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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,m,hd[N],nxt[N],to[N],ec,vis[N],col[N],Hd[N],stk[N],top,tag,ans[N],cnt;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
inline void Add(int u,int v){nxt[++ec]=Hd[u],Hd[u]=ec,to[ec]=v;return;}

void dfs(int u,int from,int cl){
	vis[u]=1,col[u]=cl;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		if(!vis[v])dfs(v,u,4-cl);
		else if(col[u]==col[v])Add(u,v),Add(v,u);
	}
	return;
}

void dfs2(int u,int from,int cl){
	vis[u]=1,col[u]+=cl,stk[++top]=u;
	for(int i=Hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		if(!vis[v])dfs2(v,u,cl^1);
		else if(col[u]==col[v]){
			if(!tag){
				tag=1;
				while(stk[top]!=v)ans[++cnt]=stk[top--];
				ans[++cnt]=v;
			}
		}
	}
	if(!tag)--top;
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs(1,0,1);
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++)if(!vis[i])dfs2(i,0,0);
	if(tag){
		printf("B ");
		printf("%d ",cnt);
		for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	else{
		printf("A ");
		for(int i=1;i<=n;i++)printf("%d ",col[i]);
		printf("\n");
	}
	return 0;
}

