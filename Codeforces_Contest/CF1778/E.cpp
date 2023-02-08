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

int T,n,m,val[N],hd[N],nxt[N],to[N],ec,dfn[N],tot,cnt[N],pr[N][32],dep[N];

struct node{
	int v[32];
	void init0(){
		for(int i=0;i<32;i++)v[i]=0;
		return;
	}
	int qmx(){
		int res=0;
		for(int i=30;i>=0;i--){
			if((res^v[i])>res)res^=v[i];
		}
		return res;
	}
}f[220000],g[220000],pre[220000],suf[220000];

inline void link(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

void add(node& p,int x){
	for(int i=30;i>=0;i--)if(x&(1<<i)){
		if(!p.v[i]){
			p.v[i]=x;
			break;
		}
		else x^=p.v[i];
	}
	return;
}

node merge(node p1,node p2){
	node p=p1;
	for(int i=30;i>=0;i--)if(p2.v[i])add(p,p2.v[i]);
	return p;
}

void dfs(int u,int from){
	pr[u][0]=from;
	dep[u]=dep[from]+1;
	dfn[u]=++tot,cnt[u]=1;
	add(f[u],val[u]);
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		dfs(v,u);
		cnt[u]+=cnt[v];
		f[u]=merge(f[u],f[v]);
	}
//	printf("f[%d].mx=%d\n",u,f[u].qmx());
	return;
}

void dfs2(int u,int from){
	if(from)add(g[u],val[from]);
	vector<int> a;
	for(int i=hd[u],v;i;i=nxt[i]){
		v=to[i];
		if(v==from)continue;
		a.pb(v);
	}
	int sz=a.size();
	for(int i=0;i<sz;i++){
		if(i==0)pre[a[i]]=f[a[i]];
		else pre[a[i]]=merge(f[a[i]],pre[a[i-1]]);
	}
	for(int i=sz-1;i>=0;i--){
		if(i==sz-1)suf[a[i]]=f[a[i]];
		else suf[a[i]]=merge(f[a[i]],suf[a[i+1]]);
	}
	for(int i=0;i<sz;i++){
		g[a[i]]=g[u];
		if(i>0)g[a[i]]=merge(g[a[i]],pre[a[i-1]]);
		if(i<sz-1)g[a[i]]=merge(g[a[i]],suf[a[i+1]]);
		dfs2(a[i],u);
	}
	return;
}

int find(int u,int v){
	for(int i=30;i>=0;i--)if(dep[pr[u][i]]>dep[v])u=pr[u][i];
	return u;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)val[i]=read();
		for(int i=1,u,v;i<n;i++)u=read(),v=read(),link(u,v),link(v,u);
		dfs(1,0);
		for(int i=1;i<=30;i++)for(int j=1;j<=n;j++){
			pr[j][i]=pr[pr[j][i-1]][i-1];
		}
		dfs2(1,0);
		m=read();
		while(m--){
			int u=read(),v=read();
			if(u==v)_write(f[1].qmx()); 
			else if(dfn[u]<=dfn[v]&&dfn[v]<=dfn[u]+cnt[u]-1)_write(f[v].qmx());
			else if(dfn[v]<=dfn[u]&&dfn[u]<=dfn[v]+cnt[v]-1)_write(g[find(u,v)].qmx());
			else _write(f[v].qmx());
		}
		for(int i=1;i<=n;i++){
			f[i].init0(),g[i].init0(),pre[i].init0(),suf[i].init0();
			hd[i]=0;
		}
		tot=ec=0;
	}
    return 0;
}


