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
//const int Mod=998244353;
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
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=1e6+7;

struct mixtra{
	int v[8][8];
	
	void init_0(){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				v[i][j]=0;
			}
		}
		return;
	}
	
	void init_e(){
		init_0();
		for(int i=0;i<8;i++)v[i][i]=1;
		return;
	}
};

int n,f1,f2,f3,c,sz;

mixtra mul(mixtra x,mixtra y){
	mixtra z;
	z.init_0();
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
			for(int k=0;k<sz;k++)(z.v[i][j]+=x.v[i][k]*y.v[k][j])%=(Mod-1);
		}
	}
	return z;
}

mixtra mpow(mixtra x,int k){
	mixtra res;
	res.init_e();
	while(k){
		if(k&1ll)res=mul(res,x);
		x=mul(x,x),k/=2;
	}
	return res;
}

signed main(){
	sz=3;
	n=read(),f1=read(),f2=read(),f3=read(),c=read();
	mixtra a;
	a.init_0();
	a.v[0][0]=a.v[0][1]=a.v[0][2]=a.v[1][0]=a.v[2][1]=1;
	a=mpow(a,n-3);
	int A=a.v[0][2];
	int B=a.v[0][1];
	int C=a.v[0][0];
	int ans=fpow(f1,A)*fpow(f2,B)%Mod*fpow(f3,C)%Mod;
	pc(10);
	sz=5;
	a.init_0();
	a.v[0][0]=a.v[0][1]=a.v[0][2]=a.v[0][3]=a.v[1][0]=a.v[2][1]=a.v[3][3]=a.v[4][4]=1,a.v[3][4]=2;
	a=mpow(a,n-2);
	mixtra b;
	b.init_0();
	b.v[4][0]=1;
	b=mul(a,b);
	ans=ans*fpow(c,b.v[0][0])%Mod;
	_write(ans);
	return 0;
}


