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
int n,m,vis[N],rt,rtv,ans[N],q[N];
int cnt[N],sz,ds[N],dds[N],ct[N],tp,ttp,d[N];
int hd[N],to[N],c[N],nxt[N],ec;
inline void add(int u,int v,int w){to[++ec]=v,c[ec]=w,nxt[ec]=hd[u],hd[u]=ec;return;}

void findrt(int u,int from){
	cnt[u]=1;
	int ms=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]||v==from)continue;
		findrt(v,u),cnt[u]+=cnt[v];
		ms=max(ms,cnt[v]);
	}
	ms=max(ms,sz-cnt[u]);
	if(ms<rtv)rt=u,rtv=ms;
	return;
}

void getdis(int u,int fw,int from){
	ds[++tp]=d[u]+fw;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]||v==from)continue;
		d[v]=d[u]+c[i];
		getdis(v,fw,u);
	}
	return;
}

void solve(int u,int fw,int t){
	tp=ttp=0;
	d[u]=0,ds[0]=-1,getdis(u,fw,0);
	sort(ds+1,ds+tp+1);
	
	for(int i=1;i<=tp;i++){
		if(ds[i]==ds[i-1])++ct[ttp];
		else dds[++ttp]=ds[i],ct[ttp]=1;
	}
	for(int p=1;p<=m;p++){
		for(int L=1,R=ttp;L<=ttp;L++){
			while(R>1&&dds[L]+dds[R]>q[p])--R;
			if(dds[L]+dds[R]==q[p]){
				ans[p]+=ct[L]*ct[R]*t;
				if(L==R)ans[p]-=ct[L]*t;
			}
		}
	}
	return;
}

void divide(int u){
	solve(u,0,1);
	vis[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		solve(v,c[i],-1);
		rt=0,rtv=INF,sz=cnt[v],findrt(v,0);
		divide(rt);
	}
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	for(int i=1;i<=m;i++)q[i]=read();
	
	sz=n,rtv=INF;
	findrt(1,0);
	divide(rt);
	for(int i=1;i<=m;i++){
		if(ans[i])printf("AYE\n");
		else printf("NAY\n");
	}
	return 0;
}

