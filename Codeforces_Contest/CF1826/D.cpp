// Author: Zimse
// Data: 2023-04-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)

namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=1.01e6;
int T,n,a[N],f[N][4];

signed main(){
    T=read();
    f[0][1]=f[0][2]=f[0][3]=-INF;
    while(T--){
        n=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
            for(int j=0;j<4;j++)f[i][j]=f[i-1][j];
            _max(f[i][1],f[i-1][0]+a[i]+i);
            _max(f[i][2],f[i-1][1]+a[i]);
            _max(f[i][3],f[i-1][2]+a[i]-i);
        }
        _write(f[n][3]);
    }
    return 0;
}

