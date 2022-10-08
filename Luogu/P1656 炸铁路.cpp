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

const int N=1e4+7,Mod=998244353,INF=1e9+7;
int n,m,dfn[N],low[N],ct,t;
struct edge{
	int to,tag;
	edge(int to=0,int tag=0):to(to),tag(tag){}
};
vector<edge> g[N];
struct ans{
	int u,v;
	ans(int u=0,int v=0):u(u),v(v){};
	bool operator < (const ans& A)const{if(u==A.u)return v<A.v;return u<A.u;}
}a[N];

void tarjan(int u,int pr){
	dfn[u]=low[u]=++ct;
	for(int i=0,v;i<int(g[u].size());i++){
		v=g[u][i].to;
		if(!dfn[v]){
			tarjan(v,u);
			if(dfn[u]<low[v]){
				a[++t]=ans(min(u,v),max(u,v));
			}
			low[u]=min(low[u],low[v]);
		}
		else if(v!=pr)low[u]=min(low[u],dfn[v]);
	}
	return;
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		g[u].push_back(edge(v,0)),g[v].push_back(edge(u,1));
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i,i);
	sort(a+1,a+t+1);
	for(int i=1;i<=t;i++)printf("%d %d\n",a[i].u,a[i].v);
	return 0;
}
