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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,m,Q,K,S;
int pr[N],ct[N],f[N],val[N],fa[N][22],mi[N];
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
struct eg{
	int u,v,w;
	eg(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	bool operator < (const eg& A)const{return w>A.w;}
}e[N];
struct node{
	int id,d;
	node(int id=0,int d=0):id(id),d(d){}
	bool operator < (const node& A)const{return d>A.d;}
};
vector<edge> g[N];
vector<int> ch[N];
priority_queue<node> q;
int dis[N],vis[N];

int F(int x){
	if(x!=pr[x])pr[x]=F(pr[x]);
	return pr[x];
}

void add(int u,int v){
	ch[u].push_back(v),fa[v][0]=u;
	return;
}

int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n*2;i++){
			g[i].resize(0),ch[i].resize(0);
			vis[i]=0,dis[i]=INF,pr[i]=i,ct[i]=1,f[i]=i;
			val[i]=INF;
		}
		for(int i=1,u,v,len,a;i<=m;i++){
			u=read(),v=read(),len=read(),a=read();
			g[u].push_back(edge(v,len)),g[v].push_back(edge(u,len));
			e[i]=eg(u,v,a);
		}
		while(!q.empty())q.pop();
		dis[1]=0,q.push(node(1,0));
		while(!q.empty()){
			int u=q.top().id;
			q.pop();
			if(vis[u]++)continue;
			for(int i=0,v,w;i<signed(g[u].size());i++){
				v=g[u][i].to,w=g[u][i].w;
				if(dis[u]+w<dis[v]){
					dis[v]=dis[u]+w;
					q.push(node(v,dis[v]));
				}
			}
		}
		for(int i=1;i<=n;i++)mi[i]=dis[i];//printf("[%d %d]\n",i,mi[i]);
		sort(e+1,e+m+1);
		int tot=n;
		for(int i=1,u,v,w;i<=m;i++){
			u=e[i].u,v=e[i].v,w=e[i].w;
			if(F(u)!=F(v)){
				int A=F(u),B=F(v);
				if(ct[A]<ct[B])pr[A]=B,ct[B]+=ct[A];
				else pr[B]=A,ct[A]+=ct[B];
				add(++tot,f[A]),add(tot,f[B]);
				mi[tot]=min(mi[f[A]],mi[f[B]]);
				f[A]=f[B]=tot,val[tot]=w;
//				printf("[%d %d %d %d %d]\n",tot,w,mi[tot],ch[tot][0],ch[tot][1]);
			}
		}
		val[0]=-INF;
		for(int i=1;i<=20;i++)for(int j=1;j<=tot;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
		
		Q=read(),K=read(),S=read();
		for(int i=1,from,p,ans=0;i<=Q;i++){
			from=(read()+K*ans-1)%n+1,p=(read()+K*ans)%(S+1),ans=0;
			for(int j=20;j>=0;j--)if(val[fa[from][j]]>p)from=fa[from][j];
			ans=mi[from];
			printf("%d\n",ans);
		}
	}
	return 0;
}
