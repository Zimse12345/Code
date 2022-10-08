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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,k,hd[N],nxt[N],to[N],ec,f[N],ans[N],s[N],Ans,pt[N][6],t[6];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dfs(int u,int from){
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u),f[u]+=f[v];
		for(int j=0;j<k;j++)pt[u][(j+1)%k]+=pt[v][j];
	}
	f[u]+=pt[u][0];
	pt[u][0]++;
	return;
}

void dfs2(int u,int from){
	if(u==1){
		ans[u]=f[u];
		for(int i=1;i<k;i++)s[u]+=pt[u][i];
	}
	else{
		for(int i=0;i<k;i++)t[i]=pt[from][i];
		for(int i=0;i<k;i++)t[(i+1)%k]-=pt[u][i];
		for(int i=0;i<k-1;i++)swap(t[i],t[k-1]);
		ans[u]=ans[from]-pt[u][max(k-1,0ll)]+t[0];
		for(int i=0;i<k;i++)pt[u][i]+=t[i];
		for(int i=1;i<k;i++)s[u]+=pt[u][i];
	}
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs2(v,u);
	}
	return;
}

signed main(){
	n=read(),k=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++)Ans+=ans[i]+s[i];
	printf("%lld\n",Ans/2);
	return 0;
}

