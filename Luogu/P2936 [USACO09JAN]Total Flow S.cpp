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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,s,t,ans,h[N],hd[N],nxt[N],ec=1,dis[N];
struct edge{
    int u,v,f;
    edge(int u=0,int v=0,int f=0):u(u),v(v),f(f){}
}E[N];
void add(int u,int v,int w){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,w);return;}
void Add(int u,int v,int w){add(u,v,w),add(v,u,0);return;}

queue<int> Q;

int bfs(){
    for(int i=1;i<=52;i++)dis[i]=0;
    Q.push(s),dis[s]=1;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=hd[u];i;i=nxt[i])if(!dis[E[i].v]&&E[i].f){
            dis[E[i].v]=dis[u]+1;
            Q.push(E[i].v);
        }
    }
    return dis[t];
}

int dfs(int u,int maxf){
    if(!maxf||u==t)return maxf;
    int flow=0;
    for(int i=h[u];i;i=nxt[i]){
        if(dis[E[i].v]==dis[u]+1&&E[i].f){
            int f=dfs(E[i].v,min(maxf,E[i].f));
            flow+=f,maxf-=f,E[i].f-=f,E[i^1].f+=f;
            if(!maxf)break;
        }
        h[u]=nxt[i];
    }
    return flow;
}

void dinic(){
    while(bfs()){
        for(int i=1;i<=52;i++)h[i]=hd[i];
        ans+=dfs(s,INF);
    }
    return;
}

signed main(){
	s=1,t=26,n=read();
    while(n--){
        int u,v;char c;
        do{c=getchar();}while(!(('A'<=c&&c<='Z')||('a'<=c&&c<='z')));
        if('a'<=c)c+=-'a'+'A'+26;
        u=c-'A'+1;
        do{c=getchar();}while(!(('A'<=c&&c<='Z')||('a'<=c&&c<='z')));
        if('a'<=c)c+=-'a'+'A'+26;
        v=c-'A'+1;
        Add(u,v,read());
    }
    dinic();
    printf("%d\n",ans);
	return 0;
}
