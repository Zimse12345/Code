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

const int N=2e3+7,Mod=1e9+7,INF=1e9+7;
int n,m,hd[N],nxt[N],to[N],ec,w[N],dep[N];
int f[110][110][110],k,len,t[110][110],cnt[N];
int dfn[N],Time,p[N],Len[N],fac[N],invfac[N];
inline void add(int u,int v,int _w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,w[ec]=_w;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
inline int ldl(int x,int k=Mod-2){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;k/=2,x=(x*x)%Mod;}return res;}

void dfs(int u,int from,int d){
	dep[u]=d;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u,d+w[i]);
	}
	return;
}

void dp(int u,int from){
	
	cnt[u]=1;
	dfn[u]=++Time,p[Time]=u;
	for(int dis1=0;dis1<=n;dis1++){
		for(int cnt1=0;cnt1<=cnt[u];cnt1++){
			f[u][dis1][cnt1]=0;
		}
	}
	f[u][0][0]=1;
	f[u][u][1]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dp(v,u);
		for(int k1=dfn[u],dis1=0;k1<=dfn[u]+cnt[u];k1++){
			dis1=k1<dfn[u]+cnt[u]?p[k1]:0;
			for(int cnt1=0;cnt1<=cnt[u];cnt1++)if(f[u][dis1][cnt1]){
				for(int k2=dfn[v],dis2=0;k2<=dfn[v]+cnt[v];k2++){
					dis2=k2<dfn[v]+cnt[v]?p[k2]:0;
					for(int cnt2=0;cnt2<=cnt[v];cnt2++)if(f[v][dis2][cnt2]){
						if(dis1&&dis2&&(dep[dis1]+dep[dis2]-2*dep[u])>len)continue;
						int _d=dep[dis1]>dep[dis2]?dis1:dis2;
						addmod(t[_d][cnt1+cnt2],f[u][dis1][cnt1]*f[v][dis2][cnt2]);
					}
				}
			}
		}
		cnt[u]+=cnt[v];
		for(int dis1=0;dis1<=n;dis1++){
			for(int cnt1=0;cnt1<=cnt[u];cnt1++){
				f[u][dis1][cnt1]=t[dis1][cnt1];
				t[dis1][cnt1]=0;
			}
		}
	}
	return;
}

int C(int x,int y){
	if(y>x)return 0;
	return fac[x]*invfac[y]%Mod*invfac[x-y]%Mod;
}

signed main(){
	fac[0]=1,invfac[0]=1;
	for(int i=1;i<N;i++)fac[i]=(fac[i-1]*i)%Mod,invfac[i]=ldl(fac[i]);
	dep[0]=-1;
	n=read(),m=read();
	int tag=1;
	for(int i=1,u,v,_w;i<n;i++){
		u=read(),v=read(),_w=read(),add(u,v,_w),add(v,u,_w);
		Len[i+1]=_w;
		if(!(u==i&&v==i+1))tag=0;
	}
	if(tag){
		while(m--){
			int ans=0;
			k=read(),len=read();
			for(int l=1,r=1,sum=0;l<=n;l++){
				sum-=Len[l];
				while(r<n&&sum+Len[r+1]<=len)sum+=Len[++r];
				addmod(ans,C(r-l,k-1));
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	while(m--){
		k=read(),len=read();
		dfs(1,0,0);
		Time=0;
		dp(1,0);
		int ans=0;
		for(int i=1;i<=n;i++)addmod(ans,f[1][i][k]);
		printf("%lld\n",ans);
	}
	return 0;
}

