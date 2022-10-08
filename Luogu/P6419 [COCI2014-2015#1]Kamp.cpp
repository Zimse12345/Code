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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,k,to[N],nxt[N],hd[N],c[N],ec,tag[N],cnt[N];
ll f1[N],f2[N],f3[N],f4[N],f[N];
inline void add(int u,int v,int w){to[++ec]=v,c[ec]=w,nxt[ec]=hd[u],hd[u]=ec;return;}

void dfs1(int u,int from){
	cnt[u]=tag[u];
	ll mx=0;
	for(int i=hd[u],v,w;i;i=nxt[i]){
		v=to[i],w=c[i];
		if(v==from)continue;
		dfs1(v,u),cnt[u]+=cnt[v];
		if(cnt[v]){
			f2[u]+=w*2+f2[v],f1[u]+=w*2+f2[v];
			mx=max(mx,f2[v]+w-f1[v]);
		}
	}
	f1[u]-=mx;
	return;
}

void dfs2(int u,int from){
	//f1 收完子树
	//f2 收完子树再回来
	//f3 收完上面
	//f4 收完上面再回来 
	//f 收完全部再回来 
	f[u]=min(f2[u]+f3[u],f1[u]+f4[u]);
	ll m1=f4[u]-f3[u],m2=m1,mp=0;
	for(int i=hd[u],v,w;i;i=nxt[i]){
		v=to[i],w=c[i];
		if(v==from)continue;
		ll m=f2[v]-f1[v]+w;
		if(m>=m1)m2=m1,m1=m,mp=v;
		else if(m>m2)m2=m; 
	}
	for(int i=hd[u],v,w;i;i=nxt[i]){
		v=to[i],w=c[i];
		if(v==from)continue;
		if(k-cnt[v]){
			f4[v]=f4[u]+f2[u]-f2[v];
			if(!cnt[v])f4[v]+=w*2;
			f3[v]=f4[v]-w;
			if(v==mp)f3[v]-=m2;
			else f3[v]-=m1;
		}
		dfs2(v,u);
	}
	return;
}

signed main(){
	n=read(),k=read();
	for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	for(int i=1;i<=k;i++)tag[read()]=1;
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++)printf("%lld\n",f[i]);
	return 0;
}

