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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],b[N],hd[N],nxt[N],to[N],ec,tag,vis[N];
vector<int> p[N];

inline void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

void dfs(int u,int c){
	if(vis[u])return;
	vis[u]=c+1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]==vis[u])tag=0;
		else dfs(v,c^1);
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read(),b[i]=read();
			p[a[i]].push_back(i),p[b[i]].push_back(i);
		}
		for(int i=1;i<=n;i++){
			for(unsigned x=0;x<p[i].size();x++){
				for(unsigned y=x+1;y<p[i].size();y++){
					add(p[i][x],p[i][y]);
					add(p[i][y],p[i][x]);
				}
			}
		}
		tag=1;
		for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
		if(tag)printf("Yes\n");
		else printf("No\n");
		for(int i=1;i<=ec;i++)nxt[i]=to[i]=0;
		for(int i=1;i<=n;i++)p[i].resize(0),hd[i]=0,vis[i]=0;
		ec=0;
	}
	return 0;
}

