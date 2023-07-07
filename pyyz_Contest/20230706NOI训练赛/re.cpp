// Author:Zimse  Data:2023-06-
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

const int N=3.01e3;
int f[N],g[N],mp[N][N],x,y,k;
// int s[N][N];

void solve(int n){
    if(n<=3){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)mp[x+i][y+j]=1;
        }
        x+=n-1,y+=n-1;
        return;
    }
    int a=g[n],b=n-a;
    if(x<y&&a<b)swap(a,b);
    if(x>y&&a>b)swap(a,b);
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++)mp[x+i][y+j]=1;
    }
    x+=a,y+=b;
    solve(a),solve(b);
    return;
}

signed main(){
    iF("re.in");
    oF("re.out");

    f[1]=0,f[2]=2,f[3]=4;
    g[1]=1,g[2]=2,g[3]=3;
    for(int i=4;i<=1000;i++){
        f[i]=INF;
        for(int j=1;j<i;j++)if(f[j]+f[i-j]+i<f[i]){
            f[i]=f[j]+f[i-j]+i,g[i]=j;
        }
    }
    x=1,y=1,mp[1][1]=1,k=read();
    solve(k);
    printf("%d %d\n",x,y);
    // s[0][1]=1;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            pc('0'+(mp[i][j]^1));
            // if(mp[i][j])s[i][j]=(s[i-1][j]+s[i][j-1])%Mod;
        }
        pc(10);
    }
    // int fac=1;
    // for(int i=1;i<=k;i++)fac=1ll*fac*i%Mod;
    // printf("%d %d\n",fac,s[x][y]);
    return 0;
}

