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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=1e9+7,INF=1e9+7;
int q,n,m,hd[N],nxt[N],to[N],ec,ans,S,T;
int dis[2][N],vis[N],cnt[2][N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return y>A.y;}};
priority_queue<node> Q;
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void Dijkstra(int s,int t){
	for(int i=1;i<=n;i++)dis[t][i]=INF,vis[i]=0;
	dis[t][s]=0,cnt[t][s]=1,Q.push(node(s,0));
	while(!Q.empty()){
		int u=Q.top().x;Q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(dis[t][u]+1<dis[t][v])dis[t][v]=dis[t][u]+1,cnt[t][v]=cnt[t][u],Q.push(node(v,dis[t][v]));
			else if(dis[t][u]+1==dis[t][v])(cnt[t][v]+=cnt[t][u])%=Mod;
		}
	}
	return;
}

signed main(){
	q=read();
	while(q--){
		n=read(),m=read();
		S=read(),T=read();
		for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v),add(v,u);
		Dijkstra(S,0),Dijkstra(T,1);
		ans=cnt[0][T];
		for(int u=1;u<=n;u++){
			for(int i=hd[u],v;i;i=nxt[i]){
				v=to[i];
				if(dis[0][u]+1==dis[0][v])continue;
				if(dis[0][T]==dis[0][u]+dis[1][v])ans=(ans+cnt[0][u]*cnt[1][v])%Mod;
			}
		}
		printf("%lld\n",ans);
		
		for(int i=1;i<=ec;i++)nxt[i]=to[i]=0;
		for(int i=1;i<=n;i++)cnt[0][i]=cnt[1][i]=hd[i]=0;
		ans=ec=0;
	}
	return 0;
}

