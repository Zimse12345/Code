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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,val[N],nxt[N],hd[N],to[N],ec,ans[N];
int mx[N][22],tot[N],p[30];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}};
vector<node> Q[N];

void dfs(int u,int from){
	mx[u][1]=val[u],tot[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u);
		int p1=1,p2=1,p3=1;
		while((p1<=tot[u]||p2<=tot[v])&&p3<=20){
			if(p1>tot[u])p[p3]=mx[v][p2],++p2,++p3;
			else if(p2>tot[v])p[p3]=mx[u][p1],++p1,++p3;
			else if(mx[u][p1]>mx[v][p2])p[p3]=mx[u][p1],++p1,++p3;
			else p[p3]=mx[v][p2],++p2,++p3;
		}
		for(int j=1;j<=p3;j++)mx[u][j]=p[j];
		tot[u]=p3-1;
	}
	for(unsigned j=0;j<Q[u].size();j++)ans[Q[u][j].y]=mx[u][Q[u][j].x];
	return;
}

signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	for(int i=1,v,k;i<=q;i++){
		v=read(),k=read();
		Q[v].push_back(node(k,i));
	}
	dfs(1,0);
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}

