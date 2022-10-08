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

const int N=4e5+7,Mod=998244353,INF=1e18;
int n,m,k,hd[N],nxt[N],to[N],len[N],ec,dis[21][N],vis[N],U[N],V[N],W[N],mx[N];

inline void add(int u,int v,int w){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
	return;
}

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& _)const{return y>_.y;}
}a[N];

priority_queue<node> Q;

void dij(int s,int id){
	for(int i=1;i<=n;i++)dis[id][i]=INF,vis[i]=0;
	dis[id][s]=0,Q.emplace(s,0);
	while(!Q.empty()){
		int u=Q.top().x;
		Q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(dis[id][u]+len[i]<dis[id][v]){
				dis[id][v]=dis[id][u]+len[i];
				Q.emplace(v,dis[id][v]);
			}
		}
	}
	return;
}

inline int Abs(int x){
	return x<0?-x:x;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
		U[i]=u,V[i]=v,W[i]=w;
	}
	k=read();
	dij(1,0); 
	for(int i=1;i<=k;i++)dij(read(),i);
	int ans=INF;
	for(int i=1;i<=n;i++){
		int t=-INF;
		for(int j=0;j<=k;j++)t=max(t,dis[j][i]);
		ans=min(ans,t*2);
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=k;j++)a[j]=node(dis[j][U[i]],dis[j][V[i]]);
		sort(a,a+k+1);
		mx[0]=a[0].x;
		for(int j=1;j<=k;j++){
			ans=min(ans,max(a[j].y,mx[j-1])*2+max(0ll,W[i]-Abs(a[j].y-mx[j-1])));
			mx[j]=max(mx[j-1],a[j].x);
		}
	}
	printf("%lld\n",ans);
	return 0;
}

