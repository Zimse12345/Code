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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=1e9+7,INF=2147483647;
int n,m,q;
int hd[N],nxt[N],to[N],c[N],ty[N],ec;
int Hd[N],Nxt[N],To[N],C[N],Ty[N],Ec;
int st[N],wt[N],ft[N],tp,ins[N],rc,dist[N],dt,vis[N];
int fa[N][21],fd[N][21],dep[N],Id[N],rsz[N];
vector<int> ring[N],len[N];

inline void addeg(int u,int v,int w){to[++ec]=v,c[ec]=w,nxt[ec]=hd[u],hd[u]=ec;return;}
inline void Addeg(int u,int v,int w){fa[v][0]=u,fd[v][0]=w,To[++Ec]=v,C[Ec]=w,Nxt[Ec]=Hd[u],Hd[u]=Ec;return;}

void tarjan(int u,int from,int fw,int fid){
	ins[u]=1,st[++tp]=u,wt[tp]=fw,ft[tp]=fid,vis[u]=1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		if(ins[v]){
			++rc,dt=1,dist[1]=c[i],ty[i]=1;
			ring[rc].push_back(v),len[rc].push_back(c[i]),Id[v]=0;
			Addeg(v,n+rc,0);
			for(int j=tp;st[j]!=v;j--){
				++dt,dist[dt]=wt[j]+dist[dt-1],ty[ft[j]]=1;
				ring[rc].push_back(st[j]),len[rc].push_back(wt[j]),Id[st[j]]=ring[rc].size()-1;
			}
			for(int j=tp,k=1;st[j]!=v;j--,k++)Addeg(n+rc,st[j],min(dist[k],dist[dt]-dist[k]));
			rsz[rc]=dist[dt];
			for(unsigned i=1;i<len[rc].size();i++)len[rc][i]+=len[rc][i-1];
		}
		else if(!vis[v]){
			tarjan(v,u,c[i],i);
			if(!ty[i])Addeg(u,v,c[i]);
		}
	}
	ins[st[tp]]=0,--tp;
	return;
}

void dfs(int u){
	dep[u]=dep[fa[u][0]]+1;
	for(int i=Hd[u];i;i=Nxt[i])dfs(To[i]);
	return;
}

int main(){
	n=read(),m=read(),q=read();
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),addeg(u,v,w),addeg(v,u,w);
	tarjan(1,0,0,0);
	for(int i=1;i<=19;i++){
		for(int j=1;j<=n+rc;j++)fa[j][i]=fa[fa[j][i-1]][i-1],fd[j][i]=fd[j][i-1]+fd[fa[j][i-1]][i-1];
	}
	dfs(1);
	for(int i=1,x,y;i<=q;i++){
		x=read(),y=read();
		int ans=0;
		if(dep[x]<dep[y])swap(x,y);
		for(int j=19;j>=0;j--)if(dep[fa[x][j]]>=dep[y])ans+=fd[x][j],x=fa[x][j];
		if(x==y){
			printf("%d\n",ans);
			continue;
		}
		for(int j=19;j>=0;j--)if(fa[x][j]!=fa[y][j])ans+=fd[x][j]+fd[y][j],x=fa[x][j],y=fa[y][j];
		if(fa[x][0]<=n)ans+=fd[x][0]+fd[y][0];
		else{
			int mid=fa[x][0]-n;
			if(Id[x]>Id[y])swap(x,y);
			int ddis=0;
			if(Id[y]!=0)ddis+=len[mid][Id[y]-1];
			if(Id[x]!=0)ddis-=len[mid][Id[x]-1];
			ddis=min(ddis,rsz[mid]-ddis);
			ans+=ddis;
		}
		printf("%d\n",ans);
	}
	return 0;
}

