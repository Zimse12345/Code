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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,k,L,ty[N];
int vis[N],ins[N],dis1[N],c1[N],dis2[N],c2[N],tag[N];
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){};
};
vector<edge> g[N];

queue<int> q;
void spfa(){
//	while(!q.empty())q.pop();
//	q.push(s),dis[s]=0,ins[s]=1;
	for(int i=1;i<=n;i++)if(tag[i])dis1[i]=0,c1[i]=ty[i],q.push(i);
	while(!q.empty()){
		int u=q.front();
//		printf("(%d %d %d %d %d)\n",u,dis1[u],c1[u],dis2[u],c2[u]);
		q.pop(),++vis[u],ins[u]=0;
		for(int i=0,v,w;i<signed(g[u].size());i++){
			v=g[u][i].to,w=g[u][i].w;
			int Tag=0;
			if(c1[u]){
			if(dis1[u]+w<dis1[v]||!c1[v]){
				if(c1[u]==c1[v])dis1[v]=dis1[u]+w;
				else dis2[v]=dis1[v],c2[v]=c1[v],dis1[v]=dis1[u]+w,c1[v]=c1[u];
				Tag=1;
			}
			else if(dis1[u]+w<dis2[v]||!c2[v])if(c1[u]!=c1[v]){
				dis2[v]=dis1[u]+w,c2[v]=c1[u];
				Tag=1;
			}
			}
			if(c2[u]){
			if(dis2[u]+w<dis1[v]||!c1[v]){
				if(c2[u]==c1[v])dis1[v]=dis2[u]+w;
				else dis2[v]=dis1[v],c2[v]=c1[v],dis1[v]=dis2[u]+w,c1[v]=c2[u];
				Tag=1;
			}
			else if(dis2[u]+w<dis2[v]||!c2[v])if(c2[u]!=c1[v]){
				dis2[v]=dis2[u]+w,c2[v]=c2[u];
				Tag=1;
			}
			}
			if(Tag){
				if(!ins[v])q.push(v),ins[v]=1;
			}
		}
	}
	return;
}

signed main(){
	n=read(),m=read(),k=read(),L=read();
	for(int i=1;i<=n;i++)ty[i]=read();
	while(L--)tag[read()]=1;
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		g[u].push_back(edge(v,w));
		g[v].push_back(edge(u,w));
	}
	spfa();
	for(int i=1;i<=n;i++){
		if(c1[i]&&c1[i]!=ty[i])printf("%lld ",dis1[i]);
		else if(c2[i])printf("%lld ",dis2[i]);
		else printf("-1 ");
	}
	printf("\n");
	return 0;
}
