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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,hd[N],nxt[N],to[N],w[N],ec,dis[N],vis[N],inq[N];
inline void add(int u,int v,int c){nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,w[ec]=c;return;}
queue<int> Q;

signed main(){
	n=read(),m=read();
    for(int i=1,ty,x,y,z;i<=m;i++){
        ty=read(),x=read(),y=read();
        if(ty==1)add(x,y,-read());
        else if(ty==2)add(y,x,read());
        else add(x,y,0),add(y,x,0);
    }
    for(int i=1;i<+n;i++)add(0,i,0);
    Q.push(0);
    for(int i=1;i<=n;i++)dis[i]=INF;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop(),inq[u]=0,++vis[u];
        if(vis[u]>n+1){
            printf("No\n");
            return 0;
        }
        for(int i=hd[u],v;i;i=nxt[i]){
            v=to[i];
            if(dis[u]+w[i]<dis[v]){
                dis[v]=dis[u]+w[i];
                if(!inq[v])Q.push(v),inq[v]=1;
            }
        }
    }
    printf("Yes\n");
	return 0;
}
