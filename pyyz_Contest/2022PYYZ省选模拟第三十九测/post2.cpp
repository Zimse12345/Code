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

const int N=1e5+7,Mod=998244353,INF=1e12+7;
int n,m,C,hd[N],nxt[N],to[N],len[N],ec,ans=INF,pos[N],dis[N],vis[N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return y>A.y;}};
priority_queue<node> Q;
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;return;}

signed main(){
	n=read(),m=read(),C=read();
	for(int i=1,u,v,w;i<n;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	for(int i=1;i<=m;i++)pos[i]=read();
	for(int i=1;i<(1<<n);i++){
		int W=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j))W+=C,dis[j+1]=0,Q.push(node(j+1,0));
			else dis[j+1]=INF;
			vis[j+1]=0;
		}
		while(!Q.empty()){
			int u=Q.top().x;
			Q.pop();
			if(vis[u]++)continue;
			for(int id=hd[u],v;id;id=nxt[id]){
				v=to[id];
				if(dis[u]+len[id]<dis[v]){
					dis[v]=dis[u]+len[id];
					Q.push(node(v,dis[v]));
				}
			}
		}
		for(int i=1;i<=m;i++)W+=dis[pos[i]];
		ans=min(ans,W);
	}
	printf("%lld\n",ans);
	return 0;
}

