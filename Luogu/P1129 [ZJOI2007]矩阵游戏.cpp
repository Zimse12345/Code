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

const int N=1e5+7,Mod=998244353,INF=1e12;
int T,n,m,s,t,hd[N],nxt[N],h[N],d[N],ec=1,ans;
int c,cx[N],cy[N],a[300][300];
struct edge{int u,v,val;edge(int u=0,int v=0,int val=0):u(u),v(v),val(val){}}E[N];
inline void add(int u,int v,int val){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,val);return;}
inline void Add(int u,int v,int val){add(u,v,val),add(v,u,0);return;}
queue<int> Q;

bool bfs(){
	for(int i=1;i<=n;i++)d[i]=0;
	d[s]=1,Q.push(s);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=hd[u];i;i=nxt[i]){
			if(!d[E[i].v]&&E[i].val)d[E[i].v]=d[u]+1,Q.push(E[i].v);
		}
	}
	return d[t];
}

int dfs(int u,int maxf){
	if(u==t||!maxf)return maxf;
	int flow=0;
	for(int i=h[u];i;i=nxt[i]){
		if(d[E[i].v]==d[u]+1&&E[i].val){
			int f=dfs(E[i].v,min(maxf,E[i].val));
			flow+=f,maxf-=f,E[i].val-=f,E[i^1].val+=f;
			if(!maxf)break;
		}
		h[u]=nxt[h[u]];
	}
	return flow;
}

void dinic(){
	while(bfs()){
		for(int i=1;i<=n;i++)h[i]=hd[i];
		ans+=dfs(s,INF);
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
			a[i][j]=read(),cx[i]+=a[i][j],cy[j]+=a[i][j],c+=a[i][j];
			if(a[i][j])Add(i,j+n,1);
		}
		s=2*n+1,t=2*n+2;
		for(int i=1;i<=n;i++)Add(s,i,1),Add(n+i,t,1);
		n=2*n+2,dinic(),n=n/2-1;
		if(ans==n)printf("Yes\n");
		else printf("No\n");
		
		for(int i=1;i<=n*2+2;i++)hd[i]=0;
		for(int i=2;i<=ec;i++)nxt[i]=0;
		ans=0,ec=1;
		for(int i=1;i<=n;i++)cx[i]=cy[i]=0;
	}
	return 0;
}

