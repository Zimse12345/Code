/********************************
*FileName:
*Author: Zimse
*Data: 2022-09-19
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

int n,m,k,col[N],U[N],V[N],fa[N],cnt[N],tag[N];
ll ans;

struct node{
	int* p;
	int val;
	node(int* p=0,int val=0):p(p),val(val){}
};
vector<node> rbs;

struct edge{
	int u,v;
	edge(int u=0,int v=0):u(u),v(v){}
	bool operator < (const edge& _)const{
		if(col[u]==col[_.u])return col[v]<col[_.v];
		return col[u]<col[_.u];
	}
}e[N];

int F(int u){
	return (fa[u]==u)?u:F(fa[u]);
}

inline void link(int u,int v){
	u=F(u),v=F(v);
	if(u!=v){
		if(cnt[u]<cnt[v])swap(u,v);
		fa[v]=u,cnt[u]+=cnt[v];
	}
	return;
}

inline void _link(int u,int v){
	u=F(u),v=F(v);
	if(u!=v){
		if(cnt[u]<cnt[v])swap(u,v);
		rbs.emplace_back(&fa[v],fa[v]);
		rbs.emplace_back(&cnt[u],cnt[u]);
		fa[v]=u,cnt[u]+=cnt[v];
	}
	return;
}

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)col[i]=read();
	for(int i=1;i<=n*2;i++)fa[i]=i,cnt[i]=1;
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		if(col[u]==col[v]){
			link(u,v+n),link(u+n,v);
			if(F(u)==F(u+n))tag[col[u]]=1;
		}
		if(col[u]>col[v])swap(u,v);
		e[i]=edge(u,v);
	}
	ll ans=k;
	for(int i=1;i<=k;i++)if(tag[i])--ans;
	ans=(ans*(ans-1))/2;
	sort(e+1,e+m+1);
	for(int l=1,r=0;l<=m;){
		r=l;
		while(r<m&&col[e[r+1].u]==col[e[r].u]&&col[e[r+1].v]==col[e[r].v])++r;
		if(!tag[col[e[l].u]]&&!tag[col[e[l].v]]&&col[e[l].u]!=col[e[l].v]){
			for(int i=l;i<=r;i++){
				_link(e[i].u,e[i].v+n),_link(e[i].u+n,e[i].v);
				if(F(e[i].u)==F(e[i].u+n)){
					--ans;
					break;
				}
			}
			for(unsigned i=0;i<rbs.size();i++)*rbs[i].p=rbs[i].val;
			rbs.resize(0);
		}
		l=r+1;
	}
	printf("%lld\n",ans);
	return 0;
}


