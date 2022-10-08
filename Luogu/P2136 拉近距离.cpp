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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,vis[N],cnt[N],dis[N];
int d1,d2,ans,tag;
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N];

queue<int> Q;
void spfa(int s){
	for(int i=1;i<=n;i++)vis[i]=0,cnt[i]=0,dis[i]=INF;
	dis[s]=0,Q.push(s);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop(),vis[u]=0,++cnt[u];
		if(cnt[u]>n+1){
			tag=1;
			return;
		}
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to,w=g[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!vis[v])Q.push(v),vis[v]=1;
			}
		}
	}
	return;
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=-read();
		g[u].push_back(edge(v,w));
	}
	
	spfa(1),d1=dis[n],spfa(n),d2=dis[1],ans=min(d1,d2);
	if(tag)printf("Forever love\n");
	else printf("%d\n",ans);
	return 0;
}
