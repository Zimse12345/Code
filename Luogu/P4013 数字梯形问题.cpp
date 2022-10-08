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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,s,t,hd[N],nxt[N],ec,inq[N],dis[N],le[N],v[100][100],Id[100][100],cnt;
int Flow,Cost;
struct edge{
    int u,v,f,c;
    edge(int u=0,int v=0,int f=0,int c=0):u(u),v(v),f(f),c(c){}
}E[N];
inline void add(int u,int v,int f,int c){nxt[++ec]=hd[u],hd[u]=ec,E[ec]=edge(u,v,f,c);return;}
inline void Add(int u,int v,int f,int c){add(u,v,f,c),add(v,u,0,-c);return;}

queue<int> Q;
bool bfs(){
    for(int i=1;i<=n;i++)dis[i]=INF,inq[i]=0,le[i]=0;
    dis[s]=0,Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop(),inq[u]=0;
        for(int i=hd[u];i;i=nxt[i])if(E[i].f&&dis[u]+E[i].c<dis[E[i].v]){
            dis[E[i].v]=dis[u]+E[i].c,le[E[i].v]=i;
            if(!inq[E[i].v])Q.push(E[i].v),inq[E[i].v]=0;
        }
    }
    return le[t];
}

void ek(){
    while(bfs()){
        int flow=INF,cost=0;
        for(int i=le[t];i;i=le[E[i].u])flow=min(flow,E[i].f),cost+=E[i].c;
        for(int i=le[t];i;i=le[E[i].u])E[i].f-=flow,E[i^1].f+=flow;
        Flow+=flow,Cost+=flow*cost;
    }
    return;
}

void Init(){
    for(int i=1;i<=n;i++)hd[i]=0;
    ec=1,Flow=Cost=0;
    return;
}

signed main(){
	int U=read(),D=read()+U-1;
    for(int i=U;i<=D;i++){
        for(int j=1;j<=i;j++){
            v[i][j]=read();
            Id[i][j]=++cnt; 
        }
    }
    Init();
    n=cnt*2+2,s=n-1,t=n;
    for(int i=U;i<=D;i++){
        for(int j=1;j<=i;j++){
            Add(Id[i][j],Id[i][j]+cnt,1,-v[i][j]);
            if(i^D)Add(Id[i][j]+cnt,Id[i+1][j],1,0),Add(Id[i][j]+cnt,Id[i+1][j+1],1,0);
            else Add(Id[i][j]+cnt,t,1,0);
            if(i==U)Add(s,Id[i][j],1,0);
        }
    }
    ek();
    printf("%d\n",-Cost);
    Init();
    n=cnt*2+2,s=n-1,t=n;
    for(int i=U;i<=D;i++){
        for(int j=1;j<=i;j++){
            Add(Id[i][j],Id[i][j]+cnt,2,-v[i][j]);
            if(i^D)Add(Id[i][j]+cnt,Id[i+1][j],1,0),Add(Id[i][j]+cnt,Id[i+1][j+1],1,0);
            else Add(Id[i][j]+cnt,t,INF,0);
            if(i==U)Add(s,Id[i][j],1,0);
        }
    }
    ek();
    printf("%d\n",-Cost);
    Init();
    n=cnt*2+2,s=n-1,t=n;
    for(int i=U;i<=D;i++){
        for(int j=1;j<=i;j++){
            Add(Id[i][j],Id[i][j]+cnt,INF,-v[i][j]);
            if(i^D)Add(Id[i][j]+cnt,Id[i+1][j],INF,0),Add(Id[i][j]+cnt,Id[i+1][j+1],INF,0);
            else Add(Id[i][j]+cnt,t,INF,0);
            if(i==U)Add(s,Id[i][j],1,0);
        }
    }
    ek();
    printf("%d\n",-Cost);
	return 0;
}
