/************************
*FileName:
*Author: Zimse
*Data: 2023-01-
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
 #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
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

const int N=2048;

int n,m,f[N][N],g[N][N],h[N][N];
char str[N][N];

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",str[i]+1);
	}
	f[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i+1<=n){
				if(str[i][j]=='Y'&&str[i+1][j]=='Y'){
					addmod(f[i+1][j],f[i][j]);
					addmod(g[i+1][j],g[i][j]+f[i][j]);
					addmod(h[i+1][j],h[i][j]+2*g[i][j]+f[i][j]);
				}
				else{
					addmod(f[i+1][j],f[i][j]);
					addmod(g[i+1][j],g[i][j]);
					addmod(h[i+1][j],h[i][j]);
				}
			}
			if(j+1<=m){
				if(str[i][j]=='Y'&&str[i][j+1]=='Y'){
					addmod(f[i][j+1],f[i][j]);
					addmod(g[i][j+1],g[i][j]+f[i][j]);
					addmod(h[i][j+1],h[i][j]+2*g[i][j]+f[i][j]);
				}
				else{
					addmod(f[i][j+1],f[i][j]);
					addmod(g[i][j+1],g[i][j]);
					addmod(h[i][j+1],h[i][j]);
				}
			}
		}
	}
	_write(h[n][m]);
    return 0;
}


