// Author:Zimse  Data:2023-07-
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

const int N=1.01e7;
int T,n,m,a,b,k,rev,cur,S;
char ans[N];
vector<int> vis[N];

inline void solve(){
    n=read(),m=read(),a=read(),b=read(),k=read();
    int Lim=min(n,k/m+4);
    n=min(n,a+Lim);
    if(a>Lim)n-=a-Lim,a=Lim;
    Lim=min(m,k/n+4);
    m=min(m,b+Lim);
    if(b>Lim)m-=b-Lim,b=Lim;
    vis[0].resize(m+2),vis[n+1].resize(m+2);
    for(int i=1;i<=n;i++){
        vis[i].resize(m+2);
        for(int j=1;j<=m;j++)vis[i][j]=1;
    }
    if(a==n)a=n-a+1,rev=1;
    int len=n*m;if(len>N||a<1||a>n||b<1||b>m)return;
    if(len&1)len-=1,vis[n][m]=0;
    if(n&1){
        for(int j=(m&1)?m-1:m;j>1;j-=2){
            if(len>k)vis[n][j]=vis[n][j-1]=0,len-=2;
        }
    }
    for(int i=1;i<n;i+=2)if(i!=a&&i+1!=a){
        for(int j=m;j>2;j--){
            if(len>k)vis[i][j]=vis[i+1][j]=0,len-=2;
        }
    }
    for(int i=1;(i-1)/2<(a-1)/2;i++){
        if(len>k)vis[i][1]=vis[i][2]=0,len-=2;
    }
    for(int i=(n&1)?n-1:n;(i-1)/2>(a-1)/2;i--){
        if(len>k)vis[i][1]=vis[i][2]=0,len-=2;
    }
    for(int i=1;i<b;i++){
        if(len>k)vis[a][i]=vis[((a-1)^1)+1][i]=0,len-=2;
    }
    for(int i=m;i>b;i--){
        if(len>k)vis[a][i]=vis[((a-1)^1)+1][i]=0,len-=2;
    }
    int x=0,y=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)if(vis[i][j]){
            x=i,y=j;
            break;
        }
        if(x)break;
    }
    while(1){
        if(cur)vis[x][y]=0;
        if(x==a&&y==b&&!S)S=cur;
        if(vis[x][y+1])++y,ans[++cur]='R';
        else if(vis[x+1][y])++x,ans[++cur]='D';
        else if((n&1)&&x==n&&vis[x-1][y])--x,ans[++cur]='U';
        else if(vis[x][y-1])--y,ans[++cur]='L';
        else if(vis[x-1][y])--x,ans[++cur]='U';
        else break;
    }
    if(rev){
        for(int i=1;i<=cur;i++){
            if(ans[i]=='U')ans[i]='D';
            else if(ans[i]=='D')ans[i]='U';
        }
    }
    for(int i=S+1;i<=cur;i++)pc(ans[i]);
    for(int i=1;i<=S;i++)pc(ans[i]);
    pc(10);
    rev=cur=S=0;
    for(int i=0;i<=n+1;i++)for(int j=0;j<=m+1;j++)vis[i][j]=0;
    return;
}

signed main(){
//    iF("travel.in");
//    oF("travel.out");
    
    T=read();
    while(T--)solve();
    return 0;
}


