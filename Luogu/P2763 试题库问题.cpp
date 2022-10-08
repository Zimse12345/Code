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
int n,k,m,need[N],cnt=1,sum,ans;
int hd[N],nxt[N],h[N],d[N];
struct edge{int u,v,val;edge(int u=0,int v=0,int val=0):u(u),v(v),val(val){}}e[N];
inline void add(int u,int v,int val){nxt[++cnt]=hd[u],hd[u]=cnt,e[cnt]=edge(u,v,val);return;}
inline void link(int u,int v,int w){add(u,v,w),add(v,u,0);return;}

queue<int> Q; 
bool BFS(){
	for(int i=1;i<=n;i++)d[i]=0;
	d[n-1]=1,Q.push(n-1);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=hd[u];i;i=nxt[i])if(!d[e[i].v]&&e[i].val>0)d[e[i].v]=d[u]+1,Q.push(e[i].v);
	}
	return d[n];
}

int DFS(int u,int maxf){
	if(u==n||!maxf)return maxf;
	int flow=0;
	for(int i=h[u];i;i=nxt[i]){
		h[u]=nxt[h[u]];
		if(d[e[i].v]==d[u]+1&&e[i].val){
			int f=DFS(e[i].v,min(maxf,e[i].val));
			e[i].val-=f,e[i^1].val+=f,maxf-=f,flow+=f;
			if(!maxf)break;
		}
	}
	return flow;
}

void Dinic(){
	while(BFS()){
		for(int i=1;i<=n;i++)h[i]=hd[i];
		ans+=DFS(n-1,INF);
	}
	return;
}

signed main(){
	k=read(),m=read(),n=k+m+3;
	for(int i=1;i<=k;i++)need[i]=read(),sum+=need[i],link(k+m+2,i,need[i]);
	for(int i=1,p,ty;i<=m;i++){
		p=read();
		while(p--)ty=read(),link(ty,k+i,1);
		link(k+i,k+m+3,1);
	}
	Dinic();
	if(ans!=sum)printf("No Solution!\n");
	else{
		for(int i=1;i<=k;i++){
			printf("%d: ",i);
			for(int j=hd[i];j;j=nxt[j])if(k+1<=e[j].v&&e[j].v<=k+m+1&&e[j].val==0)printf("%d ",e[j].v-k);
			printf("\n");
		}
	}
	return 0;
}

