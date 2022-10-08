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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,Type,hd[N],nxt[N],to[N],ec,cnt[N],f[N],g[N],ans;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void dp(int u,int from){
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dp(v,u);
		f[u]+=f[v],cnt[u]+=cnt[v];
	}
	f[u]+=cnt[u],++cnt[u];
	return;
}

void dp2(int u,int from){
	if(from){
		g[u]=g[from]-cnt[u]+n-cnt[u];
	}
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dp2(v,u);
	}
	return;
}

signed main(){
//	freopen("trees3.in","r",stdin);
//	freopen("my.out","w",stdout);
	n=read(),q=read(),Type=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dp(1,0);
	g[1]=f[1];
	dp2(1,0);
	for(int i=1;i<=n;i++)ans+=g[i];
	ans/=2;
	int _ans=ans;
	int _n=n,w=f[1];
	while(q--){
		read(),read(),read();
		ans=(ans+_ans+n*_n+w*n+f[1]*_n)%Mod;
		w+=(f[1]+cnt[1])%Mod,_n+=n;
		printf("%lld\n",ans);
	}
	return 0;
}

