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

const int N=1e5+7,Mod=1073741824,INF=1e9+7;
int T,A,B,C,n,ans;
int prime[N],tot,pr[N],mu[N],e[N],sigma[N],ss[N],fa[N],fb[N],fc[N];
int val[N],cnt;
int eu[N*10],ev[N*10],deg[N],ec,vis[N];
vector<int> g[N];

inline int Gcd(int a,int b){return b?Gcd(b,a%b):a;}
inline int Lcm(int a,int b){return a/Gcd(a,b)*b;}

inline void add(int u,int v){
	++deg[u],++deg[v],eu[++ec]=u,ev[ec]=v;
	return;
}

inline int sol(int u,int v,int w,int tag){
	int uv=Lcm(u,v),vw=Lcm(v,w),uw=Lcm(u,w),k=mu[u]*mu[v]*mu[w];
	if(tag==1)return k*fa[uv]*fb[uv]%Mod*fc[uv];
	if(tag==2)return k*(fa[uv]*fb[uw]%Mod*fc[uw]+fa[uw]*fb[uv]%Mod*fc[uw]+fa[uw]*fb[uw]%Mod*fc[uv])%Mod;
	return k*(fa[uv]*fb[uw]%Mod*fc[vw]+fa[uv]*fb[vw]%Mod*fc[uw]+
			fa[uw]*fb[uv]%Mod*fc[vw]+fa[uw]*fb[vw]%Mod*fc[uv]+
			fa[vw]*fb[uv]%Mod*fc[uw]+fa[vw]*fb[uw]%Mod*fc[uv])%Mod;
}

signed main(){
	mu[1]=sigma[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])prime[++tot]=i,pr[i]=i,mu[i]=-1,sigma[i]=2,e[i]=1;
		for(int j=1,v;j<=tot&&prime[j]*i<N;j++){
			v=prime[j]*i;
			pr[v]=prime[j],mu[v]=-mu[i],sigma[v]=sigma[i]*2,e[v]=1;
			if(prime[j]==pr[i]){mu[v]=0,sigma[v]=sigma[i]/(e[i]+1)*(e[i]+2),e[v]=e[i]+1;break;}
		}
	}
	for(int i=1;i<N;i++)ss[i]=(ss[i-1]+sigma[i])%Mod;
	T=1;
	while(T--){
		A=read(),B=read(),C=read(),ans=ec=0;
		n=max(max(A,B),C);
		for(int i=1;i<=n;i++)fa[i]=ss[A/i],fb[i]=ss[B/i],fc[i]=ss[C/i];
		for(int lcm=1,x;lcm<=n;lcm++)if(mu[lcm]!=0){
			cnt=0,x=lcm;
			while(x^1)val[++cnt]=pr[x],x/=pr[x];
			for(int u=0;u<(1<<cnt);u++){
				for(int t=u,v;;t=(t-1)&u){
					v=t|(((1<<cnt)-1)^u);
					int U=1,V=1;
					for(int p=0;p<cnt;p++){
						if((1<<p)&u)U*=val[p+1];
						if((1<<p)&v)V*=val[p+1];
					}
					if(U<V)add(U,V);
					if(t==0)break;
				}
			} 
		}
		for(int i=1,u,v;i<=ec;i++){
			u=eu[i],v=ev[i];
			if(deg[v]<deg[u])swap(u,v);
			g[u].push_back(v);
		}
		for(int u=1;u<=n;u++){
			(ans+=sol(u,u,u,1))%=Mod;
			for(int i=0;i<signed(g[u].size());i++){
				vis[g[u][i]]=u;
				(ans+=sol(u,u,g[u][i],2)+sol(g[u][i],g[u][i],u,2))%=Mod;
			}
			for(int i=0,v;i<signed(g[u].size());i++){
				v=g[u][i];
				for(int j=0;j<signed(g[v].size());j++)if(vis[g[v][j]]==u)(ans+=sol(u,v,g[v][j],3))%=Mod;
			}
		}
		ans=(ans+Mod)%Mod;
		printf("%lld\n",ans);
		
		for(int i=1;i<=n;i++)deg[i]=vis[i]=0,g[i].clear();
	}
	return 0;
}

