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

const int N=1.01e6;
int n,k,A,f[N],mn[N*4],ad[N*4];

struct point{
    int x,y,c;
    point(int x=0,int y=0,int c=0):x(x),y(y),c(c){}
    bool operator < (const point &_)const{return x<_.x;}
}p[N];
vector<point> a[N];

inline void pushdown(int id){
    if(ad[id]){
        mn[id]+=ad[id];
        ad[Lid]+=ad[id],ad[Rid]+=ad[id];
        ad[id]=0;
    }
    return;
}

inline void update(int id,int L,int R,int l,int r,int x){
    pushdown(id);
    if(l<=L&&r>=R){
        ad[id]+=x,pushdown(id);
        return;
    }
    if(r<L||R<l)return;
    update(Lid,L,M,l,r,x),update(Rid,M+1,R,l,r,x);
    mn[id]=min(mn[Lid],mn[Rid]);
    return;
}

inline int query(int id,int L,int R,int l,int r){
    pushdown(id);
    if(l<=L&&r>=R)return mn[id];
    if(r<L||R<l)return INF;
    return min(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    n=read(),k=read(),A=read();
    for(int i=1,x,y,c;i<=n;i++){
        x=read(),y=read(),c=read();
        p[i]=point(x,y,c);
    }
    sort(p+1,p+n+1);
    for(int i=0,t=0;i<=k;i++){
        update(1,0,k,i,i,(i?f[i-1]:0)-i*A);
        for(unsigned j=0;j<a[k-i].size();j++){
            update(1,0,k,0,a[k-i][j].x,-a[k-i][j].c);
        }
        while(t<n&&p[t+1].x==i){
            ++t;
            a[p[t].y].pb(p[t]);
            if(p[t].y<k-i)update(1,0,k,0,p[t].x,p[t].c);
        }
        f[i]=query(1,0,k,0,i)+i*A;
    }
    _wri(f[k]);
    return 0;
}



