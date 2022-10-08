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
int n,hd[N],nxt[N],to[N],len[N],ec;
int sz,rt,cnt[N],vis[N],ms,Dis[N],dt,ddis[N],ddt;
int pr[N],prime[N],tot;
int vsum,T[N];
ll ans,Ans[N];
int U[N],V[N],p[100],pt;
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;return;}
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}

//vector<int> split(int x){
//	vector<int> res;
//	while(x!=1){
//		int y=pr[x];
//		res.push_back(y);
//		while(x%y==0)x/=y;
//	}
//	return res;
//}

inline void add(int x){
	if(x==1){
		++vsum;
		return;
	}
	pt=0;
	while(x!=1){
		int y=pr[x];
		p[pt++]=y;
		while(pr[x]==y)x/=y;
	}
	++vsum;
	for(int i=1,mul;i<(1<<pt);i++){
		mul=1;
		for(int j=0;j<pt;j++)if(i&(1<<j))mul*=p[j];
		++T[mul];
	}
	return;
}

inline int calcans(int x){
	if(x==1){
		return vsum;
	}
	int res=vsum;
	pt=0;
	while(x!=1){
		int y=pr[x];
		p[pt++]=y;
		while(pr[x]==y)x/=y;
	}
	for(int i=1,mul,z;i<(1<<pt);i++){
		mul=1,z=1;
		for(int j=0;j<pt;j++)if(i&(1<<j))mul*=p[j],z=-z;
		res+=T[mul]*z;
	}
	return res;
}

inline void del(int x){
	if(x==1){
		--vsum;
		return;
	}
	--vsum;
	pt=0;
	while(x!=1){
		int y=pr[x];
		p[pt++]=y;
		while(pr[x]==y)x/=y;
	}
	for(int i=1,mul;i<(1<<pt);i++){
		mul=1;
		for(int j=0;j<pt;j++)if(i&(1<<j))mul*=p[j];
		--T[mul];
	}
	return;
}

inline void dfs(int u,int from,int g){
	if(g)Dis[++dt]=g;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]||v==from)continue;
		if(g==1)dfs(v,u,1);
		else if(g)dfs(v,u,gcd(g,len[i]));
		else dfs(v,u,len[i]);
	}
	return;
}

inline void calc(int u){
	ddt=ans=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		dt=0;
		dfs(v,u,len[i]);
		for(int i=1;i<=dt;i++){
			ans+=calcans(Dis[i]);
			if(Dis[i]==1)++ans;
		}
		for(int i=1;i<=dt;i++)ddis[++ddt]=Dis[i],add(Dis[i]);
	}
	for(int i=1;i<=ddt;i++)del(ddis[i]);
	Ans[u]=ans;
	return;
}

void findrt(int u,int from){
	cnt[u]=1;
	int mc=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||vis[v])continue;
		findrt(v,u),cnt[u]+=cnt[v],mc=max(mc,cnt[v]);
	}
	mc=max(mc,sz-cnt[u]);
	if(mc<ms)ms=mc,rt=u;
	return;
}

void divide(int u){
	vis[u]=1;
	calc(u);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		sz=cnt[v],ms=INF,findrt(v,u);
		divide(v);
	}
	return;
}

inline ll edgedivide(int u,int v,int w){
	ll res=0;
	dt=ddt=0;
	dfs(u,v,w);
	for(int i=1;i<=dt;i++){
		if(Dis[i]==1)++res;
		add(Dis[i]),ddis[++ddt]=Dis[i];
	}
	dt=0;
	dfs(v,u,0);
	for(int i=1;i<=dt;i++)res+=calcans(Dis[i]);
	for(int i=1;i<=ddt;i++)del(ddis[i]);
	return res;
}

signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,prime[++tot]=i;
		for(int j=1;j<=tot&&prime[j]*i<N;j++){
			pr[prime[j]*i]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	n=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w),U[i]=u,V[i]=v;
	}
	sz=n,ms=INF,findrt(1,0);
	divide(rt);
	ans=0;
	for(int i=1;i<=n;i++)vis[i]=0,ans+=Ans[i];
	printf("%lld\n",ans);
	int K=read();
	while(K--){
		int eid=read(),x=read();
		int u=U[eid],v=V[eid];
		ans-=edgedivide(u,v,len[eid*2]);
		len[eid*2-1]=len[eid*2]=x;
		ans+=edgedivide(u,v,x);
		printf("%lld\n",ans);
	}
	return 0;
}

