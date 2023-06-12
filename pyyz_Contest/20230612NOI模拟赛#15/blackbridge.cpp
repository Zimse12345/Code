// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
namespace OI{const int INF=2.01e18,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=1.01e6;
int n,f[N];

struct Fun{
    int k,a,b,d,val,id;
    inline int c(int x,int typ){
        x-=id-1;
        if(typ==0)return -k*x+b+val;
        if(typ==1)return -k*(a-d)+b+d*d-(a-x)*(a-x)+val;
        if(x<a+d)return -k*(a-d)+b+val;
        return -k*(a-d)+b+(x-a-d)*(x-a-d)+val;
    }
}fun[N];

struct LiChaoTree{
    int typ,mx[N*4];
    inline void update(int id,int L,int R,int l,int r,int i){
        int &j=mx[id];
        if(!j){j=i;return;}
        if(fun[i].c(L,typ)<=fun[j].c(L,typ)&&fun[i].c(R,typ)<=fun[j].c(R,typ))return;
        if(fun[i].c(L,typ)>=fun[j].c(L,typ)&&fun[i].c(R,typ)>=fun[j].c(R,typ)){j=i;return;}
        update(Lid,L,M,l,r,i),update(Rid,M+1,R,l,r,i);
        return;
    }
    inline int query(int id,int L,int R,int x){
        if(!mx[id])return -INF;
        if(L==R)return fun[mx[id]].c(x,typ);
        return max(fun[mx[id]].c(x,typ),x<=M?query(Lid,L,M,x):query(Rid,M+1,R,x));
    }
}Tr[3];

signed main(){
    // iF("blackbridge.in");
    // oF("blackbridge.out");

    for(int i=0;i<3;i++)Tr[i].typ=i;
    n=read();
    for(int i=1;i<=n;i++){
        fun[i].k=read(),fun[i].a=read(),fun[i].b=read(),fun[i].d=read();
        fun[i].id=i;
    }
    for(int i=1;i<=n;i++){
        fun[i].val=f[i-1],f[i]=-INF;
        for(int j=0;j<3;j++){
            Tr[j].update(1,1,n,1,n,i);
            _max(f[i],Tr[j].query(1,1,n,i));
        }
    }
    _wri(f[n]);
    return 0;
}

