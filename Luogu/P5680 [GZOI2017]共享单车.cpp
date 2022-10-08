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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,k,q,tag[N];
int hd[N],nxt[N],to[N],c[N],ec;
int vis[N],dis[N],pr[N],dfn[N],ct,dep[N],fa[20][N];
int stk[N],tp,re[N],Tp;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return x<A.x;}}p[N];
priority_queue<node> Q;
vector<int> ch[N];
inline void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,c[ec]=w;return;}
int Hd[N],Nxt[N],To[N],C[N],Ec,f[N],TAG;
int lca(int u,int v);
inline void Add(int u,int v){re[++Tp]=u,Nxt[++Ec]=Hd[u],Hd[u]=Ec,To[Ec]=v,C[Ec]=dis[u]+dis[v]-dis[lca(u,v)]*2;return;}

void dfs(int u){
	dfn[u]=++ct;
	for(unsigned i=0;i<ch[u].size();i++)dep[ch[u][i]]=dep[u]+1,dfs(ch[u][i]);
	return;
}

int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=18;i>=0;i--)if(dep[v]<=dep[u]-(1<<i))u=fa[i][u];
	for(int i=18;i>=0;i--)if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	return u==v?u:pr[u];
}

void dp(int u){
	f[u]=0;
	if(tag[u])TAG=1;
	for(int i=Hd[u],v;i;i=Nxt[i]){
		v=To[i],dp(v);
		if(tag[v])f[u]+=C[i];
		else f[u]+=min(C[i],f[v]);
	}
	return;
}

signed main(){
	n=read(),m=read(),k=read(),q=read();
	for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[k]=0,Q.push(node(0,k));
	while(!Q.empty()){
		int u=Q.top().y;Q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(dis[u]+c[i]<dis[v])dis[v]=dis[u]+c[i],pr[v]=u,fa[0][v]=u,Q.push(node(-dis[v],v));
			else if(dis[u]+c[i]==dis[v]&&u<pr[v])pr[v]=u,fa[0][v]=u;
		}
	}
	for(int i=1;i<=n;i++)if(i^k)ch[pr[i]].push_back(i);
	dep[k]=1,dfs(k);
	for(int i=1;i<=18;i++)for(int j=1;j<=n;j++)fa[i][j]=fa[i-1][fa[i-1][j]];
	
	for(int i=1,op,num;i<=q;i++){
		op=read(),num=read();
		if(op){
			TAG=0;
			for(int j=1,u;j<=num;j++)u=read(),p[j]=node(dfn[u],u);
			sort(p+1,p+num+1),tp=0;
			stk[++tp]=k,stk[++tp]=p[1].y;
			for(int j=2,u;j<=num;j++){
				u=p[j].y;
				int mid=lca(p[j-1].y,u);
				while(tp>1&&dep[stk[tp-1]]>dep[mid])Add(stk[tp-1],stk[tp]),--tp;
				if(dep[stk[tp]]>dep[mid])Add(mid,stk[tp]),--tp;
				if(mid!=stk[tp])stk[++tp]=mid;stk[++tp]=u;
			}
			for(int j=1;j<tp;j++)Add(stk[j],stk[j+1]);
			dp(k);
			if(!TAG)f[k]=-1;
			printf("%d\n",f[k]);
			do{Hd[re[Tp]]=0;}while(--Tp);
			do{Nxt[Ec]=To[Ec]=C[Ec]=0;}while(--Ec);
		}
		else while(num--)tag[read()]^=1;
	}
	return 0;
}

