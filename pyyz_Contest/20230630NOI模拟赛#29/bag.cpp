// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int __int128
namespace OI{const int INF=1.01e36,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=17000,M=N/2;
int n,m,sum,f[N],ans;

struct node{
    int a,v,c,b;
    node(int a=0,int v=0,int c=0,int b=0):a(a),v(v),c(c),b(b){}
    bool operator < (const node &_)const{
        return v*_.c<_.v*c;
    }
}p[N];

signed main(){
    iF("bag.in");
    oF("bag.out");

    n=read();
    for(int i=1,a,v,c;i<=n;i++){
        a=read(),v=read(),c=read();
        p[i]=node(a,v,c,0);
    }
    sort(p+1,p+n+1);
    m=read();
    for(int i=1;i<=n;i++){
        int t=min(p[i].a,m/p[i].v);
        p[i].b=t,sum+=t*p[i].c,m-=t*p[i].v;
    }
    if(m>=20){
        _wri(sum);
        return 0;
    }
    for(int i=0;i<N;i++)f[i]=-INF;
    f[M-m]=sum;
    for(int i=1,s;i<=n;i++){
        s=p[i].b;
        for(int j=1;j<=s;j*=2){
            s-=j;
            for(int k=0;k+j*p[i].v<N;k++)_max(f[k],f[k+j*p[i].v]-j*p[i].c);
        }
        if(s)for(int k=0;k+s*p[i].v<N;k++)_max(f[k],f[k+s*p[i].v]-s*p[i].c);
        s=p[i].a-p[i].b;
        for(int j=1;j<=s;j*=2){
            s-=j;
            for(int k=N-1;k>=j*p[i].v;k--)_max(f[k],f[k-j*p[i].v]+j*p[i].c);
        }
        if(s)for(int k=N-1;k>=s*p[i].v;k--)_max(f[k],f[k-s*p[i].v]+s*p[i].c);
    }
    for(int i=0;i<=M;i++)_max(ans,f[i]);
    _wri(ans);
    return 0;
}

