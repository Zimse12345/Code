// Author:Zimse  Data:2024-07-
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

const int N=1.01e5;
char s[N],a[N],b[N];
int n,x,y,f[N][21][21],ans;

signed main(){
    scanf("%s",s+1);
    scanf("%s",a+1);
    scanf("%s",b+1);
    n=strlen(s+1),x=strlen(a+1),y=strlen(b+1);
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int p=0;p<=x;p++){
            for(int q=0;q<=y;q++)if(f[i-1][p][q]){
                int v=f[i-1][p][q];
                _mod(f[i][p][q],v);
                if(p==0&&q==0)(v*=i)%=Mod;
                if(s[i]==a[p+1])_mod(f[i][p+1][q],v);
                if(s[i]==b[q+1])_mod(f[i][p][q+1],v);
                if(s[i]==a[p+1]&&s[i]==b[q+1])_mod(f[i][p+1][q+1],v);
            }
        }
        _mod(ans,f[i][x][y]);
    }
    _wri(ans);
    return 0;
}



