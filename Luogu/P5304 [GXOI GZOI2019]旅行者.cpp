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

const int N=1e6+7,Mod=998244353,INF=1e16+7;
int T,n,m,k,dis[N],vis[N],sp[N],p[N],ans;
int hd[N],to[N],len[N],nxt[N],ec;
struct node{
	int id,d;
	node(int id=0,int d=0):id(id),d(d){};
	bool operator < (const node& A)const{return d>A.d;}
};
priority_queue<node> Q;

void add(int u,int v,int w){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read(),k=read(),ans=INF,ec=0;
		for(int i=1;i<=n;i++)hd[i]=0,sp[i]=0;
		for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),add(u,v,w);
		for(int i=1,s;i<=k;i++)s=read(),p[i]=s;
		
		for(int z=0;(1<<z)<=n;z++)for(int o=0;o<=1;o++){
			for(int i=1;i<=n;i++)vis[i]=0,dis[i]=INF,sp[i]=0;
			for(int i=1;i<=k;i++){
				if((o==1&&(p[i]&(1<<z)))||(o==0&&(!(p[i]&(1<<z)))))dis[p[i]]=0,Q.push(node(p[i],0));
				else sp[p[i]]=1;
			}
			while(!Q.empty()){
				int u=Q.top().id;
				Q.pop();
				if(vis[u]++)continue;
				for(int i=hd[u];i;i=nxt[i]){
					int v=to[i],w=len[i];
					if(dis[u]+w<dis[v]){
						dis[v]=dis[u]+w;
						Q.push(node(v,dis[v]));
					}
					if(sp[v])ans=min(ans,dis[u]+w);
				}
			}
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
