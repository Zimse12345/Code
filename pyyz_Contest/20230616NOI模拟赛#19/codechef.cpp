// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
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

const int N=1.01e3;
int T,n,w[N][3],f[2][256][256][3],c[N],ans,I,val,M;

inline int o(int x){
    return x?x+1:0;
}

signed main(){
    iF("codechef.in");
    oF("codechef.out");

    T=read();
    while(T--){
        n=read(),ans=0,M=0;
        for(int i=1;i<=n;i++)c[i]=i*(i+1)/2;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++)w[i][j]=read(),_max(M,w[i][j]);
        }
        M=sqrt(M+1)*2+1;
        for(int x=0;x<2;x++){
            for(int y=0;y<=M;y++){
                for(int z=0;z<=M;z++){
                    for(int t=0;t<3;t++)f[x][y][z][t]=-INF;
                }
            }
        }
        I=0;
        for(int t=0;t<3;t++)f[I][0][0][t]=0;
        for(int i=0;i<n;i++){
            I^=1;
            for(int x=0;x<=M;x++){
                for(int y=0;y<=M;y++){
                    for(int t=0;t<3;t++)if(f[I^1][x][y][t]>=0){
                        val=-INF,swap(val,f[I^1][x][y][t]);
                        _max(f[I][o(x)][o(y)][t],val+w[i+1][t]);
                        if(t==0){
                            _max(f[I][1][o(y)][1],val+w[i+1][1]-c[x]);
                            _max(f[I][1][o(x)][2],val+w[i+1][2]-c[y]);
                        }
                        else if(t==1){
                            _max(f[I][1][o(y)][0],val+w[i+1][0]-c[x]);
                            _max(f[I][o(x)][1][2],val+w[i+1][2]-c[y]);
                        }
                        else{
                            _max(f[I][o(y)][1][0],val+w[i+1][0]-c[x]);
                            _max(f[I][o(x)][1][1],val+w[i+1][1]-c[y]);
                        }
                    }
                }
            }
        }
        for(int x=0;x<=M;x++){
            for(int y=0;y<=M;y++){
                for(int t=0;t<3;t++){
                    _max(ans,f[I][x][y][t]-c[x]-c[y]);
                }
            }
        }
        _wri(ans);
    }
    return 0;
}

