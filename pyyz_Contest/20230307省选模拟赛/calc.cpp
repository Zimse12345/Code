/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
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
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514;
// const int Mod=998244353;
const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
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

const int N=350;

int n,m;

struct poly{
	int x,y;
    poly(int x=0,int y=0):x(x),y(y){}
	poly operator + (const poly &_)const{return poly((x+_.x)%Mod,(y+_.y)%Mod);}
	poly operator - (const poly &_)const{return poly((x-_.x+Mod)%Mod,(y-_.y+Mod)%Mod);}
    poly operator * (const poly &_)const{return poly(x*_.x%Mod,(x*_.y+y*_.x)%Mod);}
	poly operator / (const poly &_)const{
        int i=inv(_.x),rx=x*i%Mod,ry=(y-_.y*rx%Mod+Mod)*i%Mod;
        return poly(rx,ry);
	}
    poly operator - (void)const{return poly(x?Mod-x:x,y?Mod-y:y);}
}a[N][N];

signed main(){
    n=read(),m=read();
    for(int i=1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        a[u][v]=a[u][v]-poly(1,w);
        a[u][u]=a[u][u]+poly(1,w);
    }
    poly det=poly(1,0);
    --n;
    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=i;j<=n;j++)if(a[j][i].x||a[j][i].y){t=j;break;}
        if(!t){det=poly(0,0);break;}
        if(t!=i){
            for(int j=1;j<=n;j++)swap(a[i][j],a[t][j]);
            det=-det;
        }
        det=det*a[i][i];
        for(int j=i+1;j<=n;j++){
            poly x=a[j][i]/a[i][i];
            for(int k=1;k<=n;k++)a[j][k]=a[j][k]-x*a[i][k];
        }
    }
    _write(det.y);
    return 0;
}
