/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
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

const int N=1000007,M=100001;

int n,Ans;

struct node{
    int a,b,c,d,val,ans,aa;
    node(int a=0,int b=0,int c=0,int d=0,int val=0,int ans=0):a(a),b(b),c(c),d(d),val(val),ans(ans){}
}p[N];

bool cmp_a(const node& x,const node& y){
    if(x.a==y.a){
        if(x.b==y.b){
            if(x.c==y.c)return x.d<y.d;
            return x.c<y.c;
        }
        return x.b<y.b;
    }
    return x.a<y.a;
}

bool cmp_b(const node& x,const node& y){
    if(x.b==y.b){
        if(x.c==y.c){
            if(x.d==y.d)return x.aa<y.aa;
            return x.d<y.d;
        }
        return x.c<y.c;
    }
    return x.b<y.b;
}

bool cmp_c(const node& x,const node& y){
    if(x.c==y.c)return x.d<y.d;
    return x.c<y.c;
}

int mx[N];
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void upt(int x,int y){for(;x<N;ub(x))_max(mx[x],y);return;}
inline int qry(int x){int res=0;for(;x;db(x))_max(res,mx[x]);return res;}
inline void cl(int x){for(;x<N;ub(x))mx[x]=0;return;}

void cdq2(int L,int R){
    if(L==R)return;
    int M=(L+R)/2;
    cdq2(L,M),cdq2(M+1,R);
    int pos=L;
    for(int i=M+1;i<=R;i++)if(p[i].aa){
        while(pos<=M&&p[pos].c<=p[i].c){
            if(!p[pos].aa)upt(p[pos].d,p[pos].ans);
            ++pos;
        }
        _max(p[i].ans,p[i].val+qry(p[i].d));
    }
    for(int i=L;i<pos;i++)if(!p[i].aa)cl(p[i].d);
    sort(p+L,p+R+1,cmp_c);
    return;    
}

void cdq(int L,int R){
    if(L==R)return;
    int M=(L+R)/2;
    cdq(L,M);
    for(int i=L;i<=R;i++)p[i].aa=(i<=M?0:1);
    sort(p+L,p+R+1,cmp_b);
    cdq2(L,R);
    sort(p+L,p+R+1,cmp_a);
    cdq(M+1,R);
    return;
}

signed main(){
    n=read();
    for(int i=1,a,b,c,d,val;i<=n;i++){
        a=read(),b=read(),c=read(),d=read()+M,val=read();
        p[i]=node(a,b,c,d,val,val);
    }
    sort(p+1,p+n+1,cmp_a);
    for(int i=1;i<=n;i++)p[i].a=i;
    cdq(1,n);
    for(int i=1;i<=n;i++)_max(Ans,p[i].ans);
    _write(Ans);
    return 0;
}
