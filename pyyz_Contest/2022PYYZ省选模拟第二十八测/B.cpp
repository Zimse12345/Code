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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,hd[N],nxt[N*2],to[N*2],ec,ans[N];
int cnt[N],sz,rt,rs,vis[N],dis[N],dep;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return x<A.x;}};
vector<node> q[N],Q;
vector<node> qu[N];
int P,K[N],deg[N],line[N],tot,rk[N],pos[N],L[N],R[N];
inline void add(int u,int v){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;return;}

void findrt(int u,int from){
	cnt[u]=1;
	int ms=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||vis[v])continue;
		findrt(v,u),cnt[u]+=cnt[v],ms=max(ms,cnt[v]);
	}
	ms=max(ms,sz-cnt[u]);
	if(ms<rs)rs=ms,rt=u;
	return;
}

void dfs(int u,int from,int d){
	++dis[d],dep=max(dep,d);
	for(unsigned i=0;i<q[u].size();i++)Q.push_back(node(q[u][i].x-d,q[u][i].y));
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||vis[v])continue;
		dfs(v,u,d+1);
	}
	return;
}

void calc(int u,int tag){
	dep=0,Q.clear();
	dfs(u,0,tag==1?0:1);
	for(int i=1;i<=dep+1;i++)dis[i]+=dis[i-1];
	for(unsigned i=0;i<Q.size();i++){
		Q[i].x=min(Q[i].x,dep+1);
		if(Q[i].x>=0)ans[Q[i].y]+=tag*dis[Q[i].x];
	}
	for(int i=0;i<=dep+1;i++)dis[i]=0;
	return;
}

void divide(int u){
	vis[u]=1;
	calc(u,1);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		calc(v,-1);
		sz=cnt[v],rs=INF,findrt(v,u);
		divide(rt);
	}
	return;
}

void point_divide(){
	for(int i=1,x,k;i<=m;i++){
		x=qu[i][0].x,k=qu[i][0].y,q[x].push_back(node(k,i));
	}
	sz=n,rs=INF,findrt(1,0);
	divide(rt);
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return;
}

void bf_dfs(int u,int d){
	vis[u]=P;
	if(d==0)return;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v]==P)continue;
		bf_dfs(v,d-1);
	}
	return;
}

void brute_force(){
	for(int i=1;i<=m;i++){
		sz=0;
		for(int j=0;j<K[i];j++)P=qu[i][j].x,bf_dfs(qu[i][j].x,qu[i][j].y);
		for(int j=1;j<=n;j++)if(vis[j])sz++,vis[j]=0;
		printf("%d\n",sz);
	}
	return;
}

void find_line(int u,int from){
	line[++tot]=u,rk[u]=tot;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		find_line(v,u);
	}
	return;
}

signed main(){
	n=read();
	int t1=0,t2=0,tag2=0;
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u),++deg[u],++deg[v];
	for(int i=1;i<=n;i++){
		if(deg[i]==1)++t1;
		if(deg[i]==2)++t2;
	}
	if(t1==2&&t1+t2==n)tag2=1;
	m=read();
	int tag=1;
	for(int i=1,x,y;i<=m;i++){
		K[i]=read();
		if(K[i]!=1)tag=0;
		for(int j=1;j<=K[i];j++)x=read(),y=read(),qu[i].push_back(node(x,y));
	}
	if(tag){
		point_divide();
		return 0;
	}
	if((!tag2)&&n<=1000&&m<=1000){
		brute_force();
		return 0;
	}
	int S=0,sum;
	for(int i=1;i<=n;i++)if(deg[i]==1)S=i;
	find_line(S,0);
	for(int i=1;i<=m;i++){
		if(K[i]==0){
			printf("0\n");
			continue;
		}
		sum=0;
		for(int j=0;j<K[i];j++)qu[i][j].x=rk[qu[i][j].x];
		sort(qu[i].begin(),qu[i].end());
		for(int j=0;j<K[i];j++)pos[j+1]=qu[i][j].x,L[j+1]=R[j+1]=qu[i][j].y;
		for(int j=2;j<=K[i];j++)R[j]=max(R[j],R[j-1]-pos[j]+pos[j-1]);
		for(int j=K[i]-1;j>=1;j--)L[j]=max(L[j],L[j+1]-pos[j+1]+pos[j]);
		sum+=min(L[1]+1,pos[1]);
		for(int j=1;j<K[i];j++){
			sum+=min(L[j+1]+R[j]+1,pos[j+1]-pos[j]);
		}
		sum+=min(max(0,R[K[i]]),n-pos[K[i]]);
		printf("%d\n",sum);
	}
	return 0;
}

