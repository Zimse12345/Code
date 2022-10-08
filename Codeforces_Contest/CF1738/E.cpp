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
#define int long long
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

const int N=1e6+7;

int T,n,a[N],fac[N];

int C(int x,int y){
	return fac[x]*inv(fac[y])%Mod*inv(fac[x-y])%Mod;
}

int sol(int L,int R){
//	printf("[%d %d]\n",L,R);
//	int _L=L,_R=R;
	if(R<=L)return 1;
	if(a[L]&&a[R]){
		int x=a[L],y=a[R];
		while(x!=y&&L+1<R){
			if(x<y)x+=a[++L];
			else y+=a[--R];
		}
		if(x==y){
			++L,--R;
			if(L<=R){
//				printf("(%d %d)\n",L,R);
				if(a[L]==0&&a[R]){
					int cnt=0;
					while(a[L]==0)++L,++cnt;
					return (sol(L,R)*(cnt+2))%Mod;
				}
				if(a[R]==0&&a[L]){
					int cnt=0;
					while(a[R]==0)--R,++cnt;
					return (sol(L,R)*(cnt+2))%Mod;
				}
				int lc=0,rc=0;
				while(a[L]==0&&L<=R)++lc,++L;
				while(a[R]==0&&L<=R)++rc,--R;
				if(R<L){
					return fpow(2,lc+rc+1);
				}
				int Cnt=0;
				++lc,++rc;
				for(int i=0;i<=min(lc,rc);i++){
					addmod(Cnt,C(lc,i)*C(rc,i));
				}
				return (Cnt*sol(L,R))%Mod;
			}
			return 2;
		}
		return 1;
	}
	if(a[L]==0&&a[R]){
		while(a[L]==0)++L;
		return sol(L,R);
	}
	if(a[R]==0&&a[L]){
		while(a[R]==0)--R;
		return sol(L,R);
	}
	int lc=0,rc=0;
	while(a[L]==0&&L<=R)++lc,++L;
	while(a[R]==0&&L<=R)++rc,--R;
	if(R<L){
		int k=lc+rc-1;
//		printf("(%d %d %d)\n",lc,rc,k);
		return fpow(2,k);
	}
	int Cnt=0;
	for(int i=0;i<=min(lc,rc);i++){
		addmod(Cnt,C(lc,i)*C(rc,i));
	}
	return Cnt*sol(L,R)%Mod;
}

signed main(){
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod;
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		_write(sol(1,n));
	}
	return 0;
}


