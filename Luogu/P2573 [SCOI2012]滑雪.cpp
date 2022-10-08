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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,h[N],ans,len,vis[N];
int hd[N],nxt[N*10],to[N*10],c[N*10],ec;
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,c[ec]=w;return;} 
int p;
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{
		if(h[x]==h[A.x])return y>A.y;
		return h[x]<h[A.x];
	}
};
priority_queue<node> Q;

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)h[i]=read();
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	ans=1,p=1,vis[1]=1;
	while(p){
		for(int i=hd[p],v;i;i=nxt[i]){
			v=to[i];
			if(vis[v]||h[v]>h[p])continue;
			Q.push(node(v,c[i]));
		}
		p=0;
		while(!Q.empty()){
			node v=Q.top();Q.pop();
			if(vis[v.x])continue;
			p=v.x,++ans,len+=v.y,vis[p]=1;
			break;
		}
	}
	printf("%lld %lld\n",ans,len);
	return 0;
}

