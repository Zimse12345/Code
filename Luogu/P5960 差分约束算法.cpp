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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int __x=0,__y=1;char __c=' ';
while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();return __x*__y;}

struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};

const int N=1e4+7,Mod=998244353,INF=1e12+7;
int n,m,tag,vis[N],dis[N],iq[N];
vector<edge> g[N];

queue<int> Q;
int SPFA(int s){
	for(int i=0;i<=n;i++)dis[i]=INF;
	dis[s]=0,iq[s]=1,Q.push(s);
	
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		++vis[u],iq[u]=0;
		if(vis[u]>n+10)return 1;
		
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to,w=g[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!iq[v])iq[v]=1,Q.push(v);
			}
		}
	}
	return 0;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v,w;i<=m;i++){
		v=read(),u=read(),w=read();
		g[u].push_back(edge(v,w));
	}
	for(int i=1;i<=n;i++)g[0].push_back(edge(i,0));
	if(SPFA(0))return !printf("NO\n");
	for(int i=1;i<=n;i++)printf("%d ",dis[i]);
	return !printf("\n");
}
