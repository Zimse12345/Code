// Author:Zimse  Data:2023-07-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
 #define int long long
namespace OI{const int INF=1.01e18,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=5.01e3;
int T,n,fa[N],a[N],ans,f[N][N];
vector<int> ch[N];

void dfs(int u){
    if(!ch[u].size()){
        f[u][1]=INF;
        return;
    }
    int sum=0;
    for(unsigned i=0;i<ch[u].size();i++){
        int v=ch[u][i];
        dfs(v);
        sum+=a[v];
        for(int j=1;j<=n;j++)f[u][j+1]=min(f[u][j+1]+f[v][j],INF);
    }
    if(a[u]<=sum){
        f[u][1]=sum-a[u];
        return;
    }
    sum=a[u]-sum;
    for(int i=2;i<=n;i++){
        int t=min(sum,f[u][i]);
        ans+=(i-1)*t;
        sum-=t,f[u][i]-=t;
        if(!sum)break;
    }
    return;
}

signed main(){
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<=n;i++){
            ch[i].resize(0);
            for(int j=1;j<=n;j++)f[i][j]=0;
        }
        ans=0;
        for(int i=2;i<=n;i++){
            fa[i]=read();
            ch[fa[i]].push_back(i);
        }
        dfs(1);
        _wri(ans);
    }
    return 0;
}



