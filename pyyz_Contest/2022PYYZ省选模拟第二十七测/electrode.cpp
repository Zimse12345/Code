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

const int N=1e6+7,Mod=998244353,INF=1e4;
int T,nn,mm,p,X[N],Y[N],W[N],H[1200][1200];
int n,s,t,hd[N],nxt[N],h[N],d[N],ec,sum,ans;
struct edge{int u,v,val;edge(int u=0,int v=0,int val=0):u(u),v(v),val(val){}}E[N];
inline void Add(int u,int v,int val){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,val);return;}
inline void add(int u,int v,int val){Add(u,v,val),Add(v,u,0);return;}
queue<int> Q;

void my_init(){
	for(int i=1;i<=n;i++)hd[i]=0;
	while(ec)nxt[ec]=0,E[ec]=edge(0,0,0);
	n=ans=sum=s=t=0,ec=1;
	return;
}

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
		my_init();
		nn=read(),mm=read(),p=read();
		for(int i=1;i<=nn;i++)for(int j=1;j<=mm;j++)H[i][j]=read();
		n=p+2,s=n-1,t=n;
		for(int i=1;i<=p;i++){
			X[i]=read(),Y[i]=read(),W[i]=read();
			int x=W[i]*H[X[i]][Y[i]];
			sum+=x*2;
			add(s,i,x),add(i,t,x*3);
		}
		for(int i=1;i<=p;i++)for(int j=i+1;j<=p;j++){
			int dis=abs(X[i]-X[j])+abs(Y[i]-Y[j]);
			if(dis==1){
				int x=W[i]*W[j];
				sum+=x;
				add(i,j,2*x),add(j,i,2*x);
			}
		}
		dinic();
		printf("%lld\n",sum-ans);
	}
	return 0;
}

