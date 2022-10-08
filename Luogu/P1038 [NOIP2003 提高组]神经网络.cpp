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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,m,c[N],U[N],in[N];
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N];
queue<int> q; 

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)c[i]=read(),U[i]=read();
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),g[u].push_back(edge(v,w)),++in[v];
	for(int i=1;i<=n;i++){
		if(!in[i])q.push(i);
		else c[i]-=U[i];
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0,v,w;i<int(g[u].size());i++){
			v=g[u][i].to,w=g[u][i].w;
			if(c[u]>=0)c[v]+=w*c[u];
			--in[v];
			if(in[v]==0)q.push(v);
		}
	}
	int tag=0;
	for(int i=1;i<=n;i++)if(g[i].size()==0&&c[i]>0){
		printf("%d %d\n",i,c[i]);
		tag=1;
	}
	if(!tag)printf("NULL\n");
	return 0;
}
