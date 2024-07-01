// Author:Zimse  Data:2024-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
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
int n,m,c[N],t,f[N],ans;
struct node{
    int a,b;
    node(int a=0,int b=0):a(a),b(b){}
    bool operator < (const node &_)const{return a<_.a;}
}p[N];

signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++)p[i].a=read();
    for(int i=1;i<=n;i++)p[i].b=read();
    sort(p+1,p+n+1);
    p[n+1].a=N;
    t=1;
    for(int i=1;i<=n;i++){
        if(p[i].a-p[i].b<p[t].a-p[t].b)t=i;
        for(int j=p[i].a;j<p[i+1].a;j++)f[j]=f[j-p[t].a+p[t].b]+2;
    }
    for(int i=1;i<=m;i++){
        c[i]=read();
        if(c[i]>=N){
            int d=(c[i]-N)/(p[t].a-p[t].b)+1;
            c[i]-=(p[t].a-p[t].b)*d;
            ans+=d*2;
        }
        ans+=f[c[i]];
    }
    _wri(ans);
    return 0;
}

