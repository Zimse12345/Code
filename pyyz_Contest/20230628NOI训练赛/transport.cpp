// Author:Zimse  Data:2023-06-
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

const int N=3.01e3,M=2.01e5;
int n,m,ans,u[N*2][N*2],f[N][N],A[M],B[M],V[M];

inline int _abs(int x){
    return x<0?-x:x;
}

signed main(){
    n=read(),m=read();
    for(int i=1,a,b,v;i<=m;i++){
        A[i]=read(),B[i]=read(),V[i]=read();
        if(B[i]<A[i])swap(A[i],B[i]);
        a=A[i],b=B[i],v=V[i];
        int r=b-a;
        ans+=r*v;
        u[b-1][b]+=v;
        u[a-1][a]-=v;
        u[a][b+r+1]+=v;
        if(a-r>0)u[a-r][b+1]-=v;
    }
    for(int l=n*2;l>=1;l--){
        for(int r=1;r<=n*2;r++){
            u[l][r]+=u[l+1][r+1];
            if(l<=n&&r<=n)f[l][r]+=u[l][r];
        }
    }
    for(int l=0;l<=n*2+1;l++)for(int r=0;r<=n*2+1;r++)u[l][r]=0;
    for(int i=1,a,b,v;i<=m;i++){
        a=A[i],b=B[i],v=V[i];
        int r=b-a;
        u[a-1][b-r+2]+=v;
        if(a-r>0)u[a-r][b+1]-=v;
        u[a+r-1][b+2]+=v;
        u[a][b+r+1]-=v;
    }
    for(int l=n*2;l>=1;l--){
        for(int r=1;r<=n*2;r++){
            u[l][r]+=u[l+1][r-1];
            if(l<=n&&r<=n)f[l][r]+=u[l][r];
        }
    }
    for(int l=0;l<=n*2+1;l++)for(int r=0;r<=n*2+1;r++)u[l][r]=0;
    for(int i=1,a,b,v;i<=m;i++){
        a=A[i],b=B[i],v=V[i];
        int r=b-a;
        u[a+r-1][b+1]-=v*2;
        if(a-r>0)u[a-r][b+1]+=v*2;
    }
    for(int l=n*2;l>=1;l--){
        for(int r=1;r<=n*2;r++){
            u[l][r]+=u[l+1][r];
            if(l<=n&&r<=n)f[l][r]+=u[l][r];
        }
    }
    int mx=0;
    for(int l=1;l<=n;l++){
        for(int r=1;r<=n;r++)f[l][r]+=f[l][r-1];
    }
    for(int l=1;l<=n;l++){
        for(int r=1;r<=n;r++){
            f[l][r]+=f[l][r-1];
            _max(mx,f[l][r]);
        }
    }
    ans-=mx;
    _wri(ans);
    return 0;
}

