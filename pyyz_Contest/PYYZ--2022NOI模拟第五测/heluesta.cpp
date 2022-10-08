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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,X[N],Y[N],A[N],B[N],C[N];
int tr[N];

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x,int y){for(;x<N;ub(x))tr[x]+=y;return;}
inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& A)const{return x<A.x;}
}p[N];

struct query{
    int p,q,id;
    query(int p=0,int q=0,int id=0):p(p),q(q),id(id){}
    bool operator < (const query& A)const{
        return double(p)/double(q)>double(A.p)/double(A.q);
    }
}q[N];

int val[N],ct,Ans[N];
map<int,int> V;
void subtestA(){
    for(int i=1;i<=n;i++)val[i]=X[i];
    sort(val+1,val+n+1),val[0]=INF;
    for(int i=1;i<=n;i++)if(val[i]!=val[i-1])V[val[i]]=++ct;
    for(int i=1;i<=n;i++)X[i]=V[X[i]],p[i]=node(-Y[i],X[i]);

    for(int i=1;i<=m;i++){
        q[i]=query(-C[i],B[i],i);
        if(B[i]==0){
            if(C[i]>0)q[i]=query(-INF,1,i);
            else q[i]=query(INF,1,i);
        }
    }
    sort(q+1,q+m+1);
    sort(p+1,p+n+1);
    for(int i=1;i<=m;i++)Ans[q[i].id]=i;
    int ans=0;
    for(int i=1,l=1;i<=m;i++){
        printf("%.7lf\n",double(q[i].p)/double(q[i].q));
        while(l<=n&&-p[l].x*q[i].q>q[i].p){
            int r=l;
            while(r<n&&p[r+1].x==p[r].x)++r;
            for(int j=l;j<=r;j++)ans+=sum(N-1)-sum(p[j].y);
            for(int j=l;j<=r;j++)add(p[j].y,1);
            l=r+1;
        }
        Ans[q[i].id]=ans;
    }
    for(int i=1;i<=m;i++)printf("%lld\n",Ans[i]);
    return;
}

signed main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    n=read(),m=read();
    for(int i=1;i<=n;i++)X[i]=read(),Y[i]=read();
    int tagA=1;
    for(int i=1;i<=m;i++){
        A[i]=read(),B[i]=read(),C[i]=read();
        if(A[i]!=0)tagA=0;
    }
    if(tagA){
        subtestA();
        return 0;
    }
    if(n*m>100000000)return 0;
    for(int I=1;I<=m;I++){
        int ans=0,tot=0;
        for(int i=1;i<=n;i++){
            if(A[I]*X[i]+B[I]*Y[i]+C[I]>0)p[++tot]=node(X[i],Y[i]);
        }
        sort(p+1,p+tot+1);
        for(int i=1;i<=tot;i++){
            for(int j=1;j<i;j++)if(p[j].x<p[i].x&&p[j].y<p[i].y)++ans;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
