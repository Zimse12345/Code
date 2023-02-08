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
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000000000000114514;
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

const int N=10010;

int n,m,t;
int f[N][N],val[N],_L[N],_R[N],_U[N],_D[N],vis[N],tag[N],sz[N],len,g[N];
vector<int> ch[N];

int id(int x,int y){
	return x*(m+1)+y;
}

void link(int u,int v){
	ch[u].pb(v);
	tag[u]|=tag[v];
	return;
}

void dfs(int x,int y){
	int u=id(x,y);
	vis[u]=1;
	if(!_L[u]&&!vis[id(x,y-1)])dfs(x,y-1),link(u,id(x,y-1));
	if(!_R[u]&&!vis[id(x,y+1)])dfs(x,y+1),link(u,id(x,y+1));
	if(!_U[u]&&!vis[id(x-1,y)])dfs(x-1,y),link(u,id(x-1,y));
	if(!_D[u]&&!vis[id(x+1,y)])dfs(x+1,y),link(u,id(x+1,y));
//	printf("(%lld %lld %lld)\n",x,y,tag[id(x,y)]);
	return;
}

void dp(int u){
	f[u][1]=val[u],sz[u]=1;
	if(tag[u])f[u][0]=-INF,++len;
	for(unsigned i=0;i<ch[u].size();i++){
		int v=ch[u][i];
		dp(v);
		for(int x=0;x<=sz[u]+sz[v];x++)g[x]=-INF;
		for(int x=0;x<=sz[u];x++){
			for(int y=0;y<=sz[v];y++){
				if(x==0&&y>0)continue;
				_max(g[x+y],f[u][x]+f[v][y]);
			}
		}
		sz[u]+=sz[v];
		for(int x=0;x<=sz[u];x++)f[u][x]=g[x];
	}
	return;
}

signed main(){
	n=read(),m=read(),t=read();
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			val[id(i,j)]=read();
			if(i==0)_U[id(i,j)]=1;
			if(i==n)_D[id(i,j)]=1;
			if(j==0)_L[id(i,j)]=1;
			if(j==m)_R[id(i,j)]=1;
		}
	}
	for(int i=1;i<=n*m;i++){
		int p=read(),q=read(),x=read(),y=read();
		if(y==q-1)_L[id(p,q)]=_R[id(x,y)]=1;
		if(y==q+1)_R[id(p,q)]=_L[id(x,y)]=1;
		if(x==p-1)_U[id(p,q)]=_D[id(x,y)]=1;
		if(x==p+1)_D[id(p,q)]=_U[id(x,y)]=1;
	}
	tag[id(n,m)]=1;
	dfs(0,0);
	dp(0);
	int p=min((n+1)*(m+1),(t-len+1)/2+len);
	_write(f[0][p]);
//	printf("len=%lld\n",len);
//	for(int i=0;i<=sz[0];i++)printf("f[%lld]=%lld\n",i,f[0][i]);
    return 0;
}


