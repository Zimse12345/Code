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

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e14+7;
int n,m,s,t,Flow,Cost,hd[N],nxt[N],ec=1,from[N];
int D,r[N];
struct edge{
    int u,v,f,c;
    edge(int u=0,int v=0,int f=0,int c=0):u(u),v(v),f(f),c(c){}
}E[N];
void add(int u,int v,int f,int c){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,f,c);return;}
void Add(int u,int v,int f,int c){add(u,v,f,c),add(v,u,0,-c);return;}
queue<int> Q;
int dis[N],inq[N];

int spfa(){
    for(int i=1;i<=n;i++)dis[i]=INF,inq[i]=0,from[i]=0;
    Q.push(s),dis[s]=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop(),inq[u]=0;
        for(int i=hd[u];i;i=nxt[i])if(E[i].f&&dis[u]+E[i].c<dis[E[i].v]){
            dis[E[i].v]=dis[u]+E[i].c,from[E[i].v]=i;
            if(!inq[E[i].v])Q.push(E[i].v),inq[E[i].v]=1;
        }
    }
    return from[t];
}

void ek(){
    while(spfa()){
        int flow=INF,cost=0;
        for(int i=from[t];i;i=from[E[i].u])flow=min(flow,E[i].f),cost+=E[i].c;
        for(int i=from[t];i;i=from[E[i].u])E[i].f-=flow,E[i^1].f+=flow;
        Flow+=flow,Cost+=cost*flow;
    }
    return;
}

signed main(){
    D=read();
    for(int i=1;i<=D;i++)r[i]=read();
    n=D*2+2,s=D*2+1,t=D*2+2;
    int p=read(),d1=read(),c1=read(),d2=read(),c2=read();
    for(int i=1;i<=D;i++){
        Add(s,i,r[i],0);
        Add(i+D,t,r[i],0);
        Add(s,i+D,INF,p);
        if(i<D)Add(i,i+1,INF,0);
        if(i+d1<=D)Add(i,i+d1+D,INF,c1);
        if(i+d2<=D)Add(i,i+d2+D,INF,c2);
    }
    ek();
    printf("%lld\n",Cost);
	return 0;
}
