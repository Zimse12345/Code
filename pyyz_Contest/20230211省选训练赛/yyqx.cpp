/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
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

const int N=2e5+7,INF=1000000000000;
int n,m,k,a[N];
int vis[N],ins[N],dis1[N],c1[N],dis2[N],c2[N],tag[N];
struct edge{
	int to,w;
	edge(int to=0,int w=0):to(to),w(w){};
};
vector<edge> g[N];

queue<int> q;
void spfa(){
	for(int i=1;i<=n;i++)if(tag[i])dis1[i]=0,c1[i]=i,q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop(),++vis[u],ins[u]=0;
		for(int i=0,v,w;i<signed(g[u].size());i++){
			v=g[u][i].to,w=g[u][i].w;
			int Tag=0;
			if(c1[u]){
			if(dis1[u]+w<dis1[v]||!c1[v]){
				if(c1[u]==c1[v])dis1[v]=dis1[u]+w;
				else dis2[v]=dis1[v],c2[v]=c1[v],dis1[v]=dis1[u]+w,c1[v]=c1[u];
				Tag=1;
			}
			else if(dis1[u]+w<dis2[v]||!c2[v])if(c1[u]!=c1[v]){
				dis2[v]=dis1[u]+w,c2[v]=c1[u];
				Tag=1;
			}
			}
			if(c2[u]){
			if(dis2[u]+w<dis1[v]||!c1[v]){
				if(c2[u]==c1[v])dis1[v]=dis2[u]+w;
				else dis2[v]=dis1[v],c2[v]=c1[v],dis1[v]=dis2[u]+w,c1[v]=c2[u];
				Tag=1;
			}
			else if(dis2[u]+w<dis2[v]||!c2[v])if(c2[u]!=c1[v]){
				dis2[v]=dis2[u]+w,c2[v]=c2[u];
				Tag=1;
			}
			}
			if(Tag){
				if(!ins[v])q.push(v),ins[v]=1;
			}
		}
	}
	return;
}

signed main(){
	// ifile("yyqx.in");
	// ofile("yyqx.out");
	
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		g[u].push_back(edge(v,w));
		g[v].push_back(edge(u,w));
	}
    for(int i=1;i<=k;i++)a[i]=read(),tag[a[i]]=1;
	spfa();
    for(int i=1;i<=k;i++){
        if(c1[a[i]]&&c1[a[i]]!=a[i])_write(dis1[a[i]]);
        else if(c2[a[i]])_write(dis2[a[i]]);
        else _write(-1);
    }
	return 0;
}
