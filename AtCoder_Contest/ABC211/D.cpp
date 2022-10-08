#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn=2e5+7,Mod=1e9+7;
int n,m,s,vis[maxn],ans[maxn],f[maxn];
struct edge{int to,w;edge(int v,int w):to(v),w(w){}};
struct Point{int p,f;Point(int p,int f):p(p),f(f){}bool operator < (const Point& x)const{return f>x.f;}};
vector<edge> e[maxn];
queue<int> q;

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

void Dijkstra(){
	for(int i=1;i<=n;i++)ans[i]=1e9+7;
	ans[s]=0,q.push(s);
	
	while(!q.empty()){
		int u=q.front();q.pop();
		if(vis[u])continue;
		vis[u]=1;
		
		for(int v=0;v<int(e[u].size());v++){
			int V=e[u][v].to;
			ans[V]=min(ans[V],ans[u]+e[u][v].w);
			if(!vis[V])q.push(V);
		}
	}
	return;
}

int Dfs(int u){
	if(f[u])return f[u];
	for(int i=0;i<int(e[u].size());i++){
		int v=e[u][i].to;
		if(ans[v]==ans[u]-1)Dfs(v),f[u]=(f[u]+f[v])%Mod;
	}
	return f[u];
}

int main(){
	scanf("%d%d",&n,&m),s=n;
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=1;
		e[u].push_back(edge(v,w));
		e[v].push_back(edge(u,w));
	}
	Dijkstra(),f[n]=1;
//	for(int i=1;i<=n;i++)printf("(%d %d)  ",i,ans[i]);
	Dfs(1),printf("%d",f[1]);
	return 0;
}
