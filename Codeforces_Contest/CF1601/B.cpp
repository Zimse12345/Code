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

const int N=3500000+7,Mod=998244353,INF=1e9+7;
int n,m,a[N>>2],b[N>>2],cnt,p[N>>2],s[N<<2];
int hd[N<<2],nxt[N<<2],to[N<<2];
short c[N<<2],vis[N<<2];
int ec,ans[N],T;
int dis[N<<2],pr[N<<2];

void add(int u,int v,int w){
	to[++ec]=v,c[ec]=w,nxt[ec]=hd[u],hd[u]=ec;
	return;
}

deque<int> q;
void Dijkstra(int s){
	for(int i=0;i<=m;i++)dis[i]=INF;
	dis[s]=0;
	q.push_front(s);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		vis[u]=0;
		for(int i=hd[u],v,w;i;i=nxt[i]){//printf("[%d %d]\n",u,v);
			v=to[i],w=c[i];
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w,pr[v]=u;
				if(vis[v])break;
				if(w==0)q.push_front(v);
				else q.push_back(v);
			}
		}
	}
	return;
}

void build(int L,int R,int id){
	cnt=max(cnt,id);
	if(L==R){
		p[L]=id,s[id]=L;
		return;
	}
	int M=(L+R)>>1;
	build(L,M,id<<1),build(M+1,R,(id<<1)|1);
	add(id,id<<1,0),add(id,(id<<1)|1,0);
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	if(l<=L&&r>=R)add(x,id,1);
	else{
		int M=(L+R)>>1;
		if(l<=M)update(L,M,id<<1,l,r,x);
		if(r>M)update(M+1,R,(id<<1)|1,l,r,x);
	}
	return;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	build(0,n,1);
	for(int i=1;i<=n;i++){
		int L=max(0,i-a[i]),R=i;//printf("[%d %d %d]\n",1+i,L,R);
		update(0,n,1,L,R,cnt+1+i);
	}
	m=cnt+1+n;
	for(int i=1;i<=n;i++)add(p[i],min(cnt+i+b[i]+1,cnt+n+1),0);//printf("[%d %d]\n",i+b[i]+1,i);
	add(p[0],cnt+1,0);
	Dijkstra(cnt+1+n);
	
	if(dis[p[0]]>=INF)printf("-1\n");
	else{
		int u=p[0];
		while(u!=cnt+1+n){
			if(s[u])ans[++T]=s[u];
			u=pr[u];
		}
		printf("%d\n",T+1);
		for(int i=T;i>=0;i--)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
