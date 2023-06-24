// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
namespace OI{const int INF=1.01e12,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e5;
int n,k,a[N],f[2][N],T,stk[N],top;

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
}p[N];
int hd[N],ed[N],pre[N],nxt[N],tot,len[N];

struct Fun{
    int k,b;
    Fun(int k=0,int b=0):k(k),b(b){}
    inline int getY(int x){return k*x+b;}
}fun[N];

struct Data{
    int *ptr,val;
    Data(int *ptr=NULL,int val=0):ptr(ptr),val(val){}
};
int tr[N*4];
vector<Data> Rem[N];

inline void update(int id,int L,int R,int i){
    Rem[top].pb(Data(&tr[id],tr[id]));
    int &j=tr[id];
    if(!j){j=i;return;}
    if(fun[j].getY(L)<=fun[i].getY(L)&&fun[j].getY(R)<=fun[i].getY(R))return;
    if(fun[j].getY(L)>=fun[i].getY(L)&&fun[j].getY(R)>=fun[i].getY(R)){j=i;return;}
    update(Lid,L,M,i),update(Rid,M+1,R,i);
    return;
}

inline int query(int id,int L,int R,int x){
    if(!tr[id])return INF;
    return min(fun[tr[id]].getY(x),x<=M?query(Lid,L,M,x):query(Rid,M+1,R,x));
}

inline bool Cmp(int l,int mid,int r){
    return (p[l].y-p[mid].y)*(p[mid].x-p[r].x)<=(p[mid].y-p[r].y)*(p[l].x-p[mid].x);
}

inline void merge(int l,int r){
    if(len[l]<len[r]){
        while(ed[l]){
            while(hd[r]!=ed[r]&&Cmp(nxt[hd[r]],hd[r],ed[l]))hd[r]=nxt[hd[r]];
            pre[hd[r]]=ed[l],nxt[ed[l]]=hd[r],hd[r]=ed[l],ed[l]=pre[ed[l]];
        }
    }
    else{
        while(hd[r]){
            while(hd[l]!=ed[l]&&Cmp(hd[r],ed[l],pre[ed[l]]))ed[l]=pre[ed[l]];
            nxt[ed[l]]=hd[r],pre[hd[r]]=ed[l],ed[l]=hd[r],hd[r]=nxt[hd[r]];
        }
        hd[r]=hd[l],ed[r]=ed[l];
    }
    len[r]+=len[l];
    while(hd[r]!=ed[r]&&p[hd[r]].y-p[hd[r]].x*a[r]>=p[nxt[hd[r]]].y-p[nxt[hd[r]]].x*a[r])hd[r]=nxt[hd[r]],--len[r];
    return;
}

inline void Re(){
    for(unsigned i=0;i<Rem[top].size();i++)*Rem[top][i].ptr=Rem[top][i].val;
    Rem[top].resize(0),--top;
    return;
}

signed main(){
    n=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=read(),f[T][i]=INF;
    a[0]=INF;
    for(int I=1;I<=k;I++){
        T^=1;
        for(int i=0;i<=n;i++)f[T][i]=INF;
        for(int i=1;i<=n;i++){
            p[i]=node(i-1,f[T^1][i-1]),hd[i]=ed[i]=i,len[i]=1;
            while(a[i]>=a[stk[top]])merge(stk[top],i),Re();
            stk[++top]=i,fun[top]=Fun(a[i],p[hd[i]].y-p[hd[i]].x*a[i]);
            update(1,1,n,top);
            _min(f[T][i],query(1,1,n,i));
        }
        for(int i=0;i<=n+1;i++)hd[i]=ed[i]=pre[i]=nxt[i]=0;
        while(top>0)Re();
    }
    _wri(f[T][n]);
    return 0;
}

