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

//#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int n,m,s,t,ans,hd[N],h[N],nxt[N],ec=1,d[N],a[N],b[N],va[N],vb[N],Id[N];
struct edge{
    int v,f;
    edge(int v=0,int f=0):v(v),f(f){}
}E[N];
inline void add(int u,int v,int f){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(v,f);return;}
inline void Add(int u,int v,int f){add(u,v,f),add(v,u,0);return;}

queue<int> Q;
bool bfs(){
    for(int i=1;i<=n;i++)d[i]=0;
    d[s]=1,Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=hd[u];i;i=nxt[i])if(E[i].f&&!d[E[i].v])d[E[i].v]=d[u]+1,Q.push(E[i].v);
    }
    return d[t];
}

int dfs(int u,int maxf){
    if(u==t||!maxf)return maxf;
    int flow=0;
    for(int i=h[u];i;i=nxt[i]){
        if(d[u]+1==d[E[i].v]){
            int f=dfs(E[i].v,min(maxf,E[i].f));
            flow+=f,maxf-=f,E[i].f-=f,E[i^1].f+=f;
            if(!maxf)break;
        }
        h[u]=nxt[h[u]];
    }
    if(!flow)d[u]=0;
    return flow;
}

void dinic(){
    while(bfs()){
        for(int i=1;i<=n;i++)h[i]=hd[i];
        ans+=dfs(s,INF);
    }
    return;
}

signed main(){
	m=read(),n=m*2,s=++n,t=++n;
	for(int i=1;i<=m;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=1;i<=m;i++)if(!va[i]){
		int p=++n,x=i;
		Add(s,p,1);
		while(!va[x])Add(p,x,1),va[x]=1,x=a[x];
	}
	for(int i=1;i<=m;i++)if(!vb[i]){
		int p=++n,x=i;
		Add(p,t,1);
		while(!vb[x])Add(x+m,p,1),vb[x]=1,x=b[x];
	}
	for(int i=1;i<=m;i++)Add(i,i+m,1),Id[i]=ec-1;
	dinic();
	printf("%d\n",m-ans);
	for(int i=1;i<=m;i++)if(E[Id[i]].f)printf("%d ",i);
	printf("\n");
	return 0;
}
