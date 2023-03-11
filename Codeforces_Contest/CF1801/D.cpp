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

const int N=1000007;

int T,n,m,p,w[N],hd[N],nxt[N],to[N],len[N],ec;
int dis[1000][1000],vis[N],f[N],g[N];

inline void add(int u,int v,int w){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
	return;
}

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& _)const{return y>_.y;}
};
priority_queue<node> q;

struct nd{
	int x,y,z;
	nd(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
	bool operator < (const nd& _)const{
		if(y==_.y)return z<_.z;
		return y>_.y;
	}
};
priority_queue<nd> Q;

void dij(int s){
	for(int i=1;i<=n;i++)dis[s][i]=INF,vis[i]=0;
	dis[s][s]=0,q.push(node(s,0));
	while(!q.empty()){
		int u=q.top().x;
		q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(dis[s][u]+len[i]<dis[s][v]){
				dis[s][v]=dis[s][u]+len[i];
				q.push(node(v,dis[s][v]));
			}
		}
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read(),p=read();
		for(int i=1;i<=n;i++)w[i]=read();
		for(int i=1,u,v,w;i<=m;i++){
			u=read(),v=read(),w=read();
			add(u,v,w);
		}
		for(int i=1;i<=n;i++)dij(i);
		for(int i=1;i<=n;i++)f[i]=INF;
		f[1]=0,g[1]=p;
		Q.push(nd(1,0,p));
		for(int i=1;i<=n;i++)vis[i]=0;
		while(!Q.empty()){
			int u=Q.top().x;
			Q.pop();
			if(vis[u]++)continue;
			for(int v=1;v<=n;v++)if(dis[u][v]<INF){
				int d=0;
				if(g[u]<dis[u][v])d=(dis[u][v]-g[u]-1)/w[u]+1;
				if(f[u]+d<f[v]||(f[u]+d==f[v]&&g[u]+d*w[u]-dis[u][v]>g[v])){
					f[v]=f[u]+d,g[v]=g[u]+d*w[u]-dis[u][v];
					Q.push(nd(v,f[v],g[v]));
				}
			}
		}
		if(f[n]>=INF)f[n]=-1;
		_write(f[n]);
		ec=0;
		for(int i=1;i<=n;i++)hd[i]=0;
	}
    return 0;
}


