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

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e3+7,Mod=998244353,INF=1e9+7;
int n,m,k,dis[N][N],vis[N][N],pr[N][N],s,to,T,t,pa[N*10];
struct node{
	int id,from;
	node(int id=0,int from=0,int dis=0):id(id),from(from){}
};
struct ban{
	int a,b,c;
	ban(int a=0,int b=0,int c=0):a(a),b(b),c(c){}
	bool operator < (const ban& A)const{if(a==A.a){if(b==A.b)return c<A.c;return b<A.b;}return a<A.a;}
};
vector<int> g[N];
set<ban> B;
queue<node> Q;

int main(){
	n=read(),m=read(),k=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1,a,b,c;i<=k;i++){
		a=read(),b=read(),c=read();
		B.insert(ban(a,b,c));
	}
	for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dis[i][j]=INF;
	dis[1][0]=0,Q.push(node(1,0));
	while(!Q.empty()){
		int u=Q.front().id,from=Q.front().from;
		Q.pop();
		if(u==n){
			pa[++t]=to=n,s=from;
			while(s!=1)pa[++t]=s,T=s,s=pr[to][s],to=T;
			pa[++t]=1;
			printf("%d\n",t-1);
			for(int i=t;i>=1;i--)printf("%d ",pa[i]);
			printf("\n");
			return 0;
		}
		if(vis[u][from]++)continue;
		for(int i=0,v;i<signed(g[u].size());i++){
			v=g[u][i];
			if(B.count(ban(from,u,v)))continue;
			if(dis[u][from]+1<dis[v][u]){
				dis[v][u]=dis[u][from]+1,pr[v][u]=from;
				Q.push(node(v,u));
			}
		}
	}
	printf("-1\n");
	return 0;
}
