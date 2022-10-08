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
//#define int long long
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
const int INF=1000114514;
}using namespace Zimse;

const int N=1e6+7;

int n,m,Dis[N],hd[N],nxt[N],to[N],ec;
int cnt[N],rt,mx,_n,vis[N],ans;
double c[3];
int D[N],tot,s[N];

inline void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

void findrt(int u,int from){
	cnt[u]=1;
	int ms=0;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||vis[v])continue;
		findrt(v,u),cnt[u]+=cnt[v];
		_max(ms,cnt[v]);
	}
	_max(ms,_n-cnt[u]);
	if(ms<mx)mx=ms,rt=u;
	return;
}

void Dfs(int u,int from,int d){
	++s[d],D[++tot]=d;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from||vis[v])continue;
		Dfs(v,u,d+1);
	}
	return;
}

void sol(int u,int _p,int _d){
	Dfs(u,0,_d);
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=m;j++){
			if(Dis[j]-D[i]>=0)ans+=s[Dis[j]-D[i]]*_p;
		}
	}
	for(int i=1;i<=tot;i++)s[D[i]]=0;
	tot=0;
	return;
}

void divide(int u){
	vis[u]=1;
	sol(u,1,0);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(vis[v])continue;
		sol(v,-1,1);
		mx=INF,_n=cnt[v],findrt(v,0);
		divide(rt);
	}
	return;
}

signed main(){
	ifile("accelerator.in");
	ofile("accelerator.out");
	
	n=read(),m=read();
	for(int i=1;i<=m;i++)Dis[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),add(u,v),add(v,u);
	for(int i=1;i<=n;i++)c[i%3]+=1;
	for(int i=0;i<3;i++){
		c[i]=(c[i]/double(n))*((c[i]-1)/double(n-1));
	}
	mx=INF,_n=n;
	findrt(1,0);
	divide(rt);
	ans/=2;
	double A=double(ans);
	printf("%.2lf\n%.2lf\n%.2lf\n",A*c[1],A*c[2],A*c[0]);
	return 0;
}


