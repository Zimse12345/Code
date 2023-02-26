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

int T,n,m,col[N],dis[2048][2048],vis[2048][2048];
vector<int> g[N];

struct node{
	int x,y,d;
	node(int x=0,int y=0,int d=0):x(x),y(y),d(d){}
	bool operator < (const node& _)const{return d>_.d;}
};
priority_queue<node> q;

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++)col[i]=read();
		for(int i=1,u,v;i<=m;i++)u=read(),v=read(),g[u].pb(v),g[v].pb(u);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dis[i][j]=INF,vis[i][j]=0;
		}
		q.push(node(1,n,0)),dis[1][n]=0;
		while(!q.empty()){
			int x=q.top().x,y=q.top().y;
			q.pop();
			if(vis[x][y]++)continue;
			for(unsigned i=0;i<g[x].size();i++){
				for(unsigned j=0;j<g[y].size();j++){
					if(col[g[x][i]]!=col[g[y][j]]){
						if(dis[x][y]+1<dis[g[x][i]][g[y][j]]){
							dis[g[x][i]][g[y][j]]=dis[x][y]+1;
							q.push(node(g[x][i],g[y][j],dis[x][y]+1));
						}
					}
				}
			}
		}
		if(dis[n][1]==INF)dis[n][1]=-1;
		_write(dis[n][1]);
		for(int i=1;i<=n;i++)g[i].resize(0);
	}
    return 0;
}


