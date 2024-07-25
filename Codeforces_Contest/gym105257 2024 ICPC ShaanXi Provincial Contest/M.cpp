// Author:Zimse  Data:2024-07-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
// #define int long long
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
int n,cnt,vis[128][128][4];

void add(int x,int y,int z){
    if(!vis[x][y][z])vis[x][y][z]=1,++cnt;
    return;
}

signed main(){
    n=read();
    while(n--){
        int x=read(),y=read();
        add(x,y,0);
        add(x,y,1);
        add(x+1,y,0);
        add(x+1,y,3);
        add(x,y+1,1);
        add(x,y+1,2);
        add(x+1,y+1,2);
        add(x+1,y+1,3);
    }
    printf("%.2lf\n",0.25*cnt);
    return 0;
}



