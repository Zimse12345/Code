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

const int Mod=1000000007;
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
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}

const int N=1e6+7;
const int INF=1000114514;

int n,x,d[N],sz,cnt[N];

struct mixtra{
	int v[128][128];
	
	void init0(){
		for(int i=1;i<=sz;i++)for(int j=1;j<=sz;j++)v[i][j]=0;
		return;
	}
	
	void init1(){
		init0();
		for(int i=1;i<=sz;i++)v[i][i]=1;
	}
	
	void see(){
		pc(10),pc(10);
		for(int i=1;i<=sz;i++){
			for(int j=1;j<=sz;j++)write_(v[i][j]);
			pc(10);
		}
		return;
	}
};

mixtra mul(mixtra x,mixtra y){
	mixtra z;
	z.init0();
	for(int i=1;i<=sz;i++)for(int j=1;j<=sz;j++){
		for(int k=1;k<=sz;k++)addmod(z.v[i][j],x.v[i][k]*y.v[k][j]);
	}
	return z;
}

signed main(){
	n=read(),x=read()+1;
	for(int i=1;i<=n;i++)d[i]=read(),++cnt[d[i]];
	int V=100;
	sz=V+1;
	mixtra a,I;
	a.init0();
	a.v[2][1]=1;
	I.v[1][1]=I.v[1][2]=1;
	for(int i=3;i<=V+1;i++)I.v[i][i-1]=1;
	for(int i=1;i<=V;i++)I.v[2][i+1]=cnt[i];
	while(x){
		if(x&1ll)a=mul(I,a);
		I=mul(I,I),x/=2;
	}
	_write(a.v[1][1]);
	return 0;
}


