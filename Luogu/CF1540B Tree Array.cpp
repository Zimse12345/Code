/********************************
*FileName:
*Author: Zimse-09-19
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
//const int Mod=998244353;
const int Mod=1000000007;
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

const int N=512;

int n,hd[N],nxt[N],to[N],ec,ans,lca[N][N],dep[N],f[N][N];

void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

void dfs(int u,int from){
	dep[u]=dep[from]+1;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u); 
	}
	return;
}

void getlca(int u,int from,int s,int k){
	lca[s][u]=k;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		getlca(v,u,s,dep[v]<dep[u]?v:k);
	}
	return;
}

signed main(){
	n=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	int inv2=inv(2);
	for(int i=1;i<=n;i++){
		f[i][0]=1;
		for(int j=1;j<=n;j++)f[i][j]=(f[i-1][j]+f[i][j-1])*inv2%Mod;
	}
	for(int i=1;i<=n;i++){
		dfs(i,0);
		for(int j=1;j<=n;j++)getlca(j,0,j,j);
		for(int x=1;x<=n;x++){
			for(int y=1;y<x;y++){
				int dx=dep[x]-dep[lca[x][y]],dy=dep[y]-dep[lca[x][y]];
				addmod(ans,f[dy][dx]);
			}
		}
	}
	ans=ans*inv(n)%Mod;
	_write(ans);
	return 0;
}


