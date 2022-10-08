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
int A,B,T,a[N],b[N],vis[N];

struct servant{
    int x,y,id;
    servant(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
}p[N],px[N],py[N];
bool cmp_x(const servant& A,const servant& B){return A.x<B.x;}
bool cmp_y(const servant& A,const servant& B){return A.y<B.y;}

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& A)const{return x<A.x;}
};
priority_queue<node> Q;
int stk[N],top;

bool check(int x){
    for(int i=1;i<=T;i++)vis[i]=0;
    while(!Q.empty())Q.pop();
    for(int i=1,t=0;i<=A;i++){
        while(t<T&&a[i]>px[t+1].x)++t,Q.push(node(px[t].y,px[t].id));
        int X=x;
        while((X--)&&!Q.empty())vis[Q.top().y]=1,Q.pop();
    }
    top=0;
    for(int i=1,t=0;i<=B;i++){
        while(t<T&&b[i]>py[t+1].y)if(!vis[py[++t].id])stk[++top]=py[t].id;
        int X=x;
        while((X--)&&top)vis[stk[top--]]=1;
    }
    for(int i=1;i<=T;i++)if(!vis[i])return false;
    return true;
}

signed main(){
    A=read(),B=read(),T=read();
    for(int i=1;i<=A;i++)a[i]=read();
    for(int i=1;i<=B;i++)b[i]=read();
    sort(a+1,a+A+1);
    sort(b+1,b+B+1);
    for(int i=1,x,y;i<=T;i++)x=read(),y=read(),p[i]=px[i]=py[i]=servant(x,y,i);
    sort(px+1,px+T+1,cmp_x);
    sort(py+1,py+T+1,cmp_y);
    int L=1,R=T,ans=-1;
    while(L<=R){
        int M=(L+R)/2;
        if(check(M))ans=M,R=M-1;
        else L=M+1;
    }
    printf("%d\n",ans);
    return 0;
}

