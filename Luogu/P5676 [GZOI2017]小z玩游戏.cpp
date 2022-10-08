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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int T,n,w[N],e[N],ans;
int hd[N*2],nxt[N*16],to[N*16],ec;
int dfn[N],low[N],stk[N],top,Time,col[N],cc,siz[N];

inline void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

void tarjan(int u){
	dfn[u]=low[u]=++Time,stk[++top]=u;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(!col[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		++cc;
		while(stk[top+1]!=u)col[stk[top--]]=cc,++siz[cc];
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)w[i]=read();
		for(int i=1;i<=n;i++)e[i]=read();
		for(int i=1;i<=100000;i++){
			for(int j=i;j<=100000;j+=i)add(i,j+100000);
		}
		for(int i=1;i<=n;i++){
			add(w[i]+100000,i+200000);
			add(i+200000,e[i]);
		}
		tarjan(1);
		for(int i=1;i<=n;i++){
			if(dfn[i+200000]&&siz[col[i+200000]]>1)++ans;
		}
		printf("%d\n",ans);
		for(int i=1;i<=ec;i++)nxt[i]=to[i]=0;
		for(int i=1;i<=n+200000;i++)hd[i]=dfn[i]=low[i]=col[i]=siz[i]=stk[i]=0;
		ec=cc=Time=ans=0;
	}
	return 0;
}

