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
#define yes printf("Yes\n")
#define no printf("No\n")
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
inline void _ck(bool x){x?yes:no;return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int fpow(int x,int y=Mod-2){int res=1;while(y)
{if(y&1)res=1ll*res*x%Mod;x=1ll*x*x%Mod,y/=2;}return res;}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=400007;

int n,q,a[N],to[N][20],pos[20];

signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		for(int j=0;j<20;j++){
			if(a[i]&(1<<j))to[i][j]=i;
			else to[i][j]=n+1;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<20;j++)if(pos[j]&&to[i][j]<=pos[j]){
			for(int k=0;k<20;k++)_min(to[i][k],to[pos[j]][k]);
		}
		for(int j=0;j<20;j++)if(a[i]&(1<<j))pos[j]=i;
	}
	while(q--){
		int x=read(),y=read(),ans=0;
		for(int i=0;i<20;i++)if(a[y]&(1<<i)){
			if(to[x][i]<=y)ans=1;
		}
		if(ans)printf("Shi\n");
		else printf("Fou\n");
	}
    return 0;
}


