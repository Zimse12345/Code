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

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int T,n,m;
int vis[N],ins[N],dis[N];
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){};
};
vector<edge> g[N];

queue<int> q;
bool spfa(int s){
	while(!q.empty())q.pop();
	q.push(s),dis[s]=0,ins[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop(),++vis[u],ins[u]=0;
		if(vis[u]>n+1)return 1;
		for(int i=0,v,w;i<int(g[u].size());i++){
			v=g[u][i].to,w=g[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!ins[v])q.push(v),ins[v]=0;
			}
		}
	}
	return 0;
}

int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++)g[i].resize(0),dis[i]=INF,vis[i]=ins[i]=0;
		for(int i=1,u,v,w;i<=m;i++){
			u=read(),v=read(),w=read();
			g[u].push_back(edge(v,w));
			if(w>=0)g[v].push_back(edge(u,w));
		}
		if(spfa(1))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
