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
int n,k,a[N],p[N],hd[N],nxt[N],to[N],ec,t[N],ans,f[N];
int s[N],tot;
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

int dfs(int u){
	if(!t[u])return 0;
	t[u]=0;
	int res=a[u];
	for(int i=hd[u];i;i=nxt[i])res+=dfs(to[i]);
	return res;
}

void dfs2(int u,int from){
	s[++tot]=u;
	for(int i=hd[u];i;i=nxt[i])if(to[i]^from)dfs2(to[i],u);
	return;
}

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	if(n<=20){
		for(int i=0;i<(1<<n);i++){
			int P=1,A=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j))P=(P*p[j+1])%Mod,t[j+1]=1;
				else P=(P*(1-p[j+1]))%Mod,t[j+1]=0;
			}
			for(int j=0;j<n;j++){
				if(t[j+1])A=(A+qp(dfs(j+1)%Mod,k))%Mod;
			}
			ans=(ans+A%Mod*P)%Mod;
		}
		ans=(ans+Mod)%Mod;
		printf("%lld\n",ans);
		return 0;
	}
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]*(1-p[s[i]])%Mod;
		int P=1,A=0;
		for(int j=i;j>=1;j--){
			P=(P*p[s[j]])%Mod,A=(A+a[s[j]])%Mod;
			int _p=(P*(1-p[s[j-1]]))%Mod;
			if(j!=1)f[i]=(f[i]+(qp(A,k)+f[j-2])*_p)%Mod;
			else f[i]=(f[i]+qp(A,k)%Mod*_p)%Mod;
		}
	}
	printf("%lld\n",f[n]);
	return 0;
}

