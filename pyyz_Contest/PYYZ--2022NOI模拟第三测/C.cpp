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
#include <bitset>

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e5+7,M=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,x[N],y[N],v[N],hd[M],nxt[M],to[M],ec,ans[N],tag[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

bitset<4096> vis[310000];

void dfs(int u){
	if(tag[u])return;
	tag[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		dfs(v);
		vis[u]|=vis[v];
	}
	return;
}

signed main(){
//	freopen("souvenir_sample.in","r",stdin);
//	freopen("C.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)x[i]=read(),y[i]=read(),v[i]=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		if(x[u]<x[v]||y[u]<y[v])add(u,v);
		else add(v,u);
	}
	for(int I=1;(I-1)*4000<n;I++){
		int L=(I-1)*4000+1,R=min(I*4000,n);
		for(int i=1;i<=n;i++){
			vis[i]=vis[0];
			if(L<=v[i]&&v[i]<=R)vis[i][v[i]-L]=1;
			tag[i]=0;
		}
		dfs(1);
		for(int i=1;i<=n;i++)ans[i]+=vis[i].count();
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}

