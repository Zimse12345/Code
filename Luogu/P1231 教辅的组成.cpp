#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int N=2e5+7;

struct edge{
	int u,v,f;
	edge(int u=0,int v=0,int f=0):u(u),v(v),f(f){}
}E[N];
queue<int> q;

int n,d[N],S,T,ec=1,ans;
int Hd[N],hd[N],nxt[N];
int n1,n2,n3,m1,m2;

void ae(int u,int v,int f){
	nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,f);
	return;
}

void add_edge(int u,int v,int f){
	ae(u,v,f),ae(v,u,0);
	return;
}

bool bfs(){
	for(int i=1;i<=n;i++)d[i]=0;
	d[S]=1,q.push(S);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=hd[u],v;i;i=nxt[i]){
			v=E[i].v;
			if(!d[v]&&E[i].f)d[v]=d[u]+1,q.push(v);
		}
	}
	return d[T]>0;
}

int dfs(int u,int mx){
	int flow=0;
	if(!mx||u==T)return mx;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=E[i].v;
		if(d[u]+1==d[v]&&E[i].f){
			int f=dfs(v,min(mx,E[i].f));
			flow+=f,mx-=f,E[i].f-=f,E[i^1].f+=f;
			if(!mx)break;
		}
		hd[u]=nxt[hd[u]];
	}
	return flow;
}

void dinic(){
	for(int i=1;i<=n;i++)Hd[i]=hd[i];
	while(bfs()){
		ans+=dfs(S,1000000000);
		for(int i=1;i<=n;i++)hd[i]=Hd[i];
	}
	return;
}

int main(){
	scanf("%d%d%d",&n1,&n2,&n3);
	n=n1*2+n2+n3+2,S=n-1,T=n;
	for(int i=1;i<=n1;i++)add_edge(i,n1+i,1);
	for(int i=1;i<=n2;i++)add_edge(S,n1*2+i,1);
	for(int i=1;i<=n3;i++)add_edge(n1*2+n2+i,T,1);
	scanf("%d",&m1);
	while(m1--){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(n1*2+y,x,1);
	}
	scanf("%d",&m2);
	while(m2--){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(n1+x,n1*2+n2+y,1);
	}
	dinic();
	printf("%d\n",ans);
	return 0;
}

