/************************
*FileName:
*Author: Zimse
*Data: 2023-01-
*Description:
************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define pb push_back
#define ll long long
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1024;

int n,m,k,lcp[N][N],tot;
int f[N][N],g[N][N];
char str[N];

struct substr{
    int l,r;
    substr(int l=0,int r=0):l(l),r(r){}
    bool operator < (const substr& _)const{
        if(lcp[l][_.l]>=min(r-l+1,_.r-_.l+1))return r-l+1<_.r-_.l+1;
        return str[l+lcp[l][_.l]]<str[_.l+lcp[l][_.l]];
    }
}s[N*N];

bool ck(int M){
    int l=s[M].l,r=s[M].r;
    f[n+1][0]=g[n+1][0]=1;
    for(int i=n;i>=1;i--){
        int t=lcp[l][i];
        if(t<r-l+1){
            if(str[i+t]>str[l+t])++t;
            else t=INF;
        }
        else t=r-l+1;
        g[i][0]=1;
        for(int j=1;j<=m;j++){
            if(t<INF)f[i][j]=g[i+t][j-1];
            else f[i][j]=0;
            g[i][j]=min(k,g[i+1][j]+f[i][j]);
        }
    }
    return f[1][m]>=k;
}

signed main(){
    n=read(),m=read(),k=read();
    scanf("%s",str+1);
    for(int i=n;i>=1;i--){
        for(int j=n;j>=1;j--){
            if(str[i]==str[j])lcp[i][j]=lcp[i+1][j+1]+1;
        }
    }
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)s[++tot]=substr(i,j);
    sort(s+1,s+tot+1);
    int L=1,R=tot,ans=0;
    while(L<=R){
        int M=(L+R)/2;
        if(ck(M))ans=M,L=M+1;
        else R=M-1;
    }
    for(int i=s[ans].l;i<=s[ans].r;i++)pc(str[i]);
    pc(10);
    return 0;
}
