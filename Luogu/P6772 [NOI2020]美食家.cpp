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

const int N=301,INF=1e16;
int n,m,T,k,SZ,c[N],ans[N],_ans[N];

struct Matrix{
    int val[N][N];
    void Init(){
        for(int x=1;x<=SZ;x++){
            for(int y=1;y<=SZ;y++){
                val[x][y]=-INF;
            }
        }
        return;
    }
}G[30];

struct Festival{
    int t,x,y;
    Festival(int t=0,int x=0,int y=0):t(t),x(x),y(y){}
    bool operator < (const Festival& A)const{return  t<A.t;}
}fes[N];

inline void mul(Matrix& res,Matrix& A,Matrix& B){
    res.Init();
    for(int x=1;x<=SZ;x++){
        for(int y=1;y<=SZ;y++){
            for(int k=1;k<=SZ;k++)res.val[x][y]=max(res.val[x][y],A.val[x][k]+B.val[k][y]);
        }
    }
    return;
}

inline void add(Matrix& A){
    for(int i=1;i<=SZ;i++)_ans[i]=-INF;
    for(int x=1;x<=SZ;x++){
        for(int y=1;y<=SZ;y++){
            _ans[y]=max(_ans[y],ans[x]+A.val[x][y]);
        }
    }
    for(int i=1;i<=SZ;i++)ans[i]=_ans[i];
    return;
}

signed main(){
    n=read(),m=read(),T=read(),k=read();
    SZ=n*5;
    for(int i=1;i<=n;i++)c[i]=read();
    G[0].Init();
    while(m--){
        int u=read(),v=read(),w=read();
        int x=5*(u-1)+w,y=5*(v-1)+1;
        G[0].val[x][y]=c[v];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<5;j++){
            int x=5*(i-1)+j,y=x+1;
            G[0].val[x][y]=0;
        }
    }
    for(int i=1;i<30;i++)mul(G[i],G[i-1],G[i-1]);
    for(int i=1,t,x,y;i<=k;i++)t=read(),x=read(),y=read(),fes[i]=Festival(t,x,y);
    sort(fes+1,fes+k+1);
    ans[1]=c[1];
    for(int i=2;i<=SZ;i++)ans[i]=-INF;
    fes[k+1].t=T+1;
    for(int i=1,t,p;;i++){
        t=fes[i].t-1-fes[i-1].t;
        for(int j=0;j<30;j++)if(t&(1<<j))add(G[j]);
        if(i==k+1)break;
        p=5*(fes[i].x-1)+1;
        for(int j=1;j<=SZ;j++)G[0].val[j][p]+=fes[i].y;
        add(G[0]);
        for(int j=1;j<=SZ;j++)G[0].val[j][p]-=fes[i].y;
    }
    if(ans[1]<=-INF/2)ans[1]=-1;
    printf("%lld\n",ans[1]);
    return 0;
}
