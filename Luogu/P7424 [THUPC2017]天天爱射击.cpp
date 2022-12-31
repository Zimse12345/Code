/********************************
*FileName:
*Author: Zimse
*Data: 2022-12-
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
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
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

const int N=1000007;

int n,m,pl[N],pr[N],ps[N],pos[N],id[N],_id[N],tr[N],cnt[N];
vector<int> s[N];

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x,int y){for(;x<N;ub(x))tr[x]+=y;return;}
inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}

void sol(int l,int r,int L,int R){
    if(r<l)return;
    if(L==R){
        cnt[L]+=r-l+1;
        if(L==m){
            add(pos[m],1);
            for(int i=l;i<=r;i++){
                if(sum(pr[id[i]])-sum(pl[id[i]]-1)<ps[id[i]])--cnt[L];
            }
            add(pos[m],-1);
        }
        return;
    }
    int M=(L+R)/2;
    for(int i=L;i<=M;i++)add(pos[i],1);
    int _l=l-1,_r=r+1;
    for(int i=l;i<=r;i++){
        if(sum(pr[id[i]])-sum(pl[id[i]]-1)<ps[id[i]])_id[--_r]=id[i];
        else _id[++_l]=id[i];
    }
    for(int i=l;i<=r;i++)id[i]=_id[i];
    sol(_r,r,M+1,R);
    for(int i=L;i<=M;i++)add(pos[i],-1);
    sol(l,_l,L,M);
    return;
}

signed main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++)pl[i]=read(),pr[i]=read(),ps[i]=read(),id[i]=i;
    for(int i=1;i<=m;i++)pos[i]=read();
    sol(1,n,1,m);
    for(int i=1;i<=m;i++)_write(cnt[i]);
    return 0;
}
