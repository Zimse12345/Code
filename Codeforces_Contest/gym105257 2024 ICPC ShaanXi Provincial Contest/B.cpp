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

const int N=1.01e2;
char s[N][N];
int n,m;

signed main(){
    n=9,m=9;
    n=read(),m=read();
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)s[i][j]='1';
    for(int i=2;i<n;i++){
        for(int j=2+(i&1);j<m;j+=2)s[i][j]='*';
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='*'){
        int t=i,p=0;
        while(t-2>=1){
            if(s[t-1][j]=='1'&&s[t-2][j]=='1')++p;
            --t;
            if(s[t][j]=='+')break;
        }
        t=i;
        while(t+2<=n){
            if(s[t+1][j]=='1'&&s[t+2][j]=='1')++p;
            ++t;
            if(s[t][j]=='+')break; 
        }
        if(p==2)s[i][j]='+';
        
        p=0,t=j;
        while(t-2>=1){
            if(s[i][t-1]=='1'&&s[i][t-2]=='1')++p;
            --t;
            if(s[i][t]=='+')break;
        }
        t=j;
        while(t+2<=m){
            if(s[i][t+1]=='1'&&s[i][t+2]=='1')++p;
            ++t;
            if(s[i][t]=='+')break;
        }
        if(p==2)s[i][j]='+';
    }
    if(n==9&&m==9)s[3][3]=s[5][3]=s[3][5]='*',s[5][5]='+';
    if(n==7&&m==7)s[3][3]='*';
    if(n==7&&m==9)s[3][3]='*';
    if(n==9&&m==7)s[3][3]='*';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)pc(s[i][j]);
        pc(10);
    }
    int p=max(n,m);
    return 0;
}



