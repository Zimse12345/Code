/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-21
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
#define ll long long
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
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
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=512;

int n,k,a[N][N],t[N*N],cnt,lx[N*N],ly[N*N],rx[N*N],ry[N*N],p[N][N];

signed main(){
    n=read(),k=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=read();
            int v=a[i][j];
            if(!t[v])t[v]=1,++cnt,lx[v]=rx[v]=i,ly[v]=ry[v]=j;
            _min(lx[v],i),_max(rx[v],i);
            _min(ly[v],j),_max(ry[v],j);
        }
    }
    if(k>=cnt){
        _write(k-cnt);
        return 0;
    }
    for(int d=1;d<=n;d++){
        for(int i=1;i<=n*n;i++)if(t[i]){
            int X1=max(1,rx[i]-d+1),Y1=max(1,ry[i]-d+1);
            int X2=min(n-d+1,lx[i]),Y2=min(n-d+1,ly[i]);
            if(X1<=X2&&Y1<=Y2){
                ++p[X1][Y1];
                --p[X2+1][Y1];
                --p[X1][Y2+1];
                ++p[X2+1][Y2+1];
            }
        }
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++){
                p[x][y]+=-p[x-1][y-1]+p[x-1][y]+p[x][y-1];
                if(cnt-p[x][y]==k||cnt-p[x][y]==k-1){
                    _write(1);
                    return 0;
                }
            }
        }
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++){
                p[x][y]=0;
            }
        }
    }
    _write(2);
	return 0;
}
