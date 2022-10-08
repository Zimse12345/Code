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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],_a[N],ty[N],p[N],v[N],c[N],Q,f[N],d[N];
int mul[N],vis[N],ff[N],tot[N],pr[N],Mul=1,ans;
vector<int> g[N];
queue<int> q;

int cnt=0;
void dfs1(int u){//++cnt;
//if(cnt>=10000000)printf("*%lld\n",u);
	if(vis[u])return;
	vis[u]=1;
	if(ty[u]==1){
		mul[u]=1,vis[u]=1;
		return;
	}
	if(ty[u]==2){
		mul[u]=v[u],vis[u]=1;
		return;
	}
	mul[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		dfs1(v),mul[u]=(mul[u]*mul[v])%Mod;
	}
	return;
}

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=_a[i]=read();
	m=read();
	for(int i=1;i<=m;i++){
		ty[i]=read();
		if(ty[i]==1)p[i]=read(),v[i]=read();
		if(ty[i]==2)v[i]=read();
		if(ty[i]==3){
			c[i]=read();
			for(int j=1,k;j<=c[i];j++)k=read(),g[i].push_back(k),++pr[k];
		}
	}
	Q=read();
	for(int i=1;i<=Q;i++)f[i]=read();
	for(int i=1;i<=m;i++)if(!vis[N]){//printf("(%lld)",i);
		if(ty[i]==1)mul[i]=1;
		else if(ty[i]==2)mul[i]=v[i];
		else dfs1(i);
		vis[i]=1;
	}//return 0;
	ff[Q]=1,d[f[Q]]=1;
	for(int i=1;i<=Q;i++)Mul=(Mul*mul[f[i]])%Mod;
	for(int i=Q-1;i>=1;i--){
		ff[i]=(ff[i+1]*mul[f[i+1]])%Mod;
		d[f[i]]=(d[f[i]]+ff[i])%Mod;
		//printf("$$ %lld $$\n",ff[i]);
	}
	//for(int i=1;i<=m;i++)printf("<%lld>",d[i]);
	for(int i=1;i<=m;i++){
		if(pr[i]==0)q.push(i);
		//printf("{%d %d %d %d}\n",i,pr[i],mul[i],d[i]);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();//printf("<%d %d>\n",u,d[u]);
		if(ty[u]==1){
			a[p[u]]=(a[p[u]]+d[u]*v[u])%Mod;
		}
		if(ty[u]==2){
			//Mul=(Mul*qp(v[u],d[u]));
		}
		if(ty[u]==3){
			int t=g[u].size();
			int ml=1;
			for(int i=g[u].size()-1;i>=0;i--){
				int v=g[u][i];
				d[v]=(d[v]+ml*d[u])%Mod;
				ml=(ml*mul[v])%Mod;
				--pr[v];
				//printf("(%d %d)\n",v,pr[v]);
				if(pr[v]==0)q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=(a[i]+_a[i]*Mul-_a[i])%Mod;
		printf("%lld ",a[i]);
	}
	printf("\n");
	//printf("\n(%d)\n",Mul);
	return 0;
}
