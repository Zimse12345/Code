/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
 #define int long long
 #define M ((L+R)/2)
 #define Lid (id<<1)
 #define Rid (Lid|1)

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
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

int n,B,q,a[N];
int mx[N*4],ad[N*4];

void pushdown(int id){
	if(ad[id]==0)return;
	mx[id]+=ad[id];
	if(Rid<N*4)ad[Lid]+=ad[id],ad[Rid]+=ad[id];
	ad[id]=0;
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&r>=R)ad[id]+=x,pushdown(id);
	else if(r<L||R<l)return;
	else update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x),mx[id]=max(mx[Lid],mx[Rid]);
	return;
}

int findL(int L,int R,int id){
	pushdown(id);
	if(mx[id]<0)return 0;
	if(L==R)return L;
	int l=findL(L,M,Lid);
	return l?l:findL(M+1,R,Rid);
}

int query(int L,int R,int id,int x){
	pushdown(id);
	if(L==R)return mx[id];
	if(x<=M)return query(L,M,Lid,x);
	return query(M+1,R,Rid,x);
}

signed main(){
	n=read(),B=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read(),update(1,n,1,i,n,a[i]-B);
	while(q--){
		int x=read(),y=read();
		update(1,n,1,x,n,y-a[x]),a[x]=y;
		int p=findL(1,n,1);
		if(!p)p=n;
		double s=query(1,n,1,p);
		printf("%.9lf\n",s/double(p)+B);
	}
    return 0;
}


