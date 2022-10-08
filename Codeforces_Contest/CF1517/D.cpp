/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-05
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

const int Mod=998244353;//1000000007;
namespace Zimse{
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
}using namespace Zimse;

const int N=512;
const int INF=1000114514;

int n,m,k,d1[N][N],d2[N][N],f[N][N][32];

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)for(int j=1;j<m;j++)d1[i][j]=read();
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++)d2[i][j]=read();
	if(k&1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)write_(-1);
			pc(10);
		}
		return 0;
	}
	k/=2;
	for(int i=1;i<=k;i++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=m;y++){
				f[x][y][i]=INF;
				if(x>1)_min(f[x][y][i],d2[x-1][y]+f[x-1][y][i-1]);
				if(x<n)_min(f[x][y][i],d2[x][y]+f[x+1][y][i-1]);
				if(y>1)_min(f[x][y][i],d1[x][y-1]+f[x][y-1][i-1]);
				if(y<m)_min(f[x][y][i],d1[x][y]+f[x][y+1][i-1]);
				if(i==k)write_(f[x][y][i]*2);
			}
			if(i==k)pc(10);
		}
	}
	return 0;
}


