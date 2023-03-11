/********************************
*FileName:
*Author: Zimse
*Data: 2022-11-
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

int n,m,q,sum[N],_sum[N],val[N],hs,_hs;
vector<int> inedge[N];

inline int Rand(){
    int x=rand()%16384;
    int y=rand()%16384;
    return x*16384+y;
}

signed main(){
    n=read(),m=read();
    srand(time(0));
    for(int i=1;i<=n;i++)val[i]=Rand();
    for(int i=1,u,v;i<=m;i++){
        u=read(),v=read();
        inedge[v].pb(u);
        addmod(sum[v],val[u]);
    }
    for(int i=1;i<=n;i++)addmod(hs,val[i]),addmod(_hs,sum[i]),_sum[i]=sum[i];
    q=read();
    while(q--){
        int op=read();
        if(op==1){
            int x=read(),y=read();
            addmod(_hs,Mod-val[x]);
            addmod(_sum[y],Mod-val[x]);
        }
        if(op==2){
            int x=read();
            addmod(_hs,Mod-_sum[x]);
            _sum[x]=0;
        }
        if(op==3){
            int x=read(),y=read();
            addmod(_hs,val[x]);
            addmod(_sum[y],val[x]);
        }
        if(op==4){
            int x=read();
            addmod(_hs,sum[x]-_sum[x]);
            _sum[x]=sum[x];
        }
        if(hs==_hs)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
