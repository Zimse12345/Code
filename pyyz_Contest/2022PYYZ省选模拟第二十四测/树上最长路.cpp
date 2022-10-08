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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,hd[N],nxt[N],to[N],len[N],ec,mx[N],se[N],th[N],mxson[N],seson[N],f[N],ans[N];ll sum;
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;return;}

void dfs(int u,int from){
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u),f[u]=max(f[u],f[v]);
		if(mx[v]+len[i]>=mx[u])th[u]=se[u],se[u]=mx[u],mx[u]=mx[v]+len[i],seson[u]=mxson[u],mxson[u]=v;
		else if(mx[v]+len[i]>=se[u])th[u]=se[u],se[u]=mx[v]+len[i],seson[u]=v;
		else if(mx[v]+len[i]>th[u])th[u]=mx[v]+len[i];
	}
	f[u]=max(f[u],mx[u]+se[u]);
	return;
}


void dfs2(int u,int from,int w,int ww){
	if(u^1)ans[u]=max(f[u],w);
	int Mx=0,Se=0,p=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		if(f[v]>=Mx)Se=Mx,Mx=f[v],p=v;
		else if(f[v]>Se)Se=f[v];
	}
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		int k=Mx;
		if(v==p)k=Se;
		if(v==mxson[u])dfs2(v,u,max(max(w,k),max(se[u]+ww,se[u]+th[u])),max(se[u],ww)+len[i]);
		else{
			if(v==seson[u])dfs2(v,u,max(max(w,k),max(mx[u]+ww,mx[u]+th[u])),max(mx[u],ww)+len[i]);
			else dfs2(v,u,max(max(w,k),max(mx[u]+ww,mx[u]+se[u])),max(mx[u],ww)+len[i]);
		}
	}
	return;
}

signed main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	dfs(1,0);
	dfs2(1,0,0,0);
	for(int i=1;i<=n;i++)sum+=ans[i];
	printf("%lld\n",sum);
	return 0;
}

