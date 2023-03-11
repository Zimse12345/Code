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
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

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

int n,deg[N],Tag,cnt[N],f[N],F[N];
vector<int> g[N];

void dfs(int u,int from){
	if(deg[u]>2)cnt[u]=1;
	for(unsigned i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==from)continue;
		dfs(v,u),cnt[u]+=cnt[v];
	}
	return;
}

void dfs2(int u,int from){
	for(unsigned i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==from)continue;
		if(cnt[v]==0||(cnt[v]==1&&deg[v]==3))continue;
		dfs2(v,u),++f[u],F[u]|=F[v];
	}
	if(f[u]>1)F[u]=1;
	return;
}

void dfs3(int u,int from){
	if(f[u]<=1&&F[u]==0)Tag=1;
	int k=0;
	for(unsigned i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==from)continue;
		k+=F[v];
	}
	if(from){
		if(!(cnt[1]-cnt[u]==0||(cnt[1]-cnt[u]==1&&deg[from]==3)))++f[u];
	}
	if(!k&&f[u]<=2)Tag=1;
	for(unsigned i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==from)continue;
		if(!(cnt[v]==0||(cnt[v]==1&&deg[v]==3)))--f[u];
		k-=F[v];
		if(f[u]<=1&&!k)dfs3(v,u);
		if(!(cnt[v]==0||(cnt[v]==1&&deg[v]==3)))++f[u];
		k+=F[v];
	}
	return;
}

signed main(){
	n=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		++deg[u],++deg[v];
		g[u].pb(v),g[v].pb(u);
	}
	dfs(1,0);
	dfs2(1,0);
	dfs3(1,0);
	_ck(Tag);
    return 0;
}


