// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
namespace OI{const int INF=1.01e15,Mod=998244353;int read(){int x=0
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
int n,a[N],l[N],r[N];

inline bool check(int sum){
    for(int i=0;i<n;i++){
        l[i]=a[i],r[i]=sum-a[i+n];
        if(r[i]<l[i])return false;
    }
    int L=l[0],R=r[0];
    while(L<=R){
        int M=(L+R)/2;
        int x=0,y=M;
        for(int i=1;i<n;i++){
            if(y-x<l[i])y=x+l[i];
            if(y-x>r[i])x=y-r[i];
        }
        if(x<=M&&y<=sum)return true;
        if(x>M)L=M+1;
        else R=M-1;
    }
    return false;
}

signed main(){
    n=read();
    for(int i=0;i<n*2;i++)a[i]=read();
    int L=0,R=INF,ans=INF;
    while(L<=R){
        int M=(L+R)/2;
        if(check(M))ans=M,R=M-1;
        else L=M+1;
    }
    _wri(ans);
    return 0;
}

