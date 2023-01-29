/********************************
*FileName:
*Author: Zimse
*Data: 2023-01-
*Description:
*Other:
********************************/

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

using namespace std;

namespace Zimse{
// const int Mod=998244353;
const int Mod=1000000007;

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
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y);if(x>=Mod)x-=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1000007;

int n,sz;

struct mixtra{
    int v[32][32];

    void init_0(){
        for(int i=0;i<=sz;i++){
            for(int j=0;j<=sz;j++)v[i][j]=0;
        }
        return;
    }

    void init_1(){
        init_0();
        for(int i=0;i<=sz;i++)v[i][i]=1;
        return;
    }

    void see(){
        for(int i=0;i<=sz;i++){
            for(int j=0;j<=sz;j++)write_(v[i][j]);
            pc(10);
        }
        pc(10);
        return;
    }
}f[64];

mixtra mul(mixtra x,mixtra y){
    mixtra z;
    z.init_0();
    for(int i=0;i<=sz;i++){
        for(int j=0;j<=sz;j++){
            for(int k=0;k<=sz;k++)addmod(z.v[i][j],y.v[i][k]*x.v[k][j]%Mod);
        }
    }
    return z;
}

mixtra merge(mixtra x,mixtra y,int L,int R){
    mixtra mid;
    mid.init_0();
    for(int i=0;i<=sz;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<sz;k++)addmod(mid.v[i][k],mid.v[j][k]);
        }
        if(i==sz)break;
        int val=(i+R)%sz;
        int j=sz-1;
        while(1){
            addmod(mid.v[i][j],1);
            if((j+L)%sz==val)break;
            --j;
        }
    }
    addmod(mid.v[sz][sz],1);
    return mul(mul(x,mid),y);
}

int getval(int x){
    if(x<=sz)return x-1;
    int y=sz,z=0;
    while(x*2/sz>y&&y*sz<x)y*=sz;
    while(x>y)x-=y,++z;
    return (getval(x)+z)%sz;
}

signed main(){
    n=read(),sz=read();
    if(n<=sz){
        _write(fpow(2,n));
        return 0;
    }
    f[1].init_1();
    f[0].v[0][0]=1;
    for(int i=1;i<=sz;i++)f[0].v[i][0]=f[0].v[i-1][0]*2%Mod;
    --f[0].v[sz][0];
    for(int i=2,p=sz;i<64&&p<=n;i++,p*=sz){
        f[i]=f[i-1];
        for(int j=1;j<sz;j++)f[i]=merge(f[i],f[i-1],(sz*100+1-i+j)%sz,j);
        if(n*2/sz<p)break;
    }
    mixtra g;
    int t=1,p=0;
    while(t<=n*2/sz&&t*sz<=n)t*=sz,++p;
    g=f[p];
    while(t<n){
        int _t=1;
        p=0;
        while(_t<=(n-t)*2/sz&&t+_t*sz<=n)_t*=sz,++p;
        if(!p)break;
        g=merge(g,f[p],getval(t-sz+1),getval(t+1)),t+=_t;
    }
    g=merge(g,f[1],getval(t-sz+1),getval(t+1)),t+=sz;
    g=mul(f[0],g);
    int ans=g.v[sz][0];
    p=sz-1;
    while(t>n){
        addmod(ans,Mod-g.v[p][0]);
        --t,--p;
    }
    addmod(ans,1);
    _write(ans);
    return 0;
}
