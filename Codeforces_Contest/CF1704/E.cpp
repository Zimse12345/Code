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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int T,n,m,hd[N],nxt[N],to[N],ec,deg[N],a[N],f[N][N],outdeg[N];

inline void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v),++deg[v],++outdeg[u];
		queue<int> q;
		for(int i=1;i<=n;i++){
			if(!deg[i])q.push(i);
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			f[u][0]+=a[u];
			for(int i=hd[u],v;i;i=nxt[i]){
				v=to[i];
				for(int j=0;j<n;j++){
					f[v][j+1]+=f[u][j];
					if(f[v][j+1]>=2*Mod)f[v][j+1]=f[v][j+1]%Mod+Mod;
				}
				--deg[v];
				if(!deg[v])q.push(v);
			}
		}
		int ans=0,p=0;
		for(int i=1;i<=n;i++)if(!outdeg[i])p=i;
		for(int i=0;i<=n;i++){
			if(f[p][i])ans=i+1;
			f[p][i+1]+=max(0ll,f[p][i]-1);
		}
		if(f[p][n+1])ans=max(f[p][n+1]+n+1,ans);
		printf("%lld\n",ans%Mod);
		
		for(int i=1;i<=n;i++){
			deg[i]=0,hd[i]=0,outdeg[i]=0;
			for(int j=0;j<=n+1;j++)f[i][j]=0;
		}
		for(int i=1;i<=m;i++)nxt[i]=to[i]=0;
		ec=0;
	}
	return 0;
}

