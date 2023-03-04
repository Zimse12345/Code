/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514;
// const int Mod=998244353;
const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
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

const int N=1000007;

struct node{
    int x,y;
    node(int x=0,int y=0):x(min(x,y)),y(max(x,y)){}
}p[100][100];

int n,fib[N];

signed main(){
    n=read();
    fib[0]=fib[1]=1;
    for(int i=2;i<100;i++)fib[i]=fib[i-2]+fib[i-1];
    p[1][1]=node(1,2);
    for(int i=2;i<100;i++){
        for(int j=1;j<i;j++)p[i][j]=node(p[i-1][j].y,p[i-1][j].x+p[i-1][j].y);
        p[i][i]=node(fib[i+1],fib[i+1]+fib[i-1]);
    }
    while(n--){
        node q=node(read(),read());
        int ans=1,sum=0;
        while(p[ans+1][1].x<=q.x&&p[ans+1][1].y<=q.y)++ans;
        if(ans==1){
            q.x%=Mod,q.y%=Mod;
            sum=q.x*q.y%Mod;
        }
        else for(int i=1;i<=ans;i++){
            if(p[ans][i].x<=q.x&&p[ans][i].y<=q.y)addmod(sum,(q.y-p[ans][i].y)/p[ans][i].x+1);
            if(p[ans][i].x<=q.y&&p[ans][i].y<=q.x)addmod(sum,(q.x-p[ans][i].y)/p[ans][i].x+1);
        }
        printf("%lld %lld\n",ans,sum);
    }
    return 0;
}
