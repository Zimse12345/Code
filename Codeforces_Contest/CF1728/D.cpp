/********************************
*FileName:
*Author: Zimse
*Data:
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

const int N=2048;
const int INF=1000114514;

int T,n,f[N][N];
char s[N];

void dp(int L,int R){
	if(f[L][R])return;
	if(R<L){
		f[L][R]=2;
		return;
	}
	dp(L+1,R-1),dp(L+2,R),dp(L,R-2);
	f[L][R]=3;
	if((f[L+1][R-1]==1||(f[L+1][R-1]==2&&s[R]>=s[L]))&&(f[L+2][R]==1||(f[L+2][R]==2&&s[L+1]>=s[L])))f[L][R]=2;
	if((f[L+1][R-1]==1||(f[L+1][R-1]==2&&s[R]>s[L]))&&(f[L+2][R]==1||(f[L+2][R]==2&&s[L+1]>s[L])))f[L][R]=1;
	if((f[L+1][R-1]==1||(f[L+1][R-1]==2&&s[L]>=s[R]))&&(f[L][R-2]==1||(f[L][R-2]==2&&s[R-1]>=s[R])))f[L][R]=min(f[L][R],2);
	if((f[L+1][R-1]==1||(f[L+1][R-1]==2&&s[L]>s[R]))&&(f[L][R-2]==1||(f[L][R-2]==2&&s[R-1]>s[R])))f[L][R]=1;
	return;
}

signed main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=0;
		dp(1,n);
		if(f[1][n]==1)printf("Alice\n");
		if(f[1][n]==2)printf("Draw\n");
		if(f[1][n]==3)printf("Bob\n");
	}
	return 0;
}


