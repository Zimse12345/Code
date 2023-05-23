// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
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
int n,k,b,a[N],v[N],m,t[N],ans[N],cur,f[N][30];

void dfs(int p){
    if(p){
        f[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=p;j>=0;j--){
                f[i][j]=f[i-1][j];
                if(j<p&&t[j+1]==a[i])addmod(f[i][j+1],f[i-1][j]);
            }
        }
        if(!f[n][p])return;
        int s=min(k,f[n][p]),sum=0;
        for(int i=1;i<=p;i++)addmod(sum,t[i]*fpow(b,p-i));
        k-=s;
        while(s--)ans[++cur]=sum;
        if(!k)return;
    }
    if(p==n)return;
    for(int i=1;i<=m;i++){
        t[p+1]=v[i];
        dfs(p+1);
        if(!k)return;
    }
    return;
}

signed main(){
    // ifile("ttds.in");
    // ofile("ttds.out");
    
    n=read(),k=read(),b=read();
    for(int i=1;i<=n;i++)a[i]=read(),v[i]=a[i];
    sort(v+1,v+n+1);
    for(int i=1;i<=n;i++)if(v[i]!=v[i-1])v[++m]=v[i];
    dfs(0);
    for(int i=1;i<=cur;i++)_write(ans[i]);
    return 0;
}

