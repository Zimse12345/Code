/********************************
*FileName:
*Author: Zimse
*Data: 2022-12-
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
#define pb push_back
#define ll long long
// #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

using namespace std;

namespace Zimse{
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
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
const int INF=1000114514;
}using namespace Zimse;

const int N=200007;

int n,a[N],fa[N],x[N],f[N][32],ans[N],tot,g[N][32],cnt;
vector<int> ch[N];

void dfs(int u,int from){
	x[u]=1;
	f[u][a[u]]=1;
	for(unsigned i=0;i<ch[u].size();i++){
		int v=ch[u][i];
		dfs(v,u);
		x[u]+=x[v];
		int p[32];
		for(int j=0;j<32;j++)p[j]=0;
		for(int X=0;X<32;X++)if(f[u][X]){
			for(int Y=0;Y<32;Y++)if(f[v][Y])p[X^Y]=1;
		}
		for(int j=0;j<32;j++)f[u][j]=p[j];
	}
	if(x[u]%2==0)f[u][0]=1;
	return;
}

void dfs2(int u,int from,int nd){
	if(nd==0&&x[u]%2==0){
		ans[++tot]=u,ans[++tot]=u;
		return;
	}
	for(int i=0;i<32;i++)f[u][i]=0;
	f[u][a[u]]=1;
	vector<int> s;
	for(unsigned i=0;i<ch[u].size();i++){
		int v=ch[u][i];
		if(v==from)continue;
		++cnt;
		s.pb(cnt);
		int p[32];
		for(int j=0;j<32;j++)p[j]=0;
		for(int X=0;X<32;X++)if(f[u][X]){
			for(int Y=0;Y<32;Y++)if(f[v][Y])p[X^Y]=1,g[cnt][X^Y]=Y;
		}
		for(int j=0;j<32;j++)f[u][j]=p[j];
	}
	int id=s.size()-1;
	for(int i=int(ch[u].size());i>=1;i--){
		int v=ch[u][i-1];
		if(v==from)continue;
		dfs2(v,u,g[s[id]][nd]);
		nd^=g[s[id]][nd],--id;
	}
	return;
}

signed main(){
	n=read();int xo=0;
	for(int i=1;i<=n;i++)a[i]=read(),xo^=a[i];
	for(int i=2;i<=n;i++)fa[i]=read(),ch[fa[i]].push_back(i);
	dfs(1,0);
	if(!f[1][0]){
		printf("-1\n");
		return 0;
	}
	dfs2(1,0,0);
	if(tot<n*2)ans[++tot]=1,ans[++tot]=1;
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)printf("%d ",ans[i]);
	pc(10);
    return 0;
}


