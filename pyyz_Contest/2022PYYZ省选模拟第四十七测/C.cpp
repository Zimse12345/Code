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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,hd[N],nxt[N],to[N],ec,len[N],deg[N];
int dis[N][N],TAg,s[N],tot;
int f[2000][1000],ans=INF;
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;return;}

void dfs(int u,int from,int w){
	dis[TAg][u]=w;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u,w+len[i]);
	}
	return;
}

signed main(){
	n=read();
	for(int i=2,f,w;i<=n;i++)f=read(),w=read(),add(i,f,w),add(f,i,w),++deg[i],++deg[f];
	for(int i=1;i<=n;i++)TAg=i,dfs(i,0,0);
	for(int i=2;i<=n;i++)if(deg[i]==1)s[tot++]=i;
	for(int i=0;i<(1<<tot);i++)for(int j=0;j<tot;j++)f[i][j]=INF;
	for(int i=0;i<tot;i++)f[1<<i][i]=0;
	for(int i=1;i<(1<<tot);i++){
		for(int u=0;u<tot;u++)if(i&(1<<u)){
			for(int v=0;v<tot;v++)if(!(i&(1<<v))){
				f[i|(1<<v)][v]=min(f[i|(1<<v)][v],max(f[i][u],dis[s[u]][s[v]]));
			}
		}
	}
	for(int i=0;i<tot;i++)ans=min(ans,f[(1<<tot)-1][i]);
	printf("%d\n",ans);
	return 0;
}

