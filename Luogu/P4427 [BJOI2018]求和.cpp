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

const int N=6e5+7,Mod=998244353,INF=1e9+7;
int n,m;
int fa[N],cnt[N],dfn[N],dep[N],top[N],hv[N],ct,sum[N][60];
vector<int> g[N],ch[N];

void dfs1(int u,int pr,int d){
	dep[u]=d,dfn[u]=++ct,fa[u]=pr,cnt[u]=1;
	for(int i=0;i<signed(g[u].size());i++){
		int v=g[u][i];
		if(v==pr)continue;
		dfs1(v,u,d+1);
		cnt[u]+=cnt[v];
		ch[u].push_back(v);
		if(cnt[hv[u]]<cnt[v])hv[u]=v;
	}
	return;
}

void dfs2(int u,int pr){
	top[u]=pr;
	if(hv[u])dfs2(hv[u],pr);
	for(int i=0;i<signed(ch[u].size());i++){
		int v=ch[u][i];
		if(v==hv[u])continue;
		dfs2(v,v);
	}
	return;
}

signed main(){
	n=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)sum[i][0]=1;
	for(int j=1;j<=50;j++){
		for(int i=1;i<=n;i++)sum[i][j]=(sum[i][j-1]*i)%Mod;
	}
	for(int j=1;j<=50;j++){
		for(int i=1;i<=n;i++)sum[i][j]=(sum[i][j]+sum[i-1][j])%Mod;
	}
	dfs1(1,1,0),dfs2(1,1);
	m=read();
	for(int i=1,u,v,x,y,k,ans;i<=m;i++){
		x=u=read(),y=v=read(),k=read();
		while(top[u]!=top[v]){
			if(dep[top[u]]<=dep[top[v]])v=fa[top[v]];
			else u=fa[top[u]];
		}
		if(dep[u]>dep[v]){int T=u;u=v,v=T;}
		ans=sum[dep[x]][k]+sum[dep[y]][k]-sum[dep[u]][k];
		if(dep[u]!=0)ans-=sum[dep[u]-1][k];
		ans%=Mod;
		ans+=Mod;
		ans%=Mod;
		printf("%lld\n",ans);
	}
	return 0;
}
