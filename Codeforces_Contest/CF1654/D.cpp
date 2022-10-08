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
int T,n,val[N],ct[N],ctt[N],t[N];
struct edge{
	int u,v,a,b;
	edge(int u=0,int v=0,int a=0,int b=0):u(u),v(v),a(a),b(b){}
};
inline int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}
inline int inv(int x){return qp(x,Mod-2);}
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}

vector<edge> g[N];

void dfs(int u,int from){
	for(int i=0;i<signed(g[u].size());i++){
		int v=g[u][i].v,a=g[u][i].a,b=g[u][i].b;
		if(v==from)continue;
		val[v]=val[u]*inv(a)%Mod*b%Mod;
//		printf("val[%d]=val[%d]/%d*%d  (%d*inv(%d)*%d)=%lld\n",v,u,a,b,val[u],a,b,val[v]);
		vector<int> p,pp;
		for(int j=2;j*j<=a;j++)if(a%j==0){
			while(a%j==0)a/=j,p.push_back(j);
		}
		if(a>1)p.push_back(a);
		for(int j=2;j*j<=b;j++)if(b%j==0){
			while(b%j==0)b/=j,pp.push_back(j);
		}
		if(b>1)pp.push_back(b);
		
		
		for(int i=0;i<signed(pp.size());i++)++ctt[pp[i]];
		for(int i=0;i<signed(p.size());i++){
			int v=p[i];
			++ct[v];
			t[v]=max(t[v],ct[v]-ctt[v]);
		}
		dfs(v,u);
		for(int i=0;i<signed(pp.size());i++)--ctt[pp[i]];
		for(int i=0;i<signed(p.size());i++)--ct[p[i]];
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)t[i]=ct[i]=0,g[i].clear();
		for(int i=1,u,v,a,b;i<n;i++){
			u=read(),v=read(),a=read(),b=read();
			int gc=gcd(a,b);
			a/=gc,b/=gc;
			g[u].push_back(edge(u,v,a,b));
			g[v].push_back(edge(v,u,b,a));
		}
		val[1]=1;
		dfs(1,0);
		int ans=0;
		for(int i=1;i<=n;i++)ans=(ans+val[i])%Mod;
		for(int i=1;i<=n;i++)if(t[i])ans=(ans*qp(i,t[i]))%Mod;
//		printf("%lld\n",ans);
//		for(int i=1;i<=n;i++)printf("<%d> ",val[i]);
		printf("%lld\n",ans);
	}
	return 0;
}

