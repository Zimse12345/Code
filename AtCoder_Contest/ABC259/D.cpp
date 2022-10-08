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

const int N=5e3+7,Mod=998244353,INF=1e9+7;
int n,vis[N];
long double sx,sy,tx,ty;
int hd[N],nxt[51200000],to[51200000],ec;
long double x[N],y[N],r[N];
queue<int> q;

inline void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

signed main(){
	n=read(),sx=read(),sy=read(),tx=read(),ty=read();
	for(int i=1;i<=n;i++)x[i]=read(),y[i]=read(),r[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			long double dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			dis=sqrt(dis);
			if(r[i]+r[j]<dis)continue;
			if(dis+r[i]<r[j]||dis+r[j]<r[i])continue;
//			printf("%d %d %.6lf\n",i,j,dis);
			add(i,j),add(j,i);
		}
		long double dis=(x[i]-sx)*(x[i]-sx)+(y[i]-sy)*(y[i]-sy);
		dis=sqrt(dis);
		if(abs(dis-r[i])<0.0000000001)vis[i]=1,q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)if(vis[i]){
		long double dis=(x[i]-tx)*(x[i]-tx)+(y[i]-ty)*(y[i]-ty);
		dis=sqrt(dis);
		if(abs(dis-r[i])<0.0000000001){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}

