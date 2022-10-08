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

const int N=1e2+7,Mod=1e9+7,INF=1e9+7;
int n,m,f[N][N][N][N],hd[N],nxt[N*2],to[N*2],w[N*2],ec,dis[N][N],ans[1000000];
inline void add(int u,int v,int _w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,w[ec]=_w;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return x<A.x;} 
};
vector<node> query[N],p;

void dfs(int u,int from,int s,int id){
	dis[id][u]=s;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u,s+w[i],id);
	}
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v,_w;i<n;i++)u=read(),v=read(),_w=read(),add(u,v,_w),add(v,u,_w);
	for(int i=1;i<=n;i++)dfs(i,0,0,i);
	f[0][0][0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][0][0][0]=1;
		for(int j=0;j<i;j++){
			if(j==0){
				f[i][1][0][i]=1;
				continue;
			}
			if(j==1){
				for(int u=1;u<i;u++){
					f[i][1][0][u]=1;
					f[i][2][u][i]=1;
				}
				continue;
			}
			for(int u=1;u<i;u++){
				for(int v=1;v<i;v++){
					addmod(f[i][j][u][v],f[i-1][j][u][v]);
					int x=u,y=v;
					if(dis[u][i]>dis[x][y])x=u,y=i;
					if(dis[v][i]>dis[x][y])x=v,y=i;
					addmod(f[i][j+1][x][y],f[i-1][j][u][v]);
				}
			}
		}
	}
	for(int i=1,k,len;i<=m;i++)k=read(),len=read(),query[k].push_back(node(len,i));
	for(int i=1;i<=n;i++){
		sort(query[i].begin(),query[i].end());
		p.resize(0);
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++)p.push_back(node(dis[u][v],f[n][i][u][v]));
		}
		sort(p.begin(),p.end());
		int sum=0;
		for(unsigned j=0,t=0;j<query[i].size();j++){
			while(t<p.size()&&p[t].x<=query[i][j].x)addmod(sum,p[t].y),++t;
			ans[query[i][j].y]=sum;
		}
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}

