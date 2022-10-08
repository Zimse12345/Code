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
int n,a,b,p,k,vis[N],dis[N];
int hd[N],nxt[N],to[N],c[N],cnt;
struct node{
	int id,d;
	node(int id=0,int d=0):id(id),d(d){}
	bool operator <(const node& A)const{return d>A.d;}
	
};
priority_queue<node> Q;

void add(int u,int v,int w){
	to[++cnt]=v,c[cnt]=w;
	nxt[cnt]=hd[u],hd[u]=cnt;
	return;
}

void Dijkstra(int s){
	for(int i=1;i<=n;i++)dis[i]=INF,vis[i]=0;
	dis[s]=0;
	Q.push(node(s,0));
	while(!Q.empty()){
		int u=Q.top().id;Q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u];i;i=nxt[i]){
			int v=to[i],w=c[i];
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				Q.push(node(v,dis[v]));
			}
		}
	}
	return;
}

int main(){
	n=read(),a=read(),b=read();
	for(int i=1;i<=n;i++){
		p=read();
		for(int j=1;j<=p;j++){
			k=read();
			if(j==1)add(i,k,0);
			else add(i,k,1);
		}
	}
	Dijkstra(a);
	if(dis[b]==INF)dis[b]=-1;
	printf("%d\n",dis[b]);
	return 0;
}
