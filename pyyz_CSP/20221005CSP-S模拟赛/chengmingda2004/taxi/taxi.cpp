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
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
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
const int INF=1000000000000114514;
}using namespace Zimse;

const int N=1e6+7;

int T,n,m,hd[N],nxt[N],to[N],len[N],ec;
int A,B,t[N],c[N],dis[N],vis[N],D[2000][2000];

struct node{
	int pos,d;
	node(int pos=0,int d=0):pos(pos),d(d){}
	bool operator < (const node& _)const{return d>_.d;}
};
priority_queue<node> q;

inline void add(int u,int v,int w){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v,len[ec]=w;
	return;
}

void dij(int S){
	for(int i=1;i<=n;i++)D[S][i]=INF,vis[i]=0;
	D[S][S]=0,q.push(node(S,0));
	while(!q.empty()){
		int u=q.top().pos;
		q.pop();
		if(vis[u]++)continue;
		for(int i=hd[u],v;i;i=nxt[i]){
			v=to[i];
			if(D[S][u]+len[i]<D[S][v]){
				D[S][v]=D[S][u]+len[i];
				q.push(node(v,D[S][v]));
			}
		}
	}
	return;
}

signed main(){
	ifile("taxi.in");
	ofile("taxi.out");
	
	T=read();
	while(T--){
		n=read(),m=read();
		A=read(),B=read();
		while(m--){
			int u=read(),v=read(),w=read();
			add(u,v,w),add(v,u,w);
		}
		for(int i=1;i<=n;i++)dij(i);
		for(int i=1;i<=n;i++)t[i]=read(),c[i]=read(),dis[i]=INF,vis[i]=0;
		dis[B]=0,q.push(node(B,0));
		while(!q.empty()){
			int v=q.top().pos;
			q.pop();
			if(vis[v]++)continue;
			for(int u=1;u<=n;u++){
				if(D[u][v]<=t[u]&&dis[v]+c[u]<dis[u]){
					dis[u]=dis[v]+c[u];
					q.push(node(u,dis[u]));
				}
			}
		}
		if(dis[A]>=INF)dis[A]=-1;
		_write(dis[A]);
		for(int i=1;i<=ec;i++)hd[i]=nxt[i]=to[i]=0;
		for(int i=1;i<=n;i++)hd[i]=0;
		ec=0;
	}
	return 0;
}


