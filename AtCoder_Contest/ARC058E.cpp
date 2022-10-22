/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-
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
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
// const int Mod=998244353;
const int Mod=1000000007;
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
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1e6+7;

int n,X,Y,Z,f[64][32][128][32][2],ans;

signed main(){
    n=read(),X=read(),Y=read(),Z=read();
    f[0][1][0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int x=0;x<(1<<X);x++){
            for(int y=0;y<(1<<Y);y++){
                for(int z=0;z<(1<<Z);z++)for(int t=0;t<2;t++){
                    if(!f[i-1][x][y][z][t])continue;
                    for(int v=1;v<=10;v++){
                        int _x=0,_y=0,_z=0,_t=t;
                        for(int k=0;k<X;k++)if(x&(1<<k)){
                            if(k+v<X)_x|=(1<<(k+v));
                            else if(k+v==X)_y|=1;
                        }
                        for(int k=0;k<Y;k++)if(y&(1<<k)){
                            if(k+v<Y)_y|=(1<<(k+v));
                            else if(k+v==Y)_z|=1;
                        }
                        for(int k=0;k<Z;k++)if(z&(1<<k)){
                            if(k+v<Z)_z|=(1<<(k+v));
                            else if(k+v==Z)_t|=1;
                        }
                        _x|=1;
                        addmod(f[i][_x][_y][_z][_t],f[i-1][x][y][z][t]);
                    }
                }
            }
        }
    }
    for(int x=0;x<(1<<X);x++){
        for(int y=0;y<(1<<Y);y++){
            for(int z=0;z<(1<<Z);z++)addmod(ans,f[n][x][y][z][1]);
        }
    }
    _write(ans);
    return 0;
}
