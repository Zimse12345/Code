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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=1e9+7,INF=1e9+7;
int rt,n,D,hd[N],nxt[N],to[N],ec;
int fa[N],f[N],pf[N],F[N];
int f0,f1,r[N],pr[N],R[N],P[N],Cnt[2];

inline void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

void dfs0(int u,int from){
	fa[u]=from;
	int p=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs0(v,u);
		if(!f[v]){
			f[u]=1;
			if(p==0)p=v;
			else p=-1;
		}
	}
	if(f[u]==0){
		r[u]=1;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(v==from)continue;
			r[u]+=r[v];
		}
	}
	else if(p>0)r[u]=r[p];
	P[u]=p;
	return;
}

void dfs1(int u){
	F[u]=(f[u]|(pf[u]^1));
	if(F[u])++f1;
	else ++f0;
	R[u]=r[u],++Cnt[F[u]];
	if(u!=rt){
		if(F[u]==0)R[u]+=pr[u];
		else{
			if(!P[u]&&pf[u]==0)R[u]=pr[u]; 
			else if(P[u]&&pf[u]==0)R[u]=0;
		}
	}
	int cnt=0,sum=pr[u],p1=0,p2=0;
	if(pf[u]==0)p1=u;
	if(!pf[u])++cnt;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==fa[u])continue;
		if(!f[v])++cnt;
		sum+=r[v];
		if(!f[v]){
			if(p1==0)p1=v;
			else if(p2==0)p2=v;
			else p1=-1,p2=-1;
		}
	}
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==fa[u])continue;
		if(!f[v])--cnt;
		if(cnt)pf[v]=1;
		if(pf[v]==0)pr[v]=1+sum-r[v];
		else if(p1!=-1){
			if(p2==0||p2==v){
				if(p1!=v){
					if(p1==u)pr[v]=pr[u];
					else pr[v]=r[p1];
				}
			}
			if(p2&&p1==v){
				if(p2==u)pr[v]=pr[u];
				else pr[v]=r[p2];
			}
		}
		dfs1(v);
		if(!f[v])++cnt;
	}
	return;
}

struct mixtra{
	int v[2][2];
	void see(){
    	printf("%lld %lld\n%lld %lld\n",v[0][0],v[0][1],v[1][0],v[1][1]);
    	return;
	}
}a,t;

mixtra mul(mixtra A,mixtra B){
	mixtra res;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++){
		res.v[i][j]=0;
		for(int k=0;k<2;k++)(res.v[i][j]+=A.v[i][k]*B.v[k][j])%=Mod;
	}
	return res;
}

signed main(){
	n=read(),D=read(),rt=1;
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	dfs0(rt,0);
	pf[rt]=1,dfs1(rt);
	for(int i=1;i<=n;i++){
		if(!F[i]){
			(a.v[0][0]+=n-R[i])%=Mod;
			(a.v[0][1]+=n)%=Mod;
			(a.v[1][0]+=R[i])%=Mod;
		}
		else{
			(a.v[0][0]+=R[i])%=Mod;
			(a.v[1][0]+=n-R[i])%=Mod;
			(a.v[1][1]+=n)%=Mod;
		}
	}
	t.v[0][0]=f0,t.v[1][0]=f1,--D;
	while(D){
		if(D&1)t=mul(a,t);
		a=mul(a,a),D/=2;
	}
	f0=t.v[0][0],f1=t.v[1][0];
	int ans=0;
	if(!F[1])ans=R[1]*f0;
	else ans=(n-R[1])*f0+n*f1;
	ans%=Mod;
	printf("%lld\n",ans);
	return 0;
}

