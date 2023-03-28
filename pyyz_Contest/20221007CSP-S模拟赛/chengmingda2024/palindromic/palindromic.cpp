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

const int N=1e6+7,B1=43,B2=47;

int T,n,h1[N],h2[N],p1[N],p2[N];
char s[N];

int gh1(int l,int r){
	return (h1[r]-h1[l-1]*p1[r-l+1]%Mod+Mod)%Mod;
}

int gh2(int l,int r){
	return (h2[r]-h2[l-1]*p2[r-l+1]%Mod+Mod)%Mod;
}

signed main(){
	ifile("palindromic.in");
	ofile("palindromic.out");
	
	p1[0]=p2[0]=1;
	for(int i=1;i<N;i++)p1[i]=p1[i-1]*B1%Mod,p2[i]=p2[i-1]*B2%Mod;
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++){
			h1[i]=(h1[i-1]*B1+s[i]-'a')%Mod;
			h2[i]=(h2[i-1]*B2+s[i]-'a')%Mod;
		}
		int l=1,r=n,ans=0;
		while(l<=r){
			int d=0;
			while(l+d<r-d&&(!(gh1(l,l+d)==gh1(r-d,r)&&gh2(l,l+d)==gh2(r-d,r))))++d;
			if(l+d<r-d)ans+=2;
			else ans+=1;
			l+=d+1,r-=d+1;
		}
		_write(ans);
	}
	return 0;
}


