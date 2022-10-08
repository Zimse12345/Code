/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-27
*Description:
*Other:
********************************/

// #pragma GCC target("avx")
// #pragma GCC optimize("Ofast")
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
#define ll long long
// #define int long long
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

int Mod;
namespace Zimse{
// const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){x+=y;if(x>=Mod)x-=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

namespace fast {
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned __int128 ULL;

inline ull mul64hi(ull a, ull b) { return ULL(a) * b >> 64; }

struct FastDiv {
  ull base;
  uint len, divisor;
  FastDiv() = default;
  explicit FastDiv(uint x) : divisor(x) {
    len = 0;
    for (uint tmp = x - 1; tmp >>= 1;) ++len;
    base = ull((ULL(1u << len) << 64) / x) + bool(x & (x - 1));
  }
  inline ull operator()(ull x) const { return mul64hi(x, base) >> len; }
};

struct FastMod {
  FastDiv div;
  FastMod() = default;
  explicit FastMod(uint x) : div(x) {}
  inline uint operator()(ull x) const { return x - div.divisor * div(x); }
};
}  // namespace fast

fast::FastMod Mo;

const int N=3e4+7;
int B=64;

struct treearray{
    int t[N];
    inline void _init(){for(int i=0;i<N;i++)t[i]=0;return;}
    inline void ub(int& x){x+=(x&(-x));}
    inline void db(int& x){x-=(x&(-x));}
    inline void add(int x,int v){for(;x<N;ub(x))t[x]+=v;return;}
    inline int sum(int x){int res=0;for(;x;db(x))res+=t[x];return res;}
}tree;

int n,a[N],q,ans[N],_a[N],vt,vis[N];
map<int,int> V;

struct query{
    int l,r,id;
    query(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
    bool operator < (const query& _)const{
        if(l/B==_.l/B){
            if((l/B)&1)return r>_.r;
            return r<_.r;
        }
        return l<_.l;
    }
}qu[N];

struct mixtra{
    int v[2][2];
    inline void init_0(){
        v[0][0]=v[0][1]=v[1][0]=v[1][1]=0;
        return;
    }
    inline void init_e(){
        v[0][1]=v[1][0]=0,v[0][0]=v[1][1]=1;
        return;
    }
}Fib,iFib,_0;
mixtra pFib[N];

inline mixtra Mul(const mixtra& x,const mixtra& y){
    mixtra z;
    z.v[0][0]=Mo(x.v[0][0]*y.v[0][0]+x.v[0][1]*y.v[1][0]);
    z.v[0][1]=Mo(x.v[0][0]*y.v[0][1]+x.v[0][1]*y.v[1][1]);
    z.v[1][0]=Mo(x.v[1][0]*y.v[0][0]+x.v[1][1]*y.v[1][0]);
    z.v[1][1]=Mo(x.v[1][0]*y.v[0][1]+x.v[1][1]*y.v[1][1]);
    return z;
}

bool tg[N*4],lf[N*4];
int sum0[N*4],sum1[N*4];
mixtra mul[N*4];

inline void pushdown(int id){
    if(tg[id]){
        int A=(sum0[id]*mul[id].v[0][0]+sum1[id]*mul[id].v[0][1]);
        int B=(sum0[id]*mul[id].v[1][0]+sum1[id]*mul[id].v[1][1]);
        if(A>=Mod)A%=Mod;
        if(B>=Mod)B%=Mod;
        sum0[id]=A,sum1[id]=B;
        if(!lf[id]){
            if(!tg[Lid])tg[Lid]=1,mul[Lid]=mul[id];
            else mul[Lid]=Mul(mul[Lid],mul[id]);
            if(!tg[Rid])tg[Rid]=1,mul[Rid]=mul[id];
            else mul[Rid]=Mul(mul[Rid],mul[id]);
        }
        tg[id]=0,mul[id].init_e();
    }
    return;
}

void build(int L,int R,int id){
    mul[id].init_e();
    if(L!=R)build(L,M,Lid),build(M+1,R,Rid);
    else lf[id]=1;
    return;
}

void update(int L,int R,int id,int l,int r,mixtra& x){
    pushdown(id);
    if(r<L||R<l)return;
    if(l<=L&&r>=R)tg[id]=1,mul[id]=x,pushdown(id);
    else{
        update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x);
        sum0[id]=sum0[Lid]+sum0[Rid];
        sum1[id]=sum1[Lid]+sum1[Rid];
        if(sum0[id]>=Mod)sum0[id]-=Mod;
        if(sum1[id]>=Mod)sum1[id]-=Mod;
    }
    return;
}

void change(int L,int R,int id,int p,int A,int B){
    pushdown(id);
    if(L==R)sum0[id]=A,sum1[id]=B;
    else{
        if(p<=M)change(L,M,Lid,p,A,B),pushdown(Rid);
        else change(M+1,R,Rid,p,A,B),pushdown(Lid);
        sum0[id]=sum0[Lid]+sum0[Rid];
        sum1[id]=sum1[Lid]+sum1[Rid];
        if(sum0[id]>=Mod)sum0[id]-=Mod;
        if(sum1[id]>=Mod)sum1[id]-=Mod;
    }
    return;
}

inline void ins(int x){
    if(!vis[x]){
        int c=tree.sum(x-1);
        change(1,vt,1,x,Mo(pFib[c].v[0][0]*_a[x]),Mo(pFib[c].v[1][0]*_a[x]));
        update(1,vt,1,x+1,n,Fib);
        tree.add(x,1);
    }
    ++vis[x];
    return;
}

inline void era(int x){
    --vis[x];
    if(!vis[x]){
        change(1,vt,1,x,0,0);
        update(1,vt,1,x+1,n,iFib);
        tree.add(x,-1);
    }
    return;
}

signed main(){
    n=read(),Mod=read();
    Mo = fast::FastMod(Mod);
    B=sqrt(n*1.1)+1;
    tree._init();
    Fib.init_0(),Fib.v[0][0]=Fib.v[0][1]=Fib.v[1][0]=1;
    iFib.init_0(),iFib.v[0][1]=iFib.v[1][0]=1,iFib.v[1][1]=Mod-1;
    _0.init_0();
    pFib[0].init_e();
    for(int i=1;i<N;i++)pFib[i]=Mul(Fib,pFib[i-1]);

    for(int i=1;i<=n;i++)_a[i]=a[i]=read();
    sort(_a+1,_a+n+1),_a[0]=-1;
    for(int i=1;i<=n;i++)if(_a[i]!=_a[i-1])_a[++vt]=_a[i],V[_a[i]]=vt,_a[vt]%=Mod;
    for(int i=1;i<=n;i++)a[i]=V[a[i]];
    build(1,vt,1);
    q=read();
    for(int i=1,l,r;i<=q;i++)l=read(),r=read(),qu[i]=query(l,r,i);
    sort(qu+1,qu+q+1);
    for(int i=1,L=1,R=0;i<=q;i++){
        while(R>qu[i].r)era(a[R--]);
        while(L<qu[i].l)era(a[L++]);
        while(R<qu[i].r)ins(a[++R]);
        while(L>qu[i].l)ins(a[--L]);
        ans[qu[i].id]=sum0[1];
    }
    for(int i=1;i<=q;i++)_write(ans[i]);
    return 0;
}
