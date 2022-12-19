/********************************
*FileName:
*Author: Zimse
*Data: 2022-12-
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
inline void addmod(int& x,int y){(x+=y);return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1000007;

int n,a[N],f[N][16],ans;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			addmod(ans,i*(n-i+1)); 
			for(int j=0;j<16;j++)f[i][j]=f[i-1][j];
			for(int j=1;j<16;j++){
				int x=f[i][j];
				if(j>=10)x*=3;
				else if(j>=4)x*=2;
				addmod(ans,x);
			}
			++f[i][0];
			continue;
		}
		for(int j=0;j<16;j++)f[i][j]=0;
		++f[i][a[i]];
		if(a[i]==1){
			addmod(f[i][1],f[i-1][0]);
			addmod(f[i][1],f[i-1][1]);
			addmod(f[i][5],f[i-1][2]);
			addmod(f[i][1],f[i-1][3]);
			addmod(f[i][4],f[i-1][4]);
			addmod(f[i][5],f[i-1][5]);
			addmod(f[i][8],f[i-1][6]);
			addmod(f[i][4],f[i-1][7]);
			addmod(f[i][8],f[i-1][8]);
			addmod(f[i][11],f[i-1][9]);
			addmod(f[i][10],f[i-1][10]);
			addmod(f[i][11],f[i-1][11]);
			addmod(f[i][10],f[i-1][12]);
			addmod(f[i][15],f[i-1][13]);
			addmod(f[i][14],f[i-1][14]);
			addmod(f[i][15],f[i-1][15]);
		}
		if(a[i]==2){
			addmod(f[i][2],f[i-1][0]);
			addmod(f[i][4],f[i-1][1]);
			addmod(f[i][2],f[i-1][2]);
			addmod(f[i][2],f[i-1][3]);
			addmod(f[i][4],f[i-1][4]);
			addmod(f[i][5],f[i-1][5]);
			addmod(f[i][5],f[i-1][6]);
			addmod(f[i][9],f[i-1][7]);
			addmod(f[i][10],f[i-1][8]);
			addmod(f[i][9],f[i-1][9]);
			addmod(f[i][10],f[i-1][10]);
			addmod(f[i][11],f[i-1][11]);
			addmod(f[i][14],f[i-1][12]);
			addmod(f[i][11],f[i-1][13]);
			addmod(f[i][14],f[i-1][14]);
			addmod(f[i][15],f[i-1][15]);
		}
		if(a[i]==3){
			addmod(f[i][3],f[i-1][0]);
			addmod(f[i][3],f[i-1][1]);
			addmod(f[i][3],f[i-1][2]);
			addmod(f[i][3],f[i-1][3]);
			addmod(f[i][7],f[i-1][4]);
			addmod(f[i][6],f[i-1][5]);
			addmod(f[i][6],f[i-1][6]);
			addmod(f[i][7],f[i-1][7]);
			addmod(f[i][6],f[i-1][8]);
			addmod(f[i][7],f[i-1][9]);
			addmod(f[i][12],f[i-1][10]);
			addmod(f[i][13],f[i-1][11]);
			addmod(f[i][12],f[i-1][12]);
			addmod(f[i][13],f[i-1][13]);
			addmod(f[i][12],f[i-1][14]);
			addmod(f[i][13],f[i-1][15]);
		}
		for(int j=1;j<16;j++){
			int x=f[i][j];
			if(j>=10)x*=3;
			else if(j>=4)x*=2;
			addmod(ans,x);
		}
	} 
	
	_write(ans); 
    return 0;
}


