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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,q,t,c,hd[N],nxt[N],to[N],tag[N],ec;

struct node{
	int x,y,id;
	node(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
};
vector<node> task[N][N];
int vis[N];

inline void add(int u,int v,int w){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,tag[ec]=w;
	return;
}

int dfs(int u,int time){
	if(time==t){
		int res=0;
		for(unsigned i=0;i<task[u][time].size();i++){
		node p=task[u][time][i];
		if(!vis[p.id]&&time+p.x<=t){
			vis[p.id]=1;
			res=max(res,dfs(u,time+p.x)+p.y);
			vis[p.id]=0;
		}
	}
	return res;
	}
	int res=0;
	for(int i=hd[u];i;i=nxt[i]){
		res=max(res,dfs(to[i],time+1)+tag[i]*c);
	}
	res=max(res,dfs(u,time+1));
	for(unsigned i=0;i<task[u][time].size();i++){
		node p=task[u][time][i];
		if(!vis[p.id]&&time+p.x<=t){
			vis[p.id]=1;
			res=max(res,dfs(u,time+p.x)+p.y);
			vis[p.id]=0;
		}
	}
	return res;
}

signed main(){
	n=read(),q=read(),t=read(),c=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}
	for(int i=1,pos,a,k,p;i<=q;i++){
		pos=read(),a=read(),k=read(),p=read();
		task[pos][a].push_back(node(k,p,i));
	}
	for(int i=1;i<=n;i++)printf("%lld ",dfs(i,0));
	printf("\n");
	return 0;
}

