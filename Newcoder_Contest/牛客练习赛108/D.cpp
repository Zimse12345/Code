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

int T,n,m,vis[N],ans[N],p[N],q[N],Tag,X;

struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){}
};
vector<edge> g[N];
vector<int> s;

void dfs(int u){
	vis[u]=1;
	s.pb(u);
	for(unsigned i=0;i<g[u].size();i++){
		int v=g[u][i].to;
		if(vis[v]){
			if(q[u]!=q[v]){
				if(p[u]+p[v]!=g[u][i].w)Tag=-1;
			}
			else{
				int _x=q[u]*(g[u][i].w-p[u]-p[v]);
				if(_x%2!=0)Tag=-1;
				else{
					_x/=2;
					if(Tag==0)Tag=1,X=_x;
					else if(_x!=X)Tag=-1;
				}
			}
		}
		else p[v]=g[u][i].w-p[u],q[v]=-q[u],dfs(v);
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1,x,y,z;i<=m;i++){
			x=read(),y=read(),z=read();
			g[x].pb(edge(y,z));
			g[y].pb(edge(x,z));
		}
		for(int i=1;i<=n;i++)if(!vis[i]){
			Tag=0,s.resize(0);
			p[i]=0,q[i]=1,dfs(i);
			for(unsigned j=0;j<s.size();j++)ans[s[j]]=p[s[j]]+q[s[j]]*X;
			if(Tag==-1)break;
		}
		if(Tag==-1)_write(-1);
		else{
			for(int i=1;i<=n;i++)write_(ans[i]);
			pc(10);
		}
		for(int i=1;i<=n;i++)g[i].resize(0),vis[i]=0;
	}
    return 0;
}


