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
#define M ((L+R)/2)
#define Lid (id<<1)
#define Rid (Lid|1)
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

int n,x,y,a[N],b[N],pre[N],ans;

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& _)const{return x<_.x;}
}p[N];

int mn[N*4],tag[N*4];

void build(int L,int R,int id){
	if(L==R)mn[id]=pre[L];
	else{
		build(L,M,Lid),build(M+1,R,Rid);
		mn[id]=mn[Lid];
	}
	return;
}

inline void pushdown(int id){
	if(tag[id]){
		mn[id]+=tag[id];
		tag[Lid]+=tag[id],tag[Rid]+=tag[id];
		tag[id]=0;
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)tag[id]+=x,pushdown(id);
	else update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x),mn[id]=min(mn[Lid],mn[Rid]);
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(r<L||R<l)return INF;
	if(l<=L&&r>=R)return mn[id];
	return min(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

signed main(){
	ifile("monster.in");
	ofile("monster.out");
	
	pre[0]=1;
	n=read(),x=read(),y=read();
	for(int i=1;i<=n;i++){
		int v=read();
		a[i]=(v-1)/y;
		b[i]=(v-a[i]*y-1)/x+1;
		pre[i]=a[i]+pre[i-1]+1;
		p[i]=node(b[i]+1,i);
	}
	build(1,n,1);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		int x=p[i].y;
		int t=query(1,n,1,x,n);
		if(p[i].x>t)continue;
		update(1,n,1,x,n,-p[i].x),++ans;
	}
	_write(ans);
	return 0;
}


