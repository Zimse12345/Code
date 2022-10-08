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

struct node{
	int a,b;
	node(int a=0,int b=0):a(a),b(b){}
	bool operator < (const node& _)const{
		if(a==_.a)return b<_.b;
		return a<_.a;
	}
}p[N];

int T,n;
char s[N],t[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s %s",s+1,t+1);
		for(int i=1;i<=n;i++){
			p[i]=node(s[i],t[n-i+1]);
			if(p[i].b<p[i].a)swap(p[i].a,p[i].b);
		}
		sort(p+1,p+n+1);
		int tag=1,c=0;
		for(int l=1,r=0;l<=n;){
			r=l;
			while(r<n&&p[r+1].a==p[r].a&&p[r+1].b==p[r].b)++r;
			if((r-l+1)&1){
				++c;
				if(p[r].a!=p[r].b)tag=0;
			}
			l=r+1;
		}
		if(c>1)tag=0;
		_ck(tag);
	}
	return 0;
}


