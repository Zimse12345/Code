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

const int N=1e6+7,Mod=998244353,INF=1e14+7;
int n,m,l,r,a[N],dis[N],vis[N],ans;
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
struct node{
	int id,d;
	node(int id=0,int d=0):id(id),d(d){}
	bool operator < (const node& A)const{return d>A.d;}
};
vector<edge> g[N];
priority_queue<node> Q;

inline int f(int k,int p){
	if(k<p)return 0;
	return (k-p)/m;
}

signed main(){
	n=read(),l=read(),r=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1),m=a[1];
	for(int i=2;i<=n;i++){
		for(int t=0;t<m;t++)g[t].push_back(edge((t+a[i])%m,a[i]));
	}
	for(int i=0;i<m;i++)dis[i]=INF;
	dis[0]=0,Q.push(node(0,0));
	while(!Q.empty()){
		int u=Q.top().id;
		Q.pop();
		if(vis[u]++)continue;
		for(unsigned i=0,v,w;i<g[u].size();i++){
			v=g[u][i].to,w=g[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				Q.push(node(v,dis[v]));
			}
		}
	}
	for(int i=0;i<m;i++)if(dis[i]<=r){
		int L=max(l,dis[i]),R=r;
		if(L<=R)ans+=f(R,i)-f(L-1,i);
	}
	printf("%lld\n",ans);
	return 0;
}
