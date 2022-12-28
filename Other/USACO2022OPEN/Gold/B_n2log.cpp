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
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=2048;

int T,n,s1[N],t1,s2[N],t2,f[N][N],g[N][N];
char str[N];

struct ft{
    int tr[N];
    inline void ub(int& x){x+=(x&(-x));return;}
    inline void db(int& x){x-=(x&(-x));return;}
    inline void add(int x,int y){++x;for(;x<N;ub(x))addmod(tr[x],y);return;}
    inline int sum(int x){++x;int res=0;for(;x;db(x))addmod(res,tr[x]);return res;}
}ff,gg;

struct line{
    int l,r,v;
    line(int l=0,int r=0,int v=0):l(l),r(r),v(v){}
};
vector<line> F[N],G[N];

signed main(){
    T=read();
    while(T--){
        n=read();
        scanf("%s",str+1);
        for(int i=1;i<=n;i++){
            if(str[i]=='0'){
                t1=0,s1[++t1]=0;
                continue;
            }
            if(str[i]=='1')continue;
            if(str[i]=='+')s1[++t1]=1;
            else s1[++t1]=0;
        }
        scanf("%s",str+1);
        for(int i=1;i<=n;i++){
            if(str[i]=='0'){
                t2=0,s2[++t2]=0;
                continue;
            }
            if(str[i]=='1')continue;
            if(str[i]=='+')s2[++t2]=1;
            else s2[++t2]=0;
        }
        f[0][0]=g[0][0]=1;
        for(int i=0;i<=t1;i++){
            for(int j=0;j<=t2;j++){
                addmod(f[i][j],ff.sum(j));
                addmod(g[i][j],gg.sum(j));
                if(f[i][j]){
                    printf("f[%d][%d]=%d\n",i,j,f[i][j]);
                    int _i=i,_j=j;
                    while(_i<t1&&s1[_i+1]==0)++_i;
                    while(_j<t2&&s2[_j+1]==0)++_j;
                    gg.add(j,f[i][j]);
                    gg.add(_j+1,Mod-f[i][j]);
                    G[_i].pb(line(j,_j,f[i][j]));
                }
                if(g[i][j]){
                    int _i=i,_j=j;
                    while(_i<t1&&s1[_i+1]==1)++_i;
                    while(_j<t2&&s2[_j+1]==1)++_j;
                    ff.add(j,g[i][j]);
                    ff.add(_j+1,Mod-g[i][j]);
                    F[_i].pb(line(j,_j,g[i][j]));
                }
            }
            for(unsigned j=0;j<F[i].size();j++){
                ff.add(F[i][j].l,Mod-F[i][j].v);
                ff.add(F[i][j].r+1,F[i][j].v);
            }
            for(unsigned j=0;j<G[i].size();j++){
                gg.add(G[i][j].l,Mod-G[i][j].v);
                gg.add(G[i][j].r+1,G[i][j].v);
            }
        }
        int ans=(f[t1][t2]+g[t1][t2])%Mod;
        _write(ans);
        for(int i=0;i<=t1;i++){
            for(int j=0;j<=t2;j++)f[i][j]=g[i][j]=0;
        }
        for(int i=0;i<N;i++)F[i].resize(0),G[i].resize(0);
        t1=t2=0;
    }
    return 0;
}
