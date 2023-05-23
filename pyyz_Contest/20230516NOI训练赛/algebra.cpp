// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
//#define M ((L+R)/2)
namespace Zimse{const int INF=1.01e9,Mod=1000000007;
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

int k,f[32][32][2],ans;

signed main(){
    // ifile("algebra.in");
    // ofile("algebra.out");

    k=read();
    f[31][0][1]=1;
    for(int i=30;i>=0;i--){
        for(int j=0;j<32;j++){
            for(int t=0;t<2;t++)if(f[i+1][j][t]){
                if(!(t&&(k&(1<<i))==0)){
                    addmod(f[i][j+1][t],f[i+1][j][t]);
                    if(j)addmod(f[i][j][t],f[i+1][j][t]*fpow(2,j-1));
                }
                if(k&(1<<i))addmod(f[i][j][0],f[i+1][j][t]*fpow(2,max(0ll,j-1)));
                else addmod(f[i][j][t],f[i+1][j][t]*fpow(2,max(0ll,j-1)));
            }
        }
    }
    for(int j=0;j<32;j++)addmod(ans,f[0][j][0]+f[0][j][1]);
    _write(ans);
    return 0;
}
