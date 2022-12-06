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
const int Mod=31607;
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

const int N=32;

int n,m,a[N][N],f[4000000][4][2],g[4000000][4][2];

signed main(){
	n=read(),m=(1<<n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=read()*inv(10000)%Mod;
	f[m-1][3][1]=1;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			for(int z=0,p;z<2;z++){
				p=z?a[x][y]:(1-a[x][y]);
				for(int i=0;i<m;i++){
					for(int u=0;u<4;u++){
						for(int w=0;w<2;w++)if(f[i][u][w]!=0){
							int _i=i,_u=u,_w=w;
							if(!z){
								_i&=((m-1)^(1<<y));
								if(x==y)_u&=2;
								if(x==n-y-1)_u&=1;
								_w=0;
							}
							addmod(g[_i][_u][_w],f[i][u][w]*p);
						}
					}
				}
			}
			for(int i=0;i<m;i++){
				for(int u=0;u<4;u++){
					if(y==n-1){
						f[i][u][1]=g[i][u][0];
						f[i][u][0]=g[i][u][0]=g[i][u][1]=0;
						continue;
					}
					for(int w=0;w<2;w++){
						f[i][u][w]=g[i][u][w];
						g[i][u][w]=0;
					}
				}
			}
		}
	}
	_write((1-f[0][0][1]+Mod)%Mod);
	return 0;
}


