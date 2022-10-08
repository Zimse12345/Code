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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e6+7,Mod=998244353,INF=1e9+7;
int n,m,u[N],v[N],deg[N],ec,hd[N];
struct edge{
	int to,w,nxt;
	edge(int to=0,int w=0,int nxt=0):to(to),w(w),nxt(nxt){};
}e[N];
void add(int u,int v,int w){
	e[++ec]=edge(v,w,hd[u]),hd[u]=ec;
	return;
}

int vis[N],st[N],tot;
vector<int> ans;
void dfs(int x){
	for(int &i=hd[x];i;){
		int &y=e[i].to,&w=e[i].w;
		i=e[i].nxt;
		if(!vis[w]){
			vis[w]=true;
			dfs(y),st[++tot]=w;
		}
	}
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		u[i]=read(),v[i]=read();
		add(u[i],v[i],i),add(v[i],u[i],i);
		++deg[u[i]],++deg[v[i]];
	}
	int _m=m;
	for(int i=1;i<=n;i++)if(deg[i]&1)u[++_m]=0,v[_m]=i,add(0,i,_m),add(i,0,_m);
	for(int x=0;x<=n;x++){
		if(hd[x]){
			tot=0;
			dfs(x);
			for(int i=1;i<=tot;i+=2)if(st[i]<=m)ans.push_back(st[i]);
			st[++tot]=st[1];
			for(int i=2;i<tot;i+=2)if(st[i]<=m&&(st[i-1]>m||st[i+1]>m))ans.push_back(st[i]);
		}
	}
	printf("%d\n",signed(ans.size()));
	for(int i=0;i<signed(ans.size());i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}

