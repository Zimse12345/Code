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
#define ll long long
// #define int long long
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
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=1000007;

int T,n,u[N],v[N],from[N],to[N],del[N];

struct node{
	int l,r,ty,id;
	node(int l=0,int r=0,int ty=0,int id=0):l(l),r(r),ty(ty),id(id){}
	bool operator < (const node& _)const{return r<_.r;}
};

node a[N];
int tot,stk[N],top;

int sol(int tag){
	int res=0;
	tot=0;
	for(int i=1;i<=n;i++)if(del[i]==0){
		if(tag==1&&u[i]==1)a[++tot]=node(from[i],to[i],v[i],i);
		if(tag==2&&v[i]==2)a[++tot]=node(from[i],to[i],u[i]^3,i);
	}
	sort(a+1,a+tot+1);
	top=0;
	for(int i=1;i<=tot;i++){
		int l=a[i].l;
		while(top&&l<=from[stk[top]]){
			if(u[stk[top]]!=v[stk[top]]){
				if(tag==1)++u[stk[top]];
				else --v[stk[top]];
			}
			else del[stk[top]]=1;
			--top;
		}
		if(top&&u[stk[top]]==v[stk[top]]&&a[i].ty==2){
			_min(to[stk[top]],l-1);
		}
		if(top)_max(from[a[i].id],to[stk[top]]+1);
		stk[++top]=a[i].id;
	}
	return res;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			del[i]=0;
			u[i]=read(),from[i]=read(),v[i]=read(),to[i]=read();
		}
		sol(1);
		sol(2);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(del[i])u[i]=from[i]=v[i]=to[i]=0;
			else ans+=(v[i]-u[i]+1)*(to[i]-from[i]+1);
		}
		_write(ans);
		for(int i=1;i<=n;i++){
			printf("%d %d %d %d\n",u[i],from[i],v[i],to[i]);
		}
	}
    return 0;
}


