/************************
*FileName:
*Author: Zimse
*Data: 2023-01-
*Description:
************************/

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
//#define ll long long
 #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
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
//inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
//inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int n,pa[N],pb[N],a[N],b[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),pa[a[i]]=i;
	for(int i=1;i<=n;i++)b[i]=read(),pb[b[i]]=i;
	int l1=INF,r1=-INF,l2=INF,r2=-INF,ans=0;
	ans=(min(pa[1],pb[1])-1)*min(pa[1],pb[1])/2;
	ans+=(1+(n-max(pa[1],pb[1])))*(n-max(pa[1],pb[1]))/2;
	int md=(max(pa[1],pb[1])-min(pa[1],pb[1])-1);
	if(md>0)ans+=(1+md)*md/2;
	for(int i=1;i<=n;i++){
		_min(l1,pa[i]),_max(r1,pa[i]);
		_min(l2,pb[i]),_max(r2,pb[i]);
		int ll=1,L=min(l1,l2),R=max(r1,r2),rr=n;
		if(pa[i+1]<L)_max(ll,pa[i+1]+1);
		if(pb[i+1]<L)_max(ll,pb[i+1]+1);
		if(pa[i+1]>R)_min(rr,pa[i+1]-1);
		if(pb[i+1]>R)_min(rr,pb[i+1]-1);
		if(pa[i+1]>=L&&pa[i+1]<=R)continue;
		if(pb[i+1]>=L&&pb[i+1]<=R)continue;
		ans+=max(0ll,L-ll+1)*max(0ll,rr-R+1);
//		printf("(%d %d %d %d)\n",ll,L,R,rr);
	}
	_write(ans);
    return 0;
}


