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
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=114514;
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

const int N=1000007;

int n,m,k,x[N],a[N],d[N],p[N],tot;
int dis[N],vis[N],mn[64][64],f[1100000];
queue<int> q;

void dij(int s){
    for(int i=1;i<=n+1;i++)dis[i]=INF,vis[i]=0;
    dis[s]=0,q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(vis[u]++)continue;
        for(int i=1;i<=k;i++){
            if(u-a[i]>=1&&dis[u]+1<dis[u-a[i]]){
                dis[u-a[i]]=dis[u]+1;
                q.push(u-a[i]);
            }
            if(u+a[i]<=n+1&&dis[u]+1<dis[u+a[i]]){
                dis[u+a[i]]=dis[u]+1;
                q.push(u+a[i]);
            }
        }
    }
    return;
}

signed main(){
	// ifile("z.in");
	// ofile("z.out");
	
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)x[i]=read(),d[x[i]]^=1,d[x[i]+1]^=1;
    for(int i=1;i<=k;i++)a[i]=read();
    for(int i=1;i<=n+1;i++)if(d[i])p[++tot]=i;
    for(int i=1;i<=tot;i++){
        dij(p[i]);
        for(int j=1;j<=tot;j++){
            mn[i][j]=dis[p[j]];
        }
    }
    for(int i=1;i<(1<<tot);i++)f[i]=INF;
    for(int i=0;i<(1<<tot);i++){
        for(int x=0;x<tot;x++)if(!(i&(1<<x))){
            for(int y=x+1;y<tot;y++)if(!(i&(1<<y))){
                _min(f[i|(1<<x)|(1<<y)],f[i]+mn[x+1][y+1]);
            }
            break;
        }
    }
    int ans=f[(1<<tot)-1];
    if(ans>=INF)ans=-1;
    _write(ans);
    return 0;
}
