/********************************
*FileName:
*Author: Zimse
*Data: 2022-10-
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
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

using namespace std;

namespace Zimse{
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
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=100007;

int n,m,q,a[N];

struct segmenttree{
    int sz,v[N],mx[N*4],mn[N*4];

    void build(int L,int R,int id){
        if(L==R)mx[id]=mn[id]=v[L];
        else{
            build(L,M,Lid),build(M+1,R,Rid);
            mx[id]=max(mx[Lid],mx[Rid]),mn[id]=min(mn[Lid],mn[Rid]);
        }
        return;
    }

    int qmax(int L,int R,int id,int l,int r){
        if(r<L||R<l)return -INF;
        if(l<=L&&r>=R)return mx[id];
        return max(qmax(L,M,Lid,l,r),qmax(M+1,R,Rid,l,r));
    }

    int qmin(int L,int R,int id,int l,int r){
        if(r<L||R<l)return INF;
        if(l<=L&&r>=R)return mn[id];
        return min(qmin(L,M,Lid,l,r),qmin(M+1,R,Rid,l,r));
    }

    int Max(int l,int r){
        return qmax(1,sz,1,l,r);
    }

    int Min(int l,int r){
        return qmin(1,sz,1,l,r);
    }

    void Init(){
        build(1,sz,1);
        return;
    }
}A1,A2,B1,B2,C,D;

signed main(){
    n=read(),m=read(),q=read();
    A1.sz=A2.sz=B1.sz=B2.sz=C.sz=n,D.sz=m;
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]>0)A1.v[i]=A2.v[i]=a[i];
        else A2.v[i]=INF;
        if(a[i]<0)B1.v[i]=B2.v[i]=a[i];
        else B1.v[i]=-INF;
        if(a[i]==0)C.v[i]=1;
    }
    for(int i=1;i<=m;i++)D.v[i]=read();
    A1.Init(),A2.Init(),B1.Init(),B2.Init(),C.Init(),D.Init();
    while(q--){
        int l1=read(),r1=read(),l2=read(),r2=read();
        int ans=-INF*INF,x;
        x=A1.Max(l1,r1);
        if(x!=0)_max(ans,x*D.Min(l2,r2));
        x=A2.Min(l1,r1);
        if(x!=INF)_max(ans,x*D.Min(l2,r2));
        x=B1.Max(l1,r1);
        if(x!=-INF)_max(ans,x*D.Max(l2,r2));
        x=B2.Min(l1,r1);
        if(x!=0)_max(ans,x*D.Max(l2,r2));
        x=C.Max(l1,r1);
        if(x!=0)_max(ans,0);
        _write(ans);
    }
    return 0;
}
