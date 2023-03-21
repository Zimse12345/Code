/********************
*FileName:
*Author: Zimse
*Data: 2023-03-
*Description:
********************/

#include <algorithm>
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
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514,Mod=998244353;//1000000007
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);return;}
inline void write_(int x){WRI(x),pc(32);return;}
inline void _write(int x){WRI(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1024;

int n,m,sx,sy,tx,ty,dis[N][N],L[N][N],R[N][N],U[N][N],D[N][N],vis[N][N],typ[N][N];
char str[N][N];

struct node{
    int x,y,d;
    node(int x=0,int y=0,int d=0):x(x),y(y),d(d){}
    bool operator < (const node& _)const{return d>_.d;}
};
priority_queue<node> Q;

inline void Go(int x,int y,int _x,int _y,int d,int &s,int ty){
    if(dis[x][y]+d<dis[_x][_y]){
        dis[_x][_y]=dis[x][y]+d,typ[_x][_y]=ty;
        Q.push(node(_x,_y,dis[_x][_y]));
        s=0;
    }
    else ++s;
    return;
}

signed main(){
    // ifile("a.in");
    // ofile("a.out");

    n=read(),m=read();
    for(int i=1;i<=n;i++){
        scanf("%s",str[i]+1);
        for(int j=1;j<=m;j++){
            dis[i][j]=INF;
            if(str[i][j]=='.')L[i][j]=L[i][j-1]+1,U[i][j]=U[i-1][j]+1;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(str[i][j]=='.')R[i][j]=R[i][j+1]+1,D[i][j]=D[i+1][j]+1;
        }
    }
    sx=read(),sy=read(),tx=read(),ty=read();
    dis[sx][sy]=0,typ[sx][sy]=2,Q.push(node(sx,sy,0));
    while(!Q.empty()){
        int x=Q.top().x,y=Q.top().y;
        if(x==tx&&y==ty)break;
        Q.pop();
        if(vis[x][y]++)continue;
        int l=x-U[x][y]+1,r=x,w=1,d=0,s=0;
        if(typ[x][y]!=0)while(l<r){
            if(w)--r,++d,Go(x,y,l,y,d,s,0);
            else ++l,++d,Go(x,y,r,y,d,s,0);
            w^=1;
            if(s>1)break;
        }
        l=x,r=x+D[x][y]-1,w=0,d=0,s=0;
        if(typ[x][y]!=0)while(l<r){
            if(w)--r,++d,Go(x,y,l,y,d,s,0);
            else ++l,++d,Go(x,y,r,y,d,s,0);
            w^=1;
            if(s>1)break;
        }
        l=y-L[x][y]+1,r=y,w=1,d=0,s=0;
        if(typ[x][y]!=1)while(l<r){
            if(w)--r,++d,Go(x,y,x,l,d,s,1);
            else ++l,++d,Go(x,y,x,r,d,s,1);
            w^=1;
            if(s>1)break;
        }
        l=y,r=y+R[x][y]-1,w=0,d=0,s=0;
        if(typ[x][y]!=1)while(l<r){
            if(w)--r,++d,Go(x,y,x,l,d,s,1);
            else ++l,++d,Go(x,y,x,r,d,s,1);
            w^=1;
            if(s>1)break;
        }
    }
    if(dis[tx][ty]==INF)dis[tx][ty]=-1;
    _write(dis[tx][ty]);
    return 0;
}
