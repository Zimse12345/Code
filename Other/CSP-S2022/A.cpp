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

int n,m,k,pts[N],hd[N],nxt[N],to[N],ec,dis[N],p[2700][2700],mx1[N][3],mx2[N][3],ans;
int que[N],L,R;

inline void add(int u,int v){
    nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
    return;
}

signed main(){
    n=read(),m=read(),k=read()+1;
    for(int i=2;i<=n;i++)pts[i]=read();
    for(int i=1,u,v;i<=m;i++)u=read(),v=read(),add(u,v),add(v,u);
    for(int i=1;i<=n;i++){
        dis[i]=0,L=R=1,que[1]=i;
        while(L<=R){
            int u=que[L++];
            p[i][u]=1;
            if(dis[u]>=k)continue;
            for(int j=hd[u],v;j;j=nxt[j]){
                v=to[j];
                if(p[i][v])continue;
                p[i][v]=1,dis[v]=dis[u]+1,que[++R]=v;
            }
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            if(i!=j&&p[1][j]&&p[j][i]){
                for(int t=0;t<=2;t++)if(pts[j]>pts[mx1[i][t]]){
                    for(int tt=2;tt>t;tt--)mx1[i][tt]=mx1[i][tt-1];
                    mx1[i][t]=j;
                    break;
                }
            }
            if(i!=j&&p[i][j]&&p[j][1]){
                for(int t=0;t<=2;t++)if(pts[j]>pts[mx2[i][t]]){
                    for(int tt=2;tt>t;tt--)mx2[i][tt]=mx2[i][tt-1];
                    mx2[i][t]=j;
                    break;
                }
            }
        }
    }
    for(int B=2;B<=n;B++)for(int C=2;C<=n;C++)if(B!=C&&p[B][C]){
        for(int i=0,A;i<=2;i++){
            A=mx1[B][i];
            if(A==C||!A)continue;
            for(int j=0,D;j<=2;j++){
                D=mx2[C][j];
                if(B==D||A==D||!D)continue;
                _max(ans,pts[A]+pts[B]+pts[C]+pts[D]);
            }
        }
    }
    _write(ans);
    return 0;
}
