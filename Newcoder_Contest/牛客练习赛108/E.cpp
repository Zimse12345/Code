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
 #define int long long
 #define M ((L+R)/2)
 #define Lid (id<<1)
 #define Rid (Lid|1)
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

const int N=400007;

int n,m,ans[N],tot,fa[N],cnt[N];
map<int,int> mp;
vector<int> e[N*4];

struct node{
	int *p,v;
	node(int *p=NULL,int v=0):p(p),v(v){}
}re[N];
int t;

void Add(int id,int L,int R,int l,int r,int h){
	if(l<=L&&r>=R)e[id].pb(h);
	else if(r<L||R<l)return;
	else Add(Lid,L,M,l,r,h),Add(Rid,M+1,R,l,r,h);
	return;
}

int F(int x){
	if(fa[x]==x)return x;
	return F(fa[x]);
}

bool link(int h){
	int u=h/N,v=h%N;
	u=F(u),v=F(v);
	if(u==v)return false;
	if(cnt[u]<cnt[v])swap(u,v);
	re[++t]=node(&fa[v],fa[v]);
	re[++t]=node(&cnt[u],cnt[u]);
	fa[v]=u,cnt[u]+=cnt[v];
	return true;
}

void sol(int id,int L,int R){
	int pt=t;
	re[++t]=node(&tot,tot);
	for(unsigned i=0;i<e[id].size();i++){
		if(!link(e[id][i]))++tot;
	}
	if(L==R)ans[L]=fpow(2,tot)-1;
	else sol(Lid,L,M),sol(Rid,M+1,R);
	while(t>pt)*re[t].p=re[t].v,--t;
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		int h=u*N+v;
		if(!mp.count(h)||mp[h]==0)mp[h]=i;
		else Add(1,1,m,mp[h],i-1,h),mp[h]=0;
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)if(it->second!=0){
		Add(1,1,m,it->second,m,it->first);
	}
	for(int i=1;i<=n;i++)fa[i]=i,cnt[i]=1;
	sol(1,1,m);
	for(int i=1;i<=m;i++)_write(ans[i]);
    return 0;
}


