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

#define ll long long
#define pc putchar
#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=getchar();while(c<48||c>57){if(c==45)y=-1;c=getchar();}while(c>=48&&c<=57)x=x*10+c-48,c=getchar();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _no(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?_yes():_no();return;}
inline void _ent(){pc(10);return;}
inline void _spa(){pc(32);return;}
inline void write_(int x){write(x),_spa();return;}
inline void _write(int x){write(x),_ent();return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _abs(int x){return x<0?-x:x;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
inline void ckmax(int& x,int y){if(y>x)x=y;return;}
inline void ckmin(int& x,int y){if(y<x)x=y;return;}

const int N=1e6+7;
const int INF=1000114514;

int n,m,a[N];

struct mixtra{
	int v[3][3];
	
	void init0(){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				v[i][j]=0;
			}
		}
		return;
	}
	
	void init1(){
		init0();
		for(int i=0;i<3;i++)v[i][i]=1;
		return;
	}
	
	void see(){
		_ent();
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++)write_(v[i][j]);
			_ent();
		}
	}
};

mixtra mul(mixtra x,mixtra y){
	mixtra res;
	res.init0();
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++)addmod(res.v[i][j],x.v[i][k]*y.v[k][j]);
		}
	}
	return res;
}

mixtra mfpow(mixtra x,int k){
	mixtra res;
	res.init1();
	while(k){
		if(k&1ll)res=mul(res,x);
		x=mul(x,x),k/=2;
	}
	return res;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)a[i]=read();
	mixtra I,_I;
	I.v[0][0]=1,I.v[0][1]=0,I.v[0][2]=1;
	I.v[1][0]=2,I.v[1][1]=1,I.v[1][2]=2;
	I.v[2][0]=1,I.v[2][1]=1,I.v[2][2]=2;
	_I.v[0][0]=1,_I.v[0][1]=0,_I.v[0][2]=0;
	_I.v[1][0]=2,_I.v[1][1]=1,_I.v[1][2]=0;
	_I.v[2][0]=1,_I.v[2][1]=1,_I.v[2][2]=1;
	mixtra ans;
	ans.init0();
	ans.v[0][0]=1;
	a[0]=-1;
	for(int i=1;i<=m;i++)ans=mul(mfpow(I,a[i]-a[i-1]-1),ans),ans=mul(_I,ans);
	ans=mul(mfpow(I,n-a[m]-1),ans);
	_write(ans.v[2][0]);
	return 0;
}


